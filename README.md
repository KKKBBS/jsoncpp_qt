# jsoncpp_qt

jsoncpp在QtCreater中的配置和使用。在自己的项目中包括源码，方便不同平台编译器交叉编译。

## jsoncpp外部库
源码: https://github.com/open-source-parsers/jsoncpp

版本说明：
  - 1.y.z is built with C++11.
  - 0.y.z can be used with older compilers.

这里有两个源码压缩包
- jsoncpp-0.y.z.zip   (jsoncpp 0.10.7)
- jsoncpp-master.zip  (jsoncpp 1.9.5)

## 运行环境
- QtCreater: QtCreater 4.0.3 
- Linux: Ubuntu 14.04.3 LTS

## 源码准备
1. 在新建项目中创建json文件夹
2. 解压源码压缩包
3. 解压后路径include/json和路径src/lib_json下的文件都复制到第一步的json文件夹中(除了CMakeLists.txt)

## 在QtCreater中使用
1. 添加xxxx.pro文件设置。

`lessThan(QT_MAJOR_VERSION, 5): QMAKE_CXXFLAGS += -std=c++11`

`greaterThan(QT_MAJOR_VERSION, 5): CONFIG += c++11`

  1.y.z和0.y.z区别在于代码使用的c++规范不同。前者使用了c++17规范的代码，在仅支持c++11的板子上会出现无法编译的情况。

2. 从外部读取json文件

此时json文件放在编译后的build-json_test-xxxxx文件夹

4. 从项目内部资源库读取json文件

项目中添加Resources，并在代码中修改json文件路径为QT Resources的虚拟路径。
与此同时，在Resources中的json文件是虚拟文件，不能通过标准库std::ifstream文件流打开。
需要包括头文件QFile后，使用QFile打开

