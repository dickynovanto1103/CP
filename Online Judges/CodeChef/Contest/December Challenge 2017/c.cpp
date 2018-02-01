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

const int maxn = 2000000;

int cetak(int i){
	int ganjil = 0, genap = 0;
	int sum = i;
	while(sum>0){
		int bil = sum%10;
		sum/=10;
		if(bil%2==0){genap+=bil;}
		else{ganjil+=bil;}
	}
	return abs(genap-ganjil);
}

int a[3*maxn+10];
ll ans[maxn+10];
ll add[maxn+10];

int main(){
	int tc,n,i,j;

	//preprocess
	for(i=1;i<=3*maxn+5;i++){
		a[i] = cetak(i);
	}
	//printf("i: %d\n",i);
	ans[1] = 2;
	add[2] = 10;
	ans[2] = 12;
	int pt1=3,pt2=4;
	for(i=3;i<=maxn;i++){

		//printf("a[%d]: %d a[%d]: %d\n",pt1,a[pt1],pt2,a[pt2]);
		
		add[i] = add[i-1] - a[pt1]*2 - a[pt2] + a[pt2]*2 + a[pt2+1]*2 + a[pt2+2];
		
		ans[i] = ans[i-1] + add[i];
		// printf("add[%d]: %lld\n",i,add[i]);
		// printf("ans[%d]: %lld\n",i,ans[i]);
		pt1++; pt2+=2;
		//if(i==20){break;}
	}
	// for(i=0;i<10;i++){
	// 	printf("i: %d %lld\n",i,ans[i]);
	// }
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
};