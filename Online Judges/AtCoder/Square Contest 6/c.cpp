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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool reach[111][10010];
string kata[103];

int main(){
	int n,m,i,j;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		cin>>kata[i]; 
		string temp = kata[i];
		for(j=0;j<n;j++){
			kata[i] += temp;
		}
	}
	vi listValid;
	int kol = n*m;
	for(i=0;i<n;i++){
		bool valid = true;

		for(j=0;j<kol;j++){
			if(kata[i][j] == '#'){valid = false; break;}
		}
		if(valid){listValid.pb(i);}
	}
	queue<ii> q;
	q.push(ii(0,0));
	int dx[] = {1,0};
	int dy[] = {0,1};
	
	memset(reach, false, sizeof reach);
	reach[0][0] = true;
	while(!q.empty()){
		ii front = q.front(); q.pop();
		for(i=0;i<2;i++){
			int xbaru = front.first + dx[i], ybaru = front.second + dy[i];
			if(xbaru >= 0 && xbaru < n && ybaru >= 0 && ybaru < kol){
				if(kata[xbaru][ybaru] == '.' && !reach[xbaru][ybaru]){
					reach[xbaru][ybaru] = true;
					q.push(ii(xbaru, ybaru));
				}
			}
		}
	}
	for(i=0;i<listValid.size();i++){
		int r = listValid[i];
		for(j=0;j<kol;j++){
			if(reach[r][j]){
				printf("Yay!\n");
				return 0;
			}
		}
	}
	printf(":(\n");
	return 0;
};