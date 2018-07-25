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

const int maxn = 1e4 + 4;
int a[maxn];

int main(){
	int n,m,i,j;
	scanf("%d",&n);
	
	int counter[20010];
	memset(counter,0,sizeof counter);

	for(i=0;i<n;i++){scanf("%d",&a[i]); counter[a[i]]++;}
	sort(a,a+n);
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",a[i]);
	// }
	// printf("\n");
	scanf("%d",&m);
	int banyakMinim = n/m;
	int banyakMaks = banyakMinim;
	int sisaMaks = n%m;

	int sisaMinim = n - sisaMaks;

	if(n%m != 0){banyakMaks++;}
	int teralokasiMaks = banyakMaks*sisaMaks;
	int teralokasiMinim = n - teralokasiMaks;
	sisaMinim = teralokasiMinim / banyakMinim;
	// printf("banyakMaks: %d banyakMinim: %d sisaMaks: %d sisaMinim: %d\n",banyakMaks, banyakMinim, sisaMaks, sisaMinim);
	

	for(i=0;i<(1<<m);i++){
		// printf("i: %d\n",i);
		int cntMaks = 0, cntMinim = 0;
		vi urutan;
		vi ans;
		for(j=0;j<m;j++){
			if((1<<j) & i){
				cntMaks++;
				urutan.pb(1);
			}else{
				cntMinim++;
				urutan.pb(0);
			}
		}
		int start = -1;
		bool isValid = true;
		if(cntMaks == sisaMaks && cntMinim == sisaMinim) {
			//lgsg satu"
			// printf("cntMaks: %d cntMinim: %d\n",cntMaks, cntMinim);
			for(j=0;j<m;j++){
				if(urutan[j] == 1){
					start+=banyakMaks;
					if(a[start] == a[start+1]){
						isValid = false; break;
					}else{
						ans.pb(a[start] + 1);
					}
				}else{
					start+=banyakMinim;
					if(a[start] == a[start+1]){
						isValid = false; break;
					}else{
						ans.pb(a[start] + 1);
					}
				}
			}
			if(isValid){
				for(j=0;j<(ans.size()-1);j++){
					if(j){printf(" ");}
					printf("%d",ans[j]);
				}
				printf("\n");				
				return 0;
			}
		}
	}

	return 0;
};