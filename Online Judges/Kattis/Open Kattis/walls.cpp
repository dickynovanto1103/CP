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
typedef pair<double,double> ii;
typedef vector<ii> vii;

vector<vi> AdjList;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

bool isVisited[4];

bool isFulfilled(){
	for(int i=0;i<4;i++){
		if(!isVisited[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int panjang, lebar, n,r;
	int x[35], y[35];
	scanf("%d %d %d %d",&panjang,&lebar,&n,&r);
	// printf("%lf\n",hypot(3,4));
	AdjList.assign(n+1,vi());
	ii titik[] = {ii(-(double)panjang/2.0, 0.0), ii((double)panjang/2.0, 0.0), ii(0.0, (double)-lebar/2.0) , ii(0.0, (double)lebar/2.0)};
	int i,j,k,l,m;
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
		for(j=0;j<4;j++){
			double jarak = hypot(titik[j].first-(double)x[i], titik[j].second - (double)y[i]);
			if(fabs(jarak - (double)r) < eps){
				AdjList[i].pb(j);
			}else{
				if(jarak < (double)r){
					AdjList[i].pb(j);	
				}
			}
		}
	}
	
	
	for(i=0;i<n;i++){
		memset(isVisited, false, sizeof isVisited);
		for(j=0;j<AdjList[i].size();j++){
			int v = AdjList[i][j];
			isVisited[v] = true;
		}
		if(isFulfilled()){printf("1\n"); return 0;}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			memset(isVisited, false, sizeof isVisited);
			for(k=0;k<AdjList[i].size();k++){
				int v = AdjList[i][k];
				isVisited[v] = true;
			}
			for(k=0;k<AdjList[j].size();k++){
				int v = AdjList[j][k];
				isVisited[v] = true;
			}
			if(isFulfilled()){printf("2\n"); return 0;}
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				memset(isVisited, false, sizeof isVisited);
				for(l=0;l<AdjList[i].size();l++){
					int v = AdjList[i][l];
					isVisited[v] = true;
				}
				for(l=0;l<AdjList[j].size();l++){
					int v = AdjList[j][l];
					isVisited[v] = true;
				}
				for(l=0;l<AdjList[k].size();l++){
					int v = AdjList[k][l];
					isVisited[v] = true;
				}
				if(isFulfilled()){printf("3\n"); return 0;}
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				for(l=k+1;l<n;l++){
					memset(isVisited, false, sizeof isVisited);
					for(m=0;m<AdjList[i].size();m++){
						int v = AdjList[i][m];
						isVisited[v] = true;
					}
					for(m=0;m<AdjList[j].size();m++){
						int v = AdjList[j][m];
						isVisited[v] = true;
					}
					for(m=0;m<AdjList[k].size();m++){
						int v = AdjList[k][m];
						isVisited[v] = true;
					}
					for(m=0;m<AdjList[l].size();m++){
						int v = AdjList[l][m];
						isVisited[v] = true;
					}
					if(isFulfilled()){printf("4\n"); return 0;}
				}
			}
		}
	}

	
	printf("Impossible\n");
	
	
	
	return 0;
};