// 02-06-2025 17:24:35 (IST +0530)
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

class Trie {
private:    
    struct trieNode
    {
        trieNode* next[2];
        int recent;
    };
    trieNode* root;
    int count;
    trieNode* make_node(trieNode* p1, trieNode* p2)
    {
        trieNode* temp = new trieNode();
        temp->next[0] = p1;
        temp->next[1] = p2;
        temp->recent = -1;
        return temp;
    }

public:
    Trie()
    {
        count = -1;
        root = make_node(nullptr, nullptr);
    }

    void insert(int num)
    {
        count++;
        trieNode* curr = root;
        for(int pos = 32 ; pos >= 0 ; pos--)
        {
            int bit = ((num>>pos)&1);
            if(!(curr->next[bit])) curr->next[bit] = make_node(nullptr, nullptr);
            curr = curr->next[bit];
            curr->recent = count;
        }
    }

    int closest_greater_xor(int num, int k)
    {
        int ans = -1;
        trieNode* curr = root;
        for(int pos = 32 ; pos >= 0 ; pos--)
        {
            int available = ((num>>pos)&1), need = ((k>>pos)&1);
            if(need == 0)
            {
                int check = 1^available;
                if(curr->next[check]) ans = max(ans, curr->next[check]->recent);
            }
            int check = need^available;
            if(!curr->next[check]) return ans;
            curr = curr->next[check];
        }
        return max(ans, curr->recent);
    }
};

void preprocessing()
{

    // Code here

}

void solve(ll tc_no)
{
    
    // cout << "Case #" << tc_no << ":\n";
    int n, k;
    cin >> n >> k;
    vector<int> v(n); inp(v);

    Trie trie;

    int ans = INT_MAX;
    for(int i = 0 ; i<n ; i++)
    {
        trie.insert(v[i]);
        int pos = trie.closest_greater_xor(v[i], k);
        if(pos != -1) ans = min(ans, i - pos + 1);
    }

    if(ans != INT_MAX) cout << ans << "\n";
    else cout << "-1\n";
    
}

signed main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    preprocessing();

    ll t;
    cin >> t;
    for(ll i = 1 ; i<=t ; i++)
        solve(i);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}