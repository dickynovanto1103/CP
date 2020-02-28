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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int nilai = x - y;
	if(nilai < 0) {
		if(nilai + z >= 0){printf("?\n");}
		else{printf("-\n");}
	}else if(nilai == 0) {
		if(z == 0){printf("0\n");}
		else{printf("?\n");}
	}else{
		if(nilai - z <= 0){printf("?\n");}
		else{printf("+\n");}
	}
	return 0;
};