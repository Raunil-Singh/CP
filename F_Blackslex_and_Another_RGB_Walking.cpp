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

void preprocessing() {

    // Code here

}

// r g b r g b

void solve1(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0 ; i<m ; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> col(n);
    queue<int> q;
    q.push(0);

    for(int i = 1 ; q.size() ; i = i%3 + 1) {
        int x = q.size();
        while(x--) {
            int curr = q.front(); q.pop();
            if(col[curr]) continue;
            col[curr] = i;
            sort(all(adj[curr]));
            for(int next : adj[curr]) {
                q.push(next);
            }
        }
    }

    for(int num : col) {
        switch(num) {
            case 1: cout << 'r'; continue;
            case 2: cout << 'g'; continue;
            case 3: cout << 'b'; continue;
        }
    }

    cout << "\n";

}

void solve2(int tc_no) {
    
    // cout << "Case #" << tc_no << ": ";
    int q;
    cin >> q;
    map<char, char> target;
    target['r'] = 'b';
    target['g'] = 'r';
    target['b'] = 'g';
    while(q--) {
        int n;
        cin >> n;
        string s; cin >> s;
        set<char> chars;
        chars.insert('r');
        chars.insert('g');
        chars.insert('b');
        for(char c : s) chars.erase(c);
        if(chars.size() == 0) cout << "1\n";
        else if(chars.size() == 2) for(int i = 0 ; i<n ; i++) {
            if(chars.find(s[i-1]) == chars.end()) {
                cout << i+1 << "\n";
                goto NEXT;
            }
        } else {
            char mine = *chars.begin();
            for(int i = 0 ; i<n ; i++) {
                if(s[i] == target[mine]) {
                    cout << i+1 << "\n";
                    goto NEXT;
                }
            }
        }
        NEXT:;
    }

}

// Note: Ensure all template parameters are update!

/****              Algorithm keypoints:
    here:
    
    
    
****/

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    string s;
    cin >> s;

    bool flag = (s[0] == 'f');

    int t{1};
    cin >> t; // Update me!
    for(int i{1} ; i<=t ; i++)
        if(flag) solve1(i);
        else solve2(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


// ======= CHECKLIST =======
// Notebook  : 
// Using it? : 
// Sol Proof : 
// algo noted: 
// Update the number of testcases: 
// Start coding ;)