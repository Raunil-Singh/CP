#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << setprecision(10);
    cout << fixed;
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    if(n == k) {
        for(int i=0;i<n;i++) {
            cout << a[i] << " \n"[i==n-1];
        }
        return 0;
    }
    if(k == 1) {
        for(int i=0;i<n;i++) {
            cout << (double)100 / n << " \n"[i==n-1];
        }
        return 0;
    }
    vector<double> ans(n);
    for(int i=0;i<n;i++) {
        int p = n - 3;
        int q = k - 2;
        double sum = 0;
        double sum1 = a[i];
        double dem = k / (float)n;
        dem *= (k - 1);
        dem /= (n - 1);
        sum = dem * sum1;
        int c = 0;
        for(int j=(i - 1 + n);j > i;j--) {
            if(p < q) {
                break;
            }
            sum1 += a[j%n];
            dem *= (n - k - c);
            dem /= (n - c - 2);
            sum += (sum1 * dem);
            c++;
            p--;
        }
        ans[i] = sum;
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}