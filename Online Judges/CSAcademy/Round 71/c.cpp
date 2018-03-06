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

const int maxn = 1e5 + 5;
const int kiri = -1;
const int kanan = 1;

int prefSum[maxn], suffSum[maxn];
int tableReset1[maxn], tableReset2[maxn];

void dfs(int maks, int minim, int arah, int idx){
	if(arah==kiri){
		tableReset2[idx] = maks;
		if(tableReset2[idx]==minim){
			return;
		}
	}else{
		tableReset1[idx] = maks;
		if(tableReset1[idx]==minim){
			return;
		}
	}
}

int main(){
	int n,i,j;
	int a[maxn];

	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){a[i] = 1;}
		else{a[i] = -1;}
	}

	int sum = 0;
	int maks = 0;
	for(i=0;i<n;i++){
		sum+=a[i];
		if(sum<0){sum=0;}
		if(sum>maks){
			maks = sum;
		}
	}

	//balikin
	for(i=0;i<n;i++){
		if(a[i]==1){a[i] = -1;}
		else{a[i] = 1;}
	}
	
	sum = 0;
	int minim = 0;
	for(i=0;i<n;i++){
		sum+=a[i];
		if(sum<0){sum=0;}
		if(sum>minim){
			minim = sum;
		}
	}
	minim*=-1;
	printf("%d\n",maks-minim+1);
	return 0;
};