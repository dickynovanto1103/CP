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

bool isPalindrome(string kata){
	int n = kata.length();

	for(int i=0;i<n;i++){
		if(kata[i] != kata[n-i-1]){return false;}
	}
	return true;
}

int main(){
	string kata;
	cin>>kata;
	int i,j;
	int n = kata.length();
	int ans = 0;
	for(i=0;i<n;i++){
		string temp = "";
		for(j=i;j<n;j++){
			temp+=kata[j];
			if(!isPalindrome(temp)) {
				int pjg = temp.length();
				ans = max(ans,pjg);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
};