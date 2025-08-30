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
#define inp(n, v) for(ll integer_type_variable = 0 ; integer_type_variable<n ; integer_type_variable++) cin >> v[integer_type_variable]

class Solution
{
private :
    vector<int> parent;
    vector<int> rank;

    int Find(int i)
    {
        if(parent[i] == i) return i;
        else return parent[i] = Find(parent[i]);
    }
    int Unio(int i, int j){
        int pi = Find(i), pj = Find(j);
        if(pi == pj) return 0;
        
        if(rank[pi] > rank[pj])
            parent[pj] = pi;
        else if(rank[pi] < rank[pj])
            parent[pi] = pj;
        else
        {
            parent[pi] = pj;
            rank[pj]++;
        }
        return 1;
    }

public :
    void solve(ll tc_no)
    {
        
        ll n;
        cin >> n;

        parent.resize(n);
        rank.resize(n, 0);
        for(ll i =0 ; i<n ; i++) parent[i] = i;


        vector<vector<ll>> v(n, vector<ll>(2));
        for(ll i = 0 ; i<n ; i++) inp(2, v[i]);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(ll i = 0 ; i<n ; i++)
        {
            for(ll j = i+1 ; j<n ; j++)
            {
                ll num = (min(abs(v[i][0]-v[j][0]), abs(v[i][1]-v[j][1])) == 0LL) ? max(abs(v[i][0]-v[j][0]), abs(v[i][1]-v[j][1]))/2 + max(abs(v[i][0]-v[j][0]), abs(v[i][1]-v[j][1]))%2 : max(abs(v[i][0]-v[j][0]), abs(v[i][1]-v[j][1]));
                pq.push({num, n*i + j});
            }
        }

        ll comp = n;
        ll last_edge = 0;
        while(comp > 1)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            last_edge = p.F;
            comp -= Unio(p.S/n, p.S%n);
        }

        cout << last_edge << "\n";
        
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
    {
        Solution obj;
        obj.solve(i);
    }
    return 0;
}