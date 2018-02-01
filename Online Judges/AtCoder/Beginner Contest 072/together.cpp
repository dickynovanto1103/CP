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

const int maxn = 100010;

int main(){
	int n,counter[maxn],a[maxn],i,j;
	scanf("%d",&n);
	memset(counter,0,sizeof counter);
	for(i=0;i<n;i++){scanf("%d",&a[i]); counter[a[i]]++;}
	int maks = -inf;
	for(i=0;i<=100000;i++){
		if(i==0 || i==100000){
			if(i==0){maks = max(maks,counter[i] + counter[i+1]);}
			else{maks = max(maks, counter[i] + counter[i-1]);}
		}else{
			maks = max(maks, counter[i] + counter[i-1] + counter[i+1]);
		}
	}
	printf("%d\n",maks);
	return 0;
};