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
	string correctRestaurant = "-1";
	for(int i=0;i<n;i++){
		int k;
		scanf("%d\n",&k);
		string restaurant;
		getline(cin, restaurant);

		int state = 0;
		for(int j=0;j<k;j++){
			string menu;
			getline(cin, menu);
			// cout <<"restaurant: "<< restaurant<< " menu: "<<menu<<endl;
			if(menu == "pea soup") {
				state |= 1;
			} else if(menu == "pancakes") {
				state |= 2;
			}
		}
		if(state == 3 && correctRestaurant == "-1") {
			correctRestaurant = restaurant;
		}
	}

	if (correctRestaurant == "-1") {
		puts("Anywhere is fine I guess");
		return;
	}
	cout<<correctRestaurant<<endl;
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};