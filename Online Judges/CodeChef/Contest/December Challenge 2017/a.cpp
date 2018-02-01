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
	int tc,n,m,i,j;
	string kata[110];
	char benar1[110][110], benar2[110][110];
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			cin>>kata[i];
		}
		//bikin 2 versi yang bener
		char kar = 'R';

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(i==0){
					if(j==0){
						benar1[i][j] = kar;
					}else{
						if(benar1[i][j-1]=='R'){benar1[i][j]='G';}
						else{benar1[i][j]='R';}
					}
				}else{
					if(benar1[i-1][j]=='R'){benar1[i][j] = 'G';}
					else{benar1[i][j] = 'R';}	
				}
			}
		}
		kar = 'G';
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(i==0){
					if(j==0){
						benar2[i][j] = kar;
					}else{
						if(benar2[i][j-1]=='R'){benar2[i][j]='G';}
						else{benar2[i][j]='R';}
					}
				}else{
					if(benar2[i-1][j]=='R'){benar2[i][j] = 'G';}
					else{benar2[i][j] = 'R';}	
				}
			}
		}
		int minim = inf;
		int sum1 = 0, sum2 = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				char karakter = benar1[i][j];
				if(kata[i][j]=='R' && benar1[i][j]=='G'){
					sum1+=5;
				}else if(kata[i][j]=='G' && benar1[i][j]=='R'){
					sum1+=3;
				}
				
				if(kata[i][j]=='R' && benar2[i][j]=='G'){
					sum2+=5;
				}else if(kata[i][j]=='G' && benar2[i][j]=='R'){
					sum2+=3;
				}
			}
			
		}
		minim = min(sum1,sum2);
		printf("%d\n",minim);
	}
	return 0;
};