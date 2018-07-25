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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	set<int> s;
	int ans = 0;
	for(i=0;i<2*n;i++){
		int bil;
		scanf("%d",&bil);
		if(s.find(bil) == s.end()){
			s.insert(bil);
			ans = max(ans, (int)s.size());
		}else{
			s.erase(bil);
		}
	}

	printf("%d\n",ans);
	return 0;
};