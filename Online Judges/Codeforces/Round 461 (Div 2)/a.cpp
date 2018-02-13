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
	int x,y;
	scanf("%d %d",&x,&y);
	if(x==0 && y==1){printf("Yes\n"); return 0;}
	if(y==0){printf("No\n"); return 0;}
	if((y-x)>1){printf("No\n"); return 0;}
	int asli = y, palsu = asli-1;
	// printf("asli: %d palsu: %d\n",asli,palsu);
	if((x-palsu)<0){printf("No\n"); return 0;}
	if((x-palsu)%2==0){
		if(palsu==0){printf("No\n");}
		else{printf("Yes\n");}
		
	}else{
		printf("No\n");
	}
	return 0;
};