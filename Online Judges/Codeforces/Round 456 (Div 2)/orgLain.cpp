#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long m = log2(n);

    long long result = pow(2, m);
    // printf("result: %lld\n",result);
    if (k > 1) {
        long long powed = (long long)pow(2, m) - 1;
        //powed--;
        // printf("powed: %lld result: %lld\n",powed,result);
        result ^= powed;
        // printf("result %lld\n",result);
    }

    if (n > result) {
        result = n;
    }

    cout << result << '\n';

    return 0;
}