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

const int maxn =1e5 + 5;

int main(){
	int n,q,i,j;
	int a[maxn];
	scanf("%d",&n);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);}
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(l==r){
			if(a[l]%2==0){printf("Even\n");}
			else{printf("Odd\n");}
		}else{
			if(a[l]%2==0){
				if(a[l+1]==0){printf("Odd\n");}
				else{printf("Even\n");}
			}else{
				printf("Odd\n");
			}
		}
	}
	return 0;
};