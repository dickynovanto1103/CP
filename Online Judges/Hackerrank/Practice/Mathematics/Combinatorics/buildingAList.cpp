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

void process(int n, string s) {
	int num = (1<<n) - 1;
	vector<string> listAns;

	for(int i=1;i<(1<<n);i++){
		string ans = "";
		for(int j=0;j<n;j++){
			if((i & (1<<j))) {
				ans += s[j];
			}
		}
		listAns.pb(ans);
	}
	sort(listAns.begin(), listAns.end());
	for(int i=0;i<num;i++){
		cout<<listAns[i]<<endl;
	}
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;
		process(n, s);
	}
	return 0;
};