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

int main(){
	int n,m,i,j;
	while(scanf("%d %d",&n,&m), (n || m)){
		int a,b;
		a = n, b = m;
		int ans = 0;
		if(a %2 == 0 && b % 2 == 0){
			int bagi2 = b/2;
			if(bagi2 % 2 == 0){
				ans += bagi2;
				a += bagi2;
				ans += a/2;
			}else{
				b += 2;
				ans += 2;
				bagi2 = b / 2;
				ans += bagi2;
				a += bagi2;
				ans += a/2;	
			}
		}else if(a % 2 == 0 && b % 2 == 1){

			for(i=b;;i++){
				
				if(i%2 == 0){
					int bagi2 = i/2;

					if(bagi2 % 2 == 0){
						break;
					}
				}
			}
			int selisih = i-b;
			ans += selisih;
			b = i;
			int bagi2 = b / 2;
			ans += bagi2;
			a += bagi2;
			ans += a/2;	
		}else if(a % 2 == 1 && b % 2 == 0) {
			int bagi2 = b/2;
			if(bagi2 % 2 == 1){
				ans += bagi2;
				a += bagi2;
				ans += a/2;
			}else{
				b += 2;
				ans += 2;
				bagi2 = b/2;
				ans += bagi2;
				a += bagi2;
				ans += a/2;
			}
		}else{
			for(i=b;;i++){
				
				if(i%2 == 0){
					int bagi2 = i/2;

					if(bagi2 % 2 == 1){
						break;
					}
				}
			}
			int selisih = i-b;
			ans += selisih;
			b = i;
			int bagi2 = b / 2;
			ans += bagi2;
			a += bagi2;
			ans += a/2;	
		}
		printf("%d\n",ans);
	}
	return 0;
};

/*
kalo genap sama genap...perlu hitung yg tail / 2 ganjil atau genap..kalo genap..lgsg gas..kalo ganjil...tambah 2 move...terus gas

kalo genap sama ganjil...harus ke genap / 2 yg genap yg paling dekat

kalo ganjil sama genap...kalo genap / 2 ganjil...lgsg gas..kalo ngga..tambah 2 move..terus gas

kalo ganjil sama ganjil..ke genap / 2 yg ganjil yg paling dekat

*/