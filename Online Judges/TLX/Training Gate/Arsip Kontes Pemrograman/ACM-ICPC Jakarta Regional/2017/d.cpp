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

struct tup{
	int a,b,w;
};

bool cmp(tup a, tup b){return a.w < b.w;}
int cap[200010];
tup pas[100010];

int main(){
	int n,i,j,batas;
	
	scanf("%d %d",&n,&batas);
	
	map<int,int> mapper;
	map<int,int>::iterator it;
	int cnt = 0;
	for(i=0;i<n;i++){
		int a,b,w;
		scanf("%d %d %d",&pas[i].a,&pas[i].b,&pas[i].w);
		it = mapper.find(pas[i].a);
		if(it==mapper.end()){
			mapper[pas[i].a] = cnt++;
		}
		it = mapper.find(pas[i].b);
		if(it==mapper.end()){
			mapper[pas[i].b] = cnt++;
		}
	}
	// printf("hasil mapping\n");
	// for(it=mapper.begin();it!=mapper.end();it++){
	// 	printf("%d->%d\n",it->first, it->second);
	// }
	// printf("\n");
	sort(pas,pas+n,cmp);
	int ans = 0;
	for(i=0;i<n;i++){
		int node1 = mapper[pas[i].a];
		int node2 = mapper[pas[i].b];
		// printf("pasangan: %d %d\n",pas[i].a,pas[i].b);
		// printf("node1: %d node2: %d\n",node1,node2);
		if(cap[node1]>0){
			cap[node1]--;
			cap[node2] += batas;
		}else{//bikin tree baru
			ans++;
			cap[node1] = batas-1;
			cap[node2] += batas;
		}
	}
	printf("%d\n",ans);

	return 0;
};