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

bool isVowel(char kar) {
	return kar=='a' || kar=='i' || kar=='u' || kar=='e' || kar=='o' || kar=='y';
}

int main(){
	string kata;
	cin>>kata;
	int i,j,n;
	n = kata.length();
	string ans;
	for(i=0;i<n;i++){
		if(kata[i]<97){kata[i]-='A'; kata[i]+='a';}
	}
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(isVowel(kar)){continue;}
		ans+='.'; ans+=kar;
	}
	cout<<ans<<endl;
	return 0;
};