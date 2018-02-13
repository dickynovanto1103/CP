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
	string kata;
	int counter[245];
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		memset(counter,0,sizeof counter);
		scanf("%d",&n);
		cin>>kata;
		for(i=0;i<n;i++){counter[kata[i]]++;}
		int maks = -1;
		for(i=97;i<=122;i++){
			maks = max(maks, counter[i]);
		}
		printf("%d\n",n-maks);
	}
	return 0;
};