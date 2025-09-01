#include <bits/stdc++.h>
using namespace std;

#define int long long

int seg[400000];
int build(const vector<int> &v, int l, int r, int node) {
    if(l >= r) return INT_MAX;
    if(l == r-1) return seg[node] = v[l];
    return seg[node] = min(build(v, l, (l+r)/2, node*2), build(v, (l+r)/2, r, node*2 + 1));
}

int sett(int i, int num, int l, int r, int node) {
    if(l >= r) return INT_MAX;
    if(i == l && r == i+1) return seg[node] = num;
    if(i < l || r <= i) return seg[node];
    return seg[node] = min(sett(i, num, l, (l+r)/2, node*2), sett(i, num, (l+r)/2, r, node*2 + 1));
}

int get(int l, int r, int L, int R, int node) {
    if(R <= l || r <= L) return INT_MAX;
    if(l <= L && R <= r) return seg[node];
    return min(get(l, r, L, (L+R)/2, node*2), get(l, r, (L+R)/2, R, node*2 + 1));
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int &num : v) cin >> num;
    build(v, 0, n, 1);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) sett(b, c, 0, n, 1);
        else cout << get(b, c, 0, n, 1) << "\n";
    }
    return 0;
}