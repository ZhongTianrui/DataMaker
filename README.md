# DataMaker
一个为OIer准备的数据制造系统，想要造出数据？只需要打开makedata.cpp，用cout和我们提供的randd函数，即可造出20组强大的数据

用法：
1. 打开 makedata.cpp，使用randd函数自定义随机数的范围，用cout进行输出。
2. 打开 std.cpp，放上标程
3. 确保前面的 2 个编辑后又编译了一遍
4. 运行 make.exe，程序如果运行了一会后自动结束了，那么说明你成功了！
5. 打开log.log，把文件夹名字记下来，文件夹名应当是一个10位随机字符串
6. 直接把 “文件夹名.zip”上传到洛谷上就行了

储存库中的文件是一个 A+B Problem 的示例

如果你想把数据组数调整，改动一下主程序中的 for 循环的次数就行：
![image](https://user-images.githubusercontent.com/106294609/216769226-0abcb7c6-b433-41c4-9614-74c2d5b7a602.png)
