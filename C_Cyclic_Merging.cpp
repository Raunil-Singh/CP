#include <bits/stdc++.h>
using namespace std;

#define int long long // upto 9.2 * (10^18)

int par[200050], rnk[200050];

int find(int num) {
    if(par[num] == num) return num;
    else return par[num] = find(par[num]);
}

bool unio(int a, int b) {
    int pa = find(a), pb = find(b);
    if(pa == pb) return false;
    if(rnk[pa] > rnk[pb]) {
        par[pb] = pa;
        rnk[pa] += rnk[pb];
    } else {
        par[pa] = pb;
        rnk[pb] += rnk[pa];
    }
    return true;
}

void solve(int tc_no)
{
    
    int n;
    cin >> n;
    vector<int> v(n);

    vector<pair<int, int>> vp(n);
    for(int i = 0 ; i<n ; i++) {
        cin >> v[i];
        par[i] = i;
        rnk[i] = 1;
        vp[i] = make_pair(v[i], i);
    }

    sort(vp.begin(), vp.end());

    int ans = 0;
    vector<bool> flag(n);
    for(auto p : vp) {
        flag[p.second] = true;
        if(flag[(p.second-1+2*n) % n] && unio((p.second-1+2*n) % n, p.second)) {
            ans += p.first;
        } if(flag[(p.second+1+2*n) % n] && unio((p.second+1+2*n) % n, p.second)) {
            ans += p.first;
        }
    }

    cout << ans << "\n";
    
}

signed main()
{

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    return 0;
}