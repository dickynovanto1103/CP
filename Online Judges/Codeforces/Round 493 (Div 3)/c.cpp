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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	ll a[maxn];
	scanf("%d",&n);
	
	ll temp[maxn];
	for(i=0;i<n;i++){scanf("%lld",&a[i]); temp[i] = a[i];}
	ll duaPangkat[32];
	for(i=0;i<=31;i++){
		duaPangkat[i] = 1<<i;
		// if(duaPangkat[i] > 1e9){
		// 	break;
		// }
		// printf("duaPangkat: %lld\n",duaPangkat[i]);
		// printf("i: %d\n",i);
	}
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);

	sort(temp, temp + n);

	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%lld",temp[i]);
	// }
	// printf("\n");

	int cnt = 0;

	for(i=0;i<n;i++){
		ll bil = a[i];
		// printf("a[%d]: %lld\n",i,a[i]);
		// printf("bil: %lld\n",bil);
		for(j=0;j<=31;j++){
			ll diharapkan = duaPangkat[j];
			if(diharapkan <= bil){continue;}
			ll selisih = diharapkan - bil;
			int lowerBound = lower_bound(temp,temp+n,selisih) - temp;
			int upperBound = upper_bound(temp,temp+n,selisih) - temp - 1;
			// printf("lowerBound: %d upperBound: %d\n",lowerBound, upperBound);
			int banyakElemen = upperBound - lowerBound+1;
			// printf("diharapkan: %lld\n",diharapkan);
			if(banyakElemen>1){
				if(isVisited[lowerBound]){continue;}
				else{
					// printf("bil: %lld diharapkan: %lld selisih: %lld\n",bil,diharapkan,selisih);
					// printf("banyakElemen: %d lowerBound: %d upperBound: %d\n",banyakElemen, lowerBound,upperBound);
					for(int k=lowerBound;k<=upperBound;k++){
						isVisited[k] = true;
					}
				}
			}else{
				if(banyakElemen==1){
					if(selisih != bil){
						if(isVisited[lowerBound]){continue;}
						else{
							// printf("bil: %lld diharapkan: %lld selisih: %lld\n",bil,diharapkan,selisih);
							// printf("banyakElemen: %d lowerBound: %d upperBound: %d\n",banyakElemen, lowerBound,upperBound);
							for(int k=lowerBound;k<=upperBound;k++){
								isVisited[k] = true;
							}
						}
					}
				}
			}
		}
	}

	for(i=0;i<n;i++){
		if(!isVisited[i]){cnt++;}
	}

	printf("%d\n",cnt);


	return 0;
};