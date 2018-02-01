#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited 0
#define row 1
#define col 2
#define done 3
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m;
int a[55][55];
int doneness[55][55];

ii keKanan(int x, int y, int bil){
	int i,j;
	int cntJanganDihitung = 0;
	i=x;
	int cnt = 0;
	for(j=y;j<m;j++){
		if(a[i][j]==bil){
			cnt++;
			if(doneness[i][j]!=unvisited){cntJanganDihitung++;}
			if(doneness[i][j]!=done){
				if(doneness[i][j]!=col){doneness[i][j]+=col;}
			}
		}
		
	}
	return ii(cnt,cntJanganDihitung);
}
ii keBawah(int x, int y, int bil){
	int i,j;
	int cntJanganDihitung = 0;
	j=y;
	int cnt = 0;
	for(i=x;i<n;i++){
		if(a[i][j]==bil){
			cnt++;
			if(doneness[i][j]!=unvisited){cntJanganDihitung++;}
			if(doneness[i][j]!=done){
				if(doneness[i][j]!=row){doneness[i][j]+=row;}
			}
		}
		
	}
	return ii(cnt,cntJanganDihitung);
}

int main() {
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			doneness[i][j] = unvisited;
		}
	}
	ll sum = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			//printf("i: %d j: %d a: %d\n",i,j,a[i][j]);
			if(doneness[i][j]==done){continue;}
			if(doneness[i][j]==unvisited){//blm dikunjungi row dan col
				
				ii kanan = keKanan(i,j,a[i][j]);
				ll jumlah = (ll)pow(2,kanan.first)-kanan.second-1;
				sum+=jumlah;

				
				//printf("unvisited, jumlah: %lld\n",jumlah);
				ii bawah = keBawah(i,j,a[i][j]);
				jumlah = (ll)pow(2,bawah.first)-bawah.second-1;
				sum+=jumlah;
				//printf("jumlah lagi: %lld\n",jumlah);
				
				
			}else if(doneness[i][j]==row){
				
				ii bawah = keKanan(i,j,a[i][j]);
				
				ll jumlah = (ll)pow(2,bawah.first)-bawah.second-1;
				//printf("row telah ditelusuri, jumlah: %lld\n",jumlah);
				sum+=jumlah;
				
			}else if(doneness[i][j]==col){
				ii kanan = keBawah(i,j,a[i][j]);
				
				ll jumlah = (ll)pow(2,kanan.first)-kanan.second-1;
				//printf("col telah ditelusuri, jumlah: %lld\n",jumlah);
				sum+=jumlah;
				
			}
			doneness[i][j] = done;
			//printf("sum jd: %lld\n",sum);
		}
	}
	printf("%lld\n",sum);
	return 0;
}