#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
using std::string;
using std::random_device;
using std::default_random_engine;

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
int main() {
	ios::sync_with_stdio(false);
	string fn = strRand(10), sys = "mkdir " + fn;
	system(sys.c_str());
	ofstream fout("log.log");
	fout << "dir " << fn << " maked"; 
	sys = "cd " + fn;
//	system(sys.c_str());
//	sys = "zip -m " + fn + ".zip log.log";
//	system(sys.c_str());
	for (int i = 1; i <= 20; i ++) {
		string s = fn + "\\" + "in" + to_string(i) + ".in", s2 = fn + "\\" + "out" + to_string(i) + ".out";
		freopen(s.c_str(), "w", stdout);
//		cout << s.c_str() << "\n";
		system("makedata.exe"); 
		freopen(s.c_str(), "r", stdin);
		freopen(s2.c_str(), "w", stdout);
		system("std.exe");
		sys = "zip -u " + fn + "\\" + fn + ".zip " + "in" + to_string(i) + ".in";
//		system(sys.c_str());
		sys = "zip -u " + fn + "\\" + fn + ".zip " + "out" + to_string(i) + ".out";
//		system(sys.c_str());
//		cout << s2.c_str() << "\n";
	}
	sys = "zip -r -q -j " + fn + ".zip " + fn;
	system(sys.c_str()); 
	return 0;
}
