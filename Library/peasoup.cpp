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
	while(cin>>n) {
		// printf("n: %d\n", n);
		string ans = "-1";
		for(int tt=0;tt<n;tt++){
			// printf("tt: %d\n", tt);
			int k;
			scanf("%d\n", &k);
			// printf("k: %d\n", k);
			string firstMenu;
			getline(cin, firstMenu);
			// cout<<"first menu: "<<firstMenu<<endl;
			int bil = 0;
			for(int i=0;i<k;i++){
				string menu;
				getline(cin, menu);
				// cout<<"menu: "<<menu<<endl;
				if(menu == "pea soup") {
					bil |= 1;
				}else if(menu == "pancakes") {
					bil |= 2;
				}
			}

			if(bil == 3 && ans == "-1") {
				ans = firstMenu;
			}
		}

		if(ans == "-1") {
			puts("Anywhere is fine I guess");
		}else{
			cout<<ans<<endl;
		}
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