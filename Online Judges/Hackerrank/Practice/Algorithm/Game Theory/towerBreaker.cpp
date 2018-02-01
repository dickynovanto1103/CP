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
	int tc,n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		if(n%2==0){
			printf("2\n");
		}else{
			if(m==1){printf("2\n");}
			else{printf("1\n");}
		}
	}
	return 0;
};