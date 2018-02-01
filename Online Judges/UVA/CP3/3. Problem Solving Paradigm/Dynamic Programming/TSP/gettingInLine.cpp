#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,x[10],y[10],test=1;
	double jarak[10];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%d %d",&x[i],&y[i]);}
		//permutasi
		printf("**********************************************************\n");
		printf("Network #%d\n",test++);
		int listidx[10], listidxans[10];
		double listjarak[10],temp[10], maks = inf;
		for(i=0;i<n;i++){listidx[i] = i;}
		double total;
		do{
			total = 0;
			/*for(i=0;i<n;i++){
				printf(" %d",listidx[i]);
			}
			printf("\n");*/
			for(i=1;i<n;i++){
				int idx = listidx[i];
				int prev = listidx[i-1];
				temp[i] = hypot(x[idx]-x[prev], y[idx]-y[prev])+16.0; total+=temp[i];
				//printf("jarak antara (%d,%d),(%d,%d) = temp[%d]: %.2lf total: %.2lf\n",x[prev],y[prev],x[idx],y[idx],i,temp[i],total);
			}
			//printf("total: %.2lf\n",total);
			if(maks-total>eps){
				maks = total;
				//catat jaraknya dan idxnya
				//printf("maks: %.2lf\n",maks);
				//printf("idx yang dicatat:");
				for(i=0;i<n;i++){
					//int idx = listidx[i];
					//printf(" %d", listidx[i]);
					listidxans[i] = listidx[i]; listjarak[i] = temp[i];
				}
				//printf("\n");
			}
		}while(next_permutation(listidx,listidx+n));
		//listidxans[0] = 0;
		for(i=1;i<n;i++){
			int idx = listidxans[i-1];
			int nxt = listidxans[i];
			//printf("idx: %d nxt: %d\n",idx,nxt);
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",x[idx],y[idx],x[nxt],y[nxt],listjarak[i]);
		}
		printf("Number of feet of cable required is %.2lf.\n",maks);
		
	}
	return 0;
}