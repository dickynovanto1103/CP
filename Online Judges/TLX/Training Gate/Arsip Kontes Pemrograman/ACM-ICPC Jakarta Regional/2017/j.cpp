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

const int maxn = 100010;
ll a[maxn];

int main(){
	int n,k,t,i,j;
	
	scanf("%d %d %d",&n,&k,&t);
	ll biaya = 0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>t){biaya = (a[i]-t); a[i] = t; }
	}
	if(t==0){
		if(n==k){
			printf("0\n");
		}else{
			printf("-1\n");
		}
		return 0;
	}
	
	sort(a,a+n);
	if(k==n){printf("%lld\n",biaya);}
	else{
		if(a[k-1]!=a[k]){//udah pas k orang
			printf("%lld\n",biaya);
		}else{
			int patokan = a[k-1];
			//antara mau ngurangin kiri atau nambahin yang kanan dengan syarat masing-masing

			//iterasi ke kiri
			ll tambahan1 = 0;
			int idx = k-1;
			while(a[idx]==patokan && idx>=0 && a[idx]>0){
				tambahan1++;
				idx--;
			}
			//iterasi ke kanan
			ll tambahan2 = 0;
			idx = k;
			while(a[idx]==patokan && idx<n && a[idx]<t) {
				tambahan2++;
				idx++;
			}
			ll total = biaya;
			if(tambahan1==0) {
				total+=tambahan2;
			}else if(tambahan2==0){
				total+=tambahan1;
			}
			if(tambahan1!=0 && tambahan2!=0){total+=min(tambahan1,tambahan2);}
			// printf("biaya: %lld\n",biaya);
			// printf("tambahan1: %lld tambahan2: %lld\n",tambahan1,tambahan2);
			printf("%lld\n",total);
		}
	}
	
	return 0;
};
