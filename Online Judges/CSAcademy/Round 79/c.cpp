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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int main(){
    ll n,i,j;
    ll k;
    scanf("%lld %lld",&n,&k);
    ll jumlah[maxn];
    jumlah[0] = 0;
    for(i=1;i<maxn;i++){
        jumlah[i] = i;
    }

    if(n==2){
        if(k==0){printf("1 2\n");}
        else{printf("2 1\n");}
        return 0;
    }

    int a[maxn];
    for(i=0;i<n;i++){
        a[i] = i+1;
    }

    if(k==0){
        for(i=0;i<n;i++){
            if(i){printf(" ");}
            printf("%d",a[i]);
        }        
        printf("\n");
        return 0;
    }

    int idx = 1;
    int start = n-2;
    ll temp = k;
    while(temp>=jumlah[idx]) {
        temp-=jumlah[idx];
        if(temp==0){break;}

        idx++;
        if(temp < jumlah[idx]){break;}
        // printf("temp jd: %lld setelah dikurangi dengan jumlah[%d]: %lld idx sekarang: %d\n",temp,idx-1,jumlah[idx-1], idx);
        start--;
    }
    // printf("start: %d\n",start);
    reverse(a+start, a+n);
    // printf("temp: %lld\n",temp);
    //start working
    if(temp!=0){
        start--;
        int end = n-1;
        while(start<end){
            swap(a[start], a[end]);
            end--;
            temp--;
            if(temp == 0){break;}
        }
    }

    for(i=0;i<n;i++){
        if(i){printf(" ");}

        printf("%d",a[i]);
    }
    printf("\n");

    return 0;
};