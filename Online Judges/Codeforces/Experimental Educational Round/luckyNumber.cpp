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

ll power(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b%2==1){
			return a*power(a,b-1);
		}else{
			ll temp = power(a,b/2);
			return temp*temp;
		}
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	ll sum = 0;
	for(i=1;i<=n;i++){
		sum += power(2,i);
	}
	printf("%lld\n",sum);
	return 0;
};