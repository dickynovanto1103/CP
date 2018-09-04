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
	scanf("%d",&n);
	if(n<=3){
		printf("NO\n");
	}else{
		printf("YES\n");
		if(n%2==0){
			printf("4 * 3 = 12\n");
			printf("12 * 2 = 24\n");
			printf("24 * 1 = 24\n");
			int sisa = n-4;
			vi list1;
			for(i=n;i>4;i-=2){
				printf("%d - %d = 1\n",i,i-1);
				list1.pb(1);
			}
			for(i=0;i<list1.size();i++){
				printf("24 * 1 = 24\n");
			}
		}else{
			printf("5 - 1 = 4\n");
			printf("4 - 2 = 2\n");
			printf("4 * 3 = 12\n");
			printf("12 * 2 = 24\n");
			int sisa = n-5;
			vi list1;
			for(i=n;i>5;i-=2){
				printf("%d - %d = 1\n",i,i-1);
				list1.pb(1);
			}
			for(i=0;i<list1.size();i++){
				printf("24 * 1 = 24\n");
			}
		}
	}
	return 0;
};