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

ll convertToInt(string kata) {
	ll bil = 0;
	for(int i=0;i<kata.length();i++){
		char kar = kata[i];
		ll angka = kar-'0';
		bil*=10LL;
		bil+=angka;
	}
	return bil;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string input;
		cin>>input;	
		// printf("input: "); cout<<input<<endl;
		string kata1 = input,kata2 = input;
		bool bisaNaik = true, adaGanjil = false;

		for(i=0;i<input.length();i++){
			int bil = input[i] - '0';
			if(bil%2==1){
				if(bil==1){
					//versi naik dulu
					kata1[i] = bil+1 + '0';
					for(j=i+1;j<input.length();j++){
						kata1[j] = 0+'0';
					}

					//versi turun
					kata2[i] = bil-1+'0';
					for(j=i+1;j<input.length();j++){
						kata2[j] = 8+'0';
					}
				}else if(bil==9){
					//ga mungkin naik
					bisaNaik = false;
					//versi turun
					kata2[i] = bil-1+'0';
					for(j=i+1;j<input.length();j++){
						kata2[j] = 8+'0';
					}
				}else{
					//versi naik dulu
					kata1[i] = bil+1 + '0';
					for(j=i+1;j<input.length();j++){
						kata1[j] = 0+'0';
					}

					//versi turun
					kata2[i] = bil-1+'0';
					for(j=i+1;j<input.length();j++){
						kata2[j] = 8+'0';
					}
				}
				adaGanjil = true;
				break;
			}
		}
		ll selisih;
		if(!adaGanjil){printf("0\n"); continue;}
		if(!bisaNaik){
			ll bil1 = convertToInt(input);
			ll bil2 = convertToInt(kata2);
			selisih = abs(bil1-bil2);
		}else{
			ll bil1 = convertToInt(kata1);
			ll bil2 = convertToInt(kata2);
			ll nilaiInput = convertToInt(input);
			ll selisih1 = abs(bil1-nilaiInput);
			ll selisih2 = abs(bil2-nilaiInput);
			selisih = min(selisih1, selisih2);
		}
		printf("%lld\n",selisih);
	}
	

	return 0;
};