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

int main(){
	int tc,n,i,j;
	int a[maxn];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int maks = -inf;
		int maksSubSequence;
		for(i=0;i<n;i++){scanf("%d",&a[i]); maks = max(maks,a[i]);}
		//hitung subsequence
		if(maks<=0){maksSubSequence = maks;}
		else{
			maksSubSequence = 0;
			for(i=0;i<n;i++){
				if(a[i]>0){maksSubSequence+=a[i];}
			}
		}

		int maksEndingHere = 0;
		int maksSoFar = -inf;
		for(i=0;i<n;i++){
			maksEndingHere+=a[i];
			if(maksSoFar<maksEndingHere){maksSoFar = maksEndingHere;}
			if(maksEndingHere<0){maksEndingHere = 0;}
		}
		printf("%d %d\n",maksSoFar,maksSubSequence);

	}
	return 0;
};