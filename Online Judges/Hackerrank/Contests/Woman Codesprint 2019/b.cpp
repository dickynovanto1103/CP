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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string s[maxn];
	for(i=0;i<n;i++){cin>>s[i];}
	string ans = "12345";
	for(j=0;j<5;j++){
		int maksCnt = 0;
		for(int k=0;k<26;k++){
			char kar = k + 'a';
			int cnt = 0;
			for(i=0;i<n;i++){
				if(kar != s[i][j]){cnt++;}
			}
			if(cnt >= maksCnt){
				ans[j] = kar;
				maksCnt = cnt;
			}
		}
		
	}
	cout<<ans<<endl;
	return 0;
};