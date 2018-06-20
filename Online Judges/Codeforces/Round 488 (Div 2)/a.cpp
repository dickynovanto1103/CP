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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	set<int> s;
	
	int idx[10];
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		s.insert(bil);
		idx[bil] = i;
	}

	vii ans;

	for(i=0;i<m;i++){
		int bil;
		scanf("%d",&bil);
		if(s.find(bil) != s.end()){
			ans.pb(ii(idx[bil], bil));
		}
	}
	sort(ans.begin(), ans.end());
	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i].second);
	}
	printf("\n");

	return 0;
};