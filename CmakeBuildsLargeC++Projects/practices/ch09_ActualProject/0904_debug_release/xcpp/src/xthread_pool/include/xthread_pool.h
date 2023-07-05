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

#ifndef XTHREAD_POOL_H
#define XTHREAD_POOL_H
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <queue>
#include <functional>
#include "xlib.h"
namespace xcpp
{  
    //�̳߳� 
    class  XCPP_API XThreadPool
    {
    public:
        //���������߳�
        void Start(int num);
        void Stop();

        template<class F, class...Args>
        // future ��ȡ����ֵ
        auto Exec(F&& f, Args&&...args)->
            std::future<decltype(f(args...))>
        {
            using Ret = decltype(f(args...));
            //auto f1 = std::bind(f, args...);
            //f1()
            auto task = std::make_shared<std::packaged_task<Ret()>>(
                std::bind(f, args...));
            auto task_func = [task] {
                (*task)();
            };
            tasks_.push(task_func);
            cv_.notify_one();
            return task->get_future();
            //task();
        }


    private:

        //�̳߳غ���
        void Run();
        //���е��߳̾��
        std::vector<std::shared_ptr<std::thread> >threads_;
        //�������
        std::queue<std::function<void()>> tasks_;
        std::mutex mux_;

        std::condition_variable cv_;
        bool is_exit_ = false;
    };
}
#endif  
