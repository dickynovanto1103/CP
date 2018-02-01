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
	int n,k;
	int a[300010],i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(k==1){printf("0\n"); return 0;}
	sort(a,a+n);
	int kiri = 0, kanan = a[n-1] - a[0], mid;
	int ans = 0;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		int counter = 0;
		int diff = 0, idxCur = 0;
		bool foundValid = true;
		// printf("kiri: %d kanan: %d\n",kiri,kanan);
		// printf("mid: %d\n",mid);
		for(i=0;i<n;i++){
			//printf("proses: %d\n",a[i]);
			if((a[i]-a[idxCur])<=mid) {
				// diff+=(a[i] - a[idxCur]);
				// printf("diff jd: %d\n",diff);
				diff = (a[i]-a[idxCur]);
				//printf("diff jd: %d\n",diff);
				counter++;
			}else{
				if(counter>=k){
					idxCur = i;
					i--;
					counter = 0;
					diff = 0;
				}else{
					//printf("pernah masuk\n");
					foundValid = false; break;
				}
			}

		}
		if(counter<k){foundValid = false;}
		if(diff>mid){foundValid}
		if(foundValid){
			printf("valid dengan mid: %d\n",mid);
			ans = mid;
			kanan = mid-1;
		}else{
			printf("ga valid\n");
			kiri = mid+1;
		}

	}
	printf("%d\n",ans);
	return 0;
};