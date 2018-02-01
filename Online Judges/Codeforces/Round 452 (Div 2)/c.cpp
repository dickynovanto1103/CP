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
	ll n;
	ll sum1 = 0, sum2 = 0;
	int i;
	vi list1, list2;
	scanf("%lld",&n);
	for(i=n;i>=1;i--){
		if(sum1>sum2){
			list2.pb(i);
			sum2+=(ll)i;
		}else{
			list1.pb(i);
			sum1+=(ll)i;
		}
	}
	printf("%lld\n",abs(sum1-sum2));
	printf("%d",(int)list1.size());
	for(i=0;i<list1.size();i++){
		
		printf(" %d",list1[i]);
	}
	printf("\n");
	return 0;
};