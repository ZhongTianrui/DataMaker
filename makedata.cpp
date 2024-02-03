#include <bits/stdc++.h>
#include "includes/make.hpp"
using namespace std;
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	pre();
	/*make your data here
	use cout in output
	*/
	if (argv[1][0] == '0') cout << randint(1, 1e4) << " " << randint(1, 1e4);
	else if (argv[1][0] == '1') cout << randint(1, 1e7) << " " << randint(1, 1e7);
	else if (argv[1][0] == '2') cout << randint(1, 1e9) << " " << randint(1, 1e9);
	else cout << "err";
	// cout << argv[1];
	return 0;
}
