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
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){

		string ans = (i%2 == 0 ? "W":"B");
		char last = ans[0];
		for(j=1;j<n;j++){
			ans += (last == 'W' ? 'B' : 'W');
			last = ans[j];
		}
		cout<<ans<<endl;
	}
	return 0;
};