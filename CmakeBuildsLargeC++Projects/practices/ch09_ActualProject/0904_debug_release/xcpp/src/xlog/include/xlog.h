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

// xlog.h: ��׼ϵͳ�����ļ��İ����ļ�
// ����Ŀ�ض��İ����ļ���
/*! \addtogroup xlog
   *  Additional documentation for group 'xlog'
   *  @{
   */
///////////////////////////////////////////////////////////////////////////
/// @mainpage xcpp ��Դ����c++�� ��־���̳߳� ������
/// @brief
/// - ��Ŀ���Ĳܿ��Ͷ�������ʦ�������е�ѧԱ�����Բ���˿�Դ��Ŀ���������ף���д����Ŀ�����б���
/// - ��Ŀ����c++ 11 14 17 �汾������20 22 �ռ������룩��ʹ��c++��˼ά������������c���c++
/// - ��Ŀ�������߻���cmake ����Ŀ��ƽ̨�Ѿ�֧��windows linux��x86�� macos Android openharmony harmonyos 
/// - �ƻ�֧��linux(arm) ios
/// 
/// @author �Ĳܿ� ������ѧԱ��������
/// @version 1.0.1
/// @date 2022��05��10��
///////////////////////////////////////////////////////////////////////////
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






/////////////////////////////////////////////////
/**
 * @file xlog.h
 * @brief  ��־�ӿ����ļ�
 *
 * ʹ��˵��:
 * - 1
 * - 2
 * >- 2.1
 * >- 2.2
 * @code{.cpp}
 * LOGDEBUG<<"test log debug"<<10;
 * LOGINFO<<"test log info "<<10.1;
 * @endcode
 * @author xiacaojun@qq.com
 * @copyright { ��Ȩ���Ĳܿ��Ϳ�Դ�����߹�ͬӵ�У������������߽�����������������ҵӦ�á� }
 */


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

/** @brief ��־���� !<���ɱ��
*/
enum class LogLevel
{
	DEBUG,			//!< ���Լ�����־
	INFO,			//!< ����������־
	WARNING,		//!< ����
	ERROR,			//!< ����
	FATAL			//!< �����жϵĴ��� 
};
#define LOG(level) xcpp::XLogMessage(__FILE__, __LINE__, xcpp::LogLevel::level).stream()
#define LOGDEBUG LOG(DEBUG)	
#define LOGINFO LOG(INFO)
#define LOGWARNING LOG(WARNING)
#define LOGERROR LOG(ERROR)
#define LOGFATAL LOG(FATAL)
	

/**
 * @brief  ��ʼ����־ģ�飬�Ὺ����־д���߳�
 * @param appname	������־��Ӧ������
 * @param logpath	��־��д��·�����Ժ�֧������·��
 * @param filename ��־д����ļ�����Ժ�֧�ָ�ʽ�����ƣ�����������־
 * @return ��ʼ���ɹ�ʧ�� ��Ԫ������
 */
XCPP_API bool InitXLog(const char* appname,const char *logpath = DEFAULT_LOG_PATH, const char* filename = DEFAULT_LOG_FILENAME);
	
/**
 * @brief  �����ã�������־�̺߳Ͷ���
 * @return �ɹ�����true 
 */
XCPP_API bool CloseXLog();

/**
 * @brief ��־д��ӿ�
 */
class XCPP_API XWrite
{
public:
	virtual int Write(const char* msg) = 0;
	XWrite(){}
	virtual ~XWrite() {}
};


/**
 * @brief ��־��Ϣ������.
 * �����������־��Ϣ�����͵�д���߳�
 */
class XCPP_API XLogMessage
{
public:
	/**
	 * @brief  ������
	 * @return stringstream �ַ�������д�����У����������лᷢ�͸�д���߳�
	 */
	std::stringstream& stream()
	{
		return stream_;
	}
	XLogMessage();

	/**
	 * @brief ���캯��.
	 * @brief Constructor.
	 *
	 * @param[in] file		��־���������ļ���
	 * @param[in] line		��־�����к�
	 * @param[in] level		��־����
	 */
	XLogMessage(const char* file, int line, LogLevel level);
	~XLogMessage() ;
	static void set_write(std::unique_ptr<XWrite> &&w) { write_ = move(w); }
	void set_name(const char* name) { name_ = name; }
private:
	/**
	 * ��־�ַ�����
	 */
	std::stringstream stream_;
	
	/**
	 * ע���д�������
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