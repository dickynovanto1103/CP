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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int a,b,x,y,n;
	while(scanf("%d %d %d %d %d",&a,&b,&x,&y,&n)!=EOF){
		int i,j;
		int minim = inf, maks = -inf;
		int maksA = a*x;
		int maksB = b*y;
		for(i=0;i<=maksA;i++){
			int awal = i;
			int sisa = n-awal;
			int banyak1 = min(awal/x, a);
			int banyak2 = min(sisa/y, b);
			if(banyak1 >= 0 && banyak2 >= 0){
				maks = max(maks, banyak2 + banyak1);
			}
			banyak1 = awal/a;
			int atasBanyak1 = (awal+a-1)/a;
			banyak2 = sisa/b;
			int atasBanyak2 = (sisa+b-1)/b;
			int ans = 0;
			if(banyak1 >= x){
				ans += a;
				// printf("ditambah penuh a: %d\n",a);
			}else{
				if(atasBanyak1 >= x) {
					ans += awal%a;
					// printf("ditambah sisa awal %d\n",awal%a);
				}
			}
			if(banyak2 >= y){
				ans += b;
				// printf("ditambah penuh b: %d\n",b);
			}else{
				if(atasBanyak2 >= y) {
					// printf("ditambah sisa sisa %d\n",sisa%b);
					ans += sisa%b;
				}
			}
			minim = min(minim,ans);
			// printf("awal: %d sisa: %d ans: %d\n",awal, sisa, ans);
		}
		for(i=0;i<=maksB;i++){
			
			int sisa = i;
			int awal = n-sisa;
			int banyak1 = min(awal/x, a);
			int banyak2 = min(sisa/y, b);
			if(banyak1 >= 0 && banyak2 >= 0){
				maks = max(maks, banyak2 + banyak1);
			}
			banyak1 = awal/a;
			int atasBanyak1 = (awal+a-1)/a;
			banyak2 = sisa/b;
			int atasBanyak2 = (sisa+b-1)/b;
			int ans = 0;
			if(banyak1 >= x){
				ans += a;
				// printf("ditambah penuh a: %d\n",a);
			}else{
				if(atasBanyak1 >= x) {
					ans += awal%a;
					// printf("ditambah sisa awal %d\n",awal%a);
				}
			}
			if(banyak2 >= y){
				ans += b;
				// printf("ditambah penuh b: %d\n",b);
			}else{
				if(atasBanyak2 >= y) {
					// printf("ditambah sisa sisa %d\n",sisa%b);
					ans += sisa%b;
				}
			}
			minim = min(minim,ans);
			// printf("awal: %d sisa: %d ans: %d\n",awal, sisa, ans);
		}
		printf("%d %d\n",minim, maks);
	}
	

	return 0;
};