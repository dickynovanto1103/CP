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

vi a;
int counter[1000010];

int main(){
	int n,i,j;
	int mapper[256];
	
	mapper['a'] = 2;
	mapper['b'] = 2;
	mapper['c'] = 2;
	mapper['d'] = 3;
	mapper['e'] = 3;
	mapper['f'] = 3;
	mapper['g'] = 4;
	mapper['h'] = 4;
	mapper['i'] = 4;
	mapper['j'] = 5;
	mapper['k'] = 5;
	mapper['l'] = 5;
	mapper['m'] = 6;
	mapper['n'] = 6;
	mapper['o'] = 6;
	mapper['p'] = 7;
	mapper['q'] = 7;
	mapper['r'] = 7;
	mapper['s'] = 7;
	mapper['t'] = 8;
	mapper['u'] = 8;
	mapper['v'] = 8;
	mapper['w'] = 9;
	mapper['x'] = 9;
	mapper['y'] = 9;
	mapper['z'] = 9;

	map<int, int> mapper1,mapper2;

	string kata;
	scanf("%d",&n);
	int cnt = 0;
	for(i=0;i<n;i++){
		cin>>kata;
		int bil = 0;
		for(j=0;j<kata.length();j++){
			bil*=10;
			bil+=mapper[kata[j]];
		}
		if(mapper1.find(bil)==mapper1.end()){
			mapper1[bil] = cnt;
			mapper2[cnt] = bil;
			counter[cnt] = 1;
			cnt++;
		}else{
			counter[mapper1[bil]]++;
		}
		
	}
	int maks = 0;
	int ans;
	for(i=0;i<cnt;i++){
		if(counter[i]>maks){
			maks = counter[i];
			ans = mapper2[i];
		}
	}
	printf("%d\n",ans);
	return 0;
};