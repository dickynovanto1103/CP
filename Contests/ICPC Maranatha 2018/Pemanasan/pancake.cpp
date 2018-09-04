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

const int maxn = 110;

int main(){
	int tc,i,j,n;
	int a[maxn], temp[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]); temp[i] = a[i];}
		sort(a,a+n);
		vi ans;
		// printf("tc: %d\n",tc);
		for(i=n-1;i>=1;i--){
			int harapan = a[i];
			if(temp[i] == harapan){continue;}
			//cari yang angka diharapkan di array temp
			// printf("i: %d harapan: %d\n",i,harapan);
			int idx;
			if(temp[0] == harapan){
				idx = n-1-(i) + 1;
				ans.pb(idx);
				reverse(temp,temp+i+1);
			}else{
				// printf("halo\n");
				for(j=1;j<i;j++){
					if(temp[j] == harapan){
						// printf("j sama: %d\n",j);
						idx = n-1-j + 1;
						ans.pb(idx);
						reverse(temp,temp+j+1);
						idx = n-1-(i) + 1;
						ans.pb(idx);
						reverse(temp,temp+i+1);		
						break;
					}
				}
			}
			// printf("idx: %d\n",idx);
			// printf("temp: ");
			// for(j=0;j<n;j++){
			// 	if(j){printf(" ");}
			// 	printf("%d",temp[j]);
			// }
			// printf("\n");
		}
		ans.pb(0);
		int ukuran = ans.size();
		for(i=0;i<ukuran;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
};