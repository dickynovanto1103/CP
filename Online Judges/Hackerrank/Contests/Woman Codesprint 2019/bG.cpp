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

int a[] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};

bool isPalindrome(int n){
    int tail = n-1;
    int i;
    for(i=0;i<n;i++){
        if(i > tail){break;}
        if(a[i] != a[tail]){return false;}
        tail--;
    }
    return true;
}

int main(){
    int tc,i,j,n;
    n = sizeof(a) / sizeof(a[0]);
    // printf("n: %d\n",n);
    // scanf("%d",&tc);
    do{
        if(isPalindrome(n)){
            for(i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
        }
    }while(next_permutation(a,a+n));
    return 0;
};