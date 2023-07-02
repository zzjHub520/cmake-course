# CMake快速入门

##  01 cmake课程介绍 17:09

##  02 第一章介绍 04:27

##  03 cmake是什么为什么要好的构建工具06:52

##  04 什么是持续集成05:52

##  05 为什么用cmake及它的特性05:50

##  06 cmake工作原理图解分析04:35

##  07 cmake源码linux_ubuntu_编译安装10:50

##  08 cmake windows安装二进制版本06:29

##  09 windows下使用cmake编译cmake源码并安装12:18

##  10 macos_cmake安装源码编译09:26

##  11 fist_cmake第一个CMakeLists.txt示例10:07

##  12 windows下用vs2022编译第一个cmakelists.txt08:22

##  13 windwos下用cmake生成nmake的项目并编译06:50

nmake



##  14 linux和macos下编译第一个cmake c++项目10:13

```cmake
#cmake多线程编译
cmake --build build/ -j32

# 使用相关的应用程序打开已生成的项目。只有某些生成器支持这个操作
cmake --open build
```





##  15 编译cmake库的前置准备和静态库的实战原理分析09:48

> **静态库和动态库的区别**
>
> - **版权的问题**
>
> 绝大多数开源的库都是不开放静态库的，只能是共享库
>
> - **依赖库的问题**
>
> ​	在Windows中，线程库有两个版本静态的和动态的，比如你的库引用的线程库是静态的，而调用的库的程序用的是动态的，就会报编译的错误，两个库要一致的错误
>
> - **编译的时间的问题**
>
> ​	动态库的编译时间是静态库的10分之一
>
> - **命名的问题**
>
> windows 
>
> ​	编译静态库，release版和debug版的名字不同
>
> ​	release：xlog.lib
>
> ​	debug  ：xlog_d.lib
>
> unix
>
> ​	编译静态库，release版和debug版的名字相同
>
> **总结**
>
> 静态库的好处是运行简单，编译麻烦
>
> 动态库的好处是编译简单，运行麻烦



##  16 动态库原理和头文件作用09:17

##  17cmake静态库xlog跨平台编译windows、linux、macos11:23

**Windows**

xlog.lib

xlog.pdb 调试用的

##  18 cmake 链接静态库19:43

```
└── 102cmake_lib
    ├── test_xlog
    │   ├── CMakeLists.txt
    │   └── test_xlog.cpp
    └── xlog
        ├── CMakeLists.txt
        ├── xlog.cpp
        └── xlog.h
```

**xlog源码**

```
#CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(xlog)
add_library(xlog STATIC xlog.cpp xlog.h)

//xlog.h
#ifndef XLOG_H
#define XLOG_H
class XCPP_API XLog
{
public:
    XLog();
};
#endif

//xlog.cpp
#include "xlog.h"
#include <iostream>
using namespace std;
XLog::XLog()
{
    cout<<"Create XLog"<<endl;
}
```

**test_xlog源码**

```
#CMakeLists.txt test_xlog 102
cmake_minimum_required(VERSION 3.20)
project(test_xlog)
#指定头文件查找路径 
include_directories("../xlog")

# 指定库查找路径  window自动找 ../xlog/build/Debug  ../xlog/build/Release
link_directories("../xlog/build")

add_executable(test_xlog test_xlog.cpp)

# 指定加载的库
target_link_libraries(test_xlog xlog)

// test_xlog.cpp
#include <iostream>
#include "xlog.h"
using namespace std;
int main()
{
    XLog log;
    cout<<"test xlog"<<endl;
    return 0;
}
```



##  19 cmake 动态库编译和链接linux14:08

```
└── 102cmake_lib
    ├── CMakeLists.txt
    ├── test_xlog
    │   ├── CMakeLists.txt
    │   └── test_xlog.cpp
    └── xlog
        ├── CMakeLists.txt
        ├── xlog.cpp
        └── xlog.h
```



```cmake
cmake_minimum_required(VERSION 3.20)
project(blp_ch01_part20_dylibTest_Windows_mac)
include_directories(xlog)
add_library(blp_ch01_part20_xlog SHARED xlog/xlog.cpp)
add_executable(blp_ch01_part20_test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(blp_ch01_part20_test_xlog blp_ch01_part20_xlog)
```



**xlog源码**

```
//xlog.h
#ifndef XLOG_H
#define XLOG_H
class XCPP_API XLog
{
public:
    XLog();
};
#endif

//xlog.cpp
#include "xlog.h"
#include <iostream>
using namespace std;
XLog::XLog()
{
    cout<<"Create XLog"<<endl;
}
```

**test_xlog源码**

```
// test_xlog.cpp
#include <iostream>
#include "xlog.h"
using namespace std;
int main()
{
    XLog log;
    cout<<"test xlog"<<endl;
    return 0;
}
```



##  20 cmake动态库windows和mac测试14:39

# 第二章：CMake常用功能

##  01 第二章介绍 04:47                                                         

##  02 cmake注释和message基础11:27                                              

##  03 cmake message高级使用-指定日志级别07:30   

![image-20230605002519583](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605002519583.png)      

![image-20230605002914955](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605002914955.png)


##  04 cmake message日志级别代码演示和重定到文件16:43                           

##  05 cmake message 模块查找日志和显示缩进12:01                                

##  06 cmake set变量入门和示例10:58       

![image-20230605230606681](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605230606681.png)

 ![image-20230605230733846](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605230733846.png)   

  ![image-20230605230813905](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605230813905.png)



##  07 cmake 变量示例设置message消息颜色11:22                                   

![image-20230605232429826](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605232429826.png)

![image-20230605232720482](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605232720482.png)



##  08 cmake自带的四种变量和给c++传递变量演示20:59                              

![image-20230605234723986](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605234723986.png)

![image-20230605234933629](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605234933629.png)

![image-20230605235317931](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605235317931.png)

![image-20230605235349048](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605235349048.png)

![image-20230605235500202](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230605235500202.png)



##  09 cmake include分析和示例12:05                                             

![image-20230606205733337](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606205733337.png)

![image-20230606205751065](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606205751065.png)



##  10 cmake自动载入项目源码文件20:44                                           

![image-20230606212109113](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606212109113.png)

![image-20230606212126170](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606212126170.png)

![image-20230606212346784](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606212346784.png)





##  11 CMake file自动导入头文件到项目04:43                                      

##  12 CMake分步编译和清理指定target目标18:12                                   

![image-20230606220413723](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606220413723.png)

![image-20230606222623135](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606222623135.png)

##  13 cmake调试打印生成的具体指令10:51      

![image-20230606224020219](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606224020219.png)

![image-20230606224117376](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606224117376.png)

![image-20230606223946577](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606223946577.png)



##  14 CMake设置输出路径跨平台演示分析23:06                                     

![image-20230606224205073](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606224205073.png)

![image-20230606224708970](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230606224708970.png)

![image-20230608233242012](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230608233242012.png)



##  15 cmake add_subdirectory05:23    



# 第三章：CMake主要语法

##  01 第三章介绍 03:41

![image-20230608235410298](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230608235410298.png)



##  02 cmake if语法说明与常量判断代码演示18:27    

![image-20230608235841807](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230608235841807.png)

![image-20230609000843123](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000843123.png)

### if(\<constant>)

![image-20230608235932387](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230608235932387.png)

![image-20230609000124904](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000124904-16862400858691.png)

![image-20230609000143989](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000143989.png)

![image-20230609000352902](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000352902.png)

### if(\<variable>)

![image-20230609000709383](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000709383.png)

![image-20230609000730599](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000730599.png)

![image-20230609000748723](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609000748723.png)

### if(\<string>)

![image-20230609001112572](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230609001112572.png)



##  03 cmake if 变量和字符串判断代码演示07:39     





##  04 cmake if逻辑运算符06:55                    

![image-20230610143149006](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610143149006.png)



##  05 cmake if一元、二元比较和正则匹配16:46      

![image-20230610144644254](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610144644254.png)



##  06 cmake cache缓存变量设置14:16               

![image-20230610152639588](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610152639588.png)

![image-20230610153317037](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610153317037.png)

![image-20230610153810911](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610153810911-16863826920861.png)

![image-20230610153902643](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610153902643.png)



##  07 cmake普通变量和全局CACHE变量作用域测试11:30

##  08 cmake-gui与CACHE缓存变量的各种类型09:45

![image-20230610180052487](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610180052487.png)



##  09 cmake用户修改配置和option05:44         

option的变量是缓存变量



Linux也有ccmake，使用

```sh
cmake -S . -B build
ccmake ./build
```

![image-20230610183618897](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610183618897.png)



##  10 CACHE覆盖策略设置cmake_policy09:17

![image-20230610184042808](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610184042808.png)



##  11 cmake命令 传递缓存变量07:21

![image-20230610223835060](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610223835060.png)



##  12 cmake 属性说明set_property08:44

![image-20230610224334321](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610224334321.png)

![image-20230610224809472](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610224809472.png)

![image-20230610225732038](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610225732038.png)

![image-20230610225841076](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610225841076.png)

![image-20230610230340681](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610230340681.png)

![image-20230610231229032](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610231229032.png)

![image-20230610231311588](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230610231311588.png)



##  13 cmake全局属性和APPEND_STRING get_property11:08

##  14 cmake define_property属性说明设置和获取10:49

##  15 cmake文件属性和给c++传递预处理变量示例14:22

![image-20230611122828516](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611122828516.png)



##  16 cmake目标属性设置给c++传递多个宏12:02

##  17 cmake属性调试cmake_print_properties06:31

![image-20230611135800261](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611135800261.png)

![image-20230611135845632](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611135845632.png)



##  18 cmake env环境变量实战14:24

![image-20230611141336808](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611141336808.png)

![image-20230611141959358](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611141959358.png)

![image-20230611141834420](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611141834420.png)



##  19 cmake math数学计算06:02

![image-20230611144728692](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611144728692.png)



##  20 cmake string查找和字串相关处理20:52

![image-20230611150331536](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611150331536.png)

![image-20230611150821686](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611150821686.png)

![image-20230611150901383](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611150901383.png)

![image-20230611150949221](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611150949221.png)

![image-20230611151041621](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611151041621.png)

![image-20230611151119220](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611151119220.png)



##  21 cmake string追加替换和正则匹配06:35

##  22 cmake string json增删改23:00

##  23 cmake list追加、读取和拼接12:56

##  24 cmake list子数组和查找删除插入修改12:36

##  25 cmake list双向队列操作和排序09:28

##  26 cmake foreach遍历RANGE11:34

![image-20230611210558868](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611210558868.png)

![image-20230611210852044](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611210852044.png)



##  27 cmake foreach遍历list和break()16:47

##  28 cmake while循环06:04

##  29 cmake macro宏原理接口分析08:06

![image-20230611220831048](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611220831048.png)

![image-20230611221111669](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611221111669.png)

![image-20230611221402738](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611221402738.png)



##  30 cmake macro参数传递12:01

宏参不是变量，只能取值使用



##  31 cmake_parse_arguments宏传递属性类参数14:30

![image-20230611225147387](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611225147387.png)

![image-20230611225612170](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611225612170.png)



##  32 cmake function函数演示09:53

![image-20230611232537046](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230611232537046.png)





##  33 cmake函数和变量的作用域演示11:05





# 第四章：cmake生成表达式和文件操作

##  第四章介绍 02:23

##  01 cmake 生成表达式讲解和应用场景分析13:00

![image-20230612224808106](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612224808106.png)

![image-20230612224939857](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612224939857.png)

![image-20230612225523041](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612225523041.png)

![image-20230612230229862](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612230229862.png)



![image-20230612230015633](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612230015633.png)





##  02 cmake条件表达式和逻辑表达式示例11:22      

![image-20230612232924520](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612232924520.png)

![image-20230612233807147](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230612233807147.png)





##  03 cmake生成表达式的两种调试方法（重要）11:57

##  04 cmake字符串比较表达式和条件表达式10:10    

![image-20230613070220765](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613070220765.png)

![image-20230613072416844](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613072416844.png)

##  05 cmakes生成表达式目标相关查询09:22    

![image-20230613074402463](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613074402463.png)





# 第五章：CMake跨平台c++编译特性设置

##  01 第五章介绍 03:21

##  02 target_include_directories包含目录详解09:25      

![image-20230613081246963](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613081246963.png)

![image-20230613081544372](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613081544372.png)

![image-20230613082409463](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613082409463.png)

![image-20230613082730441](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613082730441.png)



##  03 PUBLIC_INTERFACE依赖传递头文件引用路径17:15      

![image-20230613224456947](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613224456947.png)

![image-20230613224529294](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613224529294.png)

![image-20230613224627935](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613224627935.png)

![image-20230613232425329](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613232425329.png)

![image-20230613232454000](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230613232454000.png)



##  04 target_link_libraries和属性的原生调试方法14:14   

##  05 target_compile_definitions演示静态库宏的传递09:10

![image-20230616210606503](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230616210606503.png)



##  06 target_compile_features16:12                     

![image-20230617210320472](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617210320472.png)

![image-20230617210728838](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617210728838.png)



##  07 cmake编译和链接OBJECT文件17:29                   

![image-20230617221239683](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617221239683.png)

![image-20230617221721892](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617221721892.png)

![image-20230617221746790](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617221746790.png)



##  08 cmake动态库的生成版本号符号链接10:48             

![image-20230617234206578](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230617234206578.png)



##  09 cmake_debug_release配置说明10:56                 

![image-20230618002457254](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618002457254.png)

![image-20230618002524749](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618002524749.png)

![image-20230618002807366](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618002807366.png)

![image-20230618011411719](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618011411719.png)

![image-20230618013219192](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618013219192.png)

![image-20230618003431821](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618003431821.png)



![image-20230618003751492](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618003751492.png)













##  10 cmake linux下配置Debug和Release13:18





##  11 cmake windows下配置Debug和Release08:00

##  12 cmake动态库跨平台Debug和Release不同输出路径23:59

##  13 cmake_vs_pdb文件输出配置07:50

![image-20230618193119835](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618193119835.png)





##  14 vs的debug和release设置不同的调试工作路径07:02





##  15 CMake VS设置运行时库MD_MTD16:49

![image-20230618230540484](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618230540484.png)

![image-20230618233124390](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230618233124390.png)



##  16 vs的souce_group代码分组显示10:35

![image-20230619002851021](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230619002851021.png)



# 第六章：CMake install部署项目

##  01 第六章介绍 02:52  

![image-20230619074832651](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230619074832651.png)                                                       

##  02 cmake install功能说明和测试项目代码准备16:51                             

![image-20230619075010485](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230619075010485.png)

![image-20230619075214338](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230619075214338.png)



##  03 cmake 第一个install示例多平台演示部署10:40                               

##  04 cmake install动态静态库和头文件安装路径设置12:37                         

![image-20230622184812842](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230622184812842.png)

![image-20230622203930296](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230622203930296.png)

![image-20230622204059745](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230622204059745.png)

![image-20230622204216849](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230622204216849.png)



##  05 cmake install Debug和Release版本不同安装路径13:52                        

![image-20230622225633071](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230622225633071.png)





##  06 cmake install 文件按类型发布和权限设置18:21                              

![image-20230623000411061](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623000411061.png)

![image-20230623000919817](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623000919817.png)

![image-20230623002513366](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623002513366.png)

![image-20230623003615756](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623003615756.png)



##  07 cmake install目录过滤git和指定后缀文件14:06

![image-20230623005650399](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623005650399.png)



##  08 cmake install code安装期间执行代码06:22

![image-20230623180119568](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623180119568.png)



##  09 cmake install分组安装06:01

![image-20230623183010225](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623183010225.png)



##  10 cmake find_package 分析10:28

![image-20230623184625518](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623184625518.png)

![image-20230623185139812](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623185139812.png)

![image-20230623185332315](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623185332315.png)

![image-20230623185403728](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623185403728.png)

![image-20230623185606130](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623185606130.png)

![image-20230623190031547](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230623190031547.png)



##  11 cmake install export自定义package16:55

##  12 find_package自定义package07:36

##  13 多版本自定义package共存25:29





# 第七章：CMake 交叉编译

##  01 第七章介绍 04:08                           

![image-20230624215210716](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624215210716.png)



##  02 cmake 交叉编译分析和测试代码准备16:11      

![image-20230624215632442](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624215632442.png)



##  03 cmake交叉编译linux arm开发板程序09:37      



##  04 cmake交叉使用NDK交叉编译安卓静态库19:33    



##  05 导入cmake编译的库到安卓项目并支持多ABI11:53



##  06 创建并分析鸿蒙ets的c++native项目10:56      



##  07 cmake编译鸿蒙Hap应用的c++库16:27   



# 第八章：cmake单元测试

##  01 第八章介绍 03:48

![image-20230624220107191](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624220107191.png)

![image-20230624220400664](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624220400664.png)



##  02 cmake_ctest单元测试分析和测试示例18:16     

![image-20230624220814874](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624220814874.png)

![image-20230624221745095](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230624221745095.png)



##  03 使用CMake的Fetch自动下载编译googletest09:59

##  04 建立第一个cmake调用googletest的示例09:36   

##  05 cmake解压编译安装gtest并测试22:20

![image-20230625010329428](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230625010329428.png)

![image-20230625010856196](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230625010856196.png)



##  06 googletest完整单元测试TEST_F08:37



##  07 解决googletest在vs上运行时库不一致问题07:12



# 第九章：CMake实战开源项目xcpp

##  01 第九章介绍 02:18

![image-20230625082816591](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230625082816591.png)



##  02 CMake实战开源项目cmake配置需求分析17:10

![image-20230701191232194](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701191232194.png)

![image-20230701194126401](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194126401.png)

![image-20230701194204334](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194204334.png)

![image-20230701194326113](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194326113.png)

![image-20230701194343513](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194343513.png)

![image-20230701194422948](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194422948.png)

![image-20230701194503234](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194503234.png)

![image-20230701194710330](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194710330.png)

![image-20230701194852408](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701194852408.png)

![image-20230701211614828](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701211614828.png)

![image-20230701211640478](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701211640478.png)

![image-20230701212342631](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701212342631.png)

![image-20230701212412715](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701212412715.png)

![image-20230701212445330](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701212445330.png)





##  03 xlog库项目配置项目源码头文件和静态库宏传递23:08   



##  04 配置xlog输出路径设置Debug Release输出路径一致16:44



##  05 xlog的install配置并支持find_package19:26



##  06 xlog生成c++代码并支持用户配置动态库16:37                                 

##  07 重构xlog的cmake完成cpp_libaray函数并导入线程池库30:52                    

##  08 配置test_xlog项目完成linux上测试24:42                                    

##  09 配置test_xlog可配置在vs上读取xlog静态库22:40                             

##  10 xthread_pool库和样例加入项目配置04:30

##  11 cmake同时编译四个项目并添加依赖关系13:32

##  12 完成xlog和xthread_pool单元测试30:52



# 第十章：cmake补充章节

##  01 cmake构建vs_qt项目示例程序完成 08:40

![image-20230701225204836](ImagesMarkDown/CMake构建大型c++项目讲义/image-20230701225204836.png)



##  02 cmake设置QT的SDK路径加载qt库和头文件 12:34

##  03 qt程序执行的依赖库自动复制 02:48

##  04 cmake导入qt库完成qt界面示例代码-有资源找不到错误 12:09

##  05 生成qt资源、界面和信号槽c++代码 14:24                 

##  06 cmake编译QT项目输出x86和x64程序 12:29                 

##  07 cmake_qt项目install07:07                              

##  08 cmake自动复制qt依赖库并完成install22:35    