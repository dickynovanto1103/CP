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

int n,l,v1,v2,k;

double cariKoordinat(double kiri, double kanan){
	double tempKiri = kiri, tempKanan = kanan;
	while(fabs(kanan-kiri) >= eps){
		double mid = (kiri+kanan)/2.0;
		double waktu1 = (mid - tempKiri) / (double)v1;
		double waktu2 = (tempKanan - mid) / (double)v2;
		printf("mid: %lf waktu1: %lf waktu2: %lf\n",mid,waktu1,waktu2);
		if(fabs(waktu1 - waktu2) < eps){
			return mid;
		}else{
			if(waktu1 > waktu2){
				kanan = mid;
			}else{
				kiri = mid;
			}
		}
	}
}

int main(){
	
	scanf("%d %d %d %d %d",&n,&l,&v1,&v2,&k);
	double waktu = 0;
	double kiri = 0;
	while(n>0){
		printf("kiri sekarang: %lf\n",kiri);
		double waktuBusKeKanan = ((double)l-kiri)/(double)v2;
		waktu += waktuBusKeKanan;
		kiri += waktuBusKeKanan*v1;
		printf("kiri: %lf waktuBusKeKanan: %lf waktu sekarang: %lf\n",kiri,waktuBusKeKanan,waktu);
		if(kiri>l){break;}
		//binser
		double mid = cariKoordinat(kiri,l);
		printf("mid: %lf\n",mid);
		waktu += (mid-kiri)/(double)v1;
		kiri = mid;
		n-=k;
	}
	printf("%.9lf\n",waktu);
	return 0;
};