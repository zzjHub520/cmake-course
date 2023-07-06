// test_thread_pool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
    pool.Start(16); //启动16个线程
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
