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
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		string kata[101];
		for(i=0;i<m;i++){
			cin>>kata[i];
		}
		string ans = kata[0];
		
		for(i=1;i<m;i++){
			bool found = false;
			for(j=n;j>=1;j--){
				string temp = kata[i].substr(0,j);
				int awal = ans.length() - j;
				string temp2 = ans.substr(awal, j);
				if(temp == temp2){
					found = true;
					for(int k=j;k<n;k++){
						ans += kata[i][k];
					}
					break;
				}
			}
			if(!found){
				for(j=0;j<n;j++){
					ans += kata[i][j];
				}
			}
		}
		// printf("ans: "); cout<<ans<<endl;
		printf("%d\n",(int)ans.length());
	}
	return 0;
};