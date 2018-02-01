#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> AdjList1, AdjList2;
int main(){
	int n,m,i,a,bil,j;
	scanf("%d %d",&n,&m);
	AdjList1.assign(n,vi()); AdjList2.assign(m,vi());
	for(i=0;i<n;i++){
		int pjg;
		scanf("%d",&pjg);
		int bil;
		for(j=0;j<pjg;j++){scanf("%d",&bil); bil--; AdjList2[bil].push_back(i); AdjList1[i].push_back(bil); }
		
	}
	//mencari grup
	map<int,int> mapper;
	map<int,int>::iterator it;
	int ans;
	ans = -1;
	int counter = 0;
	for(i=0;i<n;i++){
		//printf("orang ke: %d:",i);
		for(j=0;j<AdjList1[i].size();j++){
			int u = AdjList1[i][j];
			//printf(" %d",u);
			mapper[u] = counter++;
		}
		printf("\n");
		
		for(j=i+1;j<n;j++){
			//printf("j: %d\n",j);
			int cnt=0;
			for(int k=0;k<AdjList1[j].size();k++){
				int u = AdjList1[j][k];
				it = mapper.find(u);
				if(it!=mapper.end()){cnt++;}
			}
			ans = max(ans,cnt);
			
		}
		mapper.clear();
		
	}
	printf("%d\n",ans);
	return 0;
}