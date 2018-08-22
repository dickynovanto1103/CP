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
	int arr[16];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int ans[2];
	ans[0] = ans[1] = 0;
	int idx = 0;
	for(i=n-1;i>=0;i--){
		ans[idx]+=arr[i];
		idx++;
		idx%=2;
	}
	printf("%d %d\n",ans[0],ans[1]);
	return 0;
};