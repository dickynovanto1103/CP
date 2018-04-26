#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-12
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	long double s,y;
	scanf("%d",&tc);
	long double v[15], d[15], p[15], c[15];
	while(tc--){
		scanf("%d %Lf %Lf",&n,&s,&y);
		for(i=0;i<n;i++){
			scanf("%Lf",&v[i]);
		}
		for(i=0;i<n;i++){
			scanf("%Lf",&d[i]);
		}
		for(i=0;i<n;i++){
			scanf("%Lf",&p[i]);
		}
		for(i=0;i<n;i++){
			scanf("%Lf",&c[i]);
		}

		double time = 0;
		//proses jalan satu"
		for(i=0;i<n;i++){
			double lama = y/s;
			double awalJalan = time;
			double akhirJalan = awalJalan+lama;
			
			//cari waktu awal dan akhir dari mobil
			double waktuDepan, waktuBelakang; //ketika sampai di 0
			long double pengali = -1;
			if(p[i]<eps){p[i]*=pengali;}

			waktuDepan = p[i]/v[i];
			waktuBelakang = (p[i] + c[i])/v[i];
			double selisih1 = waktuDepan - akhirJalan;
			double selisih2 = awalJalan - waktuBelakang;

			if(selisih1 >= eps || selisih2>=eps){
				time+=lama;
			}else{
				time = waktuBelakang;
				time+=lama;
			}
		}
		printf("%.9lf\n",time);
	}
	return 0;
};