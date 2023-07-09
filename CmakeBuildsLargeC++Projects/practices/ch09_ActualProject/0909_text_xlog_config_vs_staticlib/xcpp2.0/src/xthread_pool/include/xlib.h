
#ifdef _WIN32
//int i = 0;
#endif  
#ifndef _WIN32
    #define XCPP_API 
#else
    #ifdef XTHREAD_POOL_STATIC
        #define XCPP_API 
    #else
        #ifdef XTHREAD_POOL_EXPORTS
            #define XCPP_API __declspec(dllexport)
        #else
            #define XCPP_API __declspec(dllimport)
        #endif
    #endif
#endif 