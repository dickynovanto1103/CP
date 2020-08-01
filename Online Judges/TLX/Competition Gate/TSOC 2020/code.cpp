#include <cstdio>
 
const int MOD = 1e9 + 7;

int k(int x) {
    x %= MOD;
    if(x < 0){x += MOD;}
    return x;
}

int j(int x, int y) {
    int z = y;
    z -= x;
    z = k(z);
    
    return z;
}

int i(int x, int y) {
    int z = y;
    z += x;
    z %= MOD;
    
    return z;
}

int h(int x, int y) {
    int z = 0;
    long long res = ((long long)x*(long long)y);
    res %= MOD;
    z = res;
    return z;
}

int g(int x, int y, int z) {
    int w = 0;
    w = h(x, y);
    w = i(h(y, y), w);
    w = j(h(i(x, y), z), w);
    return w;
}

int f(int x, int y) {
    int z = 0;
    
    while (x--){
        z = g(z, x, y);
        printf("x: %d\n",x);
        printf("z: %d\n",z);
    }
    return z;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", f(n, m));
    }
    return 0;
}
