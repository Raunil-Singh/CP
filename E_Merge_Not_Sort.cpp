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

const long double eps = 1e-12;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;
    vector<int> v(2*n); inp(v);
    
    map<int, int> counts;
    vector<int> pos(2*n);
    int lar = 0;
    int num = 0;
    
    for(int i = 0 ; i<2*n ; i++)
    {
        if(v[i] > lar)
        {
            num++;
            lar = v[i];
        }
        pos[i] = num;
        counts[num]++;
    }

    // for(int i = 1 ; i<=num ; i++)
    // {
    //     cout << i << " " << counts[i] << "\n";
    // }

    vector<bool> present(n+1, false);
    vector<vector<int>> dp(n+1, vector<int>(2*n + 1 , -1));
    for(int i = 0 ; i<=2*n ; i++) dp[0][i] = 0;
    present[0] = true;

    for(int i = 0 ; i<2*n-1 ; i++)
    {
        if(pos[i] == pos[i+1]) continue;
        int k = counts[pos[i]];
        for(int j = n ; j>=k ; j--)
        {
            if(present[j-k])
            {
                present[j] = true;
                dp[j][i] = pos[i];
            }
        }
    }

    if(!present[n])
    {
        cout << "-1\n";
        return 0;
    }

    // cout << "Done till here!\n";

    int p = n;
    set<int> ans;
    int curr = 2*n;
    while(p>0)
    {
        if(dp[p][curr] != -1)
        {
            int temp = dp[p][curr];
            curr -= counts[temp];
            p -= counts[temp];
            ans.insert(temp);
        }
        else curr--;
    }

    vector<int> a, b;
    for(int i = 0 ; i<2*n ; i++)
    {
        if(ans.find(pos[i])!=ans.end()) a.pb(v[i]);
        else b.pb(v[i]);
    }

    for(int &x : a) cout << x << " ";
    cout << "\n";
    for(int &x : b) cout << x << " ";
    cout << "\n";

    return 0;
}