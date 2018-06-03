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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,n,k,a[10010],i,j;
	
	scanf("%d",&tc);
	while(tc--){
		vi ganjil, genap;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i%2==0){
				// printf("genap dipush: %d\n",a[i]);
				genap.pb(a[i]);
			}
			else{
				// printf("ganjil dipush: %d\n",a[i]);
				ganjil.pb(a[i]);
			}
		}
		sort(ganjil.begin(),ganjil.end());
		sort(genap.begin(), genap.end(), cmp);
		// printf("ganjil\n");
		// for(i=0;i<ganjil.size();i++){
		// 	if(i){printf(" ");}
		// 	printf("%d",ganjil[i]);
		// }
		// printf("\n");
		// printf("genap\n");
		// for(i=0;i<genap.size();i++){
		// 	if(i){printf(" ");}
		// 	printf("%d",genap[i]);
		// }
		// printf("\n");
		for(i=0;i<k;i++){
			if(i == ganjil.size() || i == genap.size()){break;}
			if(ganjil[i] < genap[i]){
				swap(genap[i], ganjil[i]);
			}else{break;}

		}
		int motu = 0, tomu = 0;
		for(i=0;i<ganjil.size();i++){
			tomu+=ganjil[i];
		}
		for(i=0;i<genap.size();i++){
			motu+=genap[i];
		}
		// printf("motu: %d tomu: %d\n",motu, tomu);
		if(tomu > motu){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}


	return 0;
};