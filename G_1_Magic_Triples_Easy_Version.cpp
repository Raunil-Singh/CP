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

vector<int> spf;

vector<int> leastPrimeFactor(int n)
{
    vector<int> least_prime(n+1, 0); 
    least_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
 
            for (int j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }

    return least_prime;
}

void preprocessing()
{

    // Code here
    spf = leastPrimeFactor(1000100);

}

void solve(int tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int n;
    cin >> n;
    map<int, int> mpp;
    for(int i = 0 ; i<n ; i++) {
        int x;
        cin >> x;
        mpp[x]++;
    }

    int ans = 0 ;
    for(auto [a, b] : mpp) {
        ans += b*(b-1)*(b-2);
        // cout << ans << " -> " << a << "\n";
    }

    for(auto [a, b] : mpp) {
        if(a==1) continue;
        vector<int> q;
        q.push_back(1);
        int curr = a;
        while(curr > 1) {
            int fact = spf[curr];
            vector<int> lst;
            int num = fact;
            while(curr % fact == 0) {
                lst.push_back(num);
                num *= fact;
                curr /= fact;
            }
            int sze = q.size();
            for(int i = 0 ; i<sze ; i++) {
                int pres = q[i];
                for(int pf : lst) q.push_back(pres * pf);
            }
        }
        for(int cur : q) {
            if(cur == 1) continue;
            if(mpp.find(a/cur) != mpp.end() && mpp.find(a*cur) != mpp.end()) ans += mpp[a/cur]*b*mpp[a*cur];
        }
        // cout << ans << " -> " << a << "\n";
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