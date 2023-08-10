#include "xlog_thread.h"
#include <chrono>
using namespace std;
_XCPP_NAMESPACE_

bool XLogThread::Init(const char* log_path, const char* filename)
{
	//is_log_init = false;
	this->log_path_ = log_path;
	//测试用，后期改为滚动日志文件
	string logfile = log_path;
	logfile += filename;
	ofs_.open(logfile, ios::app);
	if (ofs_)
		return true;
	return false;
}

int XLogThread::Write(const char* msg)
{
	{
		lock_guard<mutex> lock(mux_);
		msgs_.push(msg);  
	}
	cv_.notify_one();
	return 0;
}

void XLogThread::Start()
{
	th_ = thread(&XLogThread::Run, this);
}
void XLogThread::Stop()
{
	if (!th_.joinable())
		return;
	is_exit_ = true;
	cv_.notify_all();
	th_.join();
}

void XLogThread::Run()
{
	for(;;)
	{
		string msg;
		unique_lock<mutex> lock(mux_);	
		cv_.wait(lock, [this] 
        {
            return is_exit_||!msgs_.empty();
        });
		while(!msgs_.empty())
		{
			msg = move(msgs_.front());
			msgs_.pop();
			lock.unlock();
			ofs_ << msg << endl;
			cout << msg << endl;
			lock.lock();
		}
		if(is_exit_)
			break;
	}
}


_END_NAMESPACE_