#include <bits/stdc++.h>
using namespace std;

#define int long long

struct info {
    int m, cnt;
    info() : m(INT_MAX), cnt(0) {}
    info(int a, int b) : m(a), cnt(b) {}
};

info cmp(info x, info y) {
    if(x.m < y.m) return x;
    else if(x.m == y.m) {
        x.cnt += y.cnt;
        return x;
    } else return y;
}

info seg[400000];
info build(vector<int> &v, int l, int r, int node) {
    cout << l << " " << r << "\n";
    if(l >= r) return info();
    if(r - l == 1) seg[node] = info(v[l], 1LL);
    else return seg[node] = cmp(build(v, l, (l+r)/2, node*2), build(v, (l+r)/2, r, node*2 + 1));
    return info();
}

info sett(int i, int num, int l, int r, int node) {
    if(l>=r) return info();
    if(i < l || r<=i) return seg[node];
    if(l == i && r == i+1) return seg[node] = info(num, 1LL);
    return seg[node] = cmp(sett(i, num, l, (l+r)/2, node*2), sett(i, num, (l+r)/2, r, node*2 + 1));
}

info get(int l, int r, int L, int R, int node) {
    if(R <= l || r<=L || L>=R) return info();
    if(l <= L && R <= r) return seg[node];
    return cmp(get(l, r,  L, (L+R)/2, node*2), get(l, r, (L+R)/2, R, node*2 + 1));
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
        else {
            info x = get(b, c, 0, n, 1);
            cout << x.m << " " << x.cnt << "\n";
        }
    }
    return 0;
}