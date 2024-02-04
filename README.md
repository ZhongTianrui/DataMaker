# DataMaker

一个为OIer准备的数据制造系统，想要造出数据？只需要打开makedata.cpp，用cout和我们提供的随机函数，即可造出多组强大的数据

## 优点：

1. 依赖于 c++，OIer 的福利
2. 自动生成 zip 文件，不用手动生成
3. 自动配置捆绑
4. 速度快

## 用法：

1. 打开 makedata.cpp，使用函数库自定义随机数，用cout进行输出。主程序的第一行必须是 `pre();`

2. 打开 std.cpp，放上标程

3. 记得保存。

4. 打开 config.json

   在 mode 中选择模式：模式 0：no subtask，模式 1：subtask 捆绑，模式 2：subtask 不捆绑

   在 name 中写入测试组的名称
   在 std 中写入参考程序的路径

   如果启用 subtask:
       在 subtasks 中写入一个 json 的列表，每一个内容里包含两个个值，begin 代表测试点的开始，end 代表测试点的结束。

   ​	在 exename 中写入输入生成器的路径

   ​	可以在输入生成器中区分不同层次的数据范围，注意写完后调试输入生成器。使用方法如：

   ```cpp
   #include <bits/stdc++.h>
   #include "includes/make.hpp"
   using namespace std;
   int main(int argc, char* argv[]) {
       ios::sync_with_stdio(false);
       pre();
       /*make your data here
       use cout in output
       */
   	   if (argv[1][0] == '0') cout << randint(1, 1e4) << " " << randint(1, 1e4);//第一种情况
   	   else if (argv[1][0] == '1') cout << randint(1, 1e7) << " " << randint(1, 1e7);//第二种
   	   else if (argv[1][0] == '2') cout << randint(1, 1e9) << " " << randint(1, 1e9);//第三种
   	   else cout << "err";//如果 config 写的是对的话，这种情况不会发生
       //每一个 subtask 对应一个
       return 0;
   }
   
   ```

   

   如果不启用 subtask:
       在 exename 中写入输入生成器的路径

   注意上述的所有写入的程序路径均不以 `./` 开头或 `.exe` 结尾，应该用 `/` 作为路径分隔符而不是 `\\`。
   程序会自动获取测试点的数量，只要你的测试点开头和结尾是按规范填的，而且每一个 subtask 的开头等于上一项的结尾的编号 + 1。

5. 运行 run.bat/run.sh，程序如果运行了一会后自动结束了，那么说明你成功了！（注意，如果发现程序卡住了，且电脑风扇转的很快，请关闭程序后重新打开）。

6. 直接把 “data-文件夹名.zip”上传到洛谷上就行了。

储存库中的 sample 文件夹包含一些示例。

## 函数库：

randint() ：随机整型，支持 `long long`

randch_up() ：随机大写字母

randch_lo() ：随机小写字母

randstr_h(int length) ：随机大小写字母和数字综合的字符串

randstr_up(int length) ：随机大写字符串

randstr_lo(int length) ：随机小写字符串

randstr_num(int length) ：随机数字串

randarr(int n, int l, int r) ：随机数组，范围 [l, r]，返回 int*

randqujian(int m, int l, int r) ：随机区间，生成 m 个 [l, r] 的区间，自动打印

randtree(int n, bool with_num, int r = 0) ：随机树，生成n个点，n-1 条边，可以选择是否带权，权值 [1, r]，自动打印。(如果不需要权值，不用传入 r)。

randgra(int n, int m, bool with_num) ：随机无向联通图，需自行打印 n 和 m，自动打印建边的输入，如果想有权值，with_num = 1，否则 with_num = 0

## update:

| date |   summary   |   version   |
| :--------------: | :---: | :---: |
| 2024/2/4 | 移除随机名称功能，部分重构 make.cpp，移除task_amount参数 | 3.1 |
| 2024/2/3 | 原本的捆绑选项变为模式选项，增加数据分层模式，把调用 makedata.cpp 的代码中增加命令行参数传入，更新函数库，重新制作 make.cpp，添加对于 Linux 的支持，支持通过 json 配置。 | 3.0 |
| 2024/2/2 | 修复捆绑，自动配置 config.yml 文件 | 2.3.2 |
| 2023/2/8 | 程序会将输出放在 log.log | 2.3.1 |
| 2023/2/6 | 更新 make.hpp，添加随机数组，随机区间，随机树，随机图 | [2.3](https://github.com/ZhongTianrui/DataMaker/releases/tag/2.3) |
| 2023/2/5 21:03 | 添加捆绑测试点的支持，整个框架都会更改 | [2.2](https://github.com/ZhongTianrui/DataMaker/releases/tag/v2.2) |
|      2023/2/5 15:08          | 更新 make.hpp | [2.1](https://github.com/ZhongTianrui/DataMaker/releases/tag/v2.1) |
|        2023/2/5 14:43        | 添加 config | 2.0 |
|2023/2/4 21:00 |完成 1.0 版本|1.0|

