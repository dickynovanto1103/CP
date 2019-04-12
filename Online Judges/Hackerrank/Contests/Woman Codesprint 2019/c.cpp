#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e3 + 3;

int main(){
    int tc,i,j,n;
    int a[maxn];
    scanf("%d",&tc);
    bool isEven[55];
    
    while(tc--){
        scanf("%d",&n);
        for(i=0;i<n;i++){scanf("%d",&a[i]);}
        int ans = 0;
        for(i=0;i<n;i++){
            memset(isEven, true, sizeof isEven);
            int cntGenap = 50, cntGanjil = 0;
            for(j=i;j<n;j++){
                int banyak = j-i + 1;
                isEven[a[j]] = (isEven[a[j]] ? false : true);
                if(isEven[a[j]]){cntGanjil--; cntGenap++;}
                else{cntGanjil++; cntGenap--;}
                if(banyak&1){//ganjil
                    // printf("i: %d j: %d\n",i,j);
                    if(cntGanjil == 1){
                        ans++;
                    }
                }else{
                    if(cntGanjil == 0){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
};