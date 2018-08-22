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

string kata1,kata2;

bool isSama(string& a, string& b, int pjg){
	if(a == b){return true;}
	if(pjg & 1){
		return false;
	}
	int pjgSelanjutnya = pjg>>1;
	string a1 = a.substr(0,pjgSelanjutnya);
	string a2 = a.substr(pjgSelanjutnya, pjgSelanjutnya);
	string b1 = b.substr(0, pjgSelanjutnya);
	string b2 = b.substr(pjgSelanjutnya, pjgSelanjutnya);
	if(isSama(a1, b1, pjgSelanjutnya) && isSama(a2, b2, pjgSelanjutnya)){
		return true;
	}
	if(isSama(a1, b2, pjgSelanjutnya) && isSama(a2, b1, pjgSelanjutnya)){
		return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>kata1>>kata2;
	int n = kata1.length(),i,j;
	if(isSama(kata1,kata2,n)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
};