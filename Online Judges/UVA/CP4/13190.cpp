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
typedef pair<int,string> is;
typedef vector<ii> vii;

void solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<string> medicines;
	vi durations;
	for(int i=0;i<n;i++){
		string med;
		int dur;
		cin>>med>>dur;
		// cout<<med<<dur<<endl;
		medicines.pb(med);
		durations.pb(dur);

		// printf("try i: %d, dur: %d n: %d\n", i, dur, n);
		// cout<<medicines[i]<<" "<<durations[i]<<" k:"<<k<<endl;
	}

	priority_queue<ii> pq;
	// printf("asu");
	for(int i=0;i<k;i++){
		pq.push(ii((i+1) * durations[0], 0));
	}

	// printf("here1");

	for(int i=1;i<n;i++){
		int times = 1;
		while(!pq.empty() && pq.top() > ii(times * durations[i], i)) {
			pq.pop();
			pq.push(ii(times * durations[i], i));
			times++;
		}
	}

	// printf("here");

	assert(pq.size() == k);

	vector<is> res(k);
	for(int i=0;i<k;i++){
		ii top = pq.top(); pq.pop();
		res[i] = is(top.first, medicines[top.second]);
	}

	reverse(res.begin(), res.end());
	for(int i=0;i<k;i++){
		printf("%d ", res[i].first);
		cout<<res[i].second<<endl;
	}
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};