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

int solve(vector<vector<int>> &v, map<vector<int>, int> &mpp, int st, int en, int dim)
{
    // cout << st << " " << en << "**\n";
    if(en < st) return -1;
    if(en-st == 0) return st;
    vector<int> unpaired;
    int prev = st;
    int curr = prev+1;
    while(curr <= en)
    {
        if(v[prev][dim] != v[curr][dim])
        {
            int rem = solve(v, mpp, prev, curr-1, dim+1);
            if(rem != -1)
            unpaired.pb(rem);
            prev = curr;
        }
        curr++;
    }
    int rem = solve(v, mpp, prev, curr-1, dim+1);
    if(rem != -1) unpaired.pb(rem);
    for(int i = 1 ; i<unpaired.size() ; i+=2)
        cout << mpp[v[unpaired[i-1]]] << " " << mpp[v[unpaired[i]]] << "\n";
    return unpaired.size()&1 ? unpaired.back() : -1;
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

    int n;
    cin >> n;
    map<vector<int>, int> mpp;

    vector<vector<int>> v(n, vector<int>(3)); 
    for(int i = 0 ; i<n ; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        mpp[v[i]] = i+1;
    }

    sort(all(v));

    assert(solve(v, mpp, 0, n-1, 0) == -1);


    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}