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
	int a,l,h;
	scanf("%d %d %d",&a,&l,&h);

	int ans = 0;
	for(int i=0;i<=a;i++){
		int binatang = a;
		int leg = l;
		int horn = h;
		binatang-=i;
		leg-=(i*4);
		horn-=(i);
		//cek untuk ram
		if(horn%2!=0){
			continue;
		}
		int banyakRam = horn/2;
		binatang-=(banyakRam);
		horn = 0;
		leg-=(banyakRam*4);
		if(binatang <0 || leg <0){continue;}
		//cek ayam
		if(leg%2!=0){continue;}
		int banyakAyam = leg/2;
		leg = 0;
		binatang-=banyakAyam;
		if(binatang==0){ans = i; break;}
	}
	printf("%d\n",ans);
	return 0;
};