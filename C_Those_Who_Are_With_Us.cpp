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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    
    int maxi = 0;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            int num;
            cin >> num;
            mat[i][j] = num;
            maxi = max(maxi, num);
        }
    }

    // cout << maxi << "->\n";

    vector<pair<int, int>> vp1, vp2;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<m ; j++)
        {
            if(mat[i][j] == maxi)
            {
                vp1.pb(mpr(i,j));
                vp2.pb(mpr(j,i));
                // cout << "Adding " << i << " " << j << "\n";
            }
        }
    }

    sort(all(vp1));
    sort(all(vp2));

    int vld11 = -1, vld12 = -1;
    bool flag1 = true, flag2 = true;

    int prev1 = -1, prev2;
    for(int i = 0 ; i<vp1.size() ; i++)
    {
        if(vld11 == -1) vld11 = vp1[i].F;
        if(vp1[i].F == prev1 && flag1)
        {
            vld11 = vp1[i].F;
            flag1 = false;
        }
        prev1 = vp1[i].F;
        if(vld12 == -1) vld12 = vp2[i].F;
        if(vp2[i].F == prev2 && flag2)
        {
            vld12 = vp2[i].F;
            flag2 = false;
        }
        prev2 = vp2[i].F;
    }

    int vld21 = -1, vld22 = -1;
    int ans1 = maxi-1, ans2 = maxi-1;
    flag1 = true;
    flag2 = true;
    for(int i = 0 ; i<vp2.size() ; i++)
    {
        if(vp2[i].S != vld11 && flag1)
        {
            if(vld21 == -1) vld21 = vp2[i].F;
            else if(vld21 != vp2[i].F)
            {
                ans1 = maxi;
                flag1 = false;
            }
        }
        if(vp1[i].S != vld12 && flag2)
        {
            if(vld22 == -1) vld22 = vp1[i].F;
            else if(vld22 != vp1[i].F)
            {
                ans2 = maxi;
                flag2 = false;
            }
        }
    }

    // cout << ans1 << " " << ans2 << " ";
    cout << min(ans1, ans2) << "\n";

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
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}