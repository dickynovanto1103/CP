#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int i,j,tc;
	ll m,k,x;
	string s;
	scanf("%d",&tc);
	while(tc--){
		cin>>s;
		ll listChar[30] = {0};
		ll last[30] = {-1};
		int n = s.length();
		for(i=0;i<n;i++){
			int idx = s[i]-97;
			listChar[idx]++;
			last[idx] = i;
		}
		scanf("%lld %lld %lld",&m,&k,&x);
		for(i=0;i<26;i++){listChar[i]*=m;}
		
	}
	

	return 0;
}