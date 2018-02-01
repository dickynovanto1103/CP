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

double a[20010];
int n;
double biaya(double kiri, double kanan){
	double sum = 0;
	for(int i=0;i<n;i++){
		if(a[i]>=kiri && a[i]<=kanan){continue;}
		else{
			double jarak1 = fabs(kiri-a[i]), jarak2 = fabs(kanan-a[i]), minim = min(jarak1,jarak2);
			sum+=(minim*minim);
		}
	}
	return sum;
}

int main() {
	int i;
	double k, maks = -inf, minim = inf;
	scanf("%d %lf",&n,&k);
	for(i=0;i<n;i++){scanf("%lf",&a[i]); maks = max(maks,a[i]); minim = min(minim,a[i]);}
	double kiri = minim, kanan = maks;
	for(i=0;i<500;i++){
		double mid1 = (kiri+kiri+kanan)/3, mid2=(kiri+kanan+kanan)/3;
		double biaya1 = biaya(mid1,mid1+k), biaya2 = biaya(mid2,mid2+k);
		/*printf("biaya1: %lf biaya2: %lf\n",biaya1,biaya2);
		printf("mid1: %lf mid2: %lf\n",mid1,mid2);*/
		if(biaya1 > biaya2){kiri = mid1;}
		else{kanan = mid2;}
		//printf("kiri: %lf mid1: %lf mid2: %lf\n",kiri,mid1,mid2);
	}
	//printf("kiri: %lf kanan: %lf\n",kiri,kanan);	
	printf("%lf\n",biaya(kiri,kiri+k));
	return 0;
}