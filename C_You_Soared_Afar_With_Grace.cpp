// ╔═══════════════════╗
// ║   By _Trefoil_    ║
// ╚═══════════════════╝

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // @Nilayan17
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

const long double eps = 1e-12;

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void preprocessing()
{

    // Code here

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ": ";

    int n;
    cin >> n;
    vector<int> v1(n); inp(v1);
    vector<int> v2(n); inp(v2);

    set<pair<int, int>> s;
    vector<pair<int, int>> vp(n);
    for(int i = 0 ; i<n ; i++)
    {
        vp[i] = mpr(v1[i], v2[i]);
        if(s.find(mpr(v2[i], v1[i]))!=s.end()) s.erase(mpr(v2[i], v1[i]));
        else s.insert(mpr(v1[i], v2[i]));
    }

    if(s.size() > 1 || (s.size() == 1 && n%2 == 0))
    {
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> res;
    if(s.size() == 1)
    {
        int p = -1;

        for(int i = 0 ; i<n ; i++)
            if(*s.begin() == vp[i])
            {
                p = i;
                break;
            }
        if(p!=n/2)
        {
            swap(vp[p], vp[n/2]);
            res.pb(mpr(p+1, n/2 + 1));
        }
    }

    map<pair<int, int>, int> pos;
    
    for(int i = 0 ; i<n ; i++)
    {
        if(i == n/2) continue;
        AGAIN:;
        if(vp[i].S == vp[n-i-1].F && vp[i].F == vp[n-i-1].S) continue;
        if(pos.find(mpr(vp[i].S, vp[i].F)) != pos.end())
        {
            int x = pos[mpr(vp[i].S, vp[i].F)];
            swap(vp[n-x-1], vp[i]);
            res.pb(mpr(n-x, i+1));
            goto AGAIN;        
        }
        else
            pos[vp[i]] = i;
    }

    cout << res.size() << "\n";
    for(pair<int, int> pa : res)
        cout << pa.F << " " << pa.S << "\n";

}

signed main()
{
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

    return 0;
}



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
// // use less_equal for multiple entries

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

// // -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

// void preprocessing()
// {

//     // Code here

// }


// void solve(ll tc_no)
// {
    
//     // cout << "Case #" << tc_no << ": ";
    
//     int n;
//     cin >> n;
//     vector<int> v1(n); inp(v1);
//     vector<int> v2(n); inp(v2);

//     vector<pair<int, int>> vp(n);
//     for(int i = 0 ; i<n ; i++) vp[i] = mpr(v1[i], v2[i]);


//     bool flag = true;
//     map<pair<int, int>, int> counts;
//     for(auto &p : vp)
//         counts[p]++;
    
//     bool f2 = false;
//     pair<int, int> tar = mpr(-1, -1);

//     for(auto [a, b] : counts)
//     {
//         if(counts[mpr(a.S, a.F)] == b && a.S != a.F) continue;
//         else if((counts[mpr(a.S, a.F)] - b == 1 || (a.S == a.F && b%2 == 1)) && f2 == false)
//         {
//             tar = mpr(a.S, a.F);
//             f2 = true;
//         }
//         else if(counts[mpr(a.S, a.F)] - b > 1 || ((counts[mpr(a.S, a.F)] - b == 1 || (a.S == a.F && b%2 == 1)) && f2 == true))
//         {
//             cout << "-1\n";
//             return;
//         }
//     }

//     vector<pair<int, int>> res;
//     if(f2)
//     {
//         for(int i = 0 ; i<n ; i++)
//         {
//             if(tar == vp[i])
//             {
//                 if(i != n/2)
//                 {
//                     res.pb(mpr(i+1, n/2 + 1));
//                     swap(vp[i], vp[n/2]);
//                 }
//                 break;
//             }
//         }
//     }

//     map<pair<int, int>, vector<int>> pos;
    
//     for(int i = 0 ; i<n ; i++)
//     {
//         if(i == n/2) continue;
//         AGAIN:;
//         if(vp[i] == mpr(vp[n-i-1].S, vp[n-i-1].F)) continue;
//         if(pos.find(mpr(vp[i].S, vp[i].F)) != pos.end())
//         {
//             int x = pos[mpr(vp[i].S, vp[i].F)].back();
//             pos[mpr(vp[i].S, vp[i].F)].ppb();
//             swap(vp[n-x-1], vp[i]);
//             res.pb(mpr(n-x, i+1));
//             goto AGAIN;
//         }
//         else pos[vp[i]].pb(i);
//     }

//     cout << res.size() << "\n";
//     for(pair<int, int> pa : res)
//         cout << pa.F << " " << pa.S << "\n";
    
    
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // cout << fixed;
//     cout << setprecision(10);

//     preprocessing();

//     ll t;
//     cin >> t;
//     for(ll i = 1 ; i<=t ; i++)
//         solve(i);

//     return 0;
// }