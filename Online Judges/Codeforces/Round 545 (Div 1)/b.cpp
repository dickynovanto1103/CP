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

const int mod = 1e9 + 7;

ll modPow(ll a, ll b){
	if(b == 0){return 1;}
	else{
		if(b % 2 == 1){return a*modPow(a,b-1)%mod;}
		else{
			ll temp = modPow(a,b/2);
			return temp*temp%mod;
		}
	}
}

int main(){
	string s,t;
	cin>>s>>t;
	int nol = 0, satu = 0;
	int i,j;
	for(i=0;i<s.length();i++){
		if(s[i] == '0'){nol++;}
		else{satu++;}
	}
	int cnt0 = 0, cnt1 = 0;
	for(i=0;i<t.length();i++){
		if(t[i] == '0'){cnt0++;}
		else{cnt1++;}
	}

	if(cnt0 <= nol && cnt1 <= satu){
		cout<<t;
		nol-=cnt0; satu -= cnt1;
	}else{
		cout<<s<<endl; return 0;
	}

	ll h[500010];
	ll p = 3;
	for(i=0;i<t.length();i++){
		h[i] = (t[i] - '0')*modPow(p, i);
		if(i){h[i] += h[i - 1]; h[i]%=mod;}
	}
	int maks = 0;
	for(i=0;i<t.length()-1;i++){
		int pjg = i + 1;
		int idxAkhir = t.length()-pjg;
		ll hashAkhir = h[t.length()-1] - h[idxAkhir-1];
		if(hashAkhir < 0){hashAkhir += mod;}
		ll hashBaru = h[i]*modPow(p,idxAkhir)%mod;
		if(hashAkhir == hashBaru){maks = pjg;}
	}
	// cout<<"t:"<<t<<endl;
	string tBaru = "";
	cnt0=0; cnt1=0;
	for(i=maks;i<t.length();i++){
		tBaru += t[i];
		if(t[i] == '0'){cnt0++;}
		else{cnt1++;}
	}
	
	// printf("tbaru: "); cout<<tBaru<<endl;
	while(cnt0 <= nol && cnt1 <= satu) {
		cout<<tBaru;
		nol -= cnt0; satu -= cnt1;
	}
	for(i=0;i<nol;i++){
		printf("0");
	}
	for(i=0;i<satu;i++){
		printf("1");
	}
	printf("\n");
	return 0;
};