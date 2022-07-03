/*
ID: dickyno1
LANG: C++14
TASK: zerosum
*/

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

int n;

char opts[] = {' ', '+', '-'};

bool isOperator(char c) {
	return c == '+' || c == '-';
}

int processWhenOperator(char lastOp, int angka) {
	int sum = 0;
	if(lastOp == 'a'){
		sum += angka;
	}else if(lastOp == '+'){
		sum += angka;
	}else{
		sum -= angka;
	}
	return sum;
}

int eval(string s) {
	int angka = 0;
	char lastOp = 'a';
	int sum = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == ' '){
			angka *= 10;
			continue;
		}
		if(isOperator(s[i])){
			sum += processWhenOperator(lastOp, angka);
			lastOp = s[i];
			angka = 0;
		}else{
			angka += s[i] - '0';
		}
	}

	sum += processWhenOperator(lastOp, angka);

	// cout<<"s: "<<s<<" evaled to: "<<sum<<endl;
	return sum;
}

void solve(int idx, string s) {
	if(idx == (n+1)){
		if(eval(s) == 0){
			cout<<s<<endl;	
		}
	
		return;
	}

	for(int i=0;i<3;i++){
		char angka = idx + '0';
		string newStr = s + opts[i];
		newStr += angka;
		solve(idx+1, newStr);
	}

}

int main(){
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);

	int i,j;
	scanf("%d",&n);

	solve(2, "1");
	
	return 0;
};