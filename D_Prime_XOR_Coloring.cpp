// // ╔═══════════════════╗
// // ║   By _Trefoil_    ║
// // ╚═══════════════════╝

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
// // order_of_key (k) : Number of items strictly smaller than k .
// // find_by_order(k) : K-th element in a set (counting from zero).

// #define int long long
// #define ll long long // upto 9.2 * (10^18)
// #define ull unsigned long long // upto 1.8 * (10^19)
// #define pb(x) push_back(x)
// #define ppb(x) pop_back(x)
// #define F first
// #define S second
// #define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
// #define all(x) x.begin(), x.end()
// #define mpr(x, y) make_pair(x, y)

// const long double eps = 1e-12;

// void seive(int n, vector<int> &prime)
// {
//     vector<bool> is_prime(n+1, true);
//     is_prime[0] = false;
//     is_prime[1] = false;
//     for (int i = 2; i <= n; i++) {
//         if (is_prime[i] && (long long)i * i <= n) {
//             for (int j = i * i; j <= n; j += i)
//                 is_prime[j] = false;
//         }
//     }

//     for(int i = 1 ; i<=n ; i++) if(is_prime[i]) prime.pb(i);
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // cout << fixed;
//     cout << setprecision(10);

//     ll lim = 200000;

//     vector<int> prime; seive(lim*10, prime);

//     // for(ll num : prime) cout << num << " ";
//     // cout << "@@\n";

//     vector<int> res2(lim+1, 1);
//     vector<int> res(lim + 1, 1);
//     res[1] = 1;
    
//     int pos = 0;
//     for(int i = 2 ; i<res.size() ; i++)
//     {
//         // cout << i << " -> ";
//         while(pos < prime.size() && prime[pos] <= 2*i) pos++;
//         set<int> s;
//         // cout << prime[pos] << " $ ";
//         for(int j = 0 ; j<pos ; j++)
//         {
//             if(i < (prime[j]^i)) continue;
//             // cout << res[prime[j]^i] << " ";
//             s.insert(res[prime[j]^i]);
//             while(s.find(res[i])!=s.end()) res[i]++;
//             // cout << " a ";
//         }
//         // cout << "# " << res[i];
//         // cout << " #\n";
//         res2[i] = max(res2[i-1], res[i]);
//     }

//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         // cout << res2[n] << "\n";
//         // for(int i = 1 ; i<=n ; i++) cout << res[i] << " ";
//         // cout << "\n";
//     }

//     cout << "Done!\n";
    
//     return 0;
// }

// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define ll long long
#define ull unsigned long long
#define pb(x) push_back(x)
#define inp(v) for (auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()

const long double eps = 1e-12;

void seive(int n, vector<int> &prime) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) prime.pb(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(10);

    ll lim = 200000;

    // Generate prime numbers using the sieve
    vector<int> prime;
    seive(lim * 10, prime);

    // Precompute Grundy numbers and maximum chromatic number
    vector<int> res2(lim + 1, 1);
    vector<int> res(lim + 1, 1);
    res[1] = 1;

    int pos = 0;
    for (int i = 2; i < res.size(); i++) {
        while (pos < prime.size() && prime[pos] <= 2 * i) pos++;
        set<int> s;
        for (int j = 0; j < pos; j++) {
            if (i < (prime[j] ^ i)) continue;
            s.insert(res[prime[j] ^ i]);
        }
        while (s.find(res[i]) != s.end()) res[i]++;
        res2[i] = max(res2[i - 1], res[i]);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << res2[n] << "\n";
    }

    return 0;
}
