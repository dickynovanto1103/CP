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

	int a = 0,b = 0;
	int c = (1<<30) - 1,d = c;
	
	bool sudahNerima = false;
	printf("? %d %d\n",c,d);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	int cur = ans;
	// printf("cur: %d\n",cur);
	for(int i=29;i>=0;i--){
		int tempC = c ^ (1<<i);
		printf("? %d %d\n",tempC, d);
		fflush(stdout);
		scanf("%d",&ans);
		bool markedA = false, markedB = false;
		if(ans < cur){
			a |= (1<<i);
			markedA = true;
		}
		

		int tempD = d ^ (1<<i);
		printf("? %d %d\n",c, tempD);
		fflush(stdout);
		scanf("%d",&ans);
		if(cur > ans){
			b |= (1<<i);
			markedB = true;
		}
		if(!markedA){
			// printf("c awal: %d\n",c);
			c ^= (1<<i);
			// printf("c akhir: %d\n",c);
		}
		if(!markedB){
			// printf("d awal: %d\n",d);
			d ^= (1<<i);
			// printf("d akhir: %d\n",d);
		}
		// printf("a sekarang: %d b sekarang: %d\n",a,b);

	}
	printf("! %d %d\n",a,b);
	return 0;
};