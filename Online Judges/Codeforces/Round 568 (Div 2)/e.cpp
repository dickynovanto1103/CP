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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;
typedef vector<iiii> viiii;

string kata[2010];
vector<vii> adj;
bool vis[2010][2010];

bool isValidToDraw(int minX, int maksX, int minY, int maksY, int kar) {
	bool isValid = true;
	int i = kar,j;
	if(minX == maksX || minY == maksY) {
		if(minX == maksX){
			for(j=0;j<adj[i].size();j++){
				ii koor = adj[i][j];
				if(vis[koor.first][koor.second]){isValid = false; break;}//nabrak
				else{vis[koor.first][koor.second] = true;}
			}

			for(j=minY;j<=maksY;j++){
				if(!vis[minX][j]){isValid = false; break;}
			}
		}else{
			for(j=0;j<adj[i].size();j++){
				ii koor = adj[i][j];
				if(vis[koor.first][koor.second]){isValid = false; break;}
				else{
					vis[koor.first][koor.second] = true;
				}
			}
			for(j=minX;j<=maksX;j++){
				if(!vis[j][minY]){isValid = false; break;}
			}
		}
	}else{
		isValid = false;
	}
	return isValid;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	memset(vis, false, sizeof vis);
	while(tc--){

		int n,m;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			cin>>kata[i];	
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				vis[i][j] = false;
			}
		}
		
		bool isExist[26];
		memset(isExist, false, sizeof isExist);
		adj.clear();
		adj.assign(26, vii());
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j] >= 'a' && kata[i][j] <= 'z'){
					isExist[kata[i][j] - 'a'] = true;
					adj[kata[i][j] - 'a'].pb(ii(i+1,j+1));
				}
			}
		}

		bool has = false;
		for(i=25;i>=0;i--){
			if(has){isExist[i] = true;}
			if(isExist[i]){has = true;}
		}
		viiii ans;
		bool isValid = true;
		//yang ga bisa adalah ketika sebelumnya ga continuous dan setelahnya continuous dan nabrak

		for(i=25;i>=0;i--){
			if(isExist[i]){
				// printf("i: %d\n",i);
				if(adj[i].size() == 0){
					iiii sebelum = ans[ans.size()-1];
					ans.pb(sebelum);
				}else{
					int minX= inf, minY= inf, maksX= -inf, maksY = -inf;
					for(j=0;j<adj[i].size();j++){
						ii koor = adj[i][j];
						minX = min(minX, koor.first);
						minY = min(minY, koor.second);
						maksX = max(maksX, koor.first);
						maksY = max(maksY, koor.second);
					}
					if(isValidToDraw(minX, maksX, minY, maksY, i)){
						if(minX == maksX){
							ans.pb(iiii(ii(minX, minY), ii(minX, maksY)));
						}else{
							ans.pb(iiii(ii(minX, minY), ii(maksX, minY)));
						}
					}else{
						isValid = false; break;
					}
				}
			}
		}
		reverse(ans.begin(), ans.end());
		if(isValid){
			printf("YES\n%d\n",(int)ans.size());
			for(i=0;i<ans.size();i++){
				iiii bil = ans[i];
				ii koor1 = bil.first, koor2 = bil.second;
				printf("%d %d %d %d\n",koor1.first, koor1.second, koor2.first, koor2.second);
			}
		}else{
			printf("NO\n");
		}
		
	}
	return 0;
};