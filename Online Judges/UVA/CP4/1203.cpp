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

void solve(){
	string command;
	vii pairs;
	while(cin>>command, command != "#") {
		int id, freq;
		scanf("%d %d",&id,&freq);
		pairs.pb(ii(freq, id));
	}

	sort(pairs.begin(), pairs.end());

	int n;
	scanf("%d",&n);
	priority_queue<ii> pq;
	for(int i=0;i<n;i++){
		pq.push(ii(pairs[0].first * (i + 1), pairs[0].second));
	}

	for(int i=1;i<pairs.size();i++){
		int times = 1;

		while(pq.top() > ii(times * pairs[i].first, pairs[i].second)) {
			pq.pop();
			pq.push(ii(times * pairs[i].first, pairs[i].second));
			times++;
		}
	}

	assert(pq.size() == n);
	vii res(n);
	for(int i=0;i<n;i++){
		res[i] = pq.top(); pq.pop();
	}

	reverse(res.begin(), res.end());
	for(int i=0;i<n;i++){
		printf("%d\n", res[i].second);
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};