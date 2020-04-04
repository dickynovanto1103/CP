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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi makeIntoArray(ll bil){
	vector<int> v;
	while(bil){
		int angka = bil % 10;
		v.pb(angka);
		bil /= 10;
	}
	reverse(v.begin(), v.end());
	return v;
}

bool isValid(ll a) {
	vi arr = makeIntoArray(a);
	for(int i=0;i<arr.size()-1;i++){
		if(abs(arr[i] - arr[i+1]) > 1){return false;}
	}
	return true;
}

int findNotMatch(ll bil) {
	string s;
	while(a){
		char c = (a % 10) + '0';
		s += c;
		a /= 10;
	}
	for(int i=0;i<s.size()-1;i++){
		int bil1 = s[i] - '0';
		int bil2 = s[i+1] - '0';
		if(abs(bil1 - bil2) > 1){return i;}
	}

}

ll ans[100001];

void generate(int n) {
	ll bil = 1;
	int cnt = 0;
	while(cnt < n) {
		while(!isValid(bil)){
			int idx = findNotMatch(bil);
		
			}
		ans[cnt++] = start;
		if(isValid(start)){
			
		}else {
			while(!isValid(start))
			
		}
		
	}
}

int main(){
	int n;
	scanf("%d",&n);

	// int cnt = 0;
	// for(ll i=1;i<=3234566667LL;i++){
	// 	if(isValid(i)){
	// 		printf("%lld,",i);
	// 		cnt++;
	// 	}
	// }
	printf("cnt: %d\n",cnt);
	return 0;
};