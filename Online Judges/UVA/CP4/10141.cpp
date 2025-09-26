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
	int n,p;
	int tt=1;
	while(scanf("%d %d\n",&n,&p) && !(n == 0 && p == 0)) {
		if(tt > 1){puts("");}
		printf("RFP #%d\n", tt++);
		// printf("n: %d, p: %d\n", n,p);
		map<string, int> requirements;
		for(int i=0;i<n;i++){
			string s;
			getline(cin, s);
			// printf("s: "); cout<<s<<endl;
			requirements[s] = i + 1;
		}

		string ans;
		int maxNumFulfilled = 0;
		double minPrices = -1;
		for(int i=0;i<p;i++){
			string company;
			getline(cin, company);
			double price;
			int r;
			scanf("%lf %d\n",&price,&r);
			// printf("company: "); cout<<company<<endl;
			// printf("price: %lf, r: %d, maxNumFulfilled: %d, minPrices: %lf\n", price, r, maxNumFulfilled, minPrices);
			for(int z=0;z<r;z++){
				string dum;
				getline(cin, dum);
				// printf("dum: "); cout<<dum<<endl;
			}


			if(r > maxNumFulfilled) {
				maxNumFulfilled = r;
				minPrices = price;
				ans = company;
				// printf("ans here: "); cout<<ans<<endl;
			}else if(r == maxNumFulfilled && minPrices > price) {
				minPrices = price;
				ans = company;
				// printf("ans here2: "); cout<<ans<<endl;
			}
		}

		cout<<ans<<endl;
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