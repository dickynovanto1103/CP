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
int a[maxn];

int lis(int n )
{
    int i, j, max = 0;
    int lis[maxn];
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( a[i] > a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    return max;
}
int lds(int n )
{
    int i, j, max = 0;
    int lis[maxn];
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( a[i] < a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    return max;
}
vi listBil;

bool isSama(){
    for(int i=0;i<listBil.size();i++){
        int bil1 = listBil[i], bil2 = a[i];
        // printf("%d %d\n",bil1,bil2);
        if(listBil[i] != a[i]){return false;}
    }
    return true;
}

int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
     a[i] = i+1;
    }
    
    int tengah = n/2 + 1;
    for(i=tengah;i<=n;i++){
        listBil.pb(i);
        // printf("yang dipush: %d\n",i);
    }
    for(i=1;i<tengah;i++){
        listBil.pb(i);
        // printf("yang dipush: %d\n",i);
    }


    int minim = 1000000;
    do{
     
     int ansLIS = lis(n), ansLDS = lds(n);
     minim = min(minim, ansLIS + ansLDS);
    //  for(i=0;i<n;i++){
    //      printf("%d ",a[i]);
    // }
    // printf("//\n");
     if(ansLDS + ansLIS == 8){
        
            for(i=0;i<n;i++){
                 printf("%d ",a[i]);
            }
            printf(" ");
             
            printf("%d %d %d\n",ansLIS, ansLDS, ansLDS + ansLIS);       
            // break;
        
     }
     

    }while(next_permutation(a,a+n));
    printf("%d\n",minim);
    return 0;
};
