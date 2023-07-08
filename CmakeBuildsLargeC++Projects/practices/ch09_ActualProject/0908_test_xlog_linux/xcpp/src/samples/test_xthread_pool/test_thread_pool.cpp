// test_thread_pool.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include "xthread_pool.h"
using namespace std;
using namespace xcpp;
int main()
{
    //{
    //    packaged_task<string()> task(
    //        []() {
    //            return "test packaged_task";
    //        });
    //    auto fut = task.get_future();
    //    task();
    //    cout<<"fut.get() = "<<fut.get()<<endl;
    //} 
    //getchar();
    XThreadPool pool;
    pool.Start(16); //����16���߳�
    auto re = pool.Exec([](int i) {
        cout << "test pool exec1" << endl;
        return 201;
        },1234);
    cout << "return =" << re.get() << endl;
    re = pool.Exec([](int i) {
        cout << "test pool exec2" << endl;
        return 202;
        }, 1234);
    cout << "return =" << re.get() << endl;
    re = pool.Exec([](int i) {
        cout << "test pool exec3" << endl;
        return 203;
        }, 1234);
    cout << "return =" << re.get() << endl;
    /*pool.Exec([]
        {
            cout << "test pool exec2" << endl; 
            return 202; 
        });
    pool.Exec([] (int index)
        {
            cout << index<< "test pool exec" << endl; 
            return 203;
        },101
    );
    */
   this_thread::sleep_for(300ms);
   pool.Stop();
   return 0;
    //getchar();
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
