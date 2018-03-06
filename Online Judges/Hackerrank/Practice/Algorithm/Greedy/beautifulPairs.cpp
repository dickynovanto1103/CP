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

const int maxn = 1010;

int main(){
	int n,i,j;
	int a[maxn], b[maxn];
	bool isVisitedA[maxn],isVisitedB[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<n;i++){scanf("%d",&b[i]);}
	memset(isVisitedB,false,sizeof isVisitedB); memset(isVisitedA,false,sizeof isVisitedA);
	int cntSama = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(isVisitedB[j]){continue;}
			if(a[i]==b[j]){
				isVisitedA[i] = true;
				isVisitedB[j] = true;
				cntSama++;
				break; //lanjut i selanjutnya
			}
		}
	}
	//cek jumlah A yang isVisited false brp
	int cntNotVisited = 0;
	for(i=0;i<n;i++){
		if(!isVisitedA[i]){cntNotVisited++;}
	}
	int ans = cntSama;
	if(cntNotVisited==0){
		ans--;
	}else{
		ans++;
	}
	printf("%d\n",ans);
	return 0;
};
