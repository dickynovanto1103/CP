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

const int maxn = 2e5 + 5;
int a[maxn], maks[maxn], partial[maxn];

bool isIncreasing(int n){
	int i;
	for(i=0;i<n-1;i++){
		if(a[i]>=a[i+1]){return false;}
	}
	return true;
}
bool isDecreasing(int n){
	int i;
	for(i=0;i<n-1;i++){
		if(a[i]<a[i+1]){return false;}
	}
	return true;	
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	int maksimal = 0;
	vi listIdxPartialMax;
	memset(partial,0,sizeof partial);
	for(i=0;i<n;i++){
		if(i>0){partial[i] = partial[i-1];}
		scanf("%d",&a[i]); 
		if(a[i]>maksimal){
			listIdxPartialMax.pb(i);
			partial[i]++;
		}
		maksimal = max(maksimal,a[i]); maks[i] = maksimal;
	}

	if(isIncreasing(n)){printf("%d\n",n-1);}
	else if(isDecreasing(n)){printf("1\n");}
	else{
		int ukuran = listIdxPartialMax.size();
		int idxHapus=-1;
		vi listIdx;
		for(i=0;i<ukuran;i++){
			int idx = listIdxPartialMax[i];
			maksimal = 0;

			if(idx<n-2){
				if(idx>0){maksimal = maks[idx-1];}
				if(a[idx+1] < a[idx] && a[idx+1] < a[idx+2] && a[idx+2] > maksimal && a[idx+1] > maksimal){
					listIdx.pb(idx);
				}
			}

		}
		
		int ans = partial[n-1];
		for(i=0;i<listIdx.size();i++){
			int idx = listIdx[i];
			//printf("idx :%d\n",idx);
			int bilangan = a[idx];
			int jumlahPartial;
			if(idx>0){jumlahPartial=partial[idx-1];}
			else{jumlahPartial = 0;}
			//partial[idx-1];
			a[idx] = 0;
			if(idx>0){maksimal = maks[idx-1];}
			else{maksimal = 0;}
			//maksimal = maks[idx-1];
			for(j=idx+1;j<n;j++){
				if(a[j]>maksimal){
					maksimal = a[j];
					jumlahPartial++;
				}
			}
			ans = max(ans,jumlahPartial);
			a[idx] = bilangan;
		}
		if(listIdx.size()==0){ans = 1;}

		ans = max(ans, partial[n-1]);
		printf("%d\n",ans);
	}
	return 0;
};