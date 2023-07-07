#ifndef XTHREAD_H
#define XTHREAD_H
#include <thread>
#include <memory>
namespace xcpp
{ 
    class XThread
    {
        /**
         * @brief  构造, 表示当前运行的线程，
         *  		join和detach在不能在该对象上调用
         * explicit 不能隐式转换 比如 th1 = th2 
        */
        explicit XThread(); 

        /**
         * @brief  等待当前线程结束
         */
        void Join();

        /**
         * @brief  detach, 分离线程与thread对象
         */
        void Detach();

        /**
         * @brief  获取当前线程id.
         *
         * @return 当前线程id
         */
        std::thread::id id() const;

        /**
         * @brief  Sleep 当前线程释放cpu 
         *  
         * @param millsecond 毫秒
         */
        static void Sleep(int ms);
        
        /**
         * @brief  交出当前线程控制权
         */
        static void Yield();
    private:
        std::unique_ptr<std::thread> th_;
    };
}
#endif