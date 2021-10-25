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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;
	while(tc--) {
		ll n;
		char c;
		cin>>n>>c;
		string s;
		cin>>s;
		// cout<<n << " "<< c <<  " "<< s<<endl;
		bool anyDiff = false;
		for(char ch: s) {
			if(ch != c) {anyDiff = true; break;}
		}
		vi ans;
		if(anyDiff) {
			for(int i=1;i<n;i++){
				if(s[i] != c) continue;
				bool can = true;
				for(int j=i;j<n;j+=(i+1)){
					if(s[j] != c){
						can = false;
						break;
					}
				}
				// cout<<"when "<<i<<" can:"<<can<<endl;
				if(can) {
					ans.pb(i+1);
					break;
				}
			}
			if(!ans.size()) {
				ans.pb(n); ans.pb(n-1);
			}
		}

		// cout<<"any diff:"<<anyDiff<<endl;
		cout<<ans.size()<<endl;
		for(int a: ans){
			cout<<a<<" ";
		}
		cout<<endl;
	}

	
	return 0;
};