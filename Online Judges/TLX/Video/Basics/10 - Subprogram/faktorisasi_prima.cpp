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

// bool isPrime(int num) {
// 	for(int i = 2; i < num; i++) {
// 		if(num % i == 0) {
// 			return false;
// 		}
// 	}

// 	return true;
// }

// bool isPrimeOptimized(int num) {
// 	for(int i = 2; i * i <= num; i++) {
// 		if(num % i == 0) {
// 			return false;
// 		}
// 	}

// 	return true;
// }

bool isPrime[1000001];

void sieve(int n) {
	isPrime[1] = false;

	for(int i = 2; i * i <= n; i++) {
		if(!isPrime[i]) {
			continue;
		}
		for(int j = i * i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
}

vector<int> generatePrimeList(int n) {
	vector<int> primeList;
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) {
			primeList.push_back(i);
		}
	}

	return primeList;
}

vector<pair<int,int>> factorise(int n, vector<int> primeList) {
	vector<pair<int,int>> ans;
	int idxPrime = 0;

	while(n > 1 && idxPrime < primeList.size()) {
		int pangkat = 0;
		int bilPrima = primeList[idxPrime];
		while(n % bilPrima == 0) {
			n /= bilPrima;
			pangkat++;
		}

		if(pangkat > 0) {
			ans.push_back(pair<int,int>(bilPrima, pangkat));
		}
		idxPrime++;
	}

	return ans;
}

void printHasilFaktorisasi(vector<pair<int,int>> hasil) {
	for(int i=0;i<hasil.size();i++){
		if(i > 0) {printf(" x ");}
		printf("%d", hasil[i].first);
		if(hasil[i].second > 1) {
			printf("^%d", hasil[i].second);
		}
	}
	puts("");
}

int main(){
	memset(isPrime, true, sizeof isPrime);
	sieve(1000000);
	int n;
	while(scanf("%d",&n) != EOF) {
		vector<int> primeList = generatePrimeList(n);
		printf("len: %d\n", primeList.size());
		vector<pair<int,int>> hasil = factorise(n, primeList);
		
		printHasilFaktorisasi(hasil);
	}
	
	
	
	
	return 0;
};