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
	int n,i,j;
	scanf("%d",&n);
	int a[maxn], b[maxn];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&b[i]);}

	sort(a,a+n); sort(b,b+n);

	int idx1 = n-1, idx2 = n-1;
	bool aTurn = true;
	ll sum1 = 0, sum2 = 0;
	while(!(idx1 == -1 && idx2 == -1)){
		// printf("idx1: %d idx2: %d\n",idx1,idx2);
		if(aTurn){
			if(idx1 == -1){
				idx2--;
			}else{
				if(idx2 == -1){
					sum1 += a[idx1];
					// printf("diambil1\n");
					idx1--;
				}else{
					if(a[idx1] > b[idx2]){
						sum1 += a[idx1];
						// printf("diambil1\n");
						// printf("sum1 jadi: %lld\n",sum1);
						idx1--;
					}else{
						idx2--;
					}	
				}
				
			}
			aTurn = false;
		}else{
			if(idx2 == -1){
				idx1--;
			}else{
				if(idx1 == -1){
					sum2 += b[idx2];
					// printf("diambil2\n");
					idx2--;
				}else{
					if(b[idx2] > a[idx1]){
						sum2 += b[idx2];
						// printf("diambil2\n");
						idx2--;
					}else{
						idx1--;
					}
				}
			}
			aTurn = true;
		}
	}
	printf("%lld\n",sum1-sum2);
	return 0;
};