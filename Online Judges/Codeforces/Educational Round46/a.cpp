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
typedef vector<string> vs;

int numOfDiff(string a, string b){
	int cnt = 0;
	for(int i=0;i<a.length();i++){
		if(a[i] != b[i]){cnt++;}
	}
	return cnt;
}

int main(){
	int n,i,j;
	scanf("%d",&n);

	string listKata[101];
	bool isVisited[101];
	memset(isVisited, false,sizeof isVisited);
	int counter[100];
	memset(counter, 0, sizeof counter);
	int cnt = 0;
	map<string,int> mapper;

	for(i=0;i<n;i++){
		string kata;
		cin>>kata;
		if(mapper.find(kata)!=mapper.end()){
			int idx = mapper[kata];
			counter[idx]++;
		}else{
			mapper[kata] = cnt;
			counter[cnt]++;;
			cnt++;
		}
		listKata[i] = kata;
		int pjg = kata.length();
	}
	
	int ans = 0;
	for(i=0;i<n;i++){
		string kata;
		cin>>kata;
		
		if(mapper.find(kata) == mapper.end()){
			ans++;
		}else{
			int idx = mapper[kata];
			if(counter[idx]==0){
				ans++;
			}else{
				counter[idx]--;
			}
		}
		// printf("idxDihapus: %d pjgMin: %d\n",idxDihapus, pjgMin);		
		
	}
	printf("%d\n",ans);
	return 0;
};