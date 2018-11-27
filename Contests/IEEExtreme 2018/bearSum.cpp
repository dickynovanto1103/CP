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

const int maxn = 2e6 + 6;

bool isAda[maxn];

int main(){
	int tc,i,j;

	scanf("%d",&tc);
	while(tc--){
		int s,n;
		scanf("%d %d",&s,&n);
		int bil;
		bool foundAns = false;
		memset(isAda, false, sizeof isAda);
		for(i=0;i<n;i++){
			scanf("%d",&bil);
			if(foundAns){continue;}
			int harapan = s - bil;
			harapan += 1000000;
			if(isAda[harapan]){
				int bil1 = bil;
				int bil2 = harapan;
				bil2 -= 1000000;
				int minim = min(bil1,bil2);
				int maks = max(bil1,bil2);
				printf("%d %d\n",minim,maks);
				foundAns = true;
			}else{
				isAda[bil + 1000000] = true;
			}
		}
		if(!foundAns){printf("!OK\n");}
	}
	return 0;
};