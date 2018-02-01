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
	int n,a,b,i;
	scanf("%d %d %d",&n,&a,&b);
	for(i=0;;i++){
		ll hasil1 = a*i;
		if(hasil1>n){break;}
		ll sisa = n-hasil1;

		if(sisa%b==0){
			int ans1 = i;
			int ans2 = sisa/b;
			printf("YES\n");
			printf("%d %d\n",ans1,ans2);
			return 0;
		}

		ll hasil2 = b*i;
		if(hasil2>n){break;}
		ll sisa2 = n-hasil2;

		if(sisa2%a==0){
			int ans2 = i;
			int ans1 = sisa2/a;
			printf("YES\n");
			printf("%d %d\n",ans1,ans2);
			return 0;
		}
	}
	printf("NO\n");
	// int gcd = __gcd(a,b);
	// if(__gcd(gcd,n)==1){
	// 	if(n==1 || gcd==1){
	// 		printf("YES\n");
	// 		for(i=0;;i++){
	// 			ll hasil1 = a*i;
	// 			if(hasil1>n){break;}
	// 			ll sisa = n-hasil1;

	// 			if(sisa%b==0){
	// 				int ans1 = i;
	// 				int ans2 = sisa/b;
	// 				printf("%d %d\n",ans1,ans2);
	// 				return 0;
	// 			}

	// 			ll hasil2 = b*i;
	// 			if(hasil2>n){break;}
	// 			ll sisa2 = n-hasil2;

	// 			if(sisa2%a==0){
	// 				int ans2 = i;
	// 				int ans1 = sisa2/a;
	// 				printf("%d %d\n",ans1,ans2);
	// 				return 0;
	// 			}
	// 		}
	// 	}else{
	// 		printf("NO\n");
	// 	}
	// }else{
	// 	printf("YES\n");
	// 	for(i=0;;i++){
	// 		ll hasil1 = a*i;
	// 		if(hasil1>n){break;}
	// 		ll sisa = n-hasil1;

	// 		if(sisa%b==0){
	// 			int ans1 = i;
	// 			int ans2 = sisa/b;
	// 			printf("%d %d\n",ans1,ans2);
	// 			return 0;
	// 		}

	// 		ll hasil2 = b*i;
	// 		if(hasil2>n){break;}
	// 		ll sisa2 = n-hasil2;

	// 		if(sisa2%a==0){
	// 			int ans2 = i;
	// 			int ans1 = sisa2/a;
	// 			printf("%d %d\n",ans1,ans2);
	// 			return 0;
	// 		}
	// 	}

	// }
	return 0;
};