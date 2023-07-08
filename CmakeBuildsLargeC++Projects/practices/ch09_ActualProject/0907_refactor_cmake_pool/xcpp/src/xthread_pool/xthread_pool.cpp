#include "xthread_pool.h"
#include <iostream>

namespace xcpp
{

    using namespace std;
    using namespace this_thread;

//线程池函数
    void XThreadPool::Run()
    {
        //cout << "Run " << get_id() << endl;
        while(!is_exit_)
        {
            unique_lock<mutex> lock(mux_);
            cv_.wait(lock, [this]
            {
                return is_exit_||!tasks_.empty();
            });
            while (!tasks_.empty())
            {
                tasks_.front()();
                tasks_.pop();
            }
        }
        //task();
    }

    void XThreadPool::Stop()
    {
        is_exit_ = true;
        cv_.notify_all();
        //unique_lock<mutex> lock(mux_);
        //is_exit_ = true;
        //num值判断，确定threads_,是否已经初始化
        for(auto &th :threads_)
        {
            th->join();
        }
        unique_lock<mutex> lock(mux_);
        threads_.clear();
    }
    void XThreadPool::Start(int num)
    {
        unique_lock<mutex> lock(mux_);
        //num值判断，确定threads_,是否已经初始化
        for (int i = 0; i < num; i++)
        {
            auto th = make_shared<thread>(&XThreadPool::Run, this);
            threads_.push_back(th);
        }
    }

}