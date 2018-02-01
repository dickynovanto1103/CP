#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int gcd(int a, int b){return b==0? a: gcd(b,a%b);}

int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        int cnt = 0,k,m;
        int batas = (int)sqrt(n / 2);
        for (m=2; m<=batas;m++) {
            if ((n/2)%m==0) {
                if (m%2==0) {k = m + 1;}
                else {k = m + 2;}
                while (k < 2 * m && k <= n / (2 * m)) {
                     if (n / (2 * m) % k == 0 && gcd(k, m) == 1){cnt++;}
                     k+=2;
                 }
             }
         }
         printf("%d\n",cnt);    
    }
    
    return 0;
}

