/*
ID: dickyno1
LANG: C++14
TASK: maze1
*/

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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string grid[300];

int main(){
	// freopen("maze1.in", "r", stdin);
	// freopen("maze1.out", "w", stdout);

	int w, h,i,j;
	scanf("%d %d\n",&w,&h);
	for(i=0;i<2*h+1;i++){
		getline(cin, grid[i]);
		cout<<grid[i]<<endl;
	}


	
	return 0;
};