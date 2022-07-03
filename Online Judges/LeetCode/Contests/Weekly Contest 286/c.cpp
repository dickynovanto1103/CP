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
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
	ll pow(int num, int pangkat) {
		ll ans = 1;
		for(int i=0;i<pangkat;i++){
			ans *= num;
		}
		return ans;
	}

	string convertIntToStr(ll a) {
		if(a == 0) {
			return "0";
		}
		string ans;
		while(a) {
			int mod = a % 10;
			ans += mod + '0';
			a /= 10;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	ll convertStrToInt(string s) {
		ll num = 0;
		for(int i=0;i<s.size();i++){
			num *= 10;
			num += (s[i] - '0');
		}
		return num;
	}

	ll computeAngkaAwal(int len) {
		len--;
		int pangkat = (len/2) - 1;
		return pow(10, pangkat);
	}

	ll createNumDigitTimes(int num, int digit) {
		string ans;
		for(int i=0;i<digit;i++){
			ans += (num + '0');
		}

		return convertStrToInt(ans);
	}

    vector<ll> kthPalindrome(vector<int>& queries, int intLength) {
        vll ans;

        int pangkat = ((intLength + 1) / 2) - 1;
        ll maksNum = 9 * pow(10, pangkat);

        for(int q: queries) {
        	if(q > maksNum){
        		ans.pb(-1);
        		continue;
        	}

        	//compute
        	if(intLength <= 2) {
        		//langsung saja;
        		// int num = q;
        		// if(intLength == 2){
        		// 	num *= 10;
        		// 	num += q;
        		// }
        		ans.pb(createNumDigitTimes(q, intLength));
        		continue;
        	}
        	
        	ll angkaAwal = computeAngkaAwal(intLength);
        	ll tambah = q / 10 + 1;
        	angkaAwal += tambah - 1;
        	if(q % 10 == 0) {
        		angkaAwal--;
        	}
        	// printf("q: %d angkaAwal: %lld\n",q, angkaAwal);
        	// cout<<"str: "<<convertIntToStr(angkaAwal)<<endl;
        	// cout<<"num: "<<convertStrToInt(convertIntToStr(angkaAwal))<<endl;

        	ll tengah = (q - 1) % 10;
        	if(tengah < 0) {
        		tengah += 10;
        	}
        	int numDigitTengah = (intLength % 2 == 0 ? 2 : 1);
        	ll numTengah = createNumDigitTimes(tengah, numDigitTengah);
  			string numTengahStr = convertIntToStr(numTengah);
  			if(numDigitTengah == 2 && numTengahStr == "0") {
  				numTengahStr = "00";
  			}
        	// printf("intLength: %d q: %d numDigitTengah: %d numTengah: %lld\n",intLength, q, numDigitTengah, numTengah);
        	string jawaban;
        	string angkaAwalStr = convertIntToStr(angkaAwal);
        	string revAngkaAwal = angkaAwalStr;
        	reverse(revAngkaAwal.begin(), revAngkaAwal.end());
        	
        	jawaban += angkaAwalStr;
        	jawaban += numTengahStr;
        	jawaban += revAngkaAwal;
        	// cout<<"jawaban: "<<jawaban<<endl;
        	ans.pb(convertStrToInt(jawaban));
        }

        return ans;
    }
};

int main(){
	int n, intLen;
	while(scanf("%d %d",&n,&intLen) != EOF) {
		vi queries(n);
		for(int i=0;i<n;i++){
			scanf("%d",&queries[i]);
		}

		Solution sol;
		vll answers = sol.kthPalindrome(queries, intLen);
		for(ll ans: answers) {
			printf("%lld ", ans);
		}

		puts("");
	}
	
	return 0;
};