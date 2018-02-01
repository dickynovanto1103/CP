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
	int i,j,n;
	cin>>kata;
	n = kata.length();
	kata = "s" + kata;
	
	int a[n+1], b[n+1];
	memset(a,0,sizeof a); memset(b,0,sizeof b);
	for(i=1;i<=n;i++){
		a[i] = a[i-1]; b[i] = b[i-1];
		if(kata[i]=='a'){a[i]++;}
		else{b[i]++;}
	}
	int ans = 0;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			int jawab = a[i] + b[j] - b[i-1] + a[n] - a[j];
			//printf("jawab: %d\n",jawab);
			ans = max(ans,jawab);
		}
		
	}
	printf("%d\n",ans);
	return 0;
};