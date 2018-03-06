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
	int tc,i,j,n;
	string kata[110];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>kata[i];
			sort(kata[i].begin(), kata[i].end());
			// cout<<kata[i]<<endl;
		}
		bool isValid = true;
		for(i=0;i<n-1;i++){
			for(j=0;j<n;j++){
				// printf("kata[%d][%d]: %c kata[%d][%d]: %c\n",j,i,kata[j][i], j,i+1,kata[j][i+1]);
				if(kata[i][j] > kata[i+1][j]){isValid = false; break;}
			}
			if(!isValid){break;}
		}
		if(isValid){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};