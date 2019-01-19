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

int a[55][55];

int n,m;

int main(){
	int i,j;
	int tc;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&m);
		bool isFlipped = false;
		if(n > m){
			swap(n,m);
			isFlipped = true;
		}
		if(n == 1 && m == 1){
			printf("1\n1\n");
			continue;
		}else if(n == 1 && m == 2){
			printf("1\n");
			a[0][0] = 1; a[0][1] = 1;
		}else if(n == 1){
			printf("2\n");
			for(i=0;i<m;i++){
				int mod = i%4;
				if(i){printf(" ");}
				if(mod <= 1){
					a[0][i] = 1;
				}else{
					a[0][i] = 2;
				}
			}
		}else if(n == 2 && m == 2){
			printf("2\n1 2\n1 2\n");
			continue;
		}else if(n == 2){
			printf("3\n");
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					int mod = (j%3) + 1;
					a[i][j] = mod;
				}
			}
		}else{
			printf("4\n");
			for(i=0;i<n;i++){
				for(j=0;j<m;j++) {
					if(i%4 < 2){
						int mod = (j%4) + 1;
						a[i][j] = mod;
					}else{
						int mod = j%4;
						if(mod == 0){a[i][j] = 3;}
						else if(mod == 1){a[i][j] = 4;}
						else if(mod == 2){a[i][j] = 1;}
						else{a[i][j] = 2;}
					}
				}
			}
		}

		if(isFlipped){
			for(j=0;j<m;j++){
				for(i=0;i<n;i++){
					if(i){printf(" ");}
					printf("%d",a[i][j]);
				}
				printf("\n");
			}
		}else{
			for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(j){printf(" ");}
					printf("%d",a[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
};