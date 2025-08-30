#include <bits/stdc++.h>
using namespace std;

#define int long long

int dfs1(int curr, vector<vector<int>> &adj, vector<int> &sub) {
    for(int next : adj[curr]) sub[curr] += dfs1(next, adj, sub) + 1;
    return sub[curr];
}

void dfs2(int curr, vector<vector<int>> &adj, vector<double> &time, vector<int> &sub) {
    int cnt = sub[curr];
    int child = adj[curr].size();
    for(int next : adj[curr]) {
        if(child != 1) {
            time[next] += 1.0*(cnt - sub[next] - 1) / 2;
        }
        // cout << next << " " << time[next] << " " << cnt << " " << sub[next] << " " << child-1 << "\n";
        time[next] += time[curr];
        dfs2(next, adj, time, sub);
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> par(n+1);
    for(int i = 2 ; i<=n ; i++) {
        cin >> par[i];
    }

    vector<vector<int>> adj(n+1);
    for(int i = 2 ; i<=n ; i++) {
        adj[par[i]].push_back(i);
    }

    vector<double> time(n+1, 1.0);
    time[1] = 1.0;
    vector<int> subtree(n+1);

    dfs1(1, adj, subtree);
    dfs2(1, adj, time, subtree);

    cout << fixed << setprecision(10);
    for(int i = 1 ; i<=n ; i++) cout << time[i] << " ";
    cout << "\n";

    return 0;
}