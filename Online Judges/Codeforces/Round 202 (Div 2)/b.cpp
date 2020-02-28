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

bool canReplace(int v, int harga1, int harga2) {
	v += harga1;
	return (v >= harga2);
}

int main(){
	int v,i,j;
	int d[10];
	while(scanf("%d",&v) != EOF){
		bool bisa = false;
		int minim = inf;
		int angka = 0;
		for(i=1;i<=9;i++){
			scanf("%d",&d[i]);
			if(minim > d[i]){
				minim = d[i];
				angka = i;
			}

			if(d[i] <= v){
				bisa = true;
			}
		}
		if(!bisa){
			printf("-1\n");
			continue;
		}
		int banyakMaks = v / minim;

		string ans = "";
		for(i=0;i<banyakMaks;i++){
			ans += (angka + '0');
		}
		int sisa = v % minim;
		for(i=0;i<banyakMaks;i++){
			for(j=9;j>angka;j--){
				//coba ganti
				sisa += d[angka];
				if(sisa >= d[j]){
					sisa -= d[j];
					ans[i] = (j + '0');
					break;
				}else{
					sisa -= d[angka];
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
};