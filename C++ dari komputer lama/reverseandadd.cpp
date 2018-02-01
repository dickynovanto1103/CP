#include <cstdio>

using namespace std;
typedef long long ll;
ll rev;
bool ispalindrome(ll ans){
	ll temp = ans;
	rev=0;
	while(ans>0){
		rev=rev*10 + ans%10;
		ans/=10;
	}
	//printf("rev: %lld\n",rev);
	return (rev == temp);
}
int main(){
	int n,i,bil,cnt;
	ll sum;

	scanf("%d",&n);
	while(n--){
		cnt=0;
		scanf("%d",&bil);
		sum=bil;
		while(!ispalindrome(sum)){
			sum+=rev;
			cnt++;
		}
		printf("%d %lld\n",cnt,sum);
	}
	return 0;
}