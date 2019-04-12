#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int a, b, c, d;

double calc(double deg) {
    double diag = sqrt(a*a + b*b - 2*a*b*cos(deg));
    double area = a * b * sin(deg) / 2;
    if (diag < c + d) {
        double s = (diag + c + d) / 2;
        area += sqrt(s * (s-diag) * (s-c) * (s-d));
    }
    return area;
}

void solve() {
    double lo = 0;
    double hi = PI;

    if (c+d < a+b) {
        hi = acos((a*a+b*b-(c+d)*(c+d)) / 2.0 / a / b);
    }
    // printf("hi = %.8lf\n", hi);
    double ans = PI / 2;
    for (int i=0; i<10000; i++) {
        // printf("%.5lf ... %.5lf\n", 180 * lo / PI, 180 * hi / PI);
        double mi1 = (2*lo+hi)/3;
        double mi2 = (lo+2*hi)/3;

        if (calc(mi1) > calc(mi2)) {
            ans = mi1;
            hi = mi2;
        } else {
            ans = mi2;
            lo = mi1;
        }
    }
    printf("%.16lf\n", calc(ans));
}

int main() {
    while (scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
        solve();
    }
}