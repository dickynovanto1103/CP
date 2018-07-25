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

const int maxn = 1e3 + 3;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	set<int> s;
	for(i=0;i<n;i++){scanf("%d",&a[i]); s.insert(a[i]);}
	for(i=0;i<n;i++){
		int bil = a[i];
		if(bil%2==1){
			
		}else{
			a[i]--;
		}
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};