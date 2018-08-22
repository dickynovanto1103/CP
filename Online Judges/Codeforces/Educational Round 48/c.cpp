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

const int maxn = 3e5 + 5;

deque<ll> bil;
int n;
ll add1[maxn];
ll add2[maxn];

void prepareSum(int code, ll sum){
	for(int i=1;i<n;i++){
		if(bil.size() >= 4){
			for(int j=0;j<4;j++){
				if(j<2){
					ll bilanganPertama = bil.front(); bil.pop_front();
					sum -= 2LL*bilanganPertama;
				}else{
					ll bilanganTerakhir = bil.back(); bil.pop_back();
					sum -= 2LL*bilanganTerakhir;
				}
			}
			if(code==1){
				add1[i] = sum;	
			}else{
				add2[i] = sum;
			}
			
		}else{
			break;
		}
	}
}

int main(){
	int i,j;
	ll a[2][maxn];
	scanf("%d",&n);
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	
	ll sum = 0;
	ll sum1 = 0;
	ll iterasi = 0;
	vi listBil1;
	for(i=0;i<n;i++){
		sum1 += iterasi*a[0][i];
		iterasi++;
		listBil1.pb(a[0][i]);
		bil.pb(a[0][i]);
		sum += 2LL*a[0][i];
	}
	for(i=n-1;i>=0;i--){
		sum1 += iterasi*a[1][i];
		iterasi++;
		listBil1.pb(a[1][i]);
		bil.pb(a[1][i]);
		sum += 2LL*a[1][i];
	}
	add1[0] = sum;

	prepareSum(1,sum);

	sum = 0;
	bil.clear();
	ll sum2 = 0;
	iterasi = 1;
	vi listBil2;
	listBil2.pb()
	for(i=0;i<n;i++){
		sum2 += iterasi*a[1][i];
		iterasi++;
		listBil2.pb(a[1][i]);
		bil.pb(a[1][i]);
		sum += 2LL*a[1][i];
	}
	for(i=n-1;i>=1;i--){
		sum2 += iterasi*a[0][i];
		iterasi++;
		listBil2.pb(a[0][i]);
		bil.pb(a[0][i]);
		sum += 2LL*a[0][i];
	}

	add2[0] = sum;
	
	prepareSum(2,sum);

	//cari yang mode 1 dulu
	ll ans = max(sum1,sum2);
	ll cur = 0;
	int idx;
	bool keAtas = false;
	iterasi = 0;
	int row = 0, col = 0;
	ll sisa1 = sum1, sisa2 = sum2;
	int idxDepan = 0, idxBelakang = listBil2.size();
	for(i=0;i<n;i++){
		if(keAtas){
			col++;
			cur += iterasi*a[row][col];
			row--; iterasi++;
			cur += iterasi*a[row][col];
			col++;

			

			ll penambahan = add1[idx] + ;

			ans = max(ans, cur + penambahan);
			keAtas = false;
		}else{

			cur += iterasi*a[row][col];
			iterasi++; row++;
			cur += iterasi*a[row][col];
			ll penambahan = add2[idx];
			ans = max(cur + penambahan, ans);
			idx++;
			keAtas = true;
		}
	}
	printf("%lld\n",ans);
	return 0;
};