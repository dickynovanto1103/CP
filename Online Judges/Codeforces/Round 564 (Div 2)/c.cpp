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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn];

bool ada[maxn];

bool isSorted(int n){
	for(int i=0;i<n;i++){
		if(b[i] == (i+1)){continue;}
		else{return false;}
	}
	return true;
}

int waktu;

bool can(int mid, int n) {
	int i,j;

	for(i=0;i<mid;i++){
		if(b[i]){ada[b[i]] = true;}
	}
	waktu = mid;
	int next = 1;

	if(mid == 0){
		//cari next bil dicari apa;
		int bil = b[n-1]-1;
		if(bil == 0){next = 2;goto here;}
		next = bil+2;
		bool valid = true;

		for(i=n-2;i>=0;i--){
			if(b[i] == bil) {
				bil--;
				if(bil == 0){break;}
			}else{
				valid = false;
				break;
			}
		}
		if(!valid){next = 1;}
	}
	here:;
	waktu = mid;
	int idx = mid;
	// printf("next: %d\n",next);
	for(i=next;i<=n;i++){
		if(ada[i]){
			//jalan
			if(idx < n){
				if(b[idx]){
					ada[b[idx]] = true;
				}
				idx++;
			}
			waktu++;
		}
		else{return false;}
	}
	return true;
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	memset(ada, false, sizeof ada);
	set<int> bil, temp;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]){ada[a[i]] = true;}
	}
	for(i=0;i<n;i++){scanf("%d",&b[i]);}
	if(isSorted(n)){printf("0\n"); return 0;}
	//binser
	//cek dulu
	int kiri = 0, kanan = n, mid, ans;
	if(can(0,n)){printf("%d\n",waktu); return 0;}
	// else{printf("tidak bisa\n");}
	while(kiri <= kanan) {
		memset(ada, false, sizeof ada);
		for(i=0;i<n;i++){
			if(a[i]){ada[a[i]] = true;}
		}
		waktu = 0;
		mid = (kiri+kanan)/2;
		if(can(mid,n)){
			ans = waktu;
			kanan = mid-1;
			// printf("bisa: ans: %d\n",ans);
		}else{
			// printf("ga bs: kiri: %d\n", mid+1);
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};