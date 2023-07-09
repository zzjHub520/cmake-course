//////////////////////////////////  @��Ȩ˵��  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @��Ȩ˵�� ����Ϳγ̰�Ȩ���Ĳܿ���ӵ�в��Ѿ���������Ȩ���˴��������Ϊѧϰ�ο���������Ŀ��ʹ�ã�
/// �γ����漰����������Դ���������������Ӧ����Ȩ
/// �γ�Դ�벻����ֱ��ת�ص������Ĳ��ͣ�������������ƽ̨�������������������߿γ̡�
/// �γ����漰����������Դ���������������Ӧ����Ȩ  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Դ��˵��  //////////////////////////////////////////////////
/// ��Ŀ����: CMake��������c++��Ŀ
/// ����   : 			    http://blog.csdn.net/jiedichina
/// ��Ѷ����			    https://jiedi.ke.qq.com/
/// ѧ��				    ���� �Ĳܿ�
/// ���Ŀ���			    http://cppds.com 
/// CMake�ֲ�    	        http://cmake.org.cn
/// �����������γ�qqȺ ��296249312����ͬѧ���� 
/// ��ӭ���Ĳܿ���ʦ��΢�ţ�cppxcj
///�������Ŀ���Ⱥ��296249312��ֱ����ϵȺ��ͷ����ؿγ�����
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// �γ̽���qqȺ296249312 //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////

#include <sstream>
#include "xlog_thread.h"
#include <sstream>
#include <iomanip>
#include <memory>
#include <time.h>
#include "xlog.h"
using namespace std;

_XCPP_NAMESPACE_ 

unique_ptr<XWrite> XLogMessage::write_;
static const char* LogLevelName[]{
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
	"FATAL"
};
	
//ֻ�ڲ���ʱ��
bool CloseXLog()
{
	XLogMessage::set_write(nullptr);
	return true;
}
bool InitXLog(const char* appname, const char* logpath, const char* filename)
{
	cout << "Init XLog appname = " << appname <<" path = "<< logpath << endl;
	unique_ptr<XLogThread> xt(new XLogThread());
	if (!xt->Init(logpath, filename))
		return false;
	xt->Start();
	XLogMessage::set_write(move(xt));
	return true;
}
XLogMessage::~XLogMessage()
{
	if(write_)
		write_->Write(stream_.str().c_str());
}

XLogMessage::XLogMessage(const char* file, int line, LogLevel level)
{
	auto time_now = chrono::system_clock::now();
	time_t t = std::chrono::system_clock::to_time_t(time_now);

	auto duration_in_ms = chrono::duration_cast<chrono::milliseconds>(time_now.time_since_epoch());

	tm tt;
	//��ʱ��ʱ��
	#if _WIN32
	::localtime_s(&tt, &t);
	#else 
	::localtime_r(&t, &tt);
	#endif
     
	LogLevelName[1];
	int le = static_cast<int>(level);

	stream_ << "["<<LogLevelName[le] << ' ' << setfill('0')
		<< setw(4) << tt.tm_year + 1900<<"-"
		<< setw(2) << tt.tm_mon + 1 << "-"
		<< setw(2) << tt.tm_mday
		<< ' '
		<< setw(2) << tt.tm_hour << ':'
		<< setw(2) << tt.tm_min << ':'
		<< setw(2) << tt.tm_sec << '.'
		<< setw(6) << (int)((duration_in_ms % 1000).count())
		<< ' '
		<< setfill(' ') <<" (" << this_thread::get_id()<<")" << setfill('0')
		<< ' '
		<< file << ':' << line << "] ";

}
XLogMessage::XLogMessage()
{

}

_END_NAMESPACE_
