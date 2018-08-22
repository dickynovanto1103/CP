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

struct pasangan{
	int id, nilai;
};

const int maxn = 1e3 + 3;

bool cmp(pasangan a, pasangan b){
	if(a.nilai == b.nilai){return a.id < b.id;}
	return a.nilai > b.nilai;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	pasangan pas[maxn];
	for(i=0;i<n;i++){
		int sum = 0;
		for(j=0;j<4;j++){
			int bil;
			scanf("%d",&bil);
			sum += bil;
		}
		pas[i].id = i; pas[i].nilai = sum;
	}
	sort(pas, pas+n, cmp);
	for(i=0;i<n;i++){
		if(pas[i].id == 0){
			printf("%d\n",i+1);
			return 0;
		}
	}
	return 0;
};