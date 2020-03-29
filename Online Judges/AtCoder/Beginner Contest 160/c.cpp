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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int k,n,i,j;
	scanf("%d %d",&k,&n);
	int a[200001];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int maxDiff = 0;
	for(i=0;i<n-1;i++){
		maxDiff = max(maxDiff, a[i+1] - a[i]);
	}
	int jarak = k - a[n-1];
	maxDiff = max(maxDiff, jarak + a[0]);
	printf("%d\n",k-maxDiff);
	return 0;
};