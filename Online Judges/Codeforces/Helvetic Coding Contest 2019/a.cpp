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
	ll r,i,j;
	scanf("%lld",&r);
	for(i=1;i<=1000000;i++){
		ll kons = i*i + i + 1;
		ll temp = r;
		temp -= kons;
		ll koef = 2LL*i;
		if(temp%koef == 0){
			temp /= koef;
			if(temp <= 0){continue;}
			printf("%lld %lld\n",i, temp);

			return 0;
		}


	}
	printf("NO\n");
	return 0;
};