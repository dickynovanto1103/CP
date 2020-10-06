//WA for the counter case of:
// 1 1 2
// 30
// 30
// 20 20
// greedy will pick 2 biggest number only: 30 * 30 = 900, meanwhile we can do: 30 * 20 + 30 * 20 = 1200

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

bool cmp(ii a, ii b) {
	return a.first > b.first;
}

int main(){
	int r,g,b,i,j;
	while(scanf("%d %d %d",&r,&g,&b) != EOF) {
		priority_queue<int> pq[3];

		for(i=0;i<r;i++){
			int bil;
			scanf("%d",&bil);
			pq[0].push(bil);
		}
		for(i=0;i<g;i++){
			int bil;
			scanf("%d",&bil);
			pq[1].push(bil);
		}
		for(i=0;i<b;i++){
			int bil;
			scanf("%d",&bil);
			pq[2].push(bil);	
		}

		
		ll ans = 0;
		while(true) {
			vii listBil;

			for(i=0;i<3;i++){
				if(pq[i].size()){
					listBil.pb(ii(pq[i].top(), i));
				}
			}

			sort(listBil.begin(), listBil.end(), cmp);

			if(listBil.size() >= 2){
				ii pertama = listBil[0];
				ii kedua = listBil[1];

				ans += (ll)pertama.first * kedua.first;
				pq[pertama.second].pop();
				pq[kedua.second].pop();
			}else{
				break;
			}
		}
		printf("%lld\n",ans);

	}
	
	return 0;
};