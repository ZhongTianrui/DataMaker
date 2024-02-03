#include <bits/stdc++.h>
#include "includes/make.hpp"
using namespace std;
int main() {
	// ios::sync_with_stdio(false);
	pre();
	/*make your data here
	use cout in output
	*/
	int n = randint(1e2, 1e3), m = randint(n, 1e4), s = randint(1, n);
	// int n = 10, m = 10, s = 1;
	cout << n << " " << m << " " << s << "\n";
	randgra(n, m, 1);
	return 0;
}
