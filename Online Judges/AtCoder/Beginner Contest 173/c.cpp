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

string temp[7];
string s[7];

void setTemp(int n) {
	for(int i=0;i<n;i++){
		temp[i] = s[i];
	}
}

int main(){
	int n,m,z,i,j;
	scanf("%d %d %d",&n,&m,&z);
	
	for(i=0;i<n;i++){
		cin>>s[i];
		temp[i] = s[i];
	}
	int ans = 0;

	for(i=0;i<(1<<n);i++){
		vi listRow;
		for(j=0;j<n;j++){
			if((1<<j) & i) {
				listRow.pb(j);
			}
		}
		for(j=0;j<(1<<m);j++){
			vi listCol;
			for(int l=0;l<m;l++){
				if((1<<l) & j) {
					listCol.pb(l);
				}
			}

			setTemp(n);

			//process listCOl and listRow
			for(int k=0;k<listRow.size();k++){
				int row = listRow[k];
				for(int l=0;l<m;l++){
					temp[row][l] = 'z';
				}
			}

			for(int k=0;k<listCol.size();k++){
				int col = listCol[k];
				for(int l=0;l<n;l++){
					temp[l][col] = 'z';
				}
			}

			int cnt = 0;
			for(int k=0;k<n;k++){
				for(int l=0;l<m;l++){
					if(temp[k][l] == '#'){
						cnt++;
					}
				}
			}
			if(cnt == z){
				// printf("z: %d\n",z);
				// for(int k=0;k<listRow.size();k++){
				// 	printf("%d ",listRow[k]);
				// }
				// printf("\n");
				// for(int k=0;k<listCol.size();k++){
				// 	printf("%d ",listCol[k]);
				// }
				// printf("\n");
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};