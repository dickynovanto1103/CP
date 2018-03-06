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
	int tc;
	ll i,j,x;
	// for(i=1;;i++){
	// 	if(i*i>inf){break;}
	// 	int bil = i*i;
	// 	for(j=1;j*j<=bil;j++){
	// 		if((i/j)<=1){break;}
	// 		mapper[bil-j*j] = ii(i,i/j);
	// 		printf("j: %d\n",j);
	// 	}
	// }
	ll listBil[100000];
	for(i=0;;i++){
		listBil[i] = i*i;
		if(listBil[i]>(3LL*(ll)inf)){break;}
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&x);
		if(x==0){printf("1 1\n"); continue;}
		bool found = false;
		ll idxStart = lower_bound(listBil,listBil+100000,x)-listBil;
		idxStart--;
		int counter = 0;
		ll start = listBil[idxStart];
		// printf("start: %lld\n",start);
		while(start<=(2LL*(ll)inf)){
			if(counter==6){break;}
			ll bil = start;
			ll last = 0;
			for(j=1;j*j<=bil;j++){
				if((idxStart/j)<=1){break;}
				last = bil-j*j;
				if(last==x){printf("%lld %lld\n",idxStart,j); found = true; break;}
			}
			if(found){break;}
			// break;
			// if(last>x){found = false;break;}
			//if((idxStart*idxStart)>((ll)inf*2LL)){break;}
			idxStart++;
			counter++;
			start = idxStart*idxStart;

		}
		// for(i=start;;i++){
		// 	int bil = i*i;
			
		// }
		if(!found){printf("-1\n");}

	}
	return 0;
};