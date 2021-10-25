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

const int maxn = 2e5;

int a[11][maxn + 1];
int cnt[11];
int banned[100010][11];

void printVector(vi v) {
	for(int i=0;i<v.size();i++) {
		if(i > 0) {printf(" ");}
		printf("%d",v[i] + 1);
	}
	printf("\n");
}

int main(){
	int n,i,j,m;
	while(scanf("%d",&n) != EOF) {
		for(i=0;i<n;i++){
			int banyak;
			scanf("%d",&banyak);
			cnt[i] = banyak;
			for(j=0;j<banyak;j++){
				scanf("%d",&a[i][j]);
			}
		}

		scanf("%d",&m);
		set<vi> s;
		set<vi>::iterator it;
		for(i=0;i<m;i++){
			vi v(n);
			for(j=0;j<n;j++) {
				int x;
				scanf("%d",&x);
				x--;
				v[j] = x;
				banned[i][j] = x;
			}
			s.insert(v);
		}

		//cek maks
		vi maks(n);
		int sum = 0;
		for(i=0;i<n;i++){
			int idx = cnt[i] - 1;
			sum += a[i][idx];
			maks[i] = idx;
		}

		if(s.find(maks) == s.end()) {
			printVector(maks);
			continue;
		}


		int nilaiMaks = 0;
		vi ansV(n);

		for(i=0;i<m;i++){
			vi v(n);
			int sum = 0;
			for(j=0;j<n;j++){
				v[j] = banned[i][j];
				sum += a[j][v[j]];
			}
			for(j=0;j<n;j++) {
				if(v[j] > 0) {
					// printf("i: %d v[%d]: %d\n", i,j,v[j]);
					sum -= a[j][v[j]];
					v[j]--;	
					sum += a[j][v[j]];
					if(sum > nilaiMaks && s.find(v) == s.end()) {
						nilaiMaks = sum;
						for(int k=0;k<n;k++) ansV[k] = v[k];
					}
					sum -= a[j][v[j]];
					v[j]++;
					sum += a[j][v[j]];
				}
			}
		}
		// printf("nilaiMaks: %d\n", nilaiMaks);

		assert(nilaiMaks > 0);
		assert(ansV.size() > 0);
		printVector(ansV);
	}
	

	
	return 0;
};