#include <bits/stdc++.h>
// #include <windows.h>
using namespace std;
using std::string;
using std::random_device;
using std::default_random_engine;
struct js{
	string Name;
	int Num;
};
string strRand(int length) {			// length: �����ַ����ĳ���
    char tmp;							// tmp: �ݴ�һ�������
    string buffer;						// buffer: ���淵��ֵ
    
    // ���������бȽ���Ҫ:
    random_device rd;					// ����һ�� std::random_device ���� rd
    default_random_engine random(rd());	// �� rd ��ʼ��һ������������� random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// ���һ��С�� 36 ��������0-9��A-Z �� 36 ���ַ�
        if (tmp < 10) {			// ��������С�� 10���任��һ�����������ֵ� ASCII
            tmp += '0';
        } else {				// ���򣬱任��һ����д��ĸ�� ASCII
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
	ifstream finname("config\\Name.txt"), finnum("config\\Number.txt"), finbind("config\\bind.txt"), finexe("config\\exe.txt"), findata("config\\data.txt");
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
	bool bb;
	// findata >> bb;
	// if (bb) {
	// 	int Num; finnum >> Num;
	// 	for (int i = 1; i <= Num; i ++) {
	// 		string str = "data\\in" + to_string(i) + ".txt";
	// 		freopen(str.c_str(), "r", stdin);
	// 		str = fn + "\\in" + to_string(i) + ".in";
	// 		freopen(str.c_str(), "w", stdout);
	// 		string ch;
	// 		while (getline(cin, ch)) {
	// 			cout << ch << "\n";
	// 		}
	// 		str = "data\\out" + to_string(i) + ".txt";
	// 		freopen(str.c_str(), "r", stdin);
	// 		str = fn + "\\out" + to_string(i) + ".out";
	// 		freopen(str.c_str(), "w", stdout);
	// 		while (getline(cin, ch)) {
	// 			cout << ch << "\n";
	// 		}
	// 	}
	// }
	bool b;
	finbind >> b;
	if (!b) {
		int Num;
		finnum >> Num;
		for (int i = 1; i <= Num; i ++) {
			string s = fn + "\\" + "in" + to_string(i) + ".in", s2 = fn + "\\" + "out" + to_string(i) + ".out";
			freopen(s.c_str(), "w", stdout);
			system("./makedata.exe"); 
			freopen(s.c_str(), "r", stdin);
			freopen(s2.c_str(), "w", stdout);
			system("./std.exe");
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
				exename = "./" + exename;
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
