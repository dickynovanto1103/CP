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

int banyak2 = 0, banyak5 = 0;

void factorize(int bil) {
	while(bil%2 == 0){
		bil/=2; banyak2++;
	}
	while(bil%5 == 0){
		bil/=5; banyak5++;
	}
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		factorize(i);
	}
	printf("%d\n",min(banyak5, banyak2));
	return 0;
};