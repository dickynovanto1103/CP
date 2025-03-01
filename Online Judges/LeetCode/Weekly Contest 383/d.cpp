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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
	ll hash[100010];
	int p = 31;
    ll mod = 1e9 + 9;	

    int minimumTimeToInitialState(string word, int k) {
        hashString(word);
        int cnt = 1;
        int n = word.size();
        for(int i=k;i<n;i+=k) {
        	ll hash1 = getHashString(i, n-1);
        	ll hash2 = getHashString(0, n-i-1);

        	if(hash1 == hash2) {
        		return cnt;
        	}
        	cnt++;
        }

        return cnt;
    }

    long long inv(ll a) {
	  return pow(a, mod-2, mod);
	}

    ll getHashString(int start, int end) {
    	ll valTemp = (hash[end] - (start == 0 ? 0 : hash[start-1])) % mod;
    	if(valTemp < 0) {
    		valTemp += mod;
    	}

    	ll inverse = inv(pow(p, start, mod));
    	ll ans = (valTemp * inverse) % mod;
    	return (valTemp * inv(pow(p, start, mod) % mod)) % mod;
    }

    ll pow(ll base, ll exp, ll mod) {
    	if(exp == 0) {
    		return 1;
    	}
    	if(exp % 2 == 1) {
    		return base * pow(base, exp-1, mod) % mod;
    	}else{
    		ll temp = pow(base, exp/2, mod);
    		return temp * temp % mod;
    	}
    }

    void hashString(string word) {
    	ll power = 1;
    	for(int i=0;i<word.size();i++){
    		hash[i] = (word[i] - 'a' + 1) * power % mod;
    		if(i) {
    			hash[i] += hash[i-1];
    			hash[i] %= mod;
    		}

    		power *= p;
    		power %= mod;
    		// printf("hash[%d]: %lld\n", i, hash[i]);
    	}
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	string word;
	int k;
	while(cin>>word>>k) {
		Solution s;
		printf("%d\n",s.minimumTimeToInitialState(word, k));
	}

	return 0;
};