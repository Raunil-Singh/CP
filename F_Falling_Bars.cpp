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

vector<ll> seg;

ll insert(ll tar_l, ll tar_r, ll curr_l, ll curr_r, ll pos, ll val)
{
    cout << "target_l:" << tar_l <<  "  target_r:" << tar_r << "  curr_l:" << curr_l << "  curr_r:" << curr_r << "  pos:" << pos << "  val:" << val << "\t\t\t[INSERTION]" <<"\n";
    if(curr_l > curr_r) return seg[pos/2];
    if(tar_r < curr_l || tar_l > curr_r) return seg[pos/2];
    if(tar_l <= curr_l && tar_r >= curr_r)
    {
        return seg[pos] = min(val, seg[pos]);
    }
    ll mid = (curr_r-curr_l)/2 + curr_l;
    return seg[pos] = min(insert(tar_l, tar_r, curr_l, mid, pos*2, val) , insert(tar_l, tar_r, mid+1, curr_r, pos*2+1, val));
}

ll fetch(ll tar_l, ll tar_r, ll curr_l, ll curr_r, ll pos)
{
    cout << "target_l:" << tar_l <<  "  target_r:" << tar_r << "  curr_l:" << curr_l << "  curr_r:" << curr_r << "  pos:" << pos << "\t\t\t\t[FECTHING]" <<"\n";
    if(curr_l > curr_r) return INT_MAX;
    if(tar_r < curr_l || tar_l > curr_r) return INT_MAX;
    if(tar_l <= curr_l && tar_r >= curr_r)
    {
        return seg[pos];
    }
    ll mid = (curr_r-curr_l)/2 + curr_l;
    return min(fetch(tar_l, tar_r, curr_l, mid, pos*2), fetch(tar_l, tar_r, mid+1, curr_r, pos*2+1));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	ll h, w, n;
    cin >> h >> w >> n;

    seg.assign((ll)(pow(2ll, (ll)(log2(w)*2 + 3))) , h+1);

    priority_queue<vector<ll>> pq;
    for(ll i = 0 ; i<n ; i++)
    {
        vector<ll> temp(4);
        temp[3] = i;
        cin >> temp[0] >> temp[1] >> temp[2];
        pq.push(temp);
    }

    vector<ll> v(n);
    while(!pq.empty())
    {
        // cout << "**HERE\n";
        vector<ll> curr = pq.top();
        cout << "Current   **" << curr[0] << " " << curr[1] << " " << curr[2] << " " << curr[3] << "\n";
        ll available = fetch(curr[1], curr[1] + curr[2] - 1, 1, n, 0); 
        cout << "Available **" << available << "\n";
        // cout << "**FETCHED\n";
        v[curr[3]] = available-1;
        insert(curr[1], curr[1] + curr[2] - 1, 1, n, 0, v[curr[3]]);
        pq.pop();
        // cout << "**INSERTED\n";
    }

    for(ll i : v)
    {
        cout << i << "\n";
    }


	return 0;
}