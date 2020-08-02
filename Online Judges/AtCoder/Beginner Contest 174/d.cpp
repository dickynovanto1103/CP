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
	int n,i,j;
	string s;
	cin>>n>>s;
	int lastR = -1;
	for(i=0;i<n;i++){
		if(s[i] == 'R'){lastR = i;}
	}
	if(lastR == -1 || lastR == 0){printf("0\n"); return 0;}
	int minim = 0;
	for(i=lastR;i>=0;i--){
		if(s[i] == 'W'){minim++;}
	}

	stack<int> qr, qw;
	for(i=0;i<n;i++){
		if(s[i] == 'R'){
			// printf("r push %d\n",i);
			qr.push(i);
		}
	}

	for(i=n-1;i>=0;i--){
		if(s[i] == 'W'){
			// printf("w push %d\n",i);
			qw.push(i);
		}
	}

	int cnt = 0;
	if(qw.size() == 0){printf("0\n"); return 0;}
	while(qr.size() > 0 && qw.size() > 0) {

		int frontR = qr.top(); qr.pop();
		int frontW = qw.top(); qw.pop();
		if(frontR > frontW){
			cnt++;
			//swap position
			swap(s[frontW], s[frontR]);
			// cout<<s<<endl;
			// qr.push(frontW);
			// qw.push(frontR);
			// printf("push %d %d\n",frontW, frontR);
		}else{
			break;
		}
	}

	printf("%d\n",min(minim, cnt));
	return 0;
};