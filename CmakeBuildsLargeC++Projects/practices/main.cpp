//
// Created by zzj on 2023/6/3.
//

#include <iostream>
#include <regex>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    system("chcp 65001 > nul");

    string str = R"(##  cmake构建vs_qt项目示例程序完成 08:40

##  cmake设置QT的SDK路径加载qt库和头文件 12:34

##  qt程序执行的依赖库自动复制 02:48

##  cmake导入qt库完成qt界面示例代码-有资源找不到错误 12:09

##  生成qt资源、界面和信号槽c++代码 14:24

##  cmake编译QT项目输出x86和x64程序 12:29

##  cmake_qt项目install07:07

##  cmake自动复制qt依赖库并完成install22:35
)";

    regex reg("\n\n");
    auto iter = sregex_token_iterator(str.begin(), str.end(), reg, -1);
    auto end = sregex_token_iterator();
    vector<string> vec(iter, end);
    int num = 1;
    stringstream ss;
    regex regRep(R"~(^##  )~");
    for (auto &ele: vec) {
        ss.clear();
        ss.str("");
        ss << setw(2) << setfill('0') << num++;
        string strTmp;
        ss >> strTmp;
        ele = regex_replace(ele, regRep, "##  " + strTmp + " ");
        cout << ele << endl << endl;
    }


    return 0;
}