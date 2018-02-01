#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool foundAns;
ll temp;

void solve(ll a, ll ans){
	if(a==1){temp = min(ans,temp); return;}
	else if(a==2){solve(a-1,ans+1);}
	else{
		if(a%3==0){solve(a/3,ans+1);}
		else{
			if(a%3==1){solve(a-1, ans+1);}
			else if(a%3==2){solve(a+1,ans+1);}
		}	
	}
	
}

int main() {
	ll a;
	ll bil = 1;
	scanf("%lld",&a);
	temp = 1000000000;
	solve(a,0);
	printf("%lld\n",temp);
	return 0;
}