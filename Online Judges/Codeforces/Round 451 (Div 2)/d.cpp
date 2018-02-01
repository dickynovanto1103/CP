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

const int maxn = 1e6 + 5;
bool ada[maxn];
deque<int> d;

int main(){
	int n,m,k,i,j,bil;
	scanf("%d %d %d",&n,&m,&k);
	if(k==1 || m==1){printf("%d\n",n); return 0;}
	memset(ada,false,sizeof ada);
	int maks = 0;
	for(i=0;i<n;i++){scanf("%d",&bil); ada[bil] = true; maks = max(maks,bil);}
	//list dulu di range menit awal, masukin semua alarm
	for(i=1;i<=m;i++){
		if(ada[i]){d.pb(i);}
	}
	//printf("ukuran awal: %d\n",(int)d.size());
	int ans = 0;
	
	int idxAwal = 1, idxAkhir = m;
	while(true){
		//printf("%d ada: %d\n",idxAwal,ada[idxAwal]);
		//while(i-d.front()>=m && !d.empty()){d.pop_front();}
		while(d.size()>=k && !d.empty()){
			ans++;
			// printf("ukuran: %d k: %d\n",(int)d.size(),k);
			// printf("ans jd: %d\n",ans);
			d.pop_back();
		}
		idxAkhir++;
		//printf("idxAwal :%d idxAkhir: %d\n",idxAwal,idxAkhir);
		if(idxAkhir>1000000){break;}
		if(ada[idxAkhir]==true){d.pb(idxAkhir);}

		if(ada[idxAwal]==true){
			if(!d.empty()){
				d.pop_front();	
			}
			
			//printf("ukuran jd: %d\n",d.size());
		}
		idxAwal++;
		

		
	}
	printf("%d\n",ans);
	return 0;
};