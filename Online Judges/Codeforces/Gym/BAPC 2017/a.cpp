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
	int banyakSlice,banyakRing,i,j;
	double r;
	scanf("%d %d %lf",&banyakSlice,&banyakRing,&r);
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	double minim = inf*1.0;

	double derajatSlice = 180.0/(double)banyakSlice;
	// printf("derajatSlice: %lf\n",derajatSlice);
	double setengahLingkaran = pi*r;
	// printf("setengahLingkaran: %lf\n",setengahLingkaran);
	double panjangCurvePerSlice = (derajatSlice/180.0)*setengahLingkaran;


	double panjangLurus = r/(double)banyakRing;

	for(i=0;i<=banyakRing;i++){
		//lewat y = i..nanti ja
		double jarakKeIDariAwal = panjangLurus*abs(y1-i);
		double radius = panjangLurus*i;

		double jarakMemutar = (radius*pi/(double)banyakSlice) * abs(x1-x2);

		double jarakDariTengahKeAkhir = panjangLurus*abs(i-y2);
		double ans = jarakKeIDariAwal + jarakMemutar + jarakDariTengahKeAkhir;
		minim = min(minim, ans);
	}
	printf("%.9lf\n",minim);

	// double rKecil = panjangLurus*(double)min(y1,y2);
	// printf("rKecil: %lf\n",rKecil);
	// double panjangCurveTerkecil = rKecil*pi/banyakSlice;
	// printf("%lf\n",rKecil*pi);
	// printf("panjangLurus: %lf panjangCurvePerSlice: %lf panjangCurveTerkecil: %lf\n",panjangLurus,panjangCurvePerSlice,panjangCurveTerkecil);
	// int selisihX = abs(x1-x2);
	// int selisihY = abs(y1-y2);
	// double ans = (double)selisihX*(panjangCurveTerkecil);
	// ans += (double)selisihY*(panjangLurus);
	// printf("%.9lf\n",ans);
	return 0;
};