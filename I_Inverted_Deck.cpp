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
    vector<int> v(n); inp(v);

    int st = -1;
    for(int i = 0 ; i<n-1 ; i++) {
        if(v[i] > v[i+1]) st = i+1;
        else
            continue;
        break;
    }

    while(st>1 && v[st-1] == v[st-2]) st--;
    
    int en = n;
    for(int i = st;i<n-1;++i){
        if(v[i]<v[i+1]) {

            en = i+1;
            break;
        }
    }
    if(st==-1){
        cout << "1 1" << endl;
        return 0;u
    }
    // cout << st << ' ' << en << endl;
    reverse(v.begin()+st-1,v.begin()+en);
    for(int i=0;i<n-1;++i){
        if(v[i+1]<v[i]){
            cout << "impossible\n" ;
            return 0;
        }
    }
    cout << st << ' ' << en << endl;
    // while(en<n-1 && v[en] == v[en+1]) en++; 

    // bool flag = true;
    // if(st > en || st == -1 || en == n) flag = false;

    // if(flag) reverse(v.begin() + st, v.begin() + en + 1);

    // for(int i = 1 ; i<n ; i++) if(v[i] < v[i-1]) flag = false;

    // if(flag) cout << st + 1 << " " << en+1 << "\n";
    // else cout << "impossible\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}