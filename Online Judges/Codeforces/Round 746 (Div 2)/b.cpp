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

const int maxn = 1e5 + 5;

int a[maxn], sorted[maxn];
int can[maxn];

int main(){
	int tc,i,j,n,x;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&n,&x);
		for(i=0;i<n;i++){
			can[i] = false;
			scanf("%d",&a[i]);
			sorted[i] = a[i];
		}

		for(i=0;i<n;i++){
			if(i-x >= 0 || i+x <n){
				can[i] = true;
			}
		}

		sort(sorted, sorted + n);
		bool ans = true;
		for(i=0;i<n;i++){
			if(!can[i] && a[i] != sorted[i]){
				ans = false;
			}
		}
		ans ? printf("YES\n") : printf("NO\n");
	}
	
	return 0;
};