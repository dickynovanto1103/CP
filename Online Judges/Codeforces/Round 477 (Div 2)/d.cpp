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

bool cmp(ii a, ii b){
	return a.first < b.first;
}

int main(){
	int n,i,j;
	int x1,x2;
	int c[maxn];
	int listMinim[maxn], listMaks[maxn];
	ii pas[maxn];
	scanf("%d %d %d",&n,&x1,&x2);

	for(i=0;i<n;i++){scanf("%d",&c[i]); pas[i].first = c[i]; pas[i].second = i+1; listMaks[i] = -inf; listMinim[i] = inf;}

	sort(pas, pas+n, cmp);
	vi listBil, listIdx;
	for(i=0;i<n;i++){
		listBil.pb(pas[i].first);
	}

	bool isSwapped = false;
	if(x1 > x2){swap(x1,x2); isSwapped = true;}
	
	int banyak1 = -1, banyak2 = -1, banyakTerambil = 0;
	vi list1, list2;
	for(i=1;i<=n;i++){ //buat urusan maks
		int hasilBagi = maks / i;
		if(maks % i != 0){hasilBagi++;}
		int idx = n-i;
		int nilai = pas[idx].first;
		if(nilai >= hasilBagi){
			if(maks==x1){
				banyak1 = (n-1) - (n-i) + 1; banyakTerambil = banyak1;
				for(j=n-i;j<n;j++){list1.pb(pas[j].second); }
			}else{
				banyak2 = (n-1) - (n-i) + 1; banyakTerambil = banyak2;
				for(j=n-i;j<n;j++){list2.pb(pas[j].second); printf("yang dipush: %d\n",pas[j].second);}
			}
			printf("i: %d\n",i);
			break;
		}
	}
	if(i==(n+1)){printf("No\n"); return 0;}
	int sisa = n - banyakTerambil;
	if(sisa == 0){printf("No\n"); return 0;}
	printf("sisa: %d\n",sisa);
	int hasilBagi = minim / sisa;
	printf("hasilBagi: %d\n",hasilBagi);
	if(minim % sisa != 0){hasilBagi++;}
	if(pas[0].first >= hasilBagi){
		if(banyak1 == -1){
			banyak1 = sisa;
			for(j=0;j<banyak1;j++){list1.pb(pas[j].second); printf("yang dipush: %d\n",pas[j].second);}
		}else{
			banyak2 = sisa;
			for(j=0;j<banyak2;j++){list2.pb(pas[j].second);}
		}
	}

	printf("Yes\n");
	printf("%d %d\n",banyak1, banyak2);
	for(i=0;i<banyak1;i++){
		if(i){printf(" ");}
		printf("%d",list1[i]);
	}
	printf("\n");

	for(i=0;i<banyak2;i++){
		if(i){printf(" ");}
		printf("%d",list2[i]);
	}
	printf("\n");

	return 0;
};