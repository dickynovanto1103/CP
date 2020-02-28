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

const int maxn = 3e5 + 5;

int a[maxn], temp[maxn];
int m;

int jarak(int sekarang, int expected) {
	if(expected >= sekarang) {return expected - sekarang;}
	else{return m - (sekarang - expected);}
}

bool can(int mid, int n) {
	if(jarak(a[0], 0) <= mid){
		a[0] = 0;
	}
	for(int i=1;i<n;i++){
		if(jarak(a[i], a[i-1]) <= mid) {
			a[i] = a[i-1];
		}else{
			if(a[i] >= a[i-1]){
				//ok
			}else{
				return false;
			}
		}
	}
	return true;
}

void reset(int n) {
	for(int i=0;i<n;i++){
		a[i] = temp[i];
	}
}

int main(){
	int n,i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		temp[i] = a[i];
	}
	int kiri = 0, kanan = m, mid, ans;
	while(kiri <= kanan) {
		reset(n);
		mid = (kiri+kanan) / 2;
		if(can(mid,n)) {
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
};