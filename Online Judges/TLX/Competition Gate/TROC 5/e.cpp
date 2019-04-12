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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

int a[maxn], n;

bool isNotSame(int bil, int idx){
	if(idx == 0){
		if(bil != a[idx+1]){return true;}
	}else if(idx == n-1) {
		if(bil != a[idx-1]){return true;}
	}else{
		if(bil != a[idx+1] && bil!=a[idx-1]){return true;}
	}
	return false;
	
}

int main(){
	int k,p,i,j;
	scanf("%d %d %d",&n,&k,&p);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	priority_queue<iii> pq;
	int cur = -1, awal = -1;
	int cnt = 1;
	for(i=0;i<n;i++){
		int bil = a[i];
		if(cur!=bil && cur!=-1){
			pq.push(iii(cnt, ii(awal, i-1)));
			printf("yang dipush: %d %d %d\n",cnt, awal, i-1);
			awal = i;
			cnt = 1;
		}else if(cur == bil){
			cnt++;
		}else if(awal == -1){
			awal = 0;
		}
		cur = bil;
	}

	if(p == 2){
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int cnt = front.first, idxAwal = front.second.first, idxAkhir = front.second.second;
			if(cnt == 1){continue;}
			int idxBerubah;
			bool isChanged = false;
			if(idxAkhir - idxAwal <= 2){//ada 2 kemungkinan
				idxBerubah = idxAwal;
			}else{
				idxBerubah = idxAwal+1;
			}
			for(i=1;i<=p;i++){
				if(isNotSame(i, idxBerubah)){
					a[idxBerubah] = i;
					isChanged = true;
					if(idxAwal != idxAkhir && cnt > 2){
						pq.push(iii(cnt-1, ii(idxAwal+1, idxAkhir)));
					}
					break;
				}
			}
			if(!isChanged){
				idxBerubah++;
				for(i=1;i<=p;i++){
					if(isNotSame(i, idxBerubah)){
						a[idxBerubah] = i;
						isChanged = true;
						if(idxAwal != idxAkhir && cnt > 2){
							pq.push(iii(cnt-1, ii(idxAwal+1, idxAkhir)));
						}
						break;
					}
				}
			}
			int cnt1 = 0, cnt2 = 9;
			if(!isChanged){
				idxBerubah--;
				int elemen = a[idxBerubah];
				int jadi = (elemen == 1? 2: 1);
				a[idxBerubah] = jadi;
				int cur = jadi, cnt = 0;

				for(i=idxBerubah;i>=0;i--){
					if(cur == a[i]){
						cnt1++;
					}else{
						break;
					}
				}
				a[idxBerubah] = elemen;
			}
			if(!isChanged){
				idxBerubah++;
				int elemen = a[idxBerubah];
				int jadi = (elemen == 1? 2: 1);
				a[idxBerubah] = jadi;
				int cur = jadi, cnt = 0;

				for(i=idxBerubah;i<n;i++){
					if(cur == a[i]){
						cnt2++;
					}else{
						break;
					}
				}
				a[idxBerubah] = elemen;
			}
			if(!isChanged){
				if(cnt1 > cnt2){
					a[idxBerubah] = (a[idxBerubah] == 1? 2: 1);
					pq.push(iii(cnt2, ii(idxBerubah, idxBerubah + cnt2 - 1)));
				}else{
					idxBerubah--;
					a[idxBerubah] = (a[idxBerubah] == 1? 2: 1);
					pq.push(iii(cnt1, ii(idxBerubah - cnt1 + 1, idxBerubah)));
				}
			}
			k--;
			if(k == 0){break;}
		}
	}else{
		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int cnt = front.first, idxAwal = front.second.first, idxAkhir = front.second.second;
			printf("idxAwal: %d idxAkhir; %d cnt: %d\n",idxAwal, idxAkhir, cnt);
			if(cnt == 1){continue;}
			bool isChanged = false;
			int idxBerubah;
			if(idxAkhir - idxAwal <= 2){
				idxBerubah = idxAwal;
			}else{
				idxBerubah = idxAwal+1;
			}
			printf("idxBerubah: %d\n",idxBerubah);
			for(i=1;i<=p;i++){
				if(isNotSame(i, idxBerubah)){
					a[idxBerubah] = i;
					if(idxAwal != idxAkhir && cnt > 2){
						pq.push(iii(cnt-1, ii(idxAwal+1, idxAkhir)));
					}
					break;
				}
			}
			k--;
			if(k == 0){break;}
		}	
	}

	
	int ans = 1;
	if(!pq.empty()){
		ans = pq.top().first;
	}
	printf("%d\n",ans);
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};