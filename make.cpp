#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
using std::string;
using std::random_device;
using std::default_random_engine;
struct js{
	string Name;
	int Num;
};
string strRand(int length) {			// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值
    
    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}
//int ReadJsonNum() {
//	Json::Reader reader;
//	Json::Value root;
//	ifstream fin("config.json", ios::binary);
//	if (reader.parse(fin, root)) {
////		J.Name = root["Name"].asString();
//		return root["Number"].asInt();
//	} else {
//		return -1;
//	}
//	
//}
//string ReadJsonName() {
//	Json::Reader reader;
//	Json::Value root;
//	ifstream fin("config.json", ios::binary);
//	if (reader.parse(fin, root)) {
//		return root["Name"].asString();
//	} else {
//		return "err";
//	}
//}
/*
This code have a problem,so we will not use it 
*/
vector <int> begin, end;
vector <string> exe;
int main() {
	ios::sync_with_stdio(false);
	ofstream fout("log.log");
	ifstream ic("config\\Name.txt"), ici("config\\Number.txt");
	string fn = strRand(10), sys = "mkdir " + fn;
	string fnn;
	ic >> fnn;
	if (fnn != "random") {
		fn = fnn;
	}
//	system("cd output");
	sys = "mkdir " + fn;
	system(sys.c_str());
	fout << "dir " << fn << " maked"; 
	sys = "cd " + fn;
	system(sys.c_str());
//	sys = "zip -m " + fn + ".zip log.log";
//	system(sys.c_str());
	int Num;
	ici >> Num;
	for (int i = 1; i <= Num; i ++) {
		string s = fn + "\\" + "in" + to_string(i) + ".in", s2 = fn + "\\" + "out" + to_string(i) + ".out";
		freopen(s.c_str(), "w", stdout);
//		cout << s.c_str() << "\n";
		system("makedata.exe"); 
		freopen(s.c_str(), "r", stdin);
		freopen(s2.c_str(), "w", stdout);
		system("std.exe");
//		sys = "zip -u " + "output\\" + fn + "\\" + fn + ".zip " + "in" + to_string(i) + ".in";
//		system(sys.c_str());
//		sys = "zip -u " + "output\\" + fn + "\\" + fn + ".zip " + "out" + to_string(i) + ".out";
//		system(sys.c_str());
//		cout << s2.c_str() << "\n";
	}
	sys = "zip -r -q -j " + fn + ".zip " + fn;
	system(sys.c_str()); 
	return 0;
}
