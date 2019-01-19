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
typedef pair<vii,int> viii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string kata[4];
		for(i=0;i<3;i++){
			cin>>kata[i];
		}
		vii patokan;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(kata[i][j] == '*'){
					patokan.pb(ii(i,j));
				}
			}
		}

		//bfs routine
		queue<viii> q;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				q.push()
			}
		}

	}
	return 0;
};