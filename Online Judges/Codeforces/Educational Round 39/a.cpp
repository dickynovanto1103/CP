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

const int maxn = 110;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	int b = 0,c = 0;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(bil>0){b+=bil;}
		else{c+=bil;}
	}
	printf("%d\n",b-c);
	return 0;
};