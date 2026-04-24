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
#define MOD 1000000007LL

vector<int> primes;

vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);

    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            res.pb(p);
    
    return res;
}

void preprocessing()
{

    primes = SieveOfEratosthenes(10000010);
    
}

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int inv(int a, int m) { // m = MOD
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int ncr(int n, int r) {
    if(r == 0) return 1;
    else return mul(mul(n, inv(r, MOD)), ncr(n-1, r-1));
}

void solve(int tc_no)
{
    
    cout << "Case #" << tc_no << ": ";
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;

    int dup_b = b;
    vector<int> valid_primes;
    for(int p : primes) {
        if(b%p == 0) valid_primes.push_back(p);
        while(b % p == 0) b /= p;
    }

    if(b > 1) valid_primes.push_back(b);

    // for(int vp : valid_primes) cout << vp << " ";
    // cout << "!!\n";

    b = dup_b;

    function<int(int)> compute = [&](int num) -> int {
        int temp_ans = 1;
        for(int p : valid_primes) {
            int curr = 0;
            while(num % p == 0) {
                curr++;
                num /= p;
            }
            temp_ans = mul(temp_ans, ncr(n+curr-1, curr));
        }
        return temp_ans;
    };

    for(int i = 1 ; i*i <= b && i<=a ; i++) {
        if(b % i != 0) continue;
        int temp = mul(compute(i), compute(b/i));
        if(b/i <= a && i*i != b) ans = add(ans, mul(temp, 2));
        else ans = add(ans, temp);
    }

    cout << ans << "\n";
    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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