#include <bits/stdc++.h>

using namespace std;
#define inf 100000000000000000LL
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<ll,iii> iiii;
typedef vector<ii> vii;

priority_queue<iiii, vector<iiii>, greater<iiii> > pq;
const int maxn = 201;
ll dist[maxn][maxn][maxn];

int main(){
	int tc,capA,capB,capC,d,i,j,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&capA,&capB,&capC,&d);
		for(i=0;i<=capA;i++){
			for(j=0;j<=capB;j++){
				for(k=0;k<=capC;k++){
					dist[i][j][k] = inf;
				}
			}
		}
		/*k=15; i=0; j=0;
		printf("dist[%d][%d][%d]: %lld\n",k,i,j,dist[k][i][j]);
		k=0; i=15; j=0;
		printf("dist[%d][%d][%d]: %lld\n",k,i,j,dist[k][i][j]);
		k=0; i=0; j=15;
		printf("dist[%d][%d][%d]: %lld\n",k,i,j,dist[k][i][j]);*/
		int batas = min(capC,d);
		ll ans = inf;
		dist[0][0][capC] = 0;
		while(!pq.empty()){pq.pop();}
		pq.push(mp(dist[0][0][capC],mp(0,ii(0,capC))));
		bool found = false;
		while(!pq.empty()){
			iiii front = pq.top(); pq.pop();
			ll jarak = front.first;
			int a = front.second.first, b = front.second.second.first, c = front.second.second.second;
			if((a==d)||(b==d)||(c==d)){
				ans = jarak; found = true;
				break;
			}
			if(jarak>dist[a][b][c]){continue;}
			//a ke b
			//printf("d: %lld a: %d b: %d c: %d\n",d,a,b,c);
			//cek kapasitas maks b
			ll banyakMaks = capB-b;
			ll selisih;
			if(banyakMaks<a){
				selisih = banyakMaks;
				if(dist[a-banyakMaks][b+banyakMaks][c]>dist[a][b][c] + selisih){
					dist[a-banyakMaks][b+banyakMaks][c] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a-banyakMaks][b+banyakMaks][c],mp(a-banyakMaks,ii(b+banyakMaks,c))));
				}
			}else{
				banyakMaks = a;
				selisih = banyakMaks;
				if(dist[a-banyakMaks][b+banyakMaks][c]>dist[a][b][c] + selisih){
					dist[a-banyakMaks][b+banyakMaks][c] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a-banyakMaks][b+banyakMaks][c],mp(a-banyakMaks,ii(b+banyakMaks,c))));
				}
			}

			//a ke c
			banyakMaks = capC-c;
			if(banyakMaks<a){
				selisih = banyakMaks;
				if(dist[a-banyakMaks][b][c+banyakMaks]>dist[a][b][c] + selisih){
					dist[a-banyakMaks][b][c+banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a-banyakMaks][b][c+banyakMaks],mp(a-banyakMaks,ii(b,c+banyakMaks))));
				}
			}else{
				banyakMaks = a;
				selisih = banyakMaks;
				if(dist[a-banyakMaks][b][c+banyakMaks]>dist[a][b][c] + selisih){
					dist[a-banyakMaks][b][c+banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a-banyakMaks][b][c+banyakMaks],mp(a-banyakMaks,ii(b,c+banyakMaks))));
				}
			}
			//b ke c
			banyakMaks = capC-c;
			
			if(banyakMaks<b){
				selisih = banyakMaks;
				if(dist[a][b-banyakMaks][c+banyakMaks]>dist[a][b][c] + selisih){
					dist[a][b-banyakMaks][c+banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a][b-banyakMaks][c+banyakMaks],mp(a,ii(b-banyakMaks,c+banyakMaks))));
				}
			}else{
				banyakMaks = b;
				selisih = banyakMaks;
				if(dist[a][b-banyakMaks][c+banyakMaks]>dist[a][b][c] + selisih){
					dist[a][b-banyakMaks][c+banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a][b-banyakMaks][c+banyakMaks],mp(a,ii(b-banyakMaks,c+banyakMaks))));
				}
			}
			//b ke a
			banyakMaks = capA-a;
			if(banyakMaks<b){
				selisih = banyakMaks;
				if(dist[a+banyakMaks][b-banyakMaks][c]>dist[a][b][c] + selisih){
					dist[a+banyakMaks][b-banyakMaks][c] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a+banyakMaks][b-banyakMaks][c],mp(a+banyakMaks,ii(b-banyakMaks,c))));
				}
			}else{
				banyakMaks = b;
				selisih = banyakMaks;
				if(dist[a+banyakMaks][b-banyakMaks][c]>dist[a][b][c] + selisih){
					dist[a+banyakMaks][b-banyakMaks][c] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a+banyakMaks][b-banyakMaks][c],mp(a+banyakMaks,ii(b-banyakMaks,c))));
				}
			}
			//c ke a
			banyakMaks = capA-a;
			if(banyakMaks<c){
				selisih = banyakMaks;
				if(dist[a+banyakMaks][b][c-banyakMaks]>dist[a][b][c] + selisih){
					dist[a+banyakMaks][b][c-banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a+banyakMaks][b][c-banyakMaks],mp(a+banyakMaks,ii(b,c-banyakMaks))));
				}
			}else{
				banyakMaks = c;
				selisih = banyakMaks;
				if(dist[a+banyakMaks][b][c-banyakMaks]>dist[a][b][c] + selisih){
					dist[a+banyakMaks][b][c-banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a+banyakMaks][b][c-banyakMaks],mp(a+banyakMaks,ii(b,c-banyakMaks))));
				}
			}
			//c ke b
			banyakMaks = capB-b;
			if(banyakMaks<c){
				selisih = banyakMaks;
				if(dist[a][b+banyakMaks][c-banyakMaks]>dist[a][b][c] + selisih){
					dist[a][b+banyakMaks][c-banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a][b+banyakMaks][c-banyakMaks],mp(a,ii(b+banyakMaks,c-banyakMaks))));
				}
			}else{
				banyakMaks = c;
				selisih = banyakMaks;
				if(dist[a][b+banyakMaks][c-banyakMaks]>dist[a][b][c] + selisih){
					dist[a][b+banyakMaks][c-banyakMaks] = dist[a][b][c] + selisih;
					pq.push(mp(dist[a][b+banyakMaks][c-banyakMaks],mp(a,ii(b+banyakMaks,c-banyakMaks))));
				}
			}
		}

		//if(pq.empty()){printf("kosong\n");}
		
		//cari nilai di batas
		//klo batas di a
		if(found){
			printf("%lld %d\n",ans,d); continue;
		}
		for(k=d-1;k>=0;k--){
			if(k<=capA){
				for(i=0;i<=capB;i++){
					for(j=0;j<=capC;j++){
						ans = min(ans,dist[k][i][j]);
						
					}
					
				}	
			}
			
			if(ans==0){break;}
			//klo batas di b
			if(k<=capB){
				for(i=0;i<=capA;i++){
					for(j=0;j<=capC;j++){
						ans = min(ans,dist[i][k][j]);
						
					}
					
				}	
			}
			
			
			//klo batas di c
			if(k<=capC){
				for(i=0;i<=capA;i++){
					for(j=0;j<=capB;j++){
						ans = min(ans,dist[i][j][k]);
						
					}
					
				}	
			}
			
			
			if(ans<inf){
				batas = k;
				break;
			}
		}
		if(ans==0){batas = 0;}
		printf("%lld %d\n",ans,batas);
	}
	

	return 0;
};