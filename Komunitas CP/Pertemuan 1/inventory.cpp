#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 10;

int main(){
	int n,i,j;
	int counter[maxn],a[maxn];
	scanf("%d",&n);
	memset(counter,0,sizeof counter);
	for(i=0;i<n;i++){scanf("%d",&a[i]); counter[a[i]]++;}
	vi listNol;
	for(i=1;i<=n;i++){
		if(counter[i]==0){listNol.pb(i);}
	}
	int ukuran = listNol.size();
	for(i=0;i<n;i++){
		int bil = a[i];
		if(counter[bil]>1 || bil>n){
			counter[bil]--;
			a[i] = listNol[listNol.size()-1];
			listNol.pop_back();
		}
	}

	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};