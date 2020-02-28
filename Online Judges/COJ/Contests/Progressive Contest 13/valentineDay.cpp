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

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		ll a,b,p[3];
		scanf("%lld %lld %lld %lld %lld",&a,&b,&p[0],&p[1],&p[2]);
		sort(p,p+3,cmp);
		if(a >= (p[0]+2*p[2]) && b >= 2*(p[1] + p[2])){
			printf("POSSIBLE\n");
			continue;
		}
		swap(a,b);
		if(a >= (p[0]+2*p[2]) && b >= 2*(p[1] + p[2])){
			printf("POSSIBLE\n");
		}else{
			printf("IMPOSSIBLE\n");
		}
		// if(luas >= exp){printf("POSSIBLE\n");}
		// else{printf("IMPOSSIBLE\n");}
	}
	return 0;
};