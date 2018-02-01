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

const int maxn = 1e5 + 5;

int a[maxn], parent[2*maxn];
vector<vi> AdjList, listNodeTinggi;

int main(){
	int h,i,j;
	scanf("%d",&h);
	bool isAmbiguous = false;
	AdjList.assign(2*maxn,vi());
	listNodeTinggi.assign(2*maxn,vi());
	int sum = 0;
	for(i=0;i<=h;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		//if(i%2==0 && a[i]!=1){isAmbiguous = true;}
	}
	for(i=0;i<h;i++){
		if(a[i]>1 && a[i+1]>1){isAmbiguous = true; break;}
	}
	if(!isAmbiguous){printf("perfect\n");}
	else{
		int node = 1;
		map<int, int> mapper; //map ketinggian ke ortu
		for(i=1;i<=h;i++){
			int banyak = a[i];
			int ortu = node;
			mapper[i] = ortu;
			while(banyak>0){
				parent[++node] = ortu;
				AdjList[ortu].pb(node);
				listNodeTinggi[i].pb(node);
				banyak--;
			}
		}

		//cetak
		printf("ambiguous\n");
		for(i=1;i<=sum;i++){
			if(i>1){printf(" ");}
			printf("%d",parent[i]);
		}
		printf("\n");

		//observasi node kosong
		for(i=1;i<=h;i++){
			if(a[i]!=1 && a[i+1]!=1){break;}
		}
		int idx = i+1;
		//printf("idx: %d\n",idx);
		int ortuAwal = mapper[idx];
		int ortuSekarang;
		for(int indeks = 0; indeks<listNodeTinggi[i].size();indeks++) {
			if(listNodeTinggi[i][indeks]!=ortuAwal){ortuSekarang = listNodeTinggi[i][indeks]; break;}
		}
		int nodeAnak = listNodeTinggi[idx][0];
		parent[nodeAnak] = ortuSekarang;
		//printf("ortuSekarang: %d ortuAwal: %d\n",ortuSekarang,ortuAwal);
		for(i=1;i<=sum;i++){
			if(i>1){printf(" ");}
			printf("%d",parent[i]);
		}
		printf("\n");
	}
	return 0;
};

//can the value of a0 >1?