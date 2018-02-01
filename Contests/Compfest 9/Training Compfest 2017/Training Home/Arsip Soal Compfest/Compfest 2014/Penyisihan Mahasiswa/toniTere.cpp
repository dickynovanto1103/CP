#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef unsigned long long uint64;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	uint64 a,b;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%llu %llu",&a,&b);
		//printf("a: %llu b: %llu\n",a,b);
		uint64 selisih = (uint64)abs(a-b);
		//printf("selisih: %llu\n",selisih);
		/*if(selisih<2){printf("Voting Ulang\n");}
		else{
			if(a>b){printf("Tere\n");}
			else{printf("Toni\n");}
		}*/
		/*if(a>b){
			if(a>=b+2){printf("Tere\n");}
			else{printf("Voting Ulang\n");}
		}else{
			if(b>=a+2){printf("Toni\n");}
			else{printf("Voting Ulang\n");}
		}*/
		if(a>b){
			if(a-b>=2){printf("Tere\n");}
			else{printf("Voting Ulang\n");}
		}else{
			if(b-a>=2){printf("Toni\n");}
			else{printf("Voting Ulang\n");}
		}
	}
	return 0;
}