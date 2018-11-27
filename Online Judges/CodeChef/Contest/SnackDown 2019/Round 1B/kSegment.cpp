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

struct pasangan{
	int koor, isStart, idx;
};

bool cmp(pasangan a, pasangan b){
	if(a.koor == b.koor){
		return a.isStart > b.isStart;
	}
	return a.koor < b.koor;
}

const int maxn = 2e5 + 5;

int bit[maxn];

void update(int idx, int val){
	for(int i=idx;i<maxn;i+=(i&-i)){
		bit[i]+=val;
		// printf("bit\n");
	}
}
int query(int idx){
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		ans += bit[i];
	}
	return ans;
}

int angka[maxn];
int l[maxn],r[maxn];
int idx;

int findAns(int butuh){
	int kiri = 1, kanan = maxn-1, mid, ans = -1;
	while(kiri <= kanan){
		// printf("kiri: %d kanan: %d\n",kiri,kanan);
		mid = (kiri+kanan)/2;
		int hasil = query(mid);
		if(hasil >= butuh){
			ans = mid;
			kanan = mid - 1;
		}else{
			kiri = mid + 1;
		}
	}
	// printf("ans: %d koordinat: %d\n",ans, angka[ans]);
	int koordinat = angka[ans];
	return koordinat;
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	pasangan pas[maxn];
	while(tc--){
		memset(bit,0, sizeof bit);
		int k,n;
		scanf("%d %d",&n,&k);
		int cnt = 0;
		// printf("n; %d k: %d\n",n,k);
		for(i=0;i<n;i++){
			scanf("%d %d",&l[i],&r[i]);
			// printf("l[%d]: %d r[%d]: %d\n",i,l[i], i,r[i]);
			pas[cnt].koor = l[i];
			pas[cnt].isStart = 1;
			pas[cnt].idx = i;
			cnt++;
			pas[cnt].koor = r[i];
			pas[cnt].isStart = 0;
			pas[cnt].idx = i;
			cnt++;
		}

		sort(pas, pas+cnt, cmp);
		map<int,int> mapper;
		idx = 1;
		for(i=0;i<cnt;i++){
			// printf("%d %d %d\n",pas[i].koor,pas[i].isStart,pas[i].idx);
			if(mapper.find(pas[i].koor) == mapper.end()){
				angka[idx] = pas[i].koor;
				mapper[pas[i].koor] = idx++;
			}
		}
		set<ii> s;
		int maks = 0;
		for(i=0;i<cnt;i++){
			if(pas[i].isStart == 0){//end point
				int indeks = pas[i].idx;
				int koorLeft = l[indeks];
				int koorRight = pas[i].koor;
				int idxMap = mapper[koorRight];
				s.erase(ii(koorLeft, indeks));
				update(idxMap, -1);
			}else{
				int indeks = pas[i].idx;
				s.insert(ii(pas[i].koor,indeks));
				int koorRight = r[indeks];
				int idxMap = mapper[koorRight];
				update(idxMap, 1);
				int ukuran = s.size();
				if(ukuran >= k){
					//hitung
					int kanan = findAns(ukuran - k + 1);
					// if(kanan < pas[i].koor){assert(false);}
					maks = max(maks, kanan - pas[i].koor);
					// printf("kanan: %d pas[%d].koor: %d\n",kanan,i,pas[i].koor);
				}
			}
			
		}
		printf("%d\n",maks);
	}
	return 0;
};