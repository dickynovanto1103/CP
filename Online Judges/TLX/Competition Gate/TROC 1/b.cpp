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

const int maxn = 1e2 + 2;

int main(){
	int n,r,v,i,j;
	int s[maxn];
	scanf("%d %d %d",&n,&r,&v);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	int jarak = r;
	double maks = 0;
	for(i=0;i<n;i++){
		int selisihSpeed = abs(v-s[i]);
		if(selisihSpeed == 0){
			printf("-1\n");
			return 0;
		}else{
			maks = max((double)jarak/(double)selisihSpeed, maks);
		}
	}
	printf("%.9lf\n",maks);
	return 0;
};