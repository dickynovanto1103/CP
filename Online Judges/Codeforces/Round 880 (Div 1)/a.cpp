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

int pow10(int exp) {
	int num = 1;
	for(int i=0;i<exp;i++){
		num *= 10;
	}
	return num;
}

ii getMinMaxAngka(int numDigits) {
	int minAngka = pow10(numDigits-1);
	int maksAngka = pow10(numDigits) - 1;
	return ii(minAngka, maksAngka);
}

ii minMaxB;
ii minMaxC;

int cntDigit(int num) {
	int cnt = 0;
	while(num) {
		num /= 10;
		cnt++;
	}

	return cnt;
}

int getMinB(int a, int bDigits, int cDigits) {
	int minB = minMaxB.first, maksB = minMaxB.second;

	int ans = -1;
	while(minB <= maksB) {
		int mid = (minB + maksB) / 2;
		if(cntDigit(a + mid) >= cDigits) {
			ans = mid;
			maksB = mid - 1;
		}else{
			minB = mid + 1;
		}
	}

	return ans;
}

int getMaksB(int a, int bDigits, int cDigits) {
	int minB = minMaxB.first, maksB = minMaxB.second;

	int ans = -1;
	while(minB <= maksB) {
		int mid = (minB + maksB) / 2;
		if(cntDigit(a + mid) <= cDigits) {
			ans = mid;
			minB = mid + 1;
		}else{
			maksB = mid - 1;
		}
	}

	return ans;
}

//   x   y
//   -----
// ----
// a  b
ii intersect(ii a, ii b) {
	if(max(a.first, b.first) > min(a.second, b.second)) {
		return ii(-1,-1);
	}
	return ii(max(a.first, b.first), min(a.second, b.second));
}


int howManyOfB(int a, int bDigits, int cDigits) {
	int minB = minMaxB.first, maksB = minMaxB.second;
	// if(!(cntDigit(a + minB) <= cDigits && cDigits <= cntDigit(a + maksB))) {
	// 	return -1;
	// }


	ii inter = intersect(ii(a + minB, a + maksB), ii(minMaxC.first, minMaxC.second));
	if(inter.first == -1 && inter.second == -1) {
		return -1;
	}

	// int maks = getMaksB(a, bDigits, cDigits);
	// int minim = getMinB(a, bDigits, cDigits);
	// assert(minim != -1 && maks != -1);
	
	// return maks - minim + 1;
	return inter.second - inter.first + 1;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int a,b,c;
		ll k;
		scanf("%d %d %d %lld",&a,&b,&c,&k);

		ii minMax = getMinMaxAngka(a);
		int minAngka = minMax.first;
		int maksAngka = minMax.second;

		minMaxB = getMinMaxAngka(b);
		minMaxC = getMinMaxAngka(c);

		bool found = false;
		int prevBanyakB = -1;
		for(int i=minAngka;i<=maksAngka;i++){
			//brp banyak angka x klo misal i + x = c dengan C digits
			int banyakB = howManyOfB(i, b, c);
			// printf("a: %d banyakB: %d\n", i, banyakB);
			if(banyakB <= -1) {continue;}

			if(k > banyakB) {
				k -= banyakB;
				continue;
			}
			// banyakB--;

			int maks = getMaksB(i, b, c);
			int minim = getMinB(i, b, c);

			int angkaB = minim + k - 1;
			printf("%d + %d = %d\n", i, angkaB, i + angkaB);
			found = true;
			break;
		}

		if(!found){puts("-1");}
	}
	
	return 0;
};

/*
18
1 1 1 9
2 2 3 1
2 2 1 1
1 5 6 42
1 6 6 10000000
5 5 6 3031568815
6 6 6 1000000000000

1 1 1 9
2 2 3 1
2 2 1 1
1 5 6 42
1 6 6 10000000
5 5 6 3031568815
6 6 6 1000000000000
6 6 6 1000000000000
6 6 6 1000000000000
6 6 6 1000000000000
6 6 6 1000000000000

*/