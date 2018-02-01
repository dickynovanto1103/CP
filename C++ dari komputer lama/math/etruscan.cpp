#include <bits/stdc++.h>

using namespace std;
#define maxn 1000000000000000000
typedef long long ll;
vector <ll> a;

int main(){
	int tc;
	ll n,total,i;
	double ans1,ans2;
	//for(i=0;i<a.size();i++){printf("%lld\n",a[i]);}
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&n);
		//if(n==0){printf("0\n");}
		ans1=(-1+sqrt(1+8*n))/2;	
		printf("%lld\n",(ll)floor(ans1));
	}
	return 0;
}
