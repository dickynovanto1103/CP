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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int a,b;
		scanf("%d %d",&a,&b);
		int n;
		scanf("%d",&n);
		int kiri = a+1, kanan = b, mid;
		while(kiri <= kanan) {
			mid = (kiri + kanan)/2;
			printf("%d\n",mid);
			// fflush(stdout);
			string kata;
			cin>>kata;
			if(kata[4] == 'S'){
				kiri = mid+1;
			}else if(kata[4] == 'B'){
				kanan = mid-1;
			}else if(kata[0] == 'C'){
				break;
			}else{
				return 0;
			}
		}
	}
	return 0;
};