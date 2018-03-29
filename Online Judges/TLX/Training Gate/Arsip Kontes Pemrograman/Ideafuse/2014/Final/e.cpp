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

int n;
int dp[50002][5];
string s;

int hitung(int a, int b){
	int c=0;
	for(int i=0;i<5;i++){
		c+= dp[b][i]-dp[a][i]>0;
	}
	return c;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++){
		printf("Case #%d: ", cc);
		scanf("%d", &n);
		cin>>s;
		if(n==5){
			printf("%d\n", s.size());
			continue;
		}
		s="0"+s;
		int mi = 0;
		dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4]= 0;
		for(int i=1;i<s.size();i++){
			for(int j=0;j<5;j++){
				dp[i][j] = dp[i-1][j];
			}
			dp[i][s[i]-'A']++;
		}
		for(int i=1;i<s.size()&&s.size()-i+1>mi;i++){
			if(s[i]==s[i-1])
				continue;
			int l = i;
			int r = s.size()-1;
			int mid = (l+r)>>1;
			while(l<r){
				if(hitung(i-1, mid) > n)
					r = mid-1;
				else
					l = mid;
				mid = (l+r+1)>>1;
			}
			mi = max(mi, mid-i+1);
		}
		printf("%d\n", mi);
	}
	return 0;
};