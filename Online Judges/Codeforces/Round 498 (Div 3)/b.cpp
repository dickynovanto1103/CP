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

const int maxn = 2e3 + 3;

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int main(){
	int n,k,i,j;
	ii a[maxn];

	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){

		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a,a+n, cmp);
	int sum = 0;
	vi listIdx;
	for(i=0;i<k;i++){
		sum+=a[i].first;
		listIdx.pb(a[i].second);
	}
	sort(listIdx.begin(), listIdx.end());
	printf("%d\n",sum);
	int idxAwal = -1;
	vi listAns;
	int totalAmbil = 0;
	for(i=0;i<listIdx.size();i++){
		int idx = listIdx[i];
		if(i){printf(" ");}
		if(i==(listIdx.size()-1)){
			printf("%d",n-totalAmbil);
		}else{
			int banyakAmbil = idx-idxAwal;
			printf("%d",banyakAmbil);	
			totalAmbil+=banyakAmbil;
		}
		
		idxAwal = idx;
	}
	printf("\n");
	return 0;
};