/*

 problem :
 by : ztrztr(luogu 602124)
 date : 2022/10/16
 update : 2022/10/16

*/
#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005], u[100005];
int dis[1000005], vis[1000005], n;
struct node{
	int v, u;
	friend bool operator <(node a, node b) {
		return a.u > b.u;
	}
} t;
priority_queue <node> pqn;
namespace fun{
	void DIJ(int s) {
		for (int i = 0; i <= n; i ++) {
			dis[i] = 2147483647;
		}
		dis[s] = 0; 
		t.v = s; t.u = 0; pqn.push(t);
		while (pqn.size()) {
			int flag = pqn.top().v; pqn.pop();
			if (vis[flag]) continue;
			vis[flag] = 1;
			for (int i = 0; i < v[flag].size(); i ++) {
				if (dis[v[flag][i]] > (long long)(dis[flag] + u[flag][i])) dis[v[flag][i]] = dis[flag] + u[flag][i], 
t.u = dis[v[flag][i]], t.v = v[flag][i], pqn.push(t);
			}
		}
	}
}
namespace OI{
	void run() {
		int m, s;
		cin >> n >> m >> s;
		for (int i = 1; i <= m; i ++) {
			int x, y, z; cin >> x >> y >> z;
			v[x].push_back(y);
			u[x].push_back(z);
			v[y].push_back(x);
			u[y].push_back(z);
		}
		fun::DIJ(s);
		for (int i = 1; i <= n; i ++) cout << dis[i] << " ";
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}

