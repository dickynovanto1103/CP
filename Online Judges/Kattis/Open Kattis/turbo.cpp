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

const int maxn = 1e5 + 5;

int bit1[maxn], bit2[maxn];
int n;

void update(int idx, int val, int nomor){
	for(int i=idx;i<=n;i+=(i&-i)){
		if(nomor == 1){
			bit1[i] += val;
		}else{
			bit2[i] += val;
		}
	}
}

int query(int idx, int nomor){
	int sum = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		if(nomor == 1){
			sum += bit1[i];
		}else{
			sum += bit2[i];
		}
	}
	return sum;
}

int main(){
	int i,j;
	scanf("%d",&n);
	int a[maxn];
	int idx[maxn];

	for(i=1;i<=n;i++){scanf("%d",&a[i]); idx[a[i]] = i;}
	int bil1 = 1, bil2 = n;
	bool aTurn = true;
	while(bil1 <= bil2){
		int ans = 0;
		if(aTurn){
			int indeks = idx[bil1];
			//cari udah dipengaruhi berapa dari kiri dan kanan
			int banyakYangKeKanan = query(indeks-1, 2);//cek yang di kiri idx dan udah di BIT2
			int banyakYangKeKiri = query(n,1) - query(indeks,1);
			update(indeks, 1, 1);
			indeks -= banyakYangKeKanan;
			indeks += banyakYangKeKiri;
			ans = abs(indeks - bil1);
			bil1++;
			aTurn = false;
		}else{
			int indeks = idx[bil2];
			int banyakYangKeKanan = query(indeks-1, 2);//cek yang di kiri idx dan udah di BIT2
			int banyakYangKeKiri = query(n,1) - query(indeks,1);
			update(indeks, 1, 2);
			indeks -= banyakYangKeKanan;
			indeks += banyakYangKeKiri;
			ans = abs(indeks - bil2);
			bil2--;
			aTurn = true;
		}
		printf("%d\n",ans);
	}
	
	return 0;
};