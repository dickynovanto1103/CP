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

bool cmp(int a, int b) {
	return a > b;
}

int main(){
	//the pattern is n-1, n-2, n-2, n-3, n-3, n-4, n-4
	int tc,i,j,k,n;
	// scanf("%d",&tc);
	scanf("%d",&n);
	//jumlah tim
	vii v;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			v.pb(ii(i,j));
		}
	}
	int banyak = v.size();
	vi maksScore(n);
	printf("banyak: %d\n", banyak);
	for(j=0;j<(1<<banyak);j++){
		vi score(n);
		if(j % 100000 == 0) printf("j: %d\n", j); 
		for(int k=0;k<banyak;k++){
			int tim1 = v[k].first, tim2 = v[k].second;
			if((1<<k) & j) {
				score[tim1]+=2;
			}else{
				score[tim2]+=2;
			}
		}
		sort(score.begin(), score.end(), cmp);
		for(i=0;i<n;i++){
			maksScore[i] = max(maksScore[i], score[i]);
		}
	}

	for(int i=0;i<n;i++){
		printf("maksScore rank: %d is: %d\n", i+1, maksScore[i]);
	}
	
	
	return 0;
};