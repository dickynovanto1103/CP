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


int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int kiri = 0, kanan = 1e9, mid, ans;
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
			for(j=0;j<cnt[i]-1;j++){
				// printf("i; %d j: %d\n",i,j);
				if(i == 0){
					if(temp[i][j] == temp[i][j+1]){
						j++;
						// printf("j jadi: %d\n",j);
						continue;
					}
					if(!(temp[i][j] == temp[i][j+1] || temp[i][j] == temp[i+1][j])) {
						valid = false;
						break;
					}
				}else{
					if(temp[i][j] == temp[i][j+1]){
						j++;
						continue;
					}
					if(temp[i][j] != temp[i][j+1]){
						valid = false;
						break;
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
	printf("%d\n",ans);

	return 0;
};