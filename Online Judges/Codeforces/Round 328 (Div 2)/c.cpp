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
typedef uint64_t ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	ul t,b,w;

	cin>>t>>w>>b;
	ul minim = min(b, w);
	ul gcd = __gcd(b, w);
	ul lcm = (b / gcd) * w;
	if(minim > t) {
		printf("1/1\n");
		return 0;
	}
	if(b/gcd > t/w) { //basically if lcm > t, just to prevent overflow in calculating lcm
		ul atas = minim - 1;
		ul bawah = t;
		gcd = __gcd(atas, bawah);
		atas /= gcd;
		bawah /= gcd;
		cout<<atas<<"/"<<bawah<<endl;
		return 0;
	}

	ul bawah = t;
	ul atas= minim-1;

	ul batasAtas = t/lcm;
	ul batasBawah = batasAtas - 1;

	ul palingAtas = batasAtas * lcm;
	ul selisih = t - palingAtas + 1;

	ul banyakAtas = min(selisih, minim);
	ul banyakBawah = minim - banyakAtas;
	
	atas += banyakAtas * batasAtas;
	atas += banyakBawah * batasBawah;

	gcd = __gcd(atas, bawah);
	atas /= gcd;
	bawah /= gcd;
	cout<<atas<<"/"<<bawah<<endl;
	
	return 0;
};