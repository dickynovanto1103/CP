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

void printArray(int n, int a[]){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[101];
	for(int tt=1;tt<=tc;tt++) {
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int ans = 0;
		for(i=0;i<n-1;i++){
			int minim = a[i], minIdx = i;
			for(j=i;j<n;j++){
				if(minim > a[j]) {
					minim = a[j];
					minIdx = j;
				}
			}
			ans += (minIdx - i + 1);
			reverse(a+i, a+minIdx+1);
			// printArray(n, a);
		}
		printf("%d\n", ans);
	}
	
	return 0;
};