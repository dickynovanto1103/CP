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

const int maxn = 1010;

int main(){
	int n,cap,i,j;
	scanf("%d %d",&n,&cap);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int kiri = 0, kanan = cap, mid;
	int ansKiri = -1, ansKanan = -1;
	//binser batas kiri dan kanan
	while(kiri<=kanan) {
		int mid = (kiri+kanan) /2;
		int first = mid;
		bool valid = true;
		for(i=0;i<n;i++){
			first+=a[i];
			if(first<0){//batas mid harus dinaikin
				kiri = mid+1;
				valid = false;
				break;
			}else if(first > cap) {
				kanan = mid-1;
				valid = false;
				break;
			}
		}
		if(!valid){continue;}
		else{
			ansKiri = mid;
			kanan = mid-1;
		}
	}
	if(ansKiri==-1){printf("0\n"); return 0;}
	kiri = 0; kanan = cap;
	while(kiri<=kanan) {
		int mid = (kiri+kanan) /2;
		int first = mid;
		bool valid = true;
		for(i=0;i<n;i++){
			first+=a[i];
			if(first<0){//batas mid harus dinaikin
				kiri = mid+1;
				valid = false;
				break;
			}else if(first > cap) {
				kanan = mid-1;
				valid = false;
				break;
			}
		}
		if(!valid){continue;}
		else{
			ansKanan = mid;
			kiri = mid+1;
		}
	}
	if(ansKanan == -1){printf("0\n"); return 0;}
	printf("%d\n",ansKanan-ansKiri+1);

	return 0;
};