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

ll memo[30010], dist[90010];
int target;

ll solve(int a){
	if(a>30000 || a<1){return inf;}
	if(a==target){return 0;}
	if(memo[a]!=-1){return memo[a];}
	ll i,b=inf,c=inf,d=inf,e=inf,f=inf,g=inf;
	for(i=0;i<6;i++){
		if(i==0){
			if(dist[a+1]!=inf){
				b = 1+solve(a+1);
				dist[a+1] = min(dist[a+1],b);
			}
			
		}
		else if(i==1){
			if(dist[a-1]!=inf){
				c = 1+solve(a-1);
				dist[a-1] = min(dist[a-1],c);
			}
			
		}
		else if(i==2){
			if(dist[a*2]!=inf){
				d = 2+solve(a*2);
				dist[a*2] = min(dist[a*2],d);
			}
			
		}
		else if(i==3 && a%2==0){
			if(dist[a/2]!=inf){
				e = 2+solve(a/2);
				dist[a/2] = min(dist[a/2],e);
			}
			
		}
		else if(i==4){
			if(dist[a*3]!=inf){
				f = 3 + solve(a*3);
				dist[a*3] = min(dist[a*3], f);
			}
			
		}
		else if(i==5 && a%3==0){
			if(dist[a/3]!=inf){
				g = 3+solve(a/3);
				dist[a/3] = min(dist[a/3], g);
			}
			
		}
	}
	memo[a] = min(dist[a+1],min(dist[a-1],min(dist[a*2],min(dist[a/2],min(dist[a*3],dist[a/3])))));
}

int main() {
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		int a;
		scanf("%d %d",&a,&target);
		memset(memo,-1,sizeof memo);
		for(i=0;i<90010;i++){dist[i]=inf;}
		dist[a] = 0;
		ll ans = solve(a);
		printf("%lld\n",ans);
	}
	return 0;
}