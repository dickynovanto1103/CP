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

vi hasilParse;

void parse(int bil){
	hasilParse.clear();
	while(bil>0){
		int angka = bil%10;
		hasilParse.pb(angka);
		bil/=10;
	}
}

int hitungJumlah(){
	int sum = 0;
	for(int i=0;i<hasilParse.size();i++){
		sum+=hasilParse[i];
	}
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i=1;i<=n;i++){
		parse(i);
		sum+=hitungJumlah();
	}
	printf("sum: %d\n",sum);
	return 0;
};