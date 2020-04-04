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

int main(){
	ofstream file;
	file.open("ans.txt");
	int cnt = 0;
	ll maks = 3234566667LL;
	for(ll i=1;i<=maks;i++){
		if(isValid(i)){
			printf("%lld\n",i);
			file<<i<<",";
			cnt++;
		}
	}
	// assert(cnt == 100000);

	file.close();
	return 0;
};