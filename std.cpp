#include <bits/stdc++.h>

using namespace std;
/*
*/
vector <int> w[100005], v[100005];
int n, m, s, dis[100005];
bool vis[100005];
struct node {
    int d, p;
    const bool operator <(const node &x) const{
        return x.d < d;
    }
};
priority_queue <node> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        w[x].push_back(y);
        v[x].push_back(z);
    }
    for(int i = 1; i <= n; i ++) dis[i] = 0x7fffffff;//
    dis[s] = 0;//
    q.push((node){0, s});
    while (!q.empty()) {
        int nd, np;
        nd = q.top().d;
        np = q.top().p;
        q.pop();
        if (vis[np]) continue;
        vis[np] = 1;
        for (int i = 0; i < w[np].size(); i ++) {
            int nxt = w[np][i];
            if (dis[nxt] > dis[np] + v[np][i]) {//
                dis[nxt] = dis[np] + v[np][i];
                if (vis[nxt] == 0) q.push((node){dis[nxt], nxt});//
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << dis[i] << " ";
    }
    return 0;
}