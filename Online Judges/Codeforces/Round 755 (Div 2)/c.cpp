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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[101], b[101];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		bool valid = true;
		for(i=0;i<n;i++){
			if(a[i] > b[n-1]){
				valid =false;
			}
			if(b[i] < a[0]){
				valid = false;
			}
			int selisih = b[i] - a[i];
			if(selisih == 0 || selisih == 1){

			}else{
				valid = false;
			}
		}
		valid ? puts("YES"):puts("NO");
	}
	
	return 0;
};