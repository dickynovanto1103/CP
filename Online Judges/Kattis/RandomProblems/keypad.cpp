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

string kata[14];
int n,m;

bool check(int x, int y){
	int cnt = 0;
	int i,j;
	for(i=0;i<n;i++){
		if(kata[i][y] == '1'){cnt++; break;}
	}
	for(j=0;j<m;j++){
		if(kata[x][j] == '1'){cnt++; break;}
	}
	return cnt < 2;
}

bool isValid(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			char kar = kata[i][j];
			if(kar == '0'){
				if(!check(i,j)){return false;}
			}
		}
	}
	return true;
}

bool isStillValid(int x, int y){
	int cnt = 0;
	int i,j;
	for(i=0;i<n;i++){
		if(kata[i][y] == '1'){cnt++; break;}
	}
	for(j=0;j<m;j++){
		if(kata[x][j] == '1'){cnt++; break;}
	}
	return cnt == 2;
}

int main(){
	int tc,i,j;
	
	scanf("%d",&tc);
	while(tc--){
		
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		char ans[12][12];
		if(!isValid()){printf("impossible\n");}
		else{
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(kata[i][j] == '1'){
						kata[i][j] = '0';

						if(isStillValid(i,j)){printf("I");}
						else{printf("P");}
						kata[i][j] = '1';
					}else{
						printf("N");
					}
				}
				printf("\n");
			}
		}
		printf("----------\n");
	}
	return 0;
};