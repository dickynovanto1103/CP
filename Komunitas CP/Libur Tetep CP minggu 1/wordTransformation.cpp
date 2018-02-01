#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
typedef vector<int> vi;

vector<vi> AdjList;

int diff(string kata1, string kata2){
	int panjang1 = kata1.length(), panjang2 = kata2.length();
	if(panjang1!=panjang2){
		return inf;//inf
	}else{
		int cnt = 0;
		for(int i=0;i<panjang1;i++){
			if(kata1[i]!=kata2[i]){cnt++;}
			if(cnt==2){break;}
		}
		return cnt;
	}
}
vi dist;
int main(){
	string kata[210];
	map<string,int> mapper;
	int i,j;
	int tc, test=1;
	scanf("%d",&tc);
	while(tc--){
		if(test>1){printf("\n");}
		//printf("test %d\n",test++);
		i=0;
		getline(cin>>ws,kata[i]);
		while(kata[i]!="*"){
			mapper[kata[i]] = i;
			i++;
			getline(cin,kata[i]);
		}
		int n = i;
		AdjList.assign(n,vi());
		/*printf("kata:\n");
		for(i=0;i<n;i++){
			cout<<kata[i]<<endl;
		}*/
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				int dif = diff(kata[i],kata[j]);
				if(dif==1){AdjList[i].push_back(j);AdjList[j].push_back(i);}
			}
		}
		/*for(i=0;i<n;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){printf(" %d",AdjList[i][j]);}
			printf("\n");
		}
		printf("dict: \n");
		for(i=0;i<n;i++){
			cout<<kata[i]<<" ";printf("%d\n",mapper[kata[i]]);
		}*/
		string kata;
		//getline(cin,kata);
		
		while(getline(cin,kata) && kata!=""){
			stringstream ss(kata);
			string kata1, kata2;
			dist.assign(n,inf);
			ss>>kata1>>kata2;
			//bfs
			int s = mapper[kata1];
			int d = mapper[kata2];
			queue<int> q;
			dist[s] = 0; q.push(s);
			while(!q.empty()){
				int front = q.front(); q.pop();
				//printf("front: %d\n",front);
				for(i=0;i<AdjList[front].size();i++){
					int v = AdjList[front][i];
					//printf("cek tetangga: %d\n",v);
					if(dist[v]==inf){
						dist[v] = dist[front] + 1;
						//printf("dist menjadi: %d\n",dist[v]);
						q.push(v);
					}
					//if(v == d){break;}
				}
			}
			cout<<kata1<<" "<<kata2; printf(" %d\n",dist[d]);
			//cout<<kata1<<" : "<<kata2<<endl;

		}
		test++;
		AdjList.clear(); mapper.clear(); dist.clear();
	}
	return 0;
}