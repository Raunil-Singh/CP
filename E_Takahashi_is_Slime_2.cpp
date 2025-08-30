// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(n, v) for(ll i = 0 ; i<n ; i++) cin >> v[i]

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll m, n, x;
    cin >> m >> n >> x;

    vector<vector<bool>> pres(m, vector<bool>(n, false));
    ll p1, p2; cin >> p1 >> p2;
    p1--;
    p2--;
    
    vector<vector<int>> v(m, vector<int>(n));
    for(ll j = 0 ; j<m ; j++) inp(n, v[j]);

    auto cmp = [&v](const pair<int, int>& a, const pair<int, int>& b) {
        return v[a.first][a.second] > v[b.first][b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    ll score = 0;
    pq.push({p1, p2});
    do
    {
        p1 = pq.top().F;
        p2 = pq.top().S;
        pq.pop();
        if(pres[p1][p2]) continue;
        score += v[p1][p2];
        pres[p1][p2] = true;
        if(p1>0 && pres[p1-1][p2] == false) pq.push({p1-1, p2});
        if(p2>0 && pres[p1][p2-1] == false) pq.push({p1, p2-1});
        if(p1<m-1 && pres[p1+1][p2] == false) pq.push({p1+1, p2});
        if(p2<n-1 && pres[p1][p2+1] == false) pq.push({p1, p2+1});
    } while(!pq.empty() && v[pq.top().F][pq.top().S] <= (score-1)/x);

    cout << score << "\n";
    
    return 0;
}