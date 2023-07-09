
#include "xthread.h"
using namespace std;
namespace xcpp{
XThread::XThread()
{
    th_ = make_unique<thread>();
}
} 
   