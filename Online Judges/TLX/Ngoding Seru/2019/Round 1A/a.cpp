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

int main(){
	int r,c,a,b,x,y;
	scanf("%d %d %d %d %d %d",&r,&c,&a,&b,&x,&y);
	if(a > x){printf("TIDAK\n"); return 0;}
	if(a == x && b == y){printf("YA\n");}
	else{
		int selisihX = abs(a-x), selisihY = abs(b-y);
		if(selisihX < selisihY){printf("TIDAK\n"); return 0;}
		if(selisihX %2 == 0){
			if(selisihY % 2 == 0){printf("YA\n");}
			else{printf("TIDAK");}
		}else{
			if(selisihY % 2 == 1){printf("YA\n");}
			else{printf("TIDAK");}
		}
		// if(selisihX == selisihY){printf("YA\n");}
		// else{printf("TIDAK\n");}
	}
	

	return 0;
};