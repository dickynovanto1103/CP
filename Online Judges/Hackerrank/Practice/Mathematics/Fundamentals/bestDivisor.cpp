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

int jumlahDigit(int n){
	int sum = 0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int maks = 0;
	int jawab;
	for(i=1;i<=n;i++){
		if(n%i==0){
			//cek jumlah digit i
			int ans = jumlahDigit(i);
			if(ans>maks){
				maks = ans;
				jawab = i;
			}
		}
	}
	printf("%d\n",jawab);
	return 0;
};