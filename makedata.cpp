#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define randd(a, b)  int(a) + (int)b * rand() / (RAND_MAX + 1)
int main() {
	ios::sync_with_stdio(false);
	srand(GetTickCount());
	/*make your data here
	use cout in output
	*/
	cout << randd(1, 1e9) << " " << randd(1, 1e9);
	return 0;
}
