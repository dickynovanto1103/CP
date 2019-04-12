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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int a[6];
	int i,j,k;
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(abs(a[i] - a[j]) > k){printf(":(\n"); return 0;}
		}
	}
	printf("Yay!\n");
	return 0;
};