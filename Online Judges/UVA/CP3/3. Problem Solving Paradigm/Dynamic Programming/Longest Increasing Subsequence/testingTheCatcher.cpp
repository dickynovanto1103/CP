#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define maxn 100000

int main() {
	int n,i,a[maxn], test=1;
	int L[maxn], L_id[maxn], P[maxn];
	int cnt, bil;
	while(1){

		scanf("%d",&bil);
		if(bil==-1){break;}
		if(test>1){printf("\n");}
		cnt = 0;
		a[cnt] = bil; cnt++;
		while(scanf("%d",&a[cnt]), a[cnt]!=-1){
			cnt++;
		}
		int lis = 0, lis_end = 0;
		reverse(a,a+cnt);
		
		for(i=0;i<cnt;i++){
			int pos = lower_bound(L,L+lis,a[i]) - L;
			L[pos] = a[i];
			L_id[pos] = i;
			P[i] = pos? L_id[pos-1] : -1;
			if(pos+1 > lis){
				lis = pos+1;
				lis_end = i;
			}
			//end of main LIS algo	
		}
		printf("Test #%d:\n",test++);
		printf("  maximum possible interceptions: %d\n", lis);
	}
	return 0;
}