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

const int maxn = 1e5 + 5;

bool isVisited[maxn];

vi s;
vi ans;

int main(){
	int n,m,i,j;
	int a[maxn];
	memset(isVisited,false,sizeof isVisited);
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		isVisited[a[i]] = true;
	}
	
	for(i=1;i<=n;i++){
		if(isVisited[i]){continue;}
		s.pb(i);
	}
	int idx = 0;
	for(i=0;i<m;i++){
		//iterasi tiap bilangan
		int bil = a[i];
		// printf("i: %d\n",i);
		if(idx<s.size()){
			while(s[idx] < bil && idx<s.size()) {
				ans.pb(s[idx]);
				idx++;
				// printf("dipush: %d idx: %d\n",s[idx],idx);
				if(idx==s.size()){break;}
			}	
		}
		
		ans.pb(bil);
	}
	while(idx<s.size()){
		ans.pb(s[idx]);
		idx++;
	}
	for(i=0;i<n;i++){
		
		printf("%d\n",ans[i]);
	}
	
	return 0;
};