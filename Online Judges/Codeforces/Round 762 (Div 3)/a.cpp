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
	int tc,i,j,n;
	string s;
	scanf("%d",&tc);
	while(tc--){
		cin>>s;
		n = s.size();
		if(n % 2 == 1) {puts("NO"); continue;}
		string sub1 = s.substr(0, n/2);
		string sub2 = s.substr(n/2,n/2);
		// cout<<sub1<<" "<<sub2<<endl;
		if(sub1 == sub2){puts("YES");}
		else{puts("NO");}
	}
	
	return 0;
};