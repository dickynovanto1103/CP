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
	int tc,i,j,n;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		int maks = 0, minim = 0;
		int kaliAtas, kaliBawah;
		if(n==2){
			kaliAtas = 1;
			kaliBawah = 1;
		}else if(n==4){
			kaliAtas = 2;
			kaliBawah = 3;
		}else if(n==8){
			kaliAtas = 3;
			kaliBawah = 5;
		}else if(n==16){
			kaliAtas = 4;
			kaliBawah = 7;
		}else if(n==32){
			kaliAtas = 5;
			kaliBawah = 9;
		}
		minim = kaliAtas*2 + 3;
		maks = kaliBawah*3 + 5;
		if(n==2){
			minim = 3;
			maks = 5;
		}
		printf("%d %d\n",minim,maks);
	}
	return 0;
};