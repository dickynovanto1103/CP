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

const int maxn = 2e5 + 5;
int bukaPref[maxn], bukaSuff[maxn], tutupPref[maxn], tutupSuff[maxn];

int main(){
	int n,k,i,j;
	string kata;
	scanf("%d %d",&n,&k);
	cin>>kata;
	if(n == k){
		cout<<kata<<endl;
		return 0;
	}
	
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar == '('){bukaPref[i]++; bukaSuff[i]++;}
		else{tutupSuff[i]++; tutupPref[i]++;}
	}
	for(i=1;i<n;i++){
		bukaPref[i] += bukaPref[i-1];
		tutupPref[i] += tutupPref[i-1];
	}
	for(i=n-2;i>=0;i--){
		bukaSuff[i] += bukaSuff[i+1];
		tutupSuff[i] += tutupSuff[i+1];
	}

	int state = 0;
	string ans;
	for(i=0;i<n;i++){
		char kar = kata[i];
		int sisa = k - ans.length();
		if(state == 0){
			if(kar == ')'){continue;}
			else{ans.pb(kar); state++;}
		}else{
			int butuhTutup = state;
			if(butuhTutup == sisa){
				if(tutupSuff[i] >= butuhTutup){
					for(j=0;j<sisa;j++){
						ans.pb(')');
					}
					cout<<ans<<endl;
					return 0;		
				}
			}else{
				ans.pb(kar);
				if(kar == '('){state++;}
				else{state--;}
			}
		}
	}
	return 0;
};