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
	int tc,i,j;
	int n;
	scanf("%d",&tc);

	int a[100001];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		sort(a,a+n);
		int tengah = (n-1)/2;
		int kiri = tengah, kanan = tengah;
		if(n % 2 == 0){
			kanan++;
		}
		vi ans;
		while(kanan < n){
			if(kiri == kanan){
				ans.pb(a[kiri]);
			}else{
				ans.pb(a[kiri]);
				ans.pb(a[kanan]);
			}
			kiri--;
			kanan++;
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
};