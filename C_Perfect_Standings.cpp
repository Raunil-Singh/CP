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

void rec(vector<int> &v, priority_queue<pair<int, string>> &pq, string curr, int score, int pos)
{
    if(pos == 5)
    {
        if(score)
            pq.push(make_pair(score, curr));
        return;
    }
    rec(v, pq, curr, score, pos+1);
    curr.pb((char)(pos + 'A'));
    rec(v, pq, curr, score+v[pos], pos+1);
    curr.ppb();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<int> v(5); inp(5, v);

    priority_queue<pair<int, string>> pq;

    string curr = "";
    int score = 0;
    rec(v, pq, curr, score, 0);

    score = INT_MAX;
    vector<string> res;
    while(!pq.empty())
    {
        if(score != pq.top().F)
        {
            sort(res.begin(), res.end());
            for(string s : res) cout << s << "\n";
            res = {};
            score = pq.top().F;
        }
        else
        {
            res.pb(pq.top().S);
            pq.pop();
        }
    }

    sort(res.begin(), res.end());
        for(string s : res) cout << s << "\n";
    
    return 0;
}