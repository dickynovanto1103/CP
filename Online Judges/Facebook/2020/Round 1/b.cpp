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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll p[1000001], q[1000001];
int n,m;

bool can(ll mid) {
	//must search to the left first, then to the right
	int lastLogVisit = 0;
	int i,j;
	// printf("mid: %d\n",mid);
	for(i=0;i<n;i++){
		//search to the left first
		ll waktu = mid;
		ll pos = q[lastLogVisit];
		ll now = p[i];
		if(pos < now){
			ll jarakKeKiri = now - pos;
			if(jarakKeKiri > waktu){
				// printf("hello waktu: %lld, q[%d]: %lld p[%d]: %lld\n", waktu,lastLogVisit, q[lastLogVisit], i, p[i]);
				return false;
			}
			//bisa ke kiri, harus balik dan assign the latest log idx that it cannot reach
			//harus pilih antara ke kanan dulu atau kiri dulu
			//coba ke kiri dulu
			int palingPolKananKalauKiriDulu = -1;
			ll waktuKiriDulu = waktu;
			int idxStartKanan = -1;
			for(j=lastLogVisit;j<m;j++){
				if(q[j] > now){
					idxStartKanan = j;
					break;
				}
			}
			if(idxStartKanan == -1){
				return true; //sudah ga ada di kanan lg, berarti sudah bs dieksplor dari posisi now sampe ke paling kiri yg belum dieksplor	
			}else{
				//log n search
				int kiri = idxStartKanan, kanan = m-1, mid, ans = -1;
				while(kiri <= kanan) {
					mid = (kiri + kanan)/2;
					ll pos = q[mid];
					ll jarakKeKanan = pos - now;
					if(waktuKiriDulu >= ((jarakKeKiri*2LL) + jarakKeKanan)) {
						ans = mid;
						kiri = mid+1;
					} else{
						kanan = mid-1;
					}
				}
				palingPolKananKalauKiriDulu = ans;
			}

			//terus coba ke kanan dulu, baru ke kiri
			int palingPolKananKalauKananDulu = -1;
			ll waktuKananDulu = waktu;
			//log n search
			int kiri = idxStartKanan, kanan = m-1, mid, ans = -1;
			while(kiri <= kanan) {
				mid = (kiri + kanan)/2;
				ll pos = q[mid];
				ll jarakKeKanan = pos - now;
				if(waktuKananDulu >= ((2LL*jarakKeKanan) + jarakKeKiri)){
					ans = mid;
					kiri = mid+1;
				}else{
					kanan = mid-1;
				}
			}
			palingPolKananKalauKananDulu = ans;

			int maksKanan = max(palingPolKananKalauKananDulu, palingPolKananKalauKiriDulu);
			if(maksKanan == m-1){return true;} //sudah bisa ke kanan pol
			else if(maksKanan == -1){lastLogVisit = idxStartKanan;}
			else{
				lastLogVisit = maksKanan + 1;
			}

		}else{
			//klo awalnya udah di kanan...bisa seoptimal mungkin tinggal ke kanan
			bool bisaLanjut = true;
			for(j=lastLogVisit;j<m;j++){
				ll pos = q[j];
				// printf("now: %lld pos: %lld\n",now, pos);
				assert(pos > now);
				ll jarak = pos - now;
				
				lastLogVisit = j;
				if(jarak > waktu) {
					bisaLanjut = false;
					break;
				}
			}
			// printf("lastLogVisit: %d bisaLanjut: %d\n",lastLogVisit, bisaLanjut);
			if(bisaLanjut){return true;} //berarti untuk orang i, dia sudah bisa reach sampe akhir log cluster
			//kalau bisaLanjur = false, berarti lastLogVisit = log terakhir yang ga bs dia visit karena kehabisan waktu, coba diattempt sama orang lain	
		}
		
		// printf("lastLogVisit: %d, mid: %lld\n", lastLogVisit, mid);
		
	}
	return false;
}

int main(){
	int tc,i,j,k,s;
	ll ap,bp,cp,dp, aq,bq,cq,dq;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		
		scanf("%d %d %d %d",&n,&m,&k,&s);
		for(i=0;i<k;i++){
			scanf("%lld",&p[i]);
			// printf("p[%d]: %lld\n",i, p[i]);
		}
		scanf("%lld %lld %lld %lld",&ap,&bp,&cp,&dp);
		for(i=k;i<n;i++){
			ll pertama = ap*p[i-2]; pertama %= dp;
			ll kedua = bp*p[i-1]; kedua %= dp;
			ll bil = pertama + kedua + cp; bil %= dp;
			p[i] = bil; p[i] %= dp;
			p[i]++;
			// printf("p[%d]: %lld\n",i, p[i]);
		}
		sort(p, p+n);
		
		for(i=0;i<k;i++){scanf("%lld",&q[i]);}
		scanf("%lld %lld %lld %lld",&aq,&bq,&cq,&dq);
		for(i=k;i<m;i++){
			ll pertama = aq*q[i-2]; pertama %= dq;
			ll kedua = bq*q[i-1]; kedua %= dq;
			ll bil = pertama + kedua + cq; bil %= dq;
			q[i] = bil;
			q[i]++;
			// printf("q[%d]: %lld\n",i, q[i]);
		}

		sort(q, q+m);
		// printf("q\n");
		// for(i=0;i<m;i++){s.insert(q[i]);}
		// printf("%d\n",(int)s.size());
		// printf("\n");

		ll kiri = 0, kanan = 2000000000LL, mid, ans;
		while(kiri <= kanan){
			mid = (kiri + kanan)/2LL;
			if(can(mid)){
				ans = mid;
				kanan = mid-1;
			}else{
				kiri = mid+1;
			}
		}
		printf("Case #%d: %lld\n",tt, ans);
	}
	
	return 0;
};