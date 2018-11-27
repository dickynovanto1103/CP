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

int titik[maxn];
int parent[maxn];
int size[maxn];
int ranking[maxn];

void makeSet(int v){
	parent[v] = v;
	size[v] = 1;
	ranking[v] = 0;
}

int findSet(int v){
	if(v == parent[v]){return v;}
	return parent[v] = findSet(parent[v]);
}

void merge(int a, int b){
	a = findSet(a);
	b = findSet(b);
	if(a != b){
		if(size[a] < size[b]){
			swap(a,b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}

int main(){
	int n,i,j,q;
	scanf("%d",&n);
	for(i=1;i<=n;i++){makeSet(i);}
	scanf("%d",&q);
	while(q--){
		char kar;
		cin>>kar;
		if(kar == 'Q'){
			int bil;
			scanf("%d",&bil);
			printf("%d\n",size[findSet(bil)]);
		}else{
			int a,b;
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
	}
	return 0;
};