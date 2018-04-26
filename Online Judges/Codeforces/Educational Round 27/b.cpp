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

string parseToString(int n) {
	string kata="";
	int digit = 0;
	while(n>0 || digit<6){
		int bil = n % 10;
		n/=10;
		kata+=(bil+'0');
		digit++;
	}
	reverse(kata.begin(), kata.end());
	// cout<<"kata sekarang: "<<kata<<endl;
	return kata;
	
}

int jumlahDigit(string kata) {
	int sum = 0;
	for(int i=0;i<3;i++){
		int angka = (kata[i]-'0');
		// printf("angka :%d\n",angka);
		sum+=angka;
	}
	return sum;
}

int banyakPerubahan(string kata1, string kata2) {
	int cnt = 0;
	for(int i=0;i<6;i++){
		if(kata1[i] != kata2[i]){cnt++;}
	}
	return cnt;
}

int main(){
	string kata;
	int i;
	cin>>kata;
	
	int ans = inf;
	//iterasi dari 0 sampe 999
	for(i=0;i<=999999;i++){
		string hasil = parseToString(i);
		string kata1 = hasil.substr(0,3), kata2 = hasil.substr(3,3);
		if(jumlahDigit(kata1) == jumlahDigit(kata2)) {
			int jwb = banyakPerubahan(kata, hasil);
			ans = min(ans, jwb);
		}
		
	}
	printf("%d\n",ans);
	return 0;
};