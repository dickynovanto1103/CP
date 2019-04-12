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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool cmp(int a, int b){return a > b;}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);

	int a[110];
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
	
	int sisa4 = n, sisa2 = 2*n;
	for(i=0;i<k;i++){
		if(a[i] >= 4){
			while(a[i] >= 4){
				if(sisa4){
					sisa4--;
					a[i] -= 4;
				}else if(sisa2 >= 2){
					sisa2-=2; a[i]-=4;
				}else{
					printf("NO\n"); return 0;
				}
			}
		}
	}

	for(i=0;i<k;i++){
		if(a[i] == 3) {
			if(sisa4){
				a[i] = 0;
				sisa4--;
			}else if(sisa2>=2){
				sisa2 -= 2;
				a[i] = 0;
			}else{
				printf("NO\n"); return 0;
			}
		}
	}

	int slot1=0;

	for(i=0;i<k;i++){
		if(a[i] == 2){
			if(sisa2){
				a[i] = 0;
				sisa2--;
			} else if(sisa4) {
				slot1++;
				sisa4--;
				a[i] = 0;
			} else{
				if(slot1>=2){
					slot1-=2;
					a[i] = 0;
				}else{
					printf("NO\n"); return 0;	
				}
				
			}
		}
	}
	slot1 += sisa4*2;
	for(i=0;i<k;i++){
		if(a[i] == 1){
			if(sisa2){
				a[i]--;
				sisa2--;
			}else if(slot1){
				slot1--;
				a[i]--;
			} else{
				printf("NO\n"); return 0;
			}
		}
	}
	printf("YES\n");

	return 0;
};