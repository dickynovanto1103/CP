#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int s[2010],f[2010];
int n,memoatas[2010][2010],memobawah[2010][2010];
int valueatas(int id, int w, int batas_akhir) {
  //if (id==tidak_mau)	 return memo[id][w] = value(id + 1, w);
  if (id == batas_akhir || w == 0) return 0;
  if (memoatas[id][w] != -1) return memoatas[id][w];
  if (s[id] > w)         return memoatas[id][w] = valueatas(id + 1, w, batas_akhir);
  return memoatas[id][w] = max(valueatas(id + 1, w, batas_akhir), f[id] + valueatas(id + 1, w - s[id], batas_akhir));
}
int valuebawah(int id, int w, int batas_akhir) {
  //if (id==tidak_mau)	 return memo[id][w] = value(id + 1, w);
  if (id == batas_akhir || w == 0) return 0;
  if (memobawah[id][w] != -1) return memobawah[id][w];
  if (s[id] > w)         return memobawah[id][w] = valuebawah(id + 1, w, batas_akhir);
  return memobawah[id][w] = max(valuebawah(id + 1, w, batas_akhir), f[id] + valuebawah(id + 1, w - s[id], batas_akhir));
}

int main(){
	int maks,i,j;
	int q,k;
	int tidak_mau;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&s[i],&f[i]);
	}
	memset(memoatas,-1,sizeof memoatas);
	memset(memobawah,-1,sizeof memobawah);
	scanf("%d",&q);
	int ans = 0;
	while(q--){
		
		scanf("%d %d",&maks,&tidak_mau);
		tidak_mau--;
		//knapsack
		int ans = -1;
		for(i=0;i<=maks;i++){
			int nilai1 = valuebawah(0,i,tidak_mau);
			int nilai2 = valueatas(tidak_mau+1,maks-i,n);
			ans = max(ans,nilai1+nilai2);
		}
		printf("%d\n",ans);
		//printf("tidak mau\n");
	}
	return 0;
}