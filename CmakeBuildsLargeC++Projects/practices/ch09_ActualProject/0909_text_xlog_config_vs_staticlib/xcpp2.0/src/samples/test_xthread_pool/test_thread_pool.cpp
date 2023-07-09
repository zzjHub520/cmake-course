
#include <iostream>
#include "xthread_pool.h"
using namespace std;
using namespace xcpp;
int main()
{
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
}

