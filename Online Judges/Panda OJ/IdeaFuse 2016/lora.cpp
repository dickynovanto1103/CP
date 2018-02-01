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
	int n,m,i,j;
	string kata[55];
	int dist[5][55][55];
	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};

	scanf("%d %d",&n,&m);
	for(int tt=0;tt<5;tt++){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				dist[tt][i][j] = inf;
			}
		}		
	}
	
	for(i=0;i<n;i++){cin>>kata[i];}
	ii listKoordinat[5];
	vii listKoordinatAngka;
	map<int,ii> mapper;
	
	int ukuran = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			char kar = kata[i][j];
			if(kar=='E' || kar=='1'|| kar=='2'|| kar=='3'|| kar=='4'){
				int bil = kar-'0';
				if(kar=='E'){bil = 0;}
				mapper[bil] = ii(i,j);
				listKoordinat[bil] = ii(i,j);
				ukuran++;
			}
		}
	}

	for(i=0;i<ukuran;i++){
		//resetting dist
		queue<ii> q; q.push(listKoordinat[i]);
		int a = listKoordinat[i].first, b = listKoordinat[i].second;
		dist[i][a][b] = 0;
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int x = front.first, y = front.second;	
			for(j=0;j<4;j++){
				int xbaru = x+dx[j], ybaru = y+dy[j];
				if(dist[i][xbaru][ybaru]==inf){
					dist[i][xbaru][ybaru] = 1 + dist[i][x][y];
					q.push(ii(xbaru,ybaru));
				}
			}
		}
	}
	int minim = inf;
	int listAngka[] = {1,2,3,4};
	do{
		
		vi listIdx;
		listIdx.pb(mapper[0]);
		for(i=0;i<4;i++){
			int angka = listAngka[i];
			listIdx.pb(mapper[angka]);
		}
		listIdx.pb(mapper[0]);
		int jarak = 0;
		for(i=0;i<5;i++){
			int angka = listIdx[i];
			if(i==0||i==4){jarak+=}
			jarak+=
		}
	}while(next_permutation(listAngka,listAngka+4));
	return 0;
};