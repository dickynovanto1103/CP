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
	string kata;
	cin>>kata;
	int i,n;
	n = kata.length();
	int freq[4];
	memset(freq,0,sizeof freq);
	for(i=0;i<n;i++){
		char kar = kata[i];
		int idx = kar-'a';
		if(kar=='a'){
			if(freq[idx+1] > 0 || freq[idx+2]>0){printf("NO\n"); return 0;}
			freq[idx]++;
		}else if(kar=='b'){
			if(freq[idx-1]==0){printf("NO\n"); return 0;}
			if(freq[idx+1] > 0){printf("NO\n"); return 0;}
			freq[idx]++;
		}else{
			if(freq[idx-1] == 0 || freq[idx-2]==0){printf("NO\n"); return 0;}
			freq[idx]++;
		}
	}
	if(freq[0] == 0 || freq[1]==0){printf("NO\n"); return 0;}
	if(freq[2]==freq[0] || freq[2]==freq[1]){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};