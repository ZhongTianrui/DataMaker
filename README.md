# DataMaker
一个为OIer准备的数据制造系统，想要造出数据？只需要打开makedata.cpp，用cout和我们提供的randd函数，即可造出多组强大的数据

优点：

1. 依赖于 c++，OIer 的福利
2. 自动生成 zip 文件，不用手动生成
3. 速度快

用法：
1. 打开 makedata.cpp，使用函数库自定义随机数，用cout进行输出。主程序的第一行必须是 `pre();`

2. 打开 std.cpp，放上标程

3. 确保前面的 2 个文件编辑后又编译了一遍

4. 打开 config 文件夹

   在 Number.txt 中输入一个 1~40 的整数，表示测试数据的组数

   在 Name.txt 中输入一个全字母的字符串，表示文件名，如果为了避免重复，输入 random，程序会自动生成一个 10 位字符串

5. 运行 make.exe，程序如果运行了一会后自动结束了，那么说明你成功了！

6. 直接把 “文件夹名.zip”上传到洛谷上就行了

储存库中的文件是一个 A+B Problem 的示例

程序库：

randint() ：随机整型，支持 `long long`

randch_up() ：随机大写字母

randch_lo() ：随机小写字母

randstr_h(int length) ：随机大小写字母和数字综合的字符串

randstr_up(int length) ：随机大写字符串

randstr_lo(int length) ：随机小写字符串

randstr_num(int length) ：随机数字串



update:

| date |   summary   |   version   |
| -------------- | ---- | ---- |
|      2023/2/5 15:08          | 更新 make.hpp | 2.1 |
|        2023/2/5 14:43        | 添加 config | 2.0 |
|2023/2/4 21:00 |完成 1.0 版本|1.0|

