#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double PI = acos(-1);

void printArray(int *arr, int n){
    for(int i=0;i<n;++i)
        printf("%d ", arr[i]);
    puts("");
}

int n,i,j,k,t;
int m;
int c[100002];
int p[100002];

bool coba(ll day){
    ll res = 0;
    for(int i=0;i<n;++i){
        ll tmp = 1LL*day*p[i] - c[i];
        if(res <= 0){continue;}

        res += tmp;
        if(res >= m){return true;}
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i)
        scanf("%d %d", p+i, c+i);
    ll l = 1, r = 2e9 + 2, ans;
    while(l <= r){
        printf("l: %lld r: %lld\n",l,r);
        int mid = (l+r)/2;
        if(coba(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        
    }
    printf("%lld\n", ans);
    return 0;
}