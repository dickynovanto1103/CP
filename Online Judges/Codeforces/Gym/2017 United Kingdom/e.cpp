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

const int maxn = 5011;



struct departWithID {
	int id, student;
};
struct bangunan {
	int capacity, rental;
};

bool cmp(departWithID a, departWithID b) {
	return a.student > b.student;
}

int ans[maxn];
departWithID depart[maxn];
bangunan building[maxn];

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&depart[i].student);
		depart[i].id = i;
	}
	sort(depart, depart+n, cmp);
	for(i=0;i<m;i++) {
		scanf("%d",&building[i].capacity);
	}
	for(i=0;i<m;i++) {
		scanf("%d",&building[i].rental);
	}
	bool valid = true;
	bool isVisited[maxn];
	memset(isVisited, false, sizeof isVisited);
	for(i=0;i<n;i++) {
		int banyakMurid = depart[i].student;
		int minimBiaya = inf, idxMinim;
		bool ketemu = false;
		for(j=0;j<m;j++) {
			if(isVisited[j]){continue;}
			if(building[j].capacity >= banyakMurid) {
				if(minimBiaya > building[j].rental){
					minimBiaya = building[j].rental;
					idxMinim = j;
					ketemu = true;
					
				}
			}
		}
		if(!ketemu){valid = false;break;}
		isVisited[idxMinim] = true;
		int idx = depart[i].id;
		ans[idx] = idxMinim;
	}
	if(!valid) {
		printf("impossible\n");
	}else{
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]+1);
		}
		printf("\n");
	}

	
	return 0;
};