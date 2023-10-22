在CMake中，export指令用于导出CMake项目的构建规则以供其他项目使用。它可以生成一个供外部项目引用的CMake配置文件，其中包含了当前项目的编译选项、依赖库等信息。通过使用export指令，您可以轻松地共享代码库或构建规则。

使用export指令的基本语法如下：

```cmake
export(TARGETS <target>... [NAMESPACE <namespace>]
       [APPEND] FILE <filename> [EXPORT_LINK_INTERFACE_LIBRARIES]
       [CXX_MODULES_DIRECTORY <directory>])
```



其中，TARGETS参数用于指定要导出的目标，可以是一个或多个目标名称。NAMESPACE参数用于指定命名空间（可选），它可以帮助组织导出的配置文件中的变量和函数名称，使其与其他项目中的名称冲突的可能性降到最低。APPEND参数用于在已有的导出配置文件中追加新的导出内容（可选）。FILE参数用于指定导出配置文件的名称。

下面是一个使用export指令的例子：

```cmake
add_library(mylib foo.cpp bar.cpp)

# 导出mylib目标以供其他项目使用
export(TARGETS mylib
       FILE MyLibConfig.cmake)
```



上述示例中，`mylib` 是要导出的目标名称，`MyLibConfig.cmake` 是生成的导出配置文件的名称。导出配置文件通常存储在项目的构建目录中，在其他项目中使用`find_package()`命令来引用该配置文件。

要在其他项目中使用导出的配置文件，可以使用`find_package()`命令。例如：

```cmake
find_package(MyLib REQUIRED)
```



这将会在搜索路径中查找名为`MyLibConfig.cmake`的配置文件，并将它加载到当前项目中。加载后，您就可以使用`${MyLib_INCLUDE_DIRS}`和`${MyLib_LIBRARIES}`等变量来引用导出的内容。

请注意，export指令和find_package()命令一起使用时，需要遵循一定的命名规范和约定，以确保正确地导入和使用其他项目的构建规则。这些规范可以在CMake的官方文档中找到，并且可以根据实际情况进行自定义调整。