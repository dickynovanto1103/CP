#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,tt,i,j;
	int n,k;
	int a[101];
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		int cnt = 0;
		while(true){
			//simulasi aja
			cnt++;
			for(i=0;i<n;i++){
				if(k>=a[i]){k-=a[i];}
				else{k=0;}
			}
			if(k==0){break;}
		}
		printf("%d\n",cnt);
	}
	return 0;
};