#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	string kata;
	cin>>kata;
	while(kata!="0"){
		int pjg = kata.length();
		int sum = 0;
		for(int i=0;i<pjg;i++){
			int bil = kata[i] - '0';
			sum+=(bil*((int)pow(2,pjg-i)-1));
		}
		cout<<sum<<endl;
		cin>>kata;
	}
	return 0;
}