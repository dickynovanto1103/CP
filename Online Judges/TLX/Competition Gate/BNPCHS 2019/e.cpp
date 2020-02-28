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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		bool valid = false;
		for(i=1;i<=12000;i++){
			ll tot = (ll)i*(ll)(i+1)/2LL;
			if(tot >= n){
				// printf("i: %d\n",i);
				ll kurang = n-tot;
				if(kurang%2LL == 0){
					ll totNeed = -kurang/2LL;
					if(totNeed == 0){
						valid = true;
						printf("%d ",i);
						for(j=0;j<i;j++){printf("+");}
						printf("\n");
						break;
					}else{
						// printf("sini totNeed: %lld\n", totNeed);
						vi listIdx;
						int biggest = i;
						// printf("biggest: %d\n",biggest);
						while(totNeed >= 0) {
							// printf("totNeed: %lld biggest: %d\n",totNeed, biggest);
							if(totNeed > biggest){
								totNeed -= biggest;
								listIdx.pb(biggest);
								// printf("apa disini biggest: %d\n",biggest);
								biggest--;

							}else if(totNeed == biggest){
								totNeed = 0;
								listIdx.pb(biggest);
								// printf("push disini %d\n",biggest);
								biggest = 0;
							}else{
								biggest--;
							}
							if(biggest == 0){break;}
						}
						if(totNeed > 0){continue;}
						// reverse(listIdx.begin(), listIdx.end());
						int ukuran = listIdx.size();
						int idx = 0;
						valid = true;
						printf("%d ",i);
						for(j=i;j>=1;j--){
							if(idx < ukuran){
								if(listIdx[idx] == j){
									printf("-");
									idx++;
								}else{
									printf("+");
								}
							}else{
								printf("+");
							}
						}
						printf("\n");
						break;
					}
				}else{
					continue;
				}
			}
		}
		if(!valid){printf("-1\n");}
	}
	return 0;
};