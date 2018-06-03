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

const int maxn = 2e3 + 3;

string kata[maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		cin>>kata[i];
	}
	int total[maxn];
	memset(total, 0, sizeof total);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(kata[j][i]=='1'){total[i]++;}
		}
	}
	bool isUnik[maxn];
	memset(isUnik,false,sizeof isUnik);
	for(i=0;i<m;i++){
		if(total[i] == 1){isUnik[i]= true;}
	}

	for(i=0;i<n;i++){
		vi listIdx;
		bool isStill = true;
		for(j=0;j<m;j++){
			if(total[j] == 1 && kata[i][j] == '1'){
				isStill = false;
				break;
			}
		}
		if(isStill){
			printf("YES\n");
			return 0;
			break;
		}
	}
	printf("NO\n");


	return 0;
};