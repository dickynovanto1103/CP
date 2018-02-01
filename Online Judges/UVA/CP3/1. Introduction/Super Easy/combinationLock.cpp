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
	int pos, a,b,c;
	while(scanf("%d %d %d %d",&pos,&a,&b,&c), (pos||a||b||c)){
		int banyak = 1080;
		int perubahan = pos-a;
		if(perubahan<0){perubahan+=40;}
		// printf("perubahan1: %d\n",perubahan);
		banyak+=(perubahan*360/40);
		perubahan = b-a;

		if(perubahan<0){perubahan+=40;}
		// printf("perubahan2: %d\n",perubahan);
		banyak+=(perubahan*360/40);
		perubahan = b-c;
		if(perubahan<0){perubahan+=40;}
		// printf("perubahan/3: %d\n",perubahan);
		banyak+=(perubahan*360/40);

		printf("%d\n",banyak);
	}
	return 0;
};