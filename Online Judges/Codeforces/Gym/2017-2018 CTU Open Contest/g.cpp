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

const int maxn = 1e6 + 4;

vector<vi> AdjList;
int counter[maxn];
int banyakNol;
int n;
int totalMinimal;

int main(){
	int k,i,j;
	while(scanf("%d %d",&n,&k)!=EOF){
		AdjList.assign(2*n + 1,vi());
		memset(counter, 0, sizeof counter);

		for(i=0;i<n;i++){
			int ukuran;
			scanf("%d",&ukuran);
			for(j=0;j<ukuran;j++){
				int jenis;
				scanf("%d",&jenis);
				AdjList[i].pb(jenis);
				AdjList[i+n].pb(jenis);
			}
		}
		totalMinimal = inf;
		//binser ukuran window
		int kiri = 0, kanan = -1;
		banyakNol = k;
		bool bisa = false;
		int total = 0;
		while(kanan<(2*n)){
			if(banyakNol>0){
				//kanan maju
				kanan++;
				if(kanan>=(2*n)){break;}
				int ukuran = AdjList[kanan].size();
				total+=ukuran;
				for(i=0;i<ukuran;i++){
					int jenis = AdjList[kanan][i];
					counter[jenis]++;
					if(counter[jenis] == 1){
						banyakNol--;
						if(banyakNol == 0){
							bisa = true;
						}
					}
				}
				if(bisa && banyakNol == 0){
					// printf("kiri: %d kanan: %d total jadi: %d\n",kiri,kanan,total);
					totalMinimal = min(totalMinimal, total);	
				}
				
			}else{
				//kiri maju
				int ukuran = AdjList[kiri].size();
				total-=ukuran;
				for(i=0;i<ukuran;i++){
					int jenis = AdjList[kiri][i];
					counter[jenis]--;
					if(counter[jenis] == 0){
						banyakNol++;
					}
				}
				kiri++;
				if(kiri > kanan){
					kanan++;
					if(kanan>=(2*n)){break;}
					int ukuran = AdjList[kanan].size();
					total+=ukuran;
					for(i=0;i<ukuran;i++){
						int jenis = AdjList[kanan][i];
						counter[jenis]++;
						if(counter[jenis] == 1){
							banyakNol--;
							if(banyakNol == 0){
								bisa = true;
							}
						}
					}
					if(bisa && banyakNol == 0){
						// printf("kiri: %d kanan: %d total jadi: %d\n",kiri,kanan,total);
						totalMinimal = min(totalMinimal, total);	
					}
				}else{
					if(bisa && banyakNol == 0){
						// printf("kiri: %d kanan: %d total jadi: %d\n",kiri,kanan,total);
						totalMinimal = min(totalMinimal, total);
					}
				}
			}
		}

		if(bisa){
			printf("%d\n",totalMinimal);	
		}else{
			printf("-1\n");
		}
		

		AdjList.clear();
	}
	return 0;
};