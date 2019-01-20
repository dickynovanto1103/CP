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

const int maxn = 1e6 + 6;

int a[2][maxn], temp[2][maxn];
int cnt[2];
bool isBedaRow[maxn];
int nomorRow[maxn];
ii indeks[maxn];


int main(){
	int n,i,j;
	scanf("%d",&n);
	map<int,int> mapper;
	int counter = 0;
	memset(a, -1, sizeof a);
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(mapper.find(a[i][j]) == mapper.end()){
				mapper[a[i][j]] = counter++;
			}
		}
	}

	bool isNol = true;

	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			if(i == 0){
				if(a[i][j] == a[i][j+1]){
					j++;
					continue;
				}else{
					if(a[i][j] == a[i+1][j]){

					}else{
						isNol = false;
						break;
					}
				}
			}else{
				if(a[i][j] == a[i][j+1]){
					j++;
					continue;
				}else{
					if(a[i][j] == a[i-1][j]){

					}else{
						isNol = false;
						break;
					}
				}
			}
		}
	}

	if(isNol){printf("0\n"); return 0;}

	memset(nomorRow, -1, sizeof nomorRow);
	memset(isBedaRow, true, sizeof isBedaRow);
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			int id = mapper[a[i][j]];
			if(nomorRow[id]!=-1) {
				if(nomorRow[id] != i){
					indeks[id] = ii(nomorRow[id], j);
					isBedaRow[id] = true;
				}else{
					isBedaRow[id] = false;
				}
			}else{
				nomorRow[id] = i;	
			}
		}	
	}
	int kiri = 1, kanan = inf, mid, ans = -1;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		// printf("mid: %d\n",mid );
		memset(temp, -1, sizeof temp);
		
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<2;i++){
			
			for(j=0;j<n;j++){
				if(a[i][j] > mid){
					temp[i][cnt[i]++] = a[i][j];
				}
			}

		}
		bool valid = true;
		// for(i=0;i<2;i++){
		// 	for(j=0;j<cnt[i];j++){
		// 		printf("%d ",temp[i][j]);
		// 	}
		// 	printf("\n");
		// }

		for(i=0;i<2;i++){
			for(j=0;j<cnt[i];j++){
				// printf("i; %d j: %d\n",i,j);
				if(i == 0){
					if(temp[i][j] == temp[i][j+1]){
						j++;
						// printf("j jadi: %d\n",j);
						continue;
					}else{
						int idx = mapper[temp[i][j]];
						if(isBedaRow[idx]){continue;}
						else{valid = false; break;}
					}
					
				}else{
					if(temp[i][j] == temp[i][j+1]){
						j++;
						continue;
					}else{
						int idx = mapper[temp[i][j]];
						if(isBedaRow[idx]){continue;}
						else{valid = false; break;}	
					}
							
				}
				
			}
			if(!valid){break;}
		}
		
		if(valid){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}

	}
	if(ans < 0){assert(false);}
	printf("%d\n",ans);

	return 0;
};