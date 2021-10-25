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

vector<vi> a, banned;

void cetakRes(vi v) {
	for(int i=0;i<v.size();i++){
		if(i > 0){printf(" ");}
		printf("%d",v[i] + 1);
	}
	printf("\n");
}

int main(){
	int n,i,j,m;
	while(scanf("%d",&n)!= EOF) {
		a.resize(n);
		for(i=0;i<n;i++){
			int c;
			scanf("%d",&c);

			a[i].resize(c);
			for(j=0;j<c;j++){
				scanf("%d",&a[i][j]);
			}
		}

		scanf("%d",&m);
		banned.resize(m);
		for(i=0;i<m;i++){
			banned[i].resize(n);
			for(j=0;j<n;j++){
				scanf("%d",&banned[i][j]);
				banned[i][j]--;
			}
		}
		
		sort(banned.begin(), banned.end());
		//cek maks
		vi ult(n);
		for(i=0;i<n;i++){
			ult[i] = a[i].size() - 1;
		}
		if(!binary_search(banned.begin(), banned.end(), ult)) {
			cetakRes(ult);
			continue;
		}

		int mx = 0;
		vi ans;
		for(i=0;i<m;i++){
			int sum = 0;
			vi tmp = banned[i];
			for(j=0;j<n;j++){
				sum += a[j][tmp[j]];
			}

			for(j=0;j<n;j++){
				if(tmp[j] > 0) {
					tmp[j]--;
					int newVal = sum - a[j][tmp[j]+1] + a[j][tmp[j]];
					if(mx < newVal && !binary_search(banned.begin(), banned.end(), tmp)) {
						ans = tmp;
						mx = newVal;
					}
					tmp[j]++;
				}
			}
		}
		cetakRes(ans);
	}
	


	return 0;
};