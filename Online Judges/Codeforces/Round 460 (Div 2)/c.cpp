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
int parentHorizontal[maxn][maxn];
int parentVertical[maxn][maxn];

int main(){
	int n,m,k,i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){cin>>kata[i];}
	if(k==1){
		int cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='.'){cnt++;}
			}
		}
		printf("%d\n",cnt);
		return 0;
	}
	//list parent horizontal
	for(i=0;i<n;i++){
		bool lagiKosong = false;
		for(j=0;j<m;j++){
			if(kata[i][j]!='.'){lagiKosong = false;}
			else{
				if(!lagiKosong){
					lagiKosong = true;
					parentHorizontal[i][j] = j;
				}else{
					parentHorizontal[i][j] = parentHorizontal[i][j-1];
				}
			}
		}
	}

	//list parent Vertical
	for(j=0;j<m;j++){
		bool lagiKosong = false;
		for(i=0;i<n;i++){
			if(kata[i][j]!='.'){lagiKosong = false;}
			else{
				if(!lagiKosong){
					lagiKosong = true;
					parentVertical[i][j] = i;
				}else{
					parentVertical[i][j] = parentVertical[i-1][j];
				}
			}
		}
	}

	//cek secara horizontal
	int cnt = 0;
	for(i=0;i<n;i++){
		bool lagiKosong = false;
		for(j=0;j<m;j++){
			int nextIdx = (j+k-1);
			if(nextIdx>=m){break;}
			if(kata[i][j] == '.' && kata[i][nextIdx]=='.'){
				if(parentHorizontal[i][j] == parentHorizontal[i][nextIdx]){
					cnt++;
				}
			}
		}
	}
	
	//cek secara vertical
	for(j=0;j<m;j++){
		bool lagiKosong = false;
		for(i=0;i<n;i++){
			int nextIdx = (i+k-1);
			if(nextIdx>=n){break;}
			if(kata[i][j] == '.' && kata[nextIdx][j]=='.'){
				if(parentVertical[i][j] == parentVertical[nextIdx][j]){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};