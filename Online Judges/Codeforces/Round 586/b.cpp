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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[1010][1010];
int ans[1010];
bool can(int dua, int n) {
	int temp = dua;
	for(int i=1;i<(n-1);i++){
		if(a[i][i+1] % temp == 0){
			// printf("a[%d][%d]: %d temp: %d\n",i,i+1,a[i][i+1],temp);
			ans[i+1] = a[i][i+1]/temp;
			// printf("ans[%d]: %d\n",i+1,ans[i+1]);
			temp = ans[i+1];	
		}else{
			return false;
		}
	}
	return true;
}

bool check(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i][j] != ans[i] * ans[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int angka = a[0][1];
	for(i=1;i*i<=angka;i++){
		if(angka % i == 0){
			int satu = i, dua = angka/i;
			if(can(dua, n)){

				ans[0] = satu, ans[1] = dua;
				if(check(n)){
					for(j=0;j<n;j++){
						printf("%d ",ans[j]);
					}
					printf("\n");
					return 0;	
				}
				
			}else if(can(satu, n)){
				// printf("sini satu: %d dua: %d\n",satu, dua);
				ans[0] = dua, ans[1] = satu;
				if(check(n)){
					for(j=0;j<n;j++){
						printf("%d ",ans[j]);
					}
					printf("\n");
					return 0;	
				}
				
			}
		}
	}
	
	return 0;
};