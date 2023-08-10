#ifndef XLOG_THREAD_H
#define XLOG_THREAD_H

#include "xlog.h"
#include <fstream>
#include <thread>
#include <mutex>
#include <string>
#include <queue>
#include <condition_variable>

_XCPP_NAMESPACE_

class XLogThread:public XWrite
{
public:
	bool Init(const char* log_path,const char *filename);
	int Write(const char* msg);
	void Start();
	void Stop();
	XLogThread(){}
	virtual ~XLogThread()
	{
		Stop();
	}
private:
	void Run();
	std::ofstream ofs_;
	std::thread th_;
	std::mutex mux_;
	std::string log_path_;
	std::queue<std::string> msgs_;
	std::condition_variable cv_;
	bool is_exit_ = false;
};

_END_NAMESPACE_

#endif
