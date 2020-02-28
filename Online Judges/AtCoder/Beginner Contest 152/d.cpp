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

ii getFirstAndLast(int num) {
	int first, last;
	last = num%10;
	while(num){
		int angka = num % 10; num /= 10;
		first = angka;
	}
	return ii(first, last);
}

int numDigit(int num) {
	int ans = 0;
	while(num){
		ans++;
		num /= 10;
	}
	return ans;
}

int pow(int a, int b){
	if(b == 0){return 1;}
	int angka = a;
	for(int i=2;i<=b;i++){
		a *= angka;
	}
	return a;
}

int form(int first, int last, int tengah, int banyakTengah) {
	first *= pow(10, banyakTengah + 1);
	tengah *= 10; tengah += last;
	first += tengah;
	return first;
}

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){

	int ans = 0;
	int a[200001];
	// printf("{");
	for(int num=1;num<=n;num++){
		ii pas = getFirstAndLast(num);
		// printf("num: %d\n",num);
		int first = pas.first, last = pas.second;
		if(first == last) {
			ans++;// 1 digit aja
			// printf("ans jd: %lld (%d, %d)\n",ans, num, num);
			//2 digit
			int temp = last;
			temp *= 10;
			temp += first;
			if(temp > n){
				continue;
			}else{
				ans++;
				// printf("(%d,%d)\n",num, temp);
			}
			for(i=3;i<=6;i++){
				int batas = pow(10, i-2);
				for(j=0;j<batas;j++){
					int angka = form(last, first, j, i-2);
					if(angka > n){
						break;
					}else{
						ans++;
						// printf("(%d,%d)\n",num, angka);
					}
				}
				
			}
		}else{
			if(last == 0){continue;}
			//2 digit
			int temp = last;
			temp *= 10;
			temp += first;
			if(temp > n){
				continue;
			}else{
				ans++;
				// printf("(%d,%d)\n",num, temp);
			}
			for(i=3;i<=6;i++){
				int batas = pow(10, i-2);
				// printf("i: %d batas: %d\n",i, batas);
				for(j=0;j<batas;j++){
					int angka = form(last, first, j, i-2);
					// printf("angka: %d\n",angka);
					if(angka > n){
						break;
					}else{
						ans++;
						// printf("(%d,%d)\n",num, angka);
					}
				}
				
			}
		}
		// a[i] = ans;
		// if(num <= 100){
		// 	printf("%d %d\n",num, ans);	
		// }
		
		// printf("num: %d ans: %lld\n",num, ans);
		// printf("num: %d ans: %lld\n",num, ans);
	}
	// printf("}\n");
	printf("%d\n",ans);
	}
	

	
	return 0;
};