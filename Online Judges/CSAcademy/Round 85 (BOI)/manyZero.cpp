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

int toInt(string kata){
	int bil = 0;
	for(int i=0;i<kata.length();i++){
		bil *= 10; bil+=(kata[i] - '0');

	}
	return bil;
}

int jumlahDigit(ll n){
	int sum = 0;
	while(n>0){
		int bil = n%10;
		n/=10;
		sum+=bil;
	}
	return sum;
}

int banyakDigit(ll n){
	int sum = 0;
	while(n>0){
		int bil = n%10;
		n/=10;
		sum+=1;
	}
	return sum;	
}

int main(){
	int x;
	string kata;
	cin>>kata>>x;
	int i,j;
	int pjg = kata.length();
	ll coba = 1;
	for(i=0;i<pjg;i++){
		coba*=10;
	}
	int n = toInt(kata);
	// printf("n: %d\n",n);
	ll selisih = coba - n;
	// printf("selisih: %d\n",selisih);
	int sumDigit = jumlahDigit(selisih);
	int curLength = pjg;
	bool masuk = false;
	while(sumDigit<x){
		sumDigit+=9;
		masuk = true;
		if(sumDigit>x){break;}
		curLength++;
	}
	if(masuk){
		printf("%d\n",curLength);
		return 0;
	}


	
	int maks = 0;

	for(i=0;i<kata.length();i++){
		ll sum = 0;
		int cntDigit = 0;
		for(j=i;j<kata.length();j++){
			// printf("halo\n");
			cntDigit++;
			char kar = kata[j];
			int bil = kar - '0';
			sum *= 10; sum += bil;
		}
		// printf("cntDigit: %d\n",cntDigit);

		// printf("sum: %d cntDigit: %d\n",sum,cntDigit);
		ll harapan = 1;
		for(j=1;j<=cntDigit;j++){
			harapan*=10;
		}

		ll selisih = harapan - sum;
		int sumDigit = jumlahDigit(selisih);
		if(sumDigit<=x){
			maks = max(maks, cntDigit);
		}
		
	}
	// printf("halo\n");
	printf("%d\n",maks);

	return 0;
};