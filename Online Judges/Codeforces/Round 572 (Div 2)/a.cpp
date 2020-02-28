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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	int cnt1 = 0, cnt0 = 0;
	for(i=0;i<n;i++){
		if(s[i] == '1'){cnt1++;}
		else{cnt0++;}
	}
	if(cnt1 != cnt0){
		printf("1\n");
		cout<<s<<endl;
	}else{
		string sub = s.substr(0,n-1);
		printf("2\n");
		cout<<sub<<" "<<s[n-1]<<endl;
	}
	return 0;
};