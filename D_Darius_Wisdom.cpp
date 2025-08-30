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

void solve(ll tc_no)
{
    
    ll n;
    cin >> n;

    vector<int> v(n), temp; inp(v);

    temp = v;
    sort(all(temp));

    priority_queue<int, vector<int>, greater<int>> pq[3];
    for(ll i = 0 ; i<n ; i++) pq[v[i]].push(i);

    vector<pair<int, int>> res;

    for(ll i = n-1 ; i>=0 ; i--)
    {
        while(temp[i]!=v[i])
        {
            ll ind = pq[v[i]+1].top();
            pq[v[i]+1].pop();
            pq[v[i]].push(ind);
            swap(v[ind], v[i]);
            res.pb(mpr(ind+1, i+1));
        }
    }

    cout << res.size() << "\n";
    for(auto p : res) cout << p.F << " " << p.S << "\n"; 
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

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

// void solve(ll tc_no)
// {
    
//     ll n;
//     cin >> n;

//     vector<int> v(n); inp(v);
//     vector<int> count(3, 0);

//     for(ll num : v) count[num]++;
//     count[2] = count[1]+count[0];
//     count[1] = count[0];
//     count[0] = 0;

//     priority_queue<int, vector<int>, greater<int>> s2;
//     priority_queue<int> s0;
//     ordered_set s1;

//     for(ll i = 0 ; i<n ; i++)
//     {
//         switch(v[i])
//         {
//             case 0 : s0.push(i); break;
//             case 1 : s1.insert(i); break;
//             case 2 : s2.push(i); break;
//         }
//     }

//     vector<pair<ll,ll>> vp;
    
//     for(ll i = n-1 ; i>=0 ; i--)
//     {
//         if(i >= count[2])
//         {
//             if(v[i] == 0)
//             {
//                 ll ind = *(s1.find_by_order(0));
//                 s1.erase(s1.find(ind));
//                 s0.pop();
//                 s0.push(ind);
//                 v[ind] = 0;
//                 v[i] = 1;
//                 s1.insert(i);
//                 vp.pb(mpr(ind+1, i+1));
//             }

//             if(v[i] == 1)
//             {
//                 s1.erase(s1.find(i));
//                 ll ind = s2.top();
//                 s2.pop();
//                 v[i] = 2;
//                 v[ind] = 1;
//                 s1.insert(ind);
//                 vp.pb(mpr(ind+1, i+1));
//             }
//         }
//         else if(i >= count[1] && v[i] == 0)
//         {
            
//             ll ind = *(s1.find_by_order(0));
//             s1.erase(s1.find(ind));
//             s0.pop();
//             s0.push(ind);
//             v[ind] = 0;
//             v[i] = 1;
//             s1.insert(i);
//             vp.pb(mpr(ind+1, i+1));
//         }
//     }

//     cout << vp.size() << "\n";
//     for(auto p : vp) cout << p.F << " " << p.S << "\n";

// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     // cout << fixed;
//     cout << setprecision(10);

//     ll t;
//     cin >> t;
//     for(ll i = 1 ; i<=t ; i++)
//         solve(i);

//     return 0;
// }