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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string kata;
	cin>>kata;
	int i,j;
	int pjg = kata.length();
	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for(i=0;i<pjg;i++){
		

		for(j=i+1;j<pjg-1;j++){
			string temp1 = kata.substr(0, i+1);
			string temp2 = kata.substr(i+1, j-i);
			int pjgAkhir = pjg - temp1.length() - temp2.length();
			string temp3 = kata.substr(j+1, pjgAkhir);
			reverse(temp1.begin(), temp1.end());
			reverse(temp2.begin(), temp2.end());
			reverse(temp3.begin(), temp3.end());
			string hasil = temp1 + temp2 + temp3;
			// cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
			if(ans > hasil){
				ans = hasil;
				// printf("i: %d j: %d\n",i,j);
				// cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
			}
			// ans = min(ans, temp1 + temp2 + temp3);
		}
	}
	cout<<ans<<endl;
	return 0;
};