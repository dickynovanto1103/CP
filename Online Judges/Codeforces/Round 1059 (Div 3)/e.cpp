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
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1];
	set<int> s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}

	vi added;
	if(s.size() == n) {
		for(int i=0;i<3;i++){
			added.pb(a[i]);
		}

		int idxAdded = 0;
		// printf("k: %d\n", k);
		for(int i=0;i<k;i++, idxAdded++, idxAdded %= added.size()) {

			printf("%d ", added[idxAdded]);
		}
		puts("");

		return;
	}

	//find missing numbers
	for(int i=1;i<=n;i++){
		if(!s.count(i)) {
			added.pb(i);
		}
	}

	if(added.size() == 1) {
		//find the next diff integer...then the first integer;
		int lastNumber = a[n-1];
		int number = -1;
		for(int i=n-2;i>=0;i--){
			if(a[i] != lastNumber) {
				number = a[i];
				break;
			}
		}

		assert(number != -1);
		added.pb(number);
		added.pb(lastNumber);
	}else if(added.size() == 2){
		added.pb(a[0]);
	}

	int idxAdded = 0;
	for(int i=0;i<k;i++, idxAdded++, idxAdded %= added.size()){
		printf("%d ", added[idxAdded]);
	}
	puts("");
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};