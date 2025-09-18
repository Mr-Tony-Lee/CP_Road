#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double x;
    while (cin >> n){
        if (n == 0) break;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> x;
            a[i] = (int)round(x * 100);
            sum += a[i];
        }
        sort(a, a+n);
        int avg = sum / n;
        int remain = sum - avg * n;
        double ans = 0.0;
        for (int i = n-1; i >= n-remain; i--){
            ans += abs(a[i] - avg - 1);
        }
        for (int i = n-remain-1; i >= 0; i--){
            ans += abs(a[i] - avg);
        }
        cout << "$" << fixed << setprecision(2) << ans / 200.0 << "\n";
    }
    return 0;
}
// i don't know how to solve this ...