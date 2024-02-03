
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
#define randint(a, b)  (long long)(a) + (long long)b * rand() / (RAND_MAX + 1)
typedef long long ll;
 
int random(int n)
{
    return (ll)rand() * rand() % n;
}

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
int* randarr(int n) {
//随机生成任意个绝对值小于1e9的整数
int m = 1e9;
int* a = new int[n+1];
for(int i = 1; i <= n; ++i)
{
    a[i] = random(2 * m + 1) - m;
}
return a;
}
void randqujian(int n, int m) {
//生成m个[1,n] 的子区间
for(int i = 1; i <= m; ++i)
{
    int l = random(n) + 1;
    int r = random(n) + 1;
    if(l > r) swap(l, r);
    printf("%d %d\n", l, r);
}
}
void randtree(int n) {
    //生成n个点，n-1条边，附带1e9的权值的树
for(int i = 2; i <= n; ++i)
{   //从点i向1~i-1 之间的点随机连一条边
    int fa = random(i - 1) + 1;
    int val = random(1000000000) + 1;
    printf("%d %d %d\n", fa, i, val);
}
}
void randgra(int n, int m, bool with_num) {
    pair<int, int> e[100005];
map<pair<int, int>, bool> h;
//先生成一棵树，保证连通
for(int i = 1; i < n; ++i)
{
    int fa = random(i) + 1;
    e[i] = make_pair(fa, i + 1);
    h[e[i]] = h[make_pair(i + 1, fa)] = 1;
}
//再生成剩余的m-n+1条边
for(int i = n; i <= m; ++i)
{
    int x, y;
    do
    {
        x = random(n) + 1, y = random(n) + 1;
    }
    while(x == y || h[make_pair(x, y)]);
    e[i] = make_pair(x, y);
    h[e[i]] = h[make_pair(y, x)] = 1;
}
//随机打乱输出
random_shuffle(e + 1, e + m + 1);
// cout << n << " " << m << " ";
// if (ss != -1) cout << ss << " ";
// if (tt != -1) cout << tt << " ";
// cout << "\n";
for(int i = 1; i <= m; ++i) {
    printf("%d %d ", e[i].first, e[i].second);
    if (with_num) printf("%d\n", randint(1, 1e3));
    else printf("\n");
}
}