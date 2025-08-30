// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

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

#define int long long
#define ll long long // upto 9.2 * (10^18)
#define ull unsigned long long // upto 1.8 * (10^19)
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define F first
#define S second
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

vector<int> lp;

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

    lp = leastPrimeFactor(1000005);

}

int find_for(int x, int k, bool &flag)
{
    if(x == 1) return 0;
    vector<int> factors;
    int t = x;
    while(t > 1)
    {
        if(factors.size() == 0 || (factors.back() != lp[t])) factors.pb(lp[t]);
        t /= lp[t];
    }

    int facts = factors.size();
    
    if(factors[facts-1] > k)
    {
        flag = false;
        return -1;
    }

    vector<int> dp_count(x+1, INT_MAX);
    vector<int> dp_prod(x+1, 1);
    dp_count[1] = 1;
    for(int num = 2 ; num <= x ; num++)
    {
        if(x % num != 0) continue;
        for(int fact = 0 ; fact < facts ; fact++)
        {
            if(num % factors[fact] != 0) continue;
            int count = dp_count[num/factors[fact]];
            int prod = dp_prod[num/factors[fact]] * factors[fact];
            if(prod > k)
            {
                count++;
                prod = factors[fact];
            }
            if(dp_count[num] > count || (dp_count[num] == count && dp_prod[num] > prod))
            {
                dp_count[num] = count;
                dp_prod[num] = prod;
            }
        }
    }

    return dp_count[x];

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int x, y, k;
    cin >> x >> y >> k;

    int common = gcd(x, y);

    x /= common;
    y /= common;

    bool flag = true;
    int moves1 = find_for(x, k, flag), moves2 = find_for(y, k, flag);

    if(flag) cout << moves1 + moves2 << "\n";
    else cout << "-1\n";
    
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

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}