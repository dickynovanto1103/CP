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
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[1001];
	while(tc--){
		int x;
		scanf("%d %d",&n,&x);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		ll selisihKecil = 0, selisihBesar = 0;
		int infected = 0;
		for(i=0;i<n;i++){
			if(a[i] < x) {
				selisihKecil += (x - a[i]);
			}else if(a[i] > x){
				selisihBesar += (a[i] - x);
			}else{
				infected++;
			}
		}
		if(selisihBesar == 0 && selisihKecil == 0){
			printf("0\n");
		}else if(selisihBesar == selisihKecil) {
			printf("1\n");
		}else{
			if(infected > 0){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}
	}
	
	return 0;
};