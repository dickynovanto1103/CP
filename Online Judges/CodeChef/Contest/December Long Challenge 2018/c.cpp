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
	int n,c;
	scanf("%d %d",&n,&c);
	int kiri = 1, ans = 0;
	int cur = kiri;
	while(1){
		printf("1 %d\n",kiri);
		fflush(stdout);
		scanf("%d",&ans);
		if(ans==1){
			break;
		}else{
			cur = kiri;
			kiri += 500;	
			if(kiri > n){break;}
		}
		
	}
	if(ans == 1){
		printf("2\n");
		fflush(stdout);
	}
	for(int i=cur;i<=kiri;i++){
		printf("1 %d\n",i);
		fflush(stdout);
		scanf("%d",&ans);
		if(ans == 1){printf("3 %d\n",i); fflush(stdout); return 0;}
	}
	
	return 0;
};