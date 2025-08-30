#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

ll find_seg_size(ll n)
{
    ll res = 1;
    while(res <= n) res *= 2;
    return res - 1;
}

ll populate(vector<ll> &v, ll ind)
{
    if(ind>=v.size())
        return 0;

    v[ind] += populate(v, 2*ind+1) + populate(v, 2*ind + 2);
    return v[ind];
}

void update(vector<ll> &v, ll ind, ll val)
{
    v[ind] = val;
    while(ind>0)
    {
        ind = (ind-1)/2;
        v[ind] = v[2*ind+1] + v[2*ind+2];
    }
}

ll range_sum(vector<ll> &v, ll ind, ll tarl, ll tarr, ll ranl, ll ranr) // tarl, tarl -> target range; ranl, ranr -> node range
{
    if(tarl>ranr || ranl>tarr) return 0;
    if(tarl <= ranl && ranr <= tarr) return v[ind];
    return range_sum(v, 2*ind+1, tarl, tarr, ranl, (ranl+ranr)/2) + range_sum(v, 2*ind+2, tarl, tarr, (ranl+ranr)/2 + 1, ranr); 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// For IO in txt file
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	ll n, m;
    cin >> n >> m;

    ll seg_size = find_seg_size(n);

    vector<ll> v(2*seg_size+1, 0);
    for(int i = 0 ; i<n ; i++) cin >> v[i + seg_size];
    
    populate(v, 0);

    for(ll i = 0 ; i<m ; i++)
    {
        ll state, l, r;
        cin >> state >> l >> r;
        
        if(state == 1)
            update(v, l + (seg_size), r);
        else if(state == 2)
            cout << range_sum(v, 0, l, r-1, 0, seg_size) << "\n";
    }


	return 0;
}