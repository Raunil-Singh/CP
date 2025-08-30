// 08-06-2025 18:28:13 (IST +0530)
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

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n, m, p;
    cin >> n >> m >> p;

    string s, move;
    cin >> s >> move;

    vector<int> pairing(n);
    stack<int> st;

    set<int> pos;
    set<int> rev;

    for(int i = 0 ; i<n ; i++)
    {
        pos.insert(i);
        rev.insert(-i);
        if(s[i] == '(') st.push(i);
        else {
            pairing[st.top()] = i;
            pairing[i] = st.top();
            st.pop();
        }
    }

    int curr = p-1;
    for(char c : move)
    {
        if(c == 'R')
        {
            curr++;
            curr = *pos.lower_bound(curr);
            continue;
        }
        else if(c == 'L')
        {
            curr--;
            curr = -(*rev.lower_bound(-curr));
            continue;
        }
        else if(c == 'D')
        {
            int a = min(curr, pairing[curr]), b = max(curr, pairing[curr]);
            pos.erase(pos.lower_bound(a), pos.upper_bound(b));
            rev.erase(rev.lower_bound(-b), rev.upper_bound(-a));
            // cout << "\n";
        }
        if(pos.size() == 0) continue;
        if(pos.lower_bound(curr) == pos.end())
        {
            curr = *pos.rbegin();
        }
        else curr = *pos.lower_bound(curr);
    }

    for(int num : pos) cout << s[num];
    cout << "\n";
    

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}