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

int a[200011];

int main(){
	int tc,i,j;
	int h,n;
	scanf("%d",&tc);
	
	while(tc--){
		scanf("%d %d",&h,&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		a[n] = 0;
		int ans = 0;
		int state = -1;
		for(i=0;i<n;i++){
			if(a[i] - 1 > a[i+1]){
				a[i] = a[i+1]+1;
				// printf("di %d a[%d] jd: %d\n",i,i,a[i]);
				i--;
			}else{
				if(a[i+1] - 1 > a[i+2]) {
					a[i+1] = a[i+1]-1;
					ans++;
					// printf("ditambah di i: %d a[%d]: %d\n",i, i+1, a[i+1]);
				}else{
					i++;
				}
			}
		}
		printf("%d\n",ans);
		for(i=0;i<n;i++){
			a[i] = 0;
		}
	}
	
	return 0;
};