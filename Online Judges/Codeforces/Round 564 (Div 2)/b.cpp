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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii pas;

bool check(int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((abs(pas[i].first-pas[j].first) + abs(pas[i].second - pas[j].second)) < (j-i)){return false;}
		}
	}
	return true;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	ii koorAwal = ii(1,1);
	int maks = 0;
	for(i=0;i<n;i++){
		pas.pb(koorAwal);
		maks = max(maks, koorAwal.first);
		maks = max(maks, koorAwal.second);
		if(i%2 == 0){
			koorAwal.second++;
		}else{
			koorAwal.first++;
		}
	}
	printf("%d\n",maks);
	for(i=0;i<n;i++){
		printf("%d %d\n",pas[i].first, pas[i].second);
	}

	assert(check(n));
	return 0;
}; 