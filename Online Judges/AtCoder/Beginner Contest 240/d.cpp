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
	int n,i,j;
	scanf("%d",&n);
	int num = 0;
	vii v;
	while(n--){
		int bil;
		scanf("%d",&bil);
		if(v.size() == 0) {
			v.pb(ii(bil, 1));
			num++;
		}else{
			ii back = v.back();
			int angka = back.first, freq = back.second;
			if(angka == bil) {
				v.pop_back();
				v.pb(ii(bil, freq + 1));
				num++;
				if(bil == freq + 1) {
					v.pop_back();
					num -= bil;
				}
			}else{
				v.pb(ii(bil, 1));
				num++;
			}
		}

		printf("%d\n", num);
	}
	
	return 0;
};