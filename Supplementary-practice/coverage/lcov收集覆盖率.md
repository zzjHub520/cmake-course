## 1、gcov

### 1.1 什么是gcov

   首先我们要了解什么是gcov，gcov伴随gcc 发布。gcc编译加入-fprofile-arcs -ftest-coverage 参数生成二进制程序，执行测试用例生成代码覆盖率信息。

### 1.2 如何使用gcov

   用GCC编译的时候加上-fprofile-arcs -ftest-coverage选项，链接的时候也加上。
   fprofile-arcs参数使gcc创建一个程序的流图，之后找到适合图的生成树。只有不在生成树中的弧被操纵（instrumented）：gcc添加了代码来清点这些弧执行的次数。当这段弧是一个块的唯一出口或入口时，操纵工具代码（instrumentation code)将会添加到块中，否则创建一个基础块来包含操纵工具代码。

   gcov主要使用.gcno和.gcda两个文件。

> .gcno是由-ftest-coverage产生的，它包含了重建基本块图和相应的块的源码的行号的信息。
>
> .gcda是由加了-fprofile-arcs编译参数的编译后的文件运行所产生的，它包含了弧跳变的次数和其他的概要信息（而gcda只能在程序运行完毕后才能产生的）。

### 1.3 gcov 覆盖分类

　　Gcov执行函数覆盖、语句覆盖和分支覆盖。

　　举个例子,程序代码由main.c和test.c两个文件组成，编译、链接、运行程序
　　编译：gcc -fprofile-arcs -ftest-coverage -o myapp main.c test.c
　　运行：./myapp
　　然后 输入

```
gcov main.c,gcov tmp.c
```

　　这个时候当前目录下有了新的文档main.c.gcov,和tmp.c.gcov
　　若想保存覆盖率文件，上述命令修改为：
　　命令：gcov main.c >>yourfilename,gcov tmp.c >>yourfilename

　　而这时候的main.c.gcov,和tmp.c.gcov就包含了函数和代码执行次数的信息，我们可以查看结果：

```
-:    0:Source:main.cpp
        -:    0:Graph:main.gcno
        -:    0:Data:main.gcda
        -:    0:Runs:1
        -:    0:Programs:1
        -:    1:#include <iostream>
        -:    2:using namespace std;
        1:    3:int main()
        -:    4:{
        -:    5:    int i,total;
        1:    6:    total = 0;
        -:    7:
       11:    8:    for (i=0; i<10; i++)
       10:    9:        total += i;
        -:   10:
        1:   11:    if (total != 45)
    #####:   12:        cout << "Failure!" << endl;
        -:   13:    else
        1:   14:        cout << "Success!" << endl;
        1:   15:    return 0;
        3:   16:}
```

　　##### 这就是表示没跑到的

### 1.4 gcov参数

　　关于gcov的参数，可以在linux环境下使用gcov查阅

# 2、关于lcov

### 2.1 什么是lcov

　　Lcov则是上的gcov 结果展现的一个前端，可以将覆盖率信息转换成html展现。

### 2.2 生成覆盖率

　　前提条件：使用 GCC 以 -fprofile-arcs 和-ftest-coverage 选项编译程序。

　　a)假设编译目录名称为 "/root/test/code_cover/"，下面有个test.c，然后执行：

```
gcc -fprofile-arcs -ftest-coverage -o test test.c
./test
```

　　则会在/root/test/code_cover/目录下生成test.gcno和test.gcda文件

> 注：一般情况，gcda和gcno会在同一个目录，假如在编译机器上面是test/path，编译的时候会在这个目录下生成*.gcno文件,那么在执行机器上也会生成*.gcda文件在test/path目录下，
>
> 如果要使用lcov统计覆盖率，必须将gcno和gcda放在同一个目录，并且有源代码，且源代码的目录和编译时的目录一样，否则不能生成。

　　然后cd该目录下执行

```
lcov --directory . --capture --output-file app.info
```

其中：

　　--directory 或者-d 表示的是目录，也就是gcno和gcda目录

　　--capture 或者 -c 表示获取覆盖率信息

　　--output-file 或者 -o 表示输出文件

　　b) 获取 HTML 输出

```
genhtml -o results app.info
```

　　results是一个目录，index.html为导航文件，使用 web 浏览器打开 index.html 文件查看代码覆盖结果。

### 2.3 lcov文件过滤

　　在某些情况下，比如三方库不需要统计覆盖率信息，则需要屏蔽，或者只需要某些文件的覆盖率，就需要对文件进行筛选

　　a)移除指定目录

```
lcov --remove all.info '/src/include/*' '/user/bin/*' -o result.info
```

　　此命令表示生成的覆盖率信息，屏蔽 '/src/include/*' '/user/bin/*' 两个目录的覆盖率信息

　　all.info  总的覆盖率信息

　　result.info 筛选后的覆盖率信息

　　b)只要固定目录

```
lcov  --extract all.info '*/src/*' '*/lib/*' -o result.info
```

　　此命令表示生成的覆盖率信息只要src和lib目录下文件的覆盖率信息

　　all.info  总的覆盖率信息

　　result.info 筛选后的覆盖率信息