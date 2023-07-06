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
    //线程池 
    class  XCPP_API XThreadPool
    {
    public:
        //启动所有线程
        void Start(int num);
        void Stop();

        template<class F, class...Args>
        // future 获取返回值
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

        //线程池函数
        void Run();
        //所有的线程句柄
        std::vector<std::shared_ptr<std::thread> >threads_;
        //任务队列
        std::queue<std::function<void()>> tasks_;
        std::mutex mux_;

        std::condition_variable cv_;
        bool is_exit_ = false;
    };
}
#endif  
