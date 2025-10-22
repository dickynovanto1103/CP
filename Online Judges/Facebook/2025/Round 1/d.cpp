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
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	// cout<<s<<endl;
	if(s[n-1] == 'A') {
		puts("Alice");
		return;
	}

	//get groupings first
	char cur = 'z';
	int howBig = 1;
	vi res;
	for(int i=0;i<n;i++){
		if(cur == s[i]) {
			howBig++;
		}else if(cur != 'z'){
			//new group is created
			if(howBig == 1) {
				cur = s[i];
				continue;
			}

			if(cur == 'B') {
				res.pb(-(howBig - 1));
			}else{
				res.pb(howBig - 1);
			}
			howBig = 1;
		}
		cur = s[i];
	}

	if(howBig > 1) {
		if(cur == 'B') {
			res.pb(-(howBig - 1));
		}else{
			res.pb(howBig - 1);
		}
	}

	// printf("printing res, size: %d: ", res.size());
	// for(int i=0;i<res.size();i++){
	// 	printf("%d ", res[i]);
	// }
	// puts("");

	vi temp;
	for(int i=0;i<res.size();i++){
		if(res[i] < 0) {
			temp.pb(res[i]);
		}else{
			assert(res[i] > 0);
			if((i + 1) < res.size()) {
				if(res[i + 1] < 0) {
					temp.pb(res[i] + res[i+1]);
					i++;
				}else{
					temp.pb(res[i]);
				}
			}else{
				temp.pb(res[i]);
			}
		}
	}

	// puts("printing temp");
	// for(int el: temp) {
	// 	printf(" %d", el);
	// }
	// puts("");

	//find positive first
	int kiri = 0, kanan = temp.size() - 1;
	bool findPositive = true;
	int posNum = -inf, negNum = -inf;
	int state = 0;
	string ans = "Bob";
	bool isAlice = true;
	int remainingAlice = 0, remainingBob = 0;
	while(kiri <= kanan) {
		// printf("kiri: %d kanan: %d isAlice: %d remainingAlice\n", kiri, kanan);
		if(isAlice && remainingAlice > 0) {
			remainingAlice--;
		}else if(!isAlice && remainingBob > 0) {
			remainingBob--;
		}else if(isAlice && remainingAlice <= 0) {
			bool found = false;
			for(int i=kiri + 1; i<= kanan;i++){
				if(temp[i] > 0) {
					kiri = i;
					posNum = temp[i];
					remainingAlice = posNum;
					found = true;
					break;
				}
			}
			if(!found) {
				ans = "Bob";
				break;
			}
		}else if(!isAlice && remainingBob <= 0){
			bool found = false;
			for(int i=kanan - 1; i>=kiri;i--){
				if(temp[i] < 0) {
					kanan = i;
					negNum = -temp[i];
					remainingBob = negNum;
					found = true;
					break;
				}
			}
			if(!found) {
				ans = "Alice";
				break;
			}
		}
		isAlice = !isAlice;
	}

	assert(ans.size() > 0);
	cout<<ans<<endl;
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--){
		printf("Case #%d: ", tt++);
		solve();
	}

	return 0;
};