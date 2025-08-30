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

bool solve(vector<pair<int, int>>&v, vector<int>&res, int pos, int left, int sum)
{
    if(res.size()-2 == pos)
    {
        int curr = 0;
        for(int i = 0 ; i<pos ; i++) curr += v[res[i]].F;
        int l = left, r = v.size()-1;
        while(l<r)
        {
            if(curr + v[l].F + v[r].F < sum) l++;
            else if(curr + v[l].F + v[r].F > sum) r--;
            else
            {
                res[pos] = l;
                res[pos+1] = r;
                priority_queue<int, vector<int>, greater<int>> pq;
                for(int num : res) pq.push(v[num].S);
                while(!pq.empty())
                {
                    cout << pq.top() << " ";
                    pq.pop();
                }
                cout << "\n";
                return true;
            }
        }
        return false;
    }
    int x = v.size() - 2;
    for(int i = left ; i<x ; i++)
    {
        res[pos] = i;
        if(solve(v, res, pos+1, i+1, sum)) return true;
    }
    return false;
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

    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> v(n);
    for(int i = 0 ; i<n ; i++)
    {
        int num; cin >> num;
        v[i] = mpr(num, i+1);
    }

    sort(all(v));

    vector<int> res(3);
    if(!solve(v, res, 0, 0, sum)) cout << "IMPOSSIBLE\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}