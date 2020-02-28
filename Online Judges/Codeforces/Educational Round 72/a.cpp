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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);

		if(a + c > b){
			int kiri = 0, kanan = c, mid, ans;
			while(kiri <= kanan) {
				mid = (kiri+kanan)/2;
				int sisa = c - mid;
				if(a + mid > sisa + b){
					ans = mid;
					kanan = mid-1;
				}else{
					kiri = mid + 1;
				}
			}
			printf("%d\n",c - ans + 1);
		}else{
			printf("0\n");
		}
	}
	return 0;
};