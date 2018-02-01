#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,n,i,b[100010],a[100010];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&b[i]);}
		int maks = 0;
		for(i=0;i<n;i+=2){
			a[i] = b[i];
		}
		for(i=1;i<n;i+=2){
			a[i] = 1;
		}
		int sum = 0;
		for(i=0;i<n-1;i++){sum+=abs(a[i]-a[i+1]);}
		maks = max(maks,sum);
		for(i=0;i<n;i+=2){
			a[i] = 1;
		}
		for(i=1;i<n;i+=2){
			a[i] = b[i];
		}
		sum = 0;
		for(i=0;i<n-1;i++){sum+=abs(a[i]-a[i+1]);}
		maks = max(maks,sum);
		printf("%d\n",maks);
	}
	return 0;
}