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

ll memo[20][300021];
int n;
ll sd,sm;

ll p[20],l[20],k[20];

ll solve(int id, ll stamina){
	if(id==n-1){
		//printf("stamina: %lld\n",stamina);
		if(stamina<sm){return inf;}
		else{return 0;}
	}
	if(stamina<p[id]){return inf;}
	else{
		if(memo[id][stamina]!=-1){return memo[id][stamina];}
		return memo[id][stamina] = min(k[id] + solve(id+1,stamina), l[id] + solve(id+1,stamina+1));
	}
}

int main() {
	string dummy;
	cin>>dummy;
	
	int i;
	scanf("%d %lld %lld",&n,&sd,&sm);
	/*printf("dummy: "); cout<<dummy<<endl;
	printf("n: %d sd: %d sm: %d\n",n,sd,sm);*/
	for(i=0;i<n-1;i++){
		scanf("%lld %lld %lld",&p[i],&k[i],&l[i]);
	}
	//printf("test\n");
	memset(memo,-1,sizeof memo);
	ll ans  = solve(0,sd);
	if(ans>=(ll)inf){printf("-1\n");}
	else{printf("%lld\n",ans);}
	
	return 0;
}