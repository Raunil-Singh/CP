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

// -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

void solve(ll tc_no)
{
    
    int n;
    cin >> n;

    vector<vector<int>> v(2, vector<int>(n));
    vector<vector<char>> op(2, vector<char>(n));

    int prev_choice = 0;
    vector<int> choice(n);

    for(int i = 0 ; i<n ; i++)
        cin >> op[0][i] >> v[0][i] >> op[1][i] >> v[1][i];
    
    for(int i = n-1 ; i>=0 ; i--)
    {
        if(op[0][i] == op[1][i])
        {
            if(op[0][i] == '+') choice[i] = prev_choice;
            else
            {
                if(v[0][i] == v[1][i]) choice[i] = prev_choice;
                else choice[i] = (v[0][i] < v[1][i]);
            }
        }
        else
        {
            if(op[0][i] == '+') choice[i] = 1;
            else choice[i] = 0;
        }
        prev_choice = choice[i];
    }

    vector<int> count(2, 1);
    int ex = 0;
    for(int i = 0 ; i<n; i++)
    {
        count[choice[i]] += ex;
        ex  = (op[0][i] == '+' ? v[0][i] : count[0]*(v[0][i]-1));
        ex += (op[1][i] == '+' ? v[1][i] : count[1]*(v[1][i]-1));
    }

    cout << count[0] + count[1] + ex << "\n";
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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