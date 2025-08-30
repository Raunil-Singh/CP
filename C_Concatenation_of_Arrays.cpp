#include <bits/stdc++.h>
using namespace std;

#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)

struct Compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        // Return true if the sum of p1 is less than the sum of p2, 
        // this ensures max-heap behavior (larger sums come first)
        return (p1.first + p1.second) < (p2.first + p2.second);
    }
};

void solve(ll tc_no)
{
	
    ll n;
    cin >> n;

    priority_queue<ll> pq;

    map<ll, priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> m;
    for(ll i = 0 ; i<n ; i++)
    {
        ll a, b;
        cin >> a >> b;
        pq.push(max(a, b));
        m[max(a, b)].push(make_pair(a, b));
    }


    stack<ll> st;

    while(!pq.empty())
    {
        ll curr = pq.top();
        pq.pop();

        pair<ll,ll> p = m[curr].top();
        m[curr].pop();

        st.push(p.second);
        st.push(p.first);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";
	
}

int main()
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
		solve(i);

	return 0;
}