#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef BG // use flag -DBG when compiling to enable
#include <dbg.h>
#else
#define dbg(x, ...) ;
#endif

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// use less_equal for multiple entries

#define int int64_t // upto 9.2 * (10^18)
#define uint uint64_t // upto 1.8 * (10^19)
#define inp(v) for(auto &temporary_variable : v) cin >> temporary_variable
#define all(x) x.begin(), x.end()
#define mpr(x, y) make_pair(x, y)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-12;
#define MOD

inline void preprocessing() {

    // Code here

}

vector<pair<int, int>> process(string &s) {
    int n = s.length();
    vector<pair<int, int>> vp;
    vp.reserve(n);

    // Handling case 2
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 1 ; i<n-1 ; i++) {
            if(s[i-1] == '0' && s[i] == '1' && s[i+1] == '0') {
                flag = true;
                vp.emplace_back(i-1, i+1);
                s[i-1] = '1';
                s[i] = '0';
                s[i+1] = '1';
            }
        }
    }

    // Handling case 1
    int start = 0;
    s.push_back('0');
    for(int i = 0 ; i<=n ; i++) {
        if(s[i] == '1' && (i==0 || s[i-1] == '0')) {
            start = i;
        }
        if(i > start+1 && s[i] == '0' && (i>0 && s[i-1] == '1')) {
            vp.emplace_back(start, i-1);
        }
    }

    string temp = s;
    for(int i = 0 ; i<n ; i++) {
        if(s[i] == '1' && ((i>0 && temp[i-1] == '1') || (i<n-1 && temp[i+1] == '1'))) {
            s[i] = '0';
        }
    }

    s.pop_back();

    start = 1;
    int end = n-2;

    if(s[0] == '0') start = 0;
    if(s[n-1] == '0') end = n-1;

    vp.emplace_back(start, end);

    return vp;
}

void solve(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    vector<pair<int, int>> first{process(s1)}, second{process(s2)};

    reverse(all(second));

    cout << first.size() + second.size() << "\n";
    for(auto [a, b] : first)  cout << a+1 << " " << b+1 << "\n";
    // cout << "*****\n";
    for(auto [a, b] : second) cout << a+1 << " " << b+1 << "\n";

}
// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    Convert both to 0000...0

    Look for the neighour of 1s.
    case 1: adjacent number is 1.
            Convert both to 0 together
    case 2: adjacent numbers are zero and atmost 1 zero on each side and not on the edge.
            Flip 010 to 101. This way the 1 will get paired with the neighbours.
    case 3: adjacent numbers are zero and atleast 1 side has 2 zeroes.
            100 -> 111 -> 000
    case 4: 1 on the edge and the other side has 1 zero...
            process in the end.
    
    note: this algorithm uses on an average 1 move per cell.

****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    int t{1};
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : Yes
// Using it? : Yes
// Sol Proof : Yes
// algo noted: 
// Update the number of testcases: 
// Start coding ;)