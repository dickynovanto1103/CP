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

const int maxn = 50010;
double x[maxn], y[maxn];
int n;

double hitungJarakMaks(double absis){
	int i;
	double maks = 0;
	for(i=0;i<n;i++){
		double jarak = hypot(absis-x[i],0-y[i]);
		maks = max(maks,jarak);
	}
	return maks;
}

int main(){
	int i,j;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%lf %lf",&x[i],&y[i]);}
		double kiri = -200000.0, kanan = -kiri, mid1,mid2, minim = inf;
		for(int tt=0;tt<75;tt++){
			mid1 = kiri + (kanan-kiri)/3.0;
			mid2 = kiri + (kanan-kiri)*2/3.0;
			double hasil1 = hitungJarakMaks(mid1), hasil2 = hitungJarakMaks(mid2);
			minim = min(minim,min(hasil1,hasil2));
			if(hasil1>hasil2){kiri = mid1;}
			else{kanan = mid2;}
		}
		printf("%.9lf %.9lf\n",kiri,minim);
	}
	return 0;
};