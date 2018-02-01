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

const int maxn = 1e5 + 5;
int maks[maxn];

int main(){
	int i,j,n;
	int a[maxn];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	maks[n-1] = a[n-1];
	for(i=n-2;i>=0;i--){
		maks[i] = max(a[i],maks[i+1]);
	}
	for(i=0;i<n-1;i++){
		int ans = maks[i+1] - a[i] + 1;
		if(ans<0){ans = 0;}
		printf("%d ",ans);
	}
	printf("0\n");
	return 0;
};