#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ll a[100010],m,k;
	int i,j,tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %d %lld",&m,&n,&k);
		for(i=0;i<n;i++){scanf("%lld",&a[i]);}
		if(m==0){printf("0\n"); continue;}
		ll volumeAwal = m;
		ll cnt = 0;
		ll minim = inf;
		int idxMin;
		for(i=0;i<n;i++){
			m+=k;
			if(a[i]<=m){//masih cukup...ambil saja airnya
				m-=a[i]; cnt++;
				//printf("cnt jd: %d\n",cnt);
				if(minim>m){minim = m; idxMin = i;}
				if(m==0){break;}
			}
			else{break;}
			//printf("m sekarang: %d\n",m);
		}
		//printf("i: %d cnt: %d\n",i,cnt);
		/*printf("i: %d m: %lld\n",i,m);
		printf("volumeAwal: %lld\n",volumeAwal);
		printf("cnt sementara: %lld\n",cnt );*/
		if(i==n){//cukup dalam n iterasi
			if(m>=volumeAwal){printf("-1\n");}//selalu sama atau lebih besar bahkan setelah n iterasi...ga bakal habis
			else{
				//printf("masuk sini\n");
				ll selisih = volumeAwal - m;
				ll banyakLoop;
				banyakLoop = minim/selisih;
				//if(minim%selisih!=0){banyakLoop++;}
				//cnt = idxMin;
				cnt=(banyakLoop*(ll)n);
				//printf("selisih: %lld banyakLoop: %lld\n",selisih,banyakLoop);
				//printf("cnt mau jadi: %lld\n",cnt);
				//masih ada sisa
				ll sisa = volumeAwal-(banyakLoop*selisih);
				//cnt++; //karena untuk nambahin counter yg terakhir
				//printf("sisa: %lld\n",sisa);
				if(sisa>0){
					while(true){
						for(i=0;i<n;i++){
							sisa+=k;
							if(a[i]<=sisa){sisa-=a[i]; cnt++; if(sisa==0){break;}}
							else{break;}
						}
						if(i<n){break;}
						
					}
					/*for(i=idxMin+1;i<n;i++){
						sisa+=k;
						if(a[i]<=sisa){
							sisa-=a[i]; cnt++;
							if(sisa==0){break;}
						}else{
							break;
						}
					}
					if(sisa>0){
						
								
					}*/
					
				}
				
				printf("%lld\n",cnt);
			}
		}else{
			printf("%lld\n",cnt);
		}
	}
	return 0;
}