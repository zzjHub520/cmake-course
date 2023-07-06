#ifndef XCONFIG_H
#define XCONFIG_H
//ֱ���޸�xconfig.h��Ч����Ҫ�޸�xconfig.h.in
#define _END_NAMESPACE_ }
#define _XCPP_NAMESPACE_ namespace xcpp {

#ifndef _WIN32
	#define XCPP_API 
#else
	#ifdef XLOG_STATIC
		#define XCPP_API 
	#else
		#if XLOG_EXPORTS
			#define XCPP_API __declspec(dllexport)
		#else
			#define XCPP_API __declspec(dllimport)
		#endif
	#endif
#endif

#endif
