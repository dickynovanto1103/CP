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

vii pas;

const int maxn = 60;

ll a[maxn][maxn];
ll pref[maxn][maxn];

void genPas(){
	int i,j;
	a[1][1] = 1;
	a[2][1] = 1;
	a[2][2] = 1;
	for(i=3;i<maxn;i++){
		for(j=1;j<=i;j++){
			if(j == 1 || j == i){a[i][j] = 1;}
			else{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
			// printf("%lld ",a[i][j]);
			assert(a[i][j] >= a[i][j] && a[i][j] >= 0);
		}
		for(j=1;j<=i;j++){
			pref[i][j] = a[i][j];
			pref[i][j] += pref[i][j-1];
		}
		// printf("\n");
	}
}

int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	genPas();
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d:\n",tt);
		scanf("%d",&n);

		pas.clear();

		pas.pb(ii(1,1)); pas.pb(ii(2,1)); pas.pb(ii(2,2));
		if(n <= 3){
			for(i=0;i<n;i++){printf("%d %d\n",pas[i].first, pas[i].second);}
			continue;
		}
		ll sum = 3;
		ii last;
		last = ii(2,2);
		int dir = (last.first == last.second ? 0:1);//0 ke kiri, 1 ke kanan

		for(i=3;i<maxn-1;i++){
			if(sum == n){break;}
			if((sum + (1LL<<(i-1))) > n){
				if(dir == 0){

					int step = 0;
					int tahap;
					for(tahap = 1;tahap < i;tahap++){
						ll jum = sum;
						int idx = i;
						for(j=0;j<tahap;j++){
							jum += a[i][idx];
							jum += a[i+1][idx+1];
							idx--;
						}
						if(jum <= n){step = tahap;}
						else{break;}
					}
					if(step == 0){
						while(sum < n){
							sum++;
							last = ii(last.first+1, last.second+1);
							pas.pb(last);
						}
						break;
					}
					// printf("step: %d\n",step);
					int idx = i;
					for(j=1;j<=step;j++){
						sum += a[i][idx];
						// printf("sum jd: %lld %d %d\n",sum, i, idx);
						pas.pb(ii(i, idx));
						last = ii(i, idx);
						idx--;
					}
					idx+=2;
					for(j=1;j<=step;j++){
						sum += a[i+1][idx];
						// printf("sum jd: %lld %d %d\n",sum, i+1, idx);
						pas.pb(ii(i+1, idx));
						last = ii(i+1, idx);
						idx++;
					}
					i++;
					// printf("i nanti: %d sum: %lld\n",i+1, sum);
				}else{

					int step = 0;
					int tahap;
					for(tahap = 1;tahap < i;tahap++){
						ll jum = sum;
						int idx = 1;
						for(j=0;j<tahap;j++){
							jum += a[i][idx];
							jum += a[i+1][idx];
							idx++;
						}
						if(jum <= n){step = tahap;}
						else{break;}
					}
					if(step == 0){
						while(sum < n){
							sum++;
							assert(last.second == 1);
							last = ii(last.first+1, last.second);
							pas.pb(last);
						}
						break;
					}
					int idx = 1;
					for(j=1;j<=step;j++){
						sum += a[i][idx];
						pas.pb(ii(i, idx));
						last = ii(i, idx);
						idx++;
					}
					idx = step;
					for(j=1;j<=step;j++){
						sum += a[i+1][idx];
						pas.pb(ii(i+1, idx));
						last = ii(i+1, idx);
						idx--;
					}
					i++;
				}
			}else{
				if(dir == 0){
					last = ii(last.first + 1, last.second + 1);
					pas.pb(last);
					sum += a[last.first][last.second];
					for(j=last.second-1;j>=1;j--){
						sum += a[last.first][j];
						last = ii(last.first, j);
						pas.pb(last);
					}
					
				}else{
					last = ii(last.first+1, last.second);
					pas.pb(last);
					sum += a[last.first][last.second];
					for(j=last.second+1;j<=last.first;j++){
						sum += a[last.first][j];
						last = ii(last.first, j);
						pas.pb(last);
					}
				}

				dir = 1 - dir;
			}
		}

		assert(pas.size() <= 500);
		for(i=0;i<pas.size();i++){
			printf("%d %d\n",pas[i].first, pas[i].second);
		}
	}
	return 0;
};