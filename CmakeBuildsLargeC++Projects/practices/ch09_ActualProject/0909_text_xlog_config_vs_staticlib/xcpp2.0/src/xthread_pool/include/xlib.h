//////////////////////////////////  @��Ȩ˵��  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @��Ȩ˵�� ����Ϳγ̰�Ȩ���Ĳܿ���ӵ�в��Ѿ���������Ȩ���˴��������Ϊѧϰ�ο���������Ŀ��ʹ�ã�
/// �γ����漰����������Դ����������������Ӧ����Ȩ
/// �γ�Դ�벻����ֱ��ת�ص������Ĳ��ͣ�������������ƽ̨�������������������߿γ̡�
/// �γ����漰����������Դ����������������Ӧ����Ȩ  @@              
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