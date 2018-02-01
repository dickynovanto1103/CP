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

vector<vii> AdjList;

int main(){
	int n,dist[3],a,b,c;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	AdjList.assign(4,vii());
	AdjList[0].pb(ii(1,a)); AdjList[1].pb(ii(0,a));
	AdjList[0].pb(ii(2,b)); AdjList[2].pb(ii(0,b));
	AdjList[2].pb(ii(1,c)); AdjList[1].pb(ii(2,c));

	int i,j;
	int state = 0;
	int sum = 0;
	for(i=0;i<n-1;i++){
		int minim = inf;
		//printf("state sekarang: %d ukuran tetangga: %d\n",state,AdjList[state].size());
		int curState;
		for(j=0;j<AdjList[state].size();j++){
			ii front = AdjList[state][j];
			int jarak = front.second, v = front.first;
			//printf("state: %d v: %d\n",state,v);
			
			if(minim>jarak){
				minim = jarak; curState = v;
				//printf("minim berubah jd: %d state berubah jd: %d\n",minim,state);
			}

			
		}
		state = curState;
		//printf("memilih ke state: %d dengan jarak: %d\n",state,minim);
		sum+=minim;
		
	}
	printf("%d\n",sum);
	return 0;
};