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

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int tc,i,j;
	int n;
	int a[101];
	scanf("%d",&tc);
	int l[101];
	while(tc--){
		scanf("%d",&n);
		int sum = 0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}

		vi bisa;
		for(i=0;i<n;i++){
			scanf("%d",&l[i]);
			if(!l[i]){
				bisa.pb(a[i]);
			}
		}

		if(sum < 0){
			sort(bisa.begin(), bisa.end());
			int idx = 0;
			for(i=0;i<n;i++){
				if(!l[i]){
					a[i] = bisa[idx++];
				}
			}
		}else{
			sort(bisa.begin(), bisa.end(), cmp);
			int idx = 0;
			for(i=0;i<n;i++){
				if(!l[i]){
					a[i] = bisa[idx++];
				}
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");

	}
	
	return 0;
};