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

int findFirstNot0(int *a, int n) {
	for(int i=0;i<n;i++){
		printf("a[%d]: %d\n",i,a[i]);
		if(a[i] != 0){
			return i;
		}
	}
	return -1;
}

int find0(int *a, int n, int idx) {
	for(int i=idx;i<n;i++){
		printf("di find0 a[%d]: %d\n",i, a[i]);
		if(a[i] == 0){
			printf("return %d\n",i-1);
			return i-1;
		}
	}
	return -1;
}

int main(){
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	int a[301], temp[301];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		temp[i] = a[i];
	}
	if(n == k){printf("1\n"); return 0;}
	int kiri = 0, kanan = k-1;
	int ans = inf+1;
	while(kanan < n){
		for(i=0;i<n;i++){a[i] = temp[i];}
		int elkiri = (kiri == 0 ? inf : a[kiri-1]);
		int elkanan = (kanan == n-1 ? inf : a[kanan+1]);
		int minim = min(elkiri, elkanan);
		int jawab = 0;
		for(i=kiri;i<=kanan;i++){
			a[i] = minim;
		}
		printf("kiri:%d kanan: %d\n",kiri, kanan);
		for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		while(true){
			int idx1 = findFirstNot0(a, n);
			if(idx1 == -1){ans = min(ans, jawab); break;}
			int idx2 = find0(a, n, idx1);
			
			if(idx2 == -1){idx2 = n-1; printf("sini\n");}
			printf("halo idx1: %d idx2: %d\n",idx1, idx2);
			int minim = inf;
			for(i=idx1;i<=idx2;i++){
				minim = min(minim, a[i]);
			}
			for(i=idx1;i<=idx2;i++){
				a[i] -= minim;
			}
			jawab += minim;
		}
		
		kiri++;
		kanan++;
	}
	printf("%d\n",ans);
	return 0;
};