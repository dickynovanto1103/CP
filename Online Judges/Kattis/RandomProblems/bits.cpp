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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int numToBinary(int n){
	// string ans = "";
	int cnt1 = 0;
	while(n){
		int bil = n%2;
		n/=2;
		if(bil){cnt1++;}
		// ans += (bil + '0');
	}
	// reverse(ans.begin(), ans.end());
	return cnt1;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int bil = 0;
		string kata;
		cin>>kata;
		int pjg = kata.length();
		int maks = 0;
		for(int i=0;i<pjg;i++){
			char kar = kata[i];
			bil *= 10;
			bil += (kar - '0');
			maks = max(maks, numToBinary(bil));
		}
		// scanf("%d",&bil);
		printf("%d\n",maks);
		// cout<<bil<<" "<<numToBinary(bil)<<endl;
	}
	return 0;
};