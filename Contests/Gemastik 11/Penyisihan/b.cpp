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
		int a[1011];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int k;
		int lower[1010], upper[1010];
		memset(lower, 0, sizeof lower); memset(upper, 0, sizeof upper);
		for(i=0;i<n;i++){
			int counter = 0;
			for(j=i+1;j<n;j++){
				if(a[j] < a[i]){lower[i]++;}
				else{upper[i]++;}
			}
		}
		ll cnt = 0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[j] > a[i]){
					cnt += lower[j];
				}else{
					cnt += upper[j];
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
};