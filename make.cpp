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
vector <int> begin, end;
vector <string> exe;
int main() {
	ios::sync_with_stdio(false);
	ofstream fout("log.log");
	ifstream finname("config\\Name.txt"), finnum("config\\Number.txt"), finbind("config\\bind.txt"), finexe("config\\exe.txt");
	string fn = strRand(10), sys = "mkdir " + fn;
	string fnn;
	finname >> fnn;
	if (fnn != "random") {
		fn = fnn;
	}
	sys = "mkdir " + fn;
	system(sys.c_str());
	fout << "dir " << fn << " maked"; 
	sys = "cd " + fn;
//	system(sys.c_str());
	bool b;
	finbind >> b;
	if (!b) {
		int Num;
		finnum >> Num;
		for (int i = 1; i <= Num; i ++) {
			string s = fn + "\\" + "in" + to_string(i) + ".in", s2 = fn + "\\" + "out" + to_string(i) + ".out";
			freopen(s.c_str(), "w", stdout);
			system("makedata.exe"); 
			freopen(s.c_str(), "r", stdin);
			freopen(s2.c_str(), "w", stdout);
			system("std.exe");
		}
		sys = "zip -r -q -j " + fn + ".zip " + fn;
		system(sys.c_str()); 
	} else {
		int numa, numb, cnt = 0;
		string fname, exename;
		finname >> fname;
		string fnnn = fn + "\\config.yml";
		ofstream off;
		off.open(fn + "\\config.yml");
		while (finnum >> numa) {
			finnum >> numb;
			finexe >> exename;
//			cout << numb << " " << exename;
			for (int i = numa; i <= numb; i ++) {
				string s = fn + "\\" + "in" + to_string(i) + ".in", s2 = fn + "\\" + "out" + to_string(i) + ".out";
				freopen(s.c_str(), "w", stdout);
				system(exename.c_str()); 
				freopen(s.c_str(), "r", stdin);
				freopen(s2.c_str(), "w", stdout);
				system("std.exe");
//				freopen(fnnn.c_str(), "w", stdout);
				off << "in"<< i << ".in:\n";
				off << "  subtaskId: " << cnt << "\n";
				off << "\n";
			}
			cnt ++;
		}
		sys = "zip -r -q -j " + fn + ".zip " + fn;
		system(sys.c_str()); 
	}
	return 0;
}
