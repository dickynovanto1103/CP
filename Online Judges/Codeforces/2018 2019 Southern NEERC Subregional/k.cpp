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

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int sum = 0;
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(sum % k == 0){
		int bagi = sum / k;
		int jumlah = 0;
		int cnt = 0;
		vi listBil;
		for(i=0;i<n;i++){
			if((jumlah + a[i]) > bagi) {
				printf("No\n");
				return 0;
			}else{
				jumlah += a[i];
				cnt++;
				if(jumlah == bagi){
					jumlah = 0;
					listBil.pb(cnt);
					cnt = 0;
				}
			}
		}
		printf("Yes\n");
		for(i=0;i<listBil.size();i++){
			if(i){printf(" ");}
			printf("%d",listBil[i]);
		}
		printf("\n");
	}else{

		printf("No\n");
	}
	return 0;
};