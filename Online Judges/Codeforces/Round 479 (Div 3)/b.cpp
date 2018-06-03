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

const int maxn = 1e5 + 5;
string text, pattern, kata;
int b[maxn], n,m;

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while(i<m) {
		while(j >= 0 && pattern[i]!=pattern[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int kmpSearch() {
	int i = 0, j = 0;
	int cnt = 0;
	while(i<n) {
		while(j >= 0 && text[i]!=pattern[j]) j = b[j];
		i++; j++;
		if(j == m) {
			// printf("pattern found in index %d\n",i-j);
			cnt++;
			j = b[j];
		}
	}
	return cnt;
}


int main(){
	m = 2;
	scanf("%d",&n);
	cin>>text;
	int maks = 0;
	string jawab;
	for(int i=0;i<(n-1);i++){
		pattern = text.substr(i,2);
		kmpPreprocess();
		int ans = kmpSearch();
		if(maks < ans){
			maks = ans;
			jawab = pattern;
		}
	}
	cout<<jawab<<endl;
	return 0;
};