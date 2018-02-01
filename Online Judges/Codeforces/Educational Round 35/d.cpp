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

const int maxn = 1510;

int main(){
	int n,i,j;
	int a[maxn];
	int m,l,r;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int cnt = 0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){cnt++;}
		}
	}
	int status = cnt%2;

	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&l,&r);
		int banyak = (r-l +1)/2;
		if(banyak%2==1){
			status = 1-status;
		}
		if(status==0){printf("even\n");}
		else{printf("odd\n");}
	}
	return 0;
};