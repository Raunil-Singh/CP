#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int long long // upto 9.2 * (10^18)
#define uint unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

void preprocessing()
{

    // Code here

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    vector<int> v(2*n); inp(v);

    int cnt= 0;
    int ans = 0;
    set<int> complete;
    for(int i = 0 ; i<v.size() ; i+=2)
    {
        if(v[i] == v[i+1])
        {
            if(complete.find(v[i]) == complete.end()) complete.insert(v[i]);
            else
            {
                ans += 2;
                cnt++;
            }
            v[i] = 0;
            v[i+1] = 0;
        }
    }

    vector<int> mpp(n+1);
    for(int i = 0 ; i<v.size() ; i+=2)
    {
        if(v[i] == 0) continue;
        if(complete.find(v[i]) == complete.end())
        {
            mpp[v[i]]++;
        }
        else ans++;

        if(complete.find(v[i+1]) == complete.end())
        {
            mpp[v[i+1]]++;
        }
        else ans++;
    }

    for(int i = 0 ; i<=v.size() ; i+=2)
    {
        if(v[i] == 0 || complete.find(v[i]) != complete.end() || complete.find(v[i+1]) != complete.end()) continue;
        if(mpp[v[i]] == 1 || mpp[v[i+1]] == 1)
        {
            cnt++;
            mpp[v[i]]--;
            mpp[v[i+1]]--;
            ans += 1;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1 ; i<=n ; i++)
    {
        if(complete.find(i) != complete.end()) continue;
        pq.push(mpp[i]);
    }

    while(cnt>0)
    {
        cnt--;
        int num = pq.top();
        ans += num;
        pq.pop();
    }

    while(!pq.empty())
    {
        int num = pq.top();
        ans += max(0LL, num-1);
        pq.pop();
    }

    cout << ans << "\n";
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t;
    cin >> t;
    for(int i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}