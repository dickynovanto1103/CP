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

bool isOdd(int n){
	while(n>0){
		int bil = n%10;
		if(bil != 0){
			if(bil%2==1){
				return true;
			}else{
				return false;
			}
		}
		n/=10;
	}
}

int main(){
	int n = 10000000;
	int i,j,cnt0 = 0, cnt1 = 0;
	int bil1,bil2;
	while(scanf("%d %d",&bil1,&bil2) != EOF){
		cnt0 = 0, cnt1 = 0;
		ll ans1, ans2;
		for(i=1;i<=bil2;i++){
			if(isOdd(i)){
				cnt1++;
			}else{
				cnt0++;
			}
			// if(i%100000 == 99999){
			
			// }
			if(i==bil2){
				printf("i: %d %d %d\n",i,cnt1,cnt0);		
			}
		}
		
		ans1 = cnt0;
		cnt0 = 0, cnt1 = 0;
		for(i=1;i<=(bil1-1);i++){
			if(isOdd(i)){
				cnt1++;
			}else{
				cnt0++;
			}
			// if(i%100000 == 99999){
			
			// }
			if(i==(bil1-1)){
				printf("i: %d %d %d\n",i,cnt1,cnt0);
			}
		}
		ans2 = cnt0;
		printf("%lld\n",ans1 - ans2);	
	}
	
	return 0;
};