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
	int n,i,j;
	int a[200001];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	ll tot = 0;
	for(i=1;i<n;i++){
		if(a[i] < a[i-1]){
			int diff = (a[i-1] - a[i]);
			tot += (a[i-1] - a[i]);
			a[i] += diff;
		}
	}
	printf("%lld\n",tot);
	
	return 0;
};