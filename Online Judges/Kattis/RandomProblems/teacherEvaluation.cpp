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
	int n,i,j;
	ll p;
	scanf("%d %lld",&n,&p);
	int sum = 0;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		sum += bil;
	}

	ll kiri = 0, kanan = 1e9, mid, ans = -1;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		ll butuhMinimal = p*(mid+n);
		ll total = mid*100LL + sum;
		if(total >= butuhMinimal){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	if(ans == -1){printf("impossible\n");}
	else{printf("%lld\n",ans);}

	return 0;
};