
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
#define randint(a, b)  (long long)(a) + (long long)b * rand() / (RAND_MAX + 1)
void pre() {
	srand(GetTickCount());
}
char randch_up() {// upper case
	return randint('A', 'Z');
}
char randch_lo() {//lower case
	return randint('a', 'z');
}
string randstr_h(int length) {			// length: ??????????????
    char tmp;							// tmp: ???????????
    string buffer;						// buffer: ???�Y???
    
    // ?????????��?????:
    random_device rd;					// ??????? std::random_device ???? rd
    default_random_engine random(rd());	// ?? rd ??????????????????? random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 62;	// ??????��?? 36 ????????0-9??A-Z ?? 36 ?????
        if (tmp < 10) {			// ????????��?? 10???��???????????????? ASCII
            tmp += '0';
        } else if (tmp < 36) {				// ?????��???????��????? ASCII
            tmp -= 10;
            tmp += 'A';
        } else {
        	tmp -= 36;
        	tmp += 'a';
		}
        buffer += tmp;
    }
    return buffer;
}
string randstr_up(int length) {
	    char tmp;							// tmp: ???????????
    string buffer;						// buffer: ???�Y???
    
    // ?????????��?????:
    random_device rd;					// ??????? std::random_device ???? rd
    default_random_engine random(rd());	// ?? rd ??????????????????? random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 52;	// ??????��?? 36 ????????0-9??A-Z ?? 36 ?????				// ?????��???????��????? ASCII
        tmp += 'A';
        buffer += tmp;
    }
    return buffer;
}
string randstr_lo(int length) {
	    char tmp;							// tmp: ???????????
    string buffer;						// buffer: ???�Y???
    
    // ?????????��?????:
    random_device rd;					// ??????? std::random_device ???? rd
    default_random_engine random(rd());	// ?? rd ??????????????????? random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// ??????��?? 36 ????????0-9??A-Z ?? 36 ?????
        tmp += 'a';
        buffer += tmp;
    }
    return buffer;
}
string randstr_num(int length) {
	    char tmp;							// tmp: ???????????
    string buffer;						// buffer: ???�Y???
    
    // ?????????��?????:
    random_device rd;					// ??????? std::random_device ???? rd
    default_random_engine random(rd());	// ?? rd ??????????????????? random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// ??????��?? 36 ????????0-9??A-Z ?? 36 ?????
        tmp += '0';
        buffer += tmp;
    }
    return buffer;
}


