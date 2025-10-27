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
typedef pair<ii, string> iis;
typedef vector<ii> vii;

bool cmp(iis a, iis b) {
	if(a.first.first == b.first.first) {
		if(a.first.second == b.first.second) {
			return a.second < b.second;
		}
		return a.first.second < b.first.second;
	}
	return a.first.first > b.first.first;
}

void solve(){
	int n;
	scanf("%d",&n);

	vector<iis> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int sumPoint = 0, sumPenalty = 0;
		for(int j=0;j<2;j++){
			int point, penalty;
			scanf("%d %d",&point, &penalty);
			sumPoint += point;
			sumPenalty += penalty;
		}

		v.pb(iis(ii(sumPoint, sumPenalty), s));
	}

	sort(v.begin(), v.end(), cmp);
	assert(v.size() == n);
	for(int i=0;i<n;i++){
		cout<<v[i].second<<endl;
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