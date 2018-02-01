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
	int a[20010];
	int benar1[20010], benar2[20010];
	scanf("%d",&n);
	for(i=0;i<2*n;i++){scanf("%d",&a[i]);}
	int bil = 0;
	for(i=0;i<2*n;i++){
		if(i==0){benar1[i] = bil;}
		else{
			if(benar1[i-1]==0){benar1[i] = 1;}
			else{benar1[i] = 0;}
		}
	}
	bil = 1;
	for(i=0;i<2*n;i++){
		if(i==0){benar2[i] = bil;}
		else{
			if(benar2[i-1]==0){benar2[i] = 1;}
			else{benar2[i] = 0;}
		}
	}

	int beda1 = 0, beda2 = 0;
	for(i=0;i<2*n;i++){
		if(a[i]!=benar1[i]){beda1++;}
		if(a[i]!=benar2[i]){beda2++;}
	}
	int jawab = min(beda1,beda2);
	printf("%d\n",jawab/2);
	return 0;
};