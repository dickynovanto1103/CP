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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int findAns(string s) {
	int n = s.length();
	int ans = 0;
	for(int i=0;i<n;i++){
		int cnt1 = 0;
		for(int j=i;j<n;j++){
			if(s[j] == '1'){cnt1++;}
			if(cnt1){
				ans++;
			}
		}
	}
	return ans;
}

void processComb(int idx, int n, int sisa, string temp) {
	if (idx == n) {
		cout<<temp<<" " << findAns(temp)<<endl;
		return;
	}
	if(sisa == 0){
		temp += "0";
		processComb(idx+1, n, sisa, temp);
		return;
	}
	if(sisa == n-idx){
		temp += "1";
		processComb(idx+1, n, sisa-1, temp);
		return;
	}

	processComb(idx+1, n, sisa-1, temp + '1');
	processComb(idx+1, n, sisa, temp + '0');

}

void genCombination(int n, int m) {
	processComb(0, n, m, "");
}

int main(){
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		genCombination(n,m);
	}
	return 0;
};