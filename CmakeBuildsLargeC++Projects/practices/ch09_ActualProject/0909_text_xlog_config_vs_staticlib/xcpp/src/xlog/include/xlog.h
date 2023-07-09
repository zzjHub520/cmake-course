#ifndef XLOG_H
#define XLOG_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#ifdef _WIN32
//int i = 0;
#endif
#include "xconfig.h"


#ifdef _WIN32
#define DEFAULT_LOG_PATH "./"
#else
#define DEFAULT_LOG_PATH "/var/log/xcpp/"
#endif
#define DEFAULT_LOG_FILENAME  "xlog.txt"


_XCPP_NAMESPACE_
// INFO:
//   Use for state changes or other major events, or to aid debugging.
// WARNING:
//   Use for undesired but relatively expected events, which may indicate a
//   problem
// ERROR:
//   Use for undesired and unexpected events that the program can recover from.
//   All ERRORs should be actionable - it should be appropriate to file a bug
//   whenever an ERROR occurs in production.
// FATAL:

/** @brief 日志级别 !<生成表格
*/
enum class LogLevel
{
	DEBUG,			//!< 调试级别日志
	INFO,			//!< 正常操作日志
	WARNING,		//!< 警告
	ERROR,			//!< 错误
	FATAL			//!< 导致中断的错误 
};
#define LOG(level) xcpp::XLogMessage(__FILE__, __LINE__, xcpp::LogLevel::level).stream()
#define LOGDEBUG LOG(DEBUG)	
#define LOGINFO LOG(INFO)
#define LOGWARNING LOG(WARNING)
#define LOGERROR LOG(ERROR)
#define LOGFATAL LOG(FATAL)
	

/**
 * @brief  初始化日志模块，会开启日志写入线程
 * @param appname	产生日志的应用名称
 * @param logpath	日志的写入路径，以后支持网络路径
 * @param filename 日志写入的文件命令，以后支持格式化名称，滚动生成日志
 * @return 初始化成功失败 单元测试用
 */
XCPP_API bool InitXLog(const char* appname,const char *logpath = DEFAULT_LOG_PATH, const char* filename = DEFAULT_LOG_FILENAME);
	
/**
 * @brief  测试用，清理日志线程和对象
 * @return 成功返回true 
 */
XCPP_API bool CloseXLog();

/**
 * @brief 日志写入接口
 */
class XCPP_API XWrite
{
public:
	virtual int Write(const char* msg) = 0;
	XWrite(){}
	virtual ~XWrite() {}
};


/**
 * @brief 日志消息处理类.
 * 接收输入的日志消息，发送到写入线程
 */
class XCPP_API XLogMessage
{
public:
	/**
	 * @brief  输入流
	 * @return stringstream 字符串流，写入其中，对象析构中会发送给写入线程
	 */
	std::stringstream& stream()
	{
		return stream_;
	}
	XLogMessage();

	/**
	 * @brief 构造函数.
	 * @brief Constructor.
	 *
	 * @param[in] file		日志产生所在文件名
	 * @param[in] line		日志产生行号
	 * @param[in] level		日志级别
	 */
	XLogMessage(const char* file, int line, LogLevel level);
	~XLogMessage() ;
	static void set_write(std::unique_ptr<XWrite> &&w) { write_ = move(w); }
	void set_name(const char* name) { name_ = name; }
private:
	/**
	 * 日志字符串流
	 */
	std::stringstream stream_;
	
	/**
	 * 注入的写处理对象
	 */
	static std::unique_ptr<XWrite> write_;

	std::string name_;
};

_END_NAMESPACE_

//class XFileWrite
//{
//public:
//	int Write(const std::string&& msg);
//private:
//	std::ofstream ofs_;
//};
//LOG(INFO) << "Found " << num_cookies << " cookies";


#endif

/*! @} */