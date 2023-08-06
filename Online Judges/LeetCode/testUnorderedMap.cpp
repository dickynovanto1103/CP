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

int main(){
	map<int, int> mapper;
	mapper[12] = 23;
	mapper[34] = 34;
	// cout<<mapper.at(12)<<" "<<mapper.at(34)<<endl;
	printf("%d\n", (int)mapper[12]);
	
	return 0;
};