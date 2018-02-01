#include <bits/stdc++.h>

using namespace std;
#define maxn 2005
int n,s[maxn],f[maxn];
int memoatas[maxn][maxn],memobawah[maxn][maxn];
int solveatas(int id, int w){
	if(id==n || w==0){return 0;}
	if(memoatas[id][w]!=-1){return memoatas[id][w];}
	if(s[id]>w){return memoatas[id][w] = solveatas(id+1, w);}
	return memoatas[id][w] = max(solveatas(id+1,w), f[id] + solveatas(id+1,w-s[id]));
}
int solvebawah(int id, int w){
	if(id<0 || w==0){return 0;}
	if(memobawah[id][w]!=-1){return memobawah[id][w];}
	if(s[id]>w){return memobawah[id][w] = solvebawah(id-1,w);}
	return memobawah[id][w] = max(solvebawah(id-1,w), f[id] + solvebawah(id-1,w-s[id]));
}

int main(){
	int q,i,j;
	int maks,id;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d %d",&s[i],&f[i]);}
	scanf("%d",&q);
	memset(memoatas,-1,sizeof memoatas);
	memset(memobawah,-1,sizeof memobawah);
	while(q--){
		scanf("%d %d",&maks,&id); id--;
		int ans = -1;
		for(i=0;i<=maks;i++){
			int nilaiatas = solveatas(id+1,i);
			int nilaibawah = solvebawah(id-1,maks-i);
			ans = max(ans,nilaiatas+nilaibawah);
		}
		printf("%d\n",ans);
		
	}
	return 0;
}