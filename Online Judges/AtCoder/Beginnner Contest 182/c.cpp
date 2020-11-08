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

ll convertToNum(string s){
	ll ans = 0;
	for(int i=0;i<s.size();i++){
		ans *= 10LL;
		ans += (s[i] - '0');
	}
	return ans;
}

int main(){
	string bil;
	while(cin>>bil){
		int i,j;
		int n = bil.size();
		int ans = inf;
		// printf("bil:"); cout<<bil<<endl;
		for(i=0;i<(1<<n);i++){
			string s;
			int cnt = 0;
			for(j=0;j<n;j++){
				if((1<<j) & i) {
					s += bil[j];
					cnt++;
				}
			}

			ll angka = convertToNum(s);
			if(angka % 3LL == 0) {
				ans = min(ans, n - cnt);
			}
		}
		if(ans == inf || ans == n){
			printf("-1\n");
		}else{
			printf("%d\n",ans);
		}

	}
	

	
	return 0;
};