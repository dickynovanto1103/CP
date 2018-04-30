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

const int maxn = 1e5 + 5;

int main(){
	int n,m,banyakTangga, banyakLift, v,i;
	scanf("%d %d %d %d %d",&n,&m,&banyakTangga,&banyakLift,&v);
	int listTangga[maxn], listLift[maxn];
	for(i=0;i<banyakTangga;i++){
		scanf("%d",&listTangga[i]);
	}

	sort(listTangga, listTangga+banyakTangga);
	for(i=0;i<banyakLift;i++){
		scanf("%d",&listLift[i]);
	}
	sort(listLift, listLift+banyakLift);

	int q;
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		// printf("%d %d %d %d\n",x1,y1,x2,y2);
		if(x1==x2){printf("%d\n",abs(y1-y2)); continue;}
		//jawab
		ll ans = (ll)inf*100LL;
		if(banyakTangga>0){
			int idxTanggaSesudah = lower_bound(listTangga, listTangga + banyakTangga, y1) - listTangga;
			if(idxTanggaSesudah==banyakTangga){idxTanggaSesudah--;}
			int yTanggaSesudah = listTangga[idxTanggaSesudah];

			ll jarak = 0;
			jarak = abs(y1 - yTanggaSesudah) + abs(yTanggaSesudah - y2); //waktu jalan ke kanan kiri
			ll lamaTangga = abs(x1-x2);
			jarak+=lamaTangga;
			ans = min(ans,jarak);

			int idxTanggaSebelum = lower_bound(listTangga, listTangga + banyakTangga, y1) - listTangga;
			if(idxTanggaSebelum>0){idxTanggaSebelum--;}
			int yTanggaSebelum = listTangga[idxTanggaSebelum];	
			//cari jawaban terpendek

			jarak = 0;
			jarak = abs(y1 - yTanggaSebelum) + abs(yTanggaSebelum - y2); //waktu jalan ke kanan kiri
			lamaTangga = abs(x1-x2);
			jarak+=lamaTangga;
			ans = min(ans,jarak);

		}
		
		if(banyakLift>0){
			int idxLiftSesudah = lower_bound(listLift, listLift + banyakLift, y1) - listLift;
			if(idxLiftSesudah==banyakLift){idxLiftSesudah--;}
			int yLiftSesudah = listLift[idxLiftSesudah];

			ll jarak = 0;
			jarak = abs(y1 - yLiftSesudah) + abs(yLiftSesudah - y2); //waktu jalan ke kanan kiri
			ll lamaLift = abs(x1-x2) / v;
			if(abs(x1-x2) % v != 0){lamaLift++;}
			jarak+=lamaLift;
			ans = min(ans,jarak);

			int idxLiftSebelum = lower_bound(listLift, listLift + banyakLift, y1) - listLift;
			if(idxLiftSebelum>0){idxLiftSebelum--;}
			int yLiftSebelum = listLift[idxLiftSebelum];	
			//cari jawaban terpendek

			jarak = 0;
			jarak = abs(y1 - yLiftSebelum) + abs(yLiftSebelum - y2); //waktu jalan ke kanan kiri
			lamaLift = abs(x1-x2) / v;
			if(abs(x1-x2) % v != 0){lamaLift++;}
			jarak+=lamaLift;
			ans = min(ans,jarak);			
		}
		printf("%lld\n",ans);
	}
	return 0;
};