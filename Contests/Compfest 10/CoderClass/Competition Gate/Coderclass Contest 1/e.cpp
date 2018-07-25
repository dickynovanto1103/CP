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

const int maxn = 2e4 + 4;

int a[maxn];
int n,k;
double getBiaya(double pusat){
	double kiri = pusat - (double)k/2.0;
	double kanan = pusat + (double)k/2.0;
	double sum = 0;
	for(int i=0;i<n;i++){
		if(a[i] < kiri){
			double selisih = kiri - (double)a[i];
			sum+=(selisih*selisih);
		}
		if(a[i] > kanan){
			double selisih = (double)a[i] - kanan;
			sum+=(selisih*selisih);
		}
	}
	return sum;
}

int main(){
	int i,j;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	double kiri = 0, kanan = 20000;
	double biayaMin;
	for(int tt=1;tt<=100;tt++){
		double t1 = kiri + (kanan-kiri)/3;
		double t2 = kiri + ((kanan-kiri)*2)/3;

		//cari biaya di t1
		double biaya1 = getBiaya(t1);
		double biaya2 = getBiaya(t2);
		if(biaya1 > biaya2){
			biayaMin = biaya2;
			kiri = t1;
		}else{
			biayaMin = biaya1;
			kanan = t2;
		}
	}
	printf("%.8lf\n",biayaMin);
	return 0;
};