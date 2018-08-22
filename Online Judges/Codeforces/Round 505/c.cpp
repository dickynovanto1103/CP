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

int main(){
	string kata;
	int n,i,j;
	cin>>kata;
	n = kata.length();
	int maks = 1;
	int pjg = 1;
	for(i=0;i<(n-1);i++){
		if(kata[i] != kata[i+1]){
			pjg++;
			maks = max(maks, pjg);
		}else{
			pjg = 1;
		}
	}
	int pjg1 = 1;
	for(i=0;i<(n-1);i++){
		if(kata[i] != kata[i+1]){
			pjg1++;
		}else{
			break;
		}	
	}
	int pjg2 = 1;
	for(i=n-1;i>=1;i--){
		if(kata[i] != kata[i-1]){
			pjg2++;
		}else{
			break;
		}
	}

	char awalKar = kata[0], akhirKar = kata[n-1];
	if(awalKar != akhirKar){
		int pjgAkhir = pjg1 + pjg2;
		maks = max(maks, pjgAkhir);
		maks = min(maks, n);
	}
	printf("%d\n",maks);
	return 0;
};