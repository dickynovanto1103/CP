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
	int tc,x,y;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&x,&y);
		if(x < y){printf("Hamada\n");}
		else if(x > y){printf("Bashar\n");}
		else{printf("Iskandar\n");}
	}
	return 0;
};