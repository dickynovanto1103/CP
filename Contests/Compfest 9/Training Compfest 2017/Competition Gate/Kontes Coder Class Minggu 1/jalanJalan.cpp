#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
int a[201],tengah;
bool memo[210][50010];

void print(vector<char> listAns){
	int ukuran = listAns.size(),i;
	for(i=0;i<ukuran;i++){
		printf("%c",listAns[i]);
	}
	printf("\n");
}

int main() {
	int tc,i,j;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int sum = 0;
		for(i=0;i<n;i++){scanf("%d",&a[i]); sum+=a[i];}
		tengah = sum/2;
		//dp subset sum
		for(i=0;i<=n;i++){memo[i][0] = true;}//sum 0 pasti true
		for(j=1;j<=tengah;j++){memo[0][j] = false;}//no barang dan sum>0..pasti false
		for(i=1;i<=n;i++){
			for(j=1;j<=tengah;j++){
				if(j<a[i-1]){memo[i][j] = memo[i-1][j];}
				else{memo[i][j] = memo[i-1][j] || memo[i-1][j-a[i-1]];}//ambil atau ngga
			}
		}
		
		/*for(i=0;i<=n;i++){
			for(j=0;j<=tengah;j++){
				printf("%d ",memo[i][j]);
			}
			printf("\n");
		}*/
		//cari jawaban dulu
		ll luas = 0;
		for(i=tengah;i>=0;i--){
			if(memo[n][i]){luas = max(luas,(ll)i*((ll)sum-(ll)i)); break;}
		}
		printf("%lld\n",luas);
		int jumlahMax = i;
		//rintf("jumlahMax: %d\n",jumlahMax);
		vector<char> listAns;
		for(i=n;i>=1;i--){
			if(memo[i-1][jumlahMax]){listAns.pb('R');}
			else if(jumlahMax>=a[i-1] && memo[i-1][jumlahMax-a[i-1]]){listAns.pb('D'); jumlahMax-=a[i-1];}
		}
		//print(listAns);
		int ukuran = listAns.size(),i;
		for(i=ukuran-1;i>=0;i--){
			printf("%c",listAns[i]);
		}
		printf("\n");
		//printf("tengah: %d\n",tengah);
		/*backtrack();
		ll jawaban = ((ll)ans)*((ll)sum-(ll)ans);
		printf("%d\n",jawaban);
		int ukuran = listAns.size();
		for(i=ukuran-1;i>=0;i--){printf("%c",listAns[i]);}
		printf("\n");
		listAns.clear();*/
	}
	return 0;
}
