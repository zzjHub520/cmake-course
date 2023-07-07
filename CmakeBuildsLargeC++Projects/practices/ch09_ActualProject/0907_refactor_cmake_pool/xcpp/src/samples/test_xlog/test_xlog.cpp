#include "xlog.h"
using namespace std;
using namespace xcpp;
int main()
{
	cout << "Test XLog " << endl;
	xcpp::InitXLog("MyApp");

	LOGINFO << "===== test xlog=====";
	LOGINFO << "cmake.org.cn";
	LOGDEBUG << "cppds.com";

	CloseXLog();
	//getchar();
	return 0;
} 