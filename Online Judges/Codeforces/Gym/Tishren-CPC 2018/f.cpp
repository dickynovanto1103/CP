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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int sor = 0;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			sor ^= bil;
		}
		if(sor == 0){printf("1\n");}
		else{printf("0\n");}
	}
	return 0;
};