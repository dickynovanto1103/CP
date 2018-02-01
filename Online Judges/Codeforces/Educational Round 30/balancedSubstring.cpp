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

int main(){
	int n,i,j;
	string kata;
	scanf("%d",&n);
	cin>>kata;
	int jumlahNol = 0, jumlahSatu = 0;
	for(i=0;i<n;i++){
		if(kata[i]=='0'){jumlahNol++;}
		else{jumlahSatu++;}
	}
	if(jumlahSatu==0 || jumlahNol==0){printf("0\n"); return 0;}
	if(jumlahSatu==jumlahNol){printf("%d\n",n); return 0;}
	int kiri = 0, kanan = n/2, mid;
	int ans;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		int pjg = mid*2;
		//printf("mid: %d pjg: %d\n",mid,pjg);
		if(pjg==0){kiri = mid+1;}
		else{
			int j=pjg-1;
			int awal = 0;
			int jml0=0, jml1 = 0;
			for(i=awal;i<=j;i++){
				if(kata[i]=='0'){jml0++;}
				else{jml1++;}
			}
			// printf("awal: %d akhir: %d\n",awal,j);
			// printf("jml0: %d jml1: %d\n",jml0,jml1);
			bool found = false;
			for(i=j;i<n;i++){
				if(jml0==jml1){found = true; break;}
				if(i==n-1){break;}
				if(kata[awal]=='0'){jml0--;}
				else{jml1--;}
				awal++;
				if(kata[i+1]=='0'){jml0++;}
				else{jml1++;}
			}
			if(found){
				//printf("ketemu disini\n");
				ans = pjg; kiri = mid+1;
			}
			else{kanan = mid-1;}
		}
	}
	printf("%d\n",ans);
	return 0;
};