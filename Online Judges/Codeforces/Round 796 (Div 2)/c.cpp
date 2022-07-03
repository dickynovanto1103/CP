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

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int cnt[256];
		memset(cnt, 0, sizeof cnt);
		for(int i=0;i<2*n;i++){
			string s;
			cin>>s;
			if(len(s) == 1) {
				cnt[s[0]]++;
			}
		}

		string final;
		cin>>final;
		if(len(final) == 1) {

		}else{
			//cuman boleh 
		}
	}
	
	return 0;
};