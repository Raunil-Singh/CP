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

typedef struct NODE1232
{
    bool flag;
    int cost;
    struct NODE1232 *l, *m, *r;
} node;

node* mk_node(bool flag, int cost = 0, node *l = NULL, node *m = NULL, node *r = NULL)
{
    node* curr = (node*) malloc(sizeof(node));
    curr->flag = flag;
    curr->cost = cost;
    curr->l = l;
    curr->m = m;
    curr->r = r;
    return curr;
}

node* build_tree(string &s, int l, int r)
{
    // cout << l << " " << r << "@@\n";
    if(r-l == 0)
        return mk_node(s[l]=='1', 1);
    node* le = build_tree(s, l, l+(r-l+1)/3-1);
    node* me = build_tree(s, l + (r-l+1)/3, l+2*(r-l+1)/3-1);
    node* re = build_tree(s, l + 2*(r-l+1)/3, r);
    node* temp = mk_node((le->flag && me->flag) || (re->flag && me->flag) || (re->flag && le->flag), 0, le, me, re);

    priority_queue<int, vector<int>, greater<int>> pq;
    if(temp->flag == le->flag) pq.push(le->cost);
    if(temp->flag == me->flag) pq.push(me->cost);
    if(temp->flag == re->flag) pq.push(re->cost);

    while(pq.size() > 1)
    {
        temp->cost += pq.top();
        pq.pop();
    }

    // cout << l << " " << r << " " << temp->cost << "#\n";

    return temp;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // cout << fixed;
    cout << setprecision(10);

    int n;
    string s;

    cin >> n >> s;
    
    int count = 1;
    while(n--) count*=3;

    // cout << "Here!\n";
    
    cout << build_tree(s, 0, count-1)->cost << "\n";
    
    return 0;
}