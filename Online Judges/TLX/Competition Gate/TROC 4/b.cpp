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

int main(){
	int n,i,j;
	scanf("%d",&n);
	string kata1,kata2;
	cin>>kata1>>kata2;
	int cntG = 0, cntB = 0, cntK = 0;
	for(i=0;i<n;i++){
		if(kata2[i] == 'G'){cntG++;}
		else if(kata2[i] == 'B'){cntB++;}
		else{cntK++;}
	}
	int nilaiG = 0, nilaiB = 0, nilaiK = 0;
	for(i=0;i<n;i++){
		char kar = kata1[i];
		if(kar == 'G'){nilaiG++;}
		else if(kar == 'B'){nilaiB++;}
		else{nilaiK++;}
	}
	int ans = 0;
	ans = min(nilaiG, cntK) + min(nilaiB, cntG) + min(nilaiK, cntB);
	printf("%d\n",ans);
	return 0;
};