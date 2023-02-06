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

   在 bind.txt 输入 `0` 或 `1`，表示是否开启 subtask

   在 Number.txt 中输入多行或者一行

   - 如果开启 subtask ：每行有 2 个整数，分别表示这个 subtask 的起点数据下标和终点下表
   - 如果不开启，输入一个数表示数据组数。

   在 Name.txt 中输入一个全字母的字符串，表示文件名，如果为了避免重复，输入 random，程序会自动生成一个 10 位字符串

   在 exe.txt 中输入多行，每一行一个字符串表示每一个 subtask 对应的数据生成源文件，如：

   ```cpp
   makefile.exe
   makefile2.exe
   ```

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

randarr(int n) ：随机数组，返回 int*

randqujian(int n, int m) ：随机区间，生成 m 个 [1,n] 的区间，自动打印

randtree(int n) ：随机树，生成n个点，n-1条边，附带1e9的权值的树，自动打印

randgra(int n, int m, bool with_num) ：随机无向联通图，需自行打印 n 和 m，自动打印建边的输入，如果想有权值，with_num = 1，否则 with_num = 0

Linux 端：

把 make.exe 替换成 linux_make.exe



update:

| date |   summary   |   version   |
| :--------------: | :---: | :---: |
| 2023/2/6 | 更新 make.hpp，添加随机数组，随机区间，随机树，随机图 | [3.1](https://github.com/ZhongTianrui/DataMaker/releases/tag/v3.2) |
| 2023/2/6 | 添加对于 Linux 的支持 | 3.1 |
| 2023/2/5 21:03 | 添加捆绑测试点的支持，整个框架都会更改， ~~自动配置 config.yml~~ （由于你谷的 Bug，这个功能暂时无法实现） | [3.0](https://github.com/ZhongTianrui/DataMaker/releases/tag/v3.0) |
|      2023/2/5 15:08          | 更新 make.hpp | [2.1](https://github.com/ZhongTianrui/DataMaker/releases/tag/v2.1) |
|        2023/2/5 14:43        | 添加 config | 2.0 |
|2023/2/4 21:00 |完成 1.0 版本|1.0|

