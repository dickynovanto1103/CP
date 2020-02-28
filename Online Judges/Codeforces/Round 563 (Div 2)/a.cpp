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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	int a[2020];
	scanf("%d",&n);
	for(i=0;i<2*n;i++){scanf("%d",&a[i]);}
	sort(a,a+2*n);
	int satu = 0, dua = 0;
	for(i=0;i<n;i++){
		satu += a[i];
	}
	for(i=n;i<2*n;i++){
		dua += a[i];
	}
	if(satu == dua){printf("-1\n");}
	else{
		for(i=0;i<2*n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
};