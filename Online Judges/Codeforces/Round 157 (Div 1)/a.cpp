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

int main(){
	string s;
	cin>>s;
	int i,j,n;
	n = s.length();
	int idx = -1;
	for(i=0;i<n;i++){
		if(s[i] == '0'){
			idx = i;
			break;
		}
	}
	if(idx == -1){
		for(i=0;i<n-1;i++){
			printf("1");
		}
		printf("\n");
	}else{
		for(i=0;i<idx;i++){
			printf("%c",s[i]);
		}
		for(i=idx+1;i<n;i++){
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
};