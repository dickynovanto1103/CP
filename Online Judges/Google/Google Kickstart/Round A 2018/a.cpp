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

bool isAllGenap(int n){
	
	while(n>0){
		int bil = n%10;
		if(bil%2==1){return false;}
		n/=10;
	}
	return true;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		//naik dulu
		int banyakAtas = 0;
		for(i=0;;i++){
			int bil1 = n+i;
			if(isAllGenap(bil1)){banyakAtas = i;break;}
			


		}
		int banyakBawah;
		for(i=0;;i++){
			int bil = n-i;
			if(isAllGenap(bil)){banyakBawah = i; break;}
		}
		printf("%d\n",min(banyakBawah,banyakAtas));
	}
	return 0;
};