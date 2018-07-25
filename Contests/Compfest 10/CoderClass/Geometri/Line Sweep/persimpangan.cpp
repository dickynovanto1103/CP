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

struct pasangan{
	int node, idAwalAtauAkhir, titikAwal, isVertikal;
};

bool cmp(pasangan a, pasangan b){
	if(a.node == b.node){return a.isVertikal > b.isVertikal;}
	return a.node < b.node;
}

int main(){
	int n,i,j;
	scanf("%d",&n);

	vector<pasangan> a;

	for(i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		pasangan pas;
		pas.node = x1, pas.idAwalAtauAkhir = 1, pas.titikAwal = -1, pas.isVertikal = (x1==x2? 1: 0);
		a.pb(pas);
		pas.node = x2, pas.idAwalAtauAkhir = 2, pas.titikAwal = x1, pas.isVertikal = (x1==x2? 1: 0);
		a.pb(pas);
	}

	sort(a.begin(), a.end(), cmp);
	return 0;
};