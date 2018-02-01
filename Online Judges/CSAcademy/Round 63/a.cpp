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

int main(){
	int n,m,i,j;
	int a[1010],b[1010];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}

	int cnt = 0;
	for(i=0;i<=m-n;i++){
		for(j=0;j<n;j++){
			//printf("i: %d j: %d\n",i,j);
			if((a[j]+b[i+j])!=1){break;}
		}
		if(j==n){
			//printf("sma\n");
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
};