#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;
P origin ; 
int top; 
double cross(P a, P b, P c) {
    int x1 = b.first - a.first, y1 = b.second - a.second;
    int x2 = c.first - a.first, y2 = c.second - a.second;
    return x1 * y2 - x2 * y1;
}

bool cmp(P a, P b) {
    int c = cross(origin, a, b);
    if (c == 0)
        return hypot(a.first - origin.first, a.second - origin.second) <
               hypot(b.first - origin.first, b.second - origin.second);
    return c > 0;
}

bool cmp_point(P a , P b ){
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

vector<P> grahamScan(vector<P> points) {
    int n = points.size();
    // 1. 找最低最左的點
    // int idx = 0; 
    // for (int i = 1; i < n; i++) {
    //     if (points[i].second < points[idx].second ||
    //        (points[i].second == points[idx].second && points[i].first < points[idx].first)) {
    //         idx = i;
    //     }
    // }
    // swap(points[0], points[idx]);
    sort(points.begin() , points.end(),cmp_point);
    origin = points[0];

    // 2. 按極角排序
    sort(points.begin() + 1, points.end(), cmp );

    // 3. Graham Scan 主邏輯
    vector<P> hull(100);
    hull[0] = (points[0]);
    hull[1] = (points[1]);
    top = 1 ;
    for (int i = 2; i < n; i++) {
        while (top && cross(hull[top-1], hull[top], points[i]) <= 0) {
            top--;
        }
        top++;
        hull[top] = (points[i]);
    }

    return hull;
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<P> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        // 求凸包
        vector<P> convex = grahamScan(points);
        // 判斷是否為純凸多邊形
        cout << (top+1 < n ? "Yes" : "No") << endl;
    }
}
// Wrong , Convex hull.