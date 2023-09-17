# RPATH是什么



### 目录

- [RPATH是什么](https://blog.csdn.net/qq_43561784/article/details/130217106#RPATH_0)
- [简介](https://blog.csdn.net/qq_43561784/article/details/130217106#_6)
- [一、rpath是什么](https://blog.csdn.net/qq_43561784/article/details/130217106#rpath_9)
- [二、搜索.so的优先级顺序](https://blog.csdn.net/qq_43561784/article/details/130217106#so_13)
- [三、查看RPATH](https://blog.csdn.net/qq_43561784/article/details/130217106#RPATH_21)
- [四、设置RPATH](https://blog.csdn.net/qq_43561784/article/details/130217106#RPATH_27)



------

# 简介

rpath 在linux中的作用等

# 一、rpath是什么

rpath全称是`run-time search path`。Linux下所有[elf](https://so.csdn.net/so/search?q=elf&spm=1001.2101.3001.7020)格式的文件都包含它，特别是可执行文件。它规定了可执行文件在寻找.so文件时的第一优先位置。
另外，[elf文件](https://so.csdn.net/so/search?q=elf文件&spm=1001.2101.3001.7020)中还规定了`runpath`。它与`rpath`相同，只是优先级低一些。

# 二、搜索.so的优先级顺序

- ```
   RPATH： 写在elf文件中
  ```

- ```
   LD_LIBRARY_PATH： 环境变量
  ```

- ```
    RUNPATH： 写在elf文件中
  ```

- ```
   ldconfig的缓存： 配置/etc/ld.conf*可改变
  ```

- ```
   默认的/lib, /usr/lib
  ```

  RPATH与RUNPATH中间隔着LD_LIBRARY_PATH。为了让用户可以通过修改LD_LIBRARY_PATH来指定.so文件，大多数编译器都将输出的RPATH留空，并用RUNPATH代替RPATH。

# 三、查看RPATH

对于任意的elf文件，可以使用`$ readelf -d xxx | grep 'R*PATH'`来查看。
结果有两类，一个是`RPATH`，另一个是`RUNPATH`。前文也说了，一般情况下，`RPATH`为空，而`RUNPATH`不为空。

`RPATH`中有个特殊的标识符`$ORIGIN`。这个标识符代表elf文件自身所在的目录。当希望使用相对位置寻找`.so`文件，就需要利用`$ORIGIN`设置`RPATH`。多个路径之间使用冒号`:`隔开。

# 四、设置RPATH

在gcc中，设置RPATH的办法很简单，就是设置linker的rpath选项：`$ gcc -Wl,-rpath,/your/rpath/ test.cpp`
如果需要设置O R I G I N ： ‘ ORIGIN：`ORIGIN：‘ gcc -Wl,-rpath,’$ORIGIN/lib’ test.cpp`。
注意，虽然选项里写着RPATH，但它设置的还是RUNPATH。原因在前文有交代。

在CMake中，事情则有些不同。由于CMake需要包揽软件安装的事宜，因此CMake使用两个变量来控制RPATH：`INSTALL_RPATH`和`BUILD_RPATH`。
设置的办法是：

```bash
SET_TARGET_PROPERTIES(target
    PROPERTIES INSTALL_RPATH "$ORIGIN;/another/run/path")
```

注意，在CMake中，多个RPATH使用分号隔开，而不是冒号。这是估计是因为冒号在CMake语法中有其他用途