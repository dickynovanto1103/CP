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
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string toBinary(ll bil){
	string ans = "";
	while(bil > 0){
		if(bil%2 == 1){
			ans += '1';
		}else{
			ans += '0';
		}
		bil /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	ll l,r,i,j;
	scanf("%lld %lld",&l,&r);
	string binaryR = toBinary(r);
	string binaryL = toBinary(l);
	int pjgR = binaryR.length();
	int pjgL = binaryL.length();
	if(pjgL < pjgR){
		string tambahan = "";
		int selisih = pjgR - pjgL;
		for(i=0;i<selisih;i++){
			tambahan += '0';
		}
		binaryL = tambahan + binaryL;
	}
	// cout<<binaryL<<" "<<binaryR<<endl;
	bool valid = false;
	ll ans = 0;
	for(i=0;i<pjgR;i++){
		char kar1 = binaryL[i], kar2 = binaryR[i];
		int jarak = pjgR - 1 - i;
		if(kar1 == '0' && kar2 == '1'){//
			valid = true;
			ans += (1LL<<jarak);
		}else if(kar1 == '1' && kar2 == '0'){
			ans += (1LL<<jarak);
		}else if(kar1 == kar2){
			if(valid){
				ans += (1LL<<jarak);
			}
		}
	}
	printf("%lld\n",ans);
	
	
	return 0;
};