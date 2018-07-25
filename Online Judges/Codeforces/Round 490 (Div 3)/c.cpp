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

const int maxn = 4e5 + 5;
vector<vi> AdjList;

int main(){
	int n,k,i,j;
	string kata;
	scanf("%d %d",&n,&k);
	AdjList.assign(27,vi());
	cin>>kata;
	bool isPrinted[maxn];
	memset(isPrinted, true,sizeof isPrinted);
	for(i=0;i<n;i++){
		char kar = kata[i];
		AdjList[kar-'a'].pb(i);
	}
	for(i=0;i<26;i++){
		reverse(AdjList[i].begin(), AdjList[i].end());
	}
	int idx = 0;
	while(true){
		while(AdjList[idx].size()>0){
			int back = AdjList[idx].back();
			isPrinted[back] = false;
			k--;
			AdjList[idx].pop_back();
			if(k==0){break;}
		}
		if(k==0){break;}
		idx++;
	}
	string ans = "";
	for(i=0;i<n;i++){
		if(isPrinted[i]){
			ans+=kata[i];
		}
	}
	cout<<ans<<endl;
	return 0;
};