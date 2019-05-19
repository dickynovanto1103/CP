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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isYYMM(int depan, int belakang) {
	if(belakang >= 1 && belakang <= 12){
		return true;
	}else{
		return false;
	}
}

bool isMMYY(int depan, int belakang) {
	if(depan >= 1 && depan <= 12) {
		return true;
	}else{
		return false;
	}
}

int main(){
	string s;
	cin>>s;
	int bil = 0;;
	for(int i=0;i<s.length();i++){
		bil*=10;
		bil += s[i] - '0';
	}
	int depan = bil / 100;
	int be = bil%100;
	// printf("depan: %d belakang: %d\n",depan, be);
	if(isYYMM(depan, be) && isMMYY(depan, be)) {
		printf("AMBIGUOUS\n");
	}else if(isYYMM(depan, be) && !isMMYY(depan, be)) {
		printf("YYMM\n");
	}else if(!isYYMM(depan, be) && isMMYY(depan, be)){
		printf("MMYY\n");
	}else{
		printf("NA\n");
	}
	return 0;
};