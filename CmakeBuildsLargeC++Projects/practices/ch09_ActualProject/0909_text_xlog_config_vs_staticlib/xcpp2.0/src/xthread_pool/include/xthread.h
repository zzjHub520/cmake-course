
#ifndef XTHREAD_H
#define XTHREAD_H
#include <thread>
#include <memory>
namespace xcpp
{ 
    class XThread
    {
        /**
         * @brief  ����, ��ʾ��ǰ���е��̣߳�
         *  		join��detach�ڲ����ڸö����ϵ���
         * explicit ������ʽת�� ���� th1 = th2 
        */
        explicit XThread(); 

        /**
         * @brief  �ȴ���ǰ�߳̽���
         */
        void Join();

        /**
         * @brief  detach, �����߳���thread����
         */
        void Detach();

        /**
         * @brief  ��ȡ��ǰ�߳�id.
         *
         * @return ��ǰ�߳�id
         */
        std::thread::id id() const;

        /**
         * @brief  Sleep ��ǰ�߳��ͷ�cpu 
         *  
         * @param millsecond ����
         */
        static void Sleep(int ms);
        
        /**
         * @brief  ������ǰ�߳̿���Ȩ
         */
        static void Yield();
    private:
        std::unique_ptr<std::thread> th_;
    };
}
#endif