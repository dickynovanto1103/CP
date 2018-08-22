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

int cnt[15];
int cntChecker[15];

bool isValid(){
	for(int i=0;i<10;i++){
		if(cnt[i] < cntChecker[i]){return false;}
	}
	return true;
}

int main(){
	string kata;
	cin>>kata;
	int n,i,j;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		cnt[bil]++;
	}
	
	int ans = 0;
	for(i=0;i<n;i++){
		
		memset(cntChecker, 0, sizeof cntChecker);
		string kata = "";
		for(j=i;j<n;j++){
			char kar = kata[j];
			kata+=kar;
			int bil = kar - '0';
			cntChecker[bil]++;
			if(isValid()){ans++;}
		}
	}
	printf("%d\n",ans);
	return 0;
};