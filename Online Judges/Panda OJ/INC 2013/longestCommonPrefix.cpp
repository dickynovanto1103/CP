#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,n,i,j;
	string listKata[10];
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		string acuan;
		int pjgMin = inf;
		for(i=0;i<n;i++){
			cin>>listKata[i];
			if(listKata[i].length()<pjgMin){
				pjgMin = listKata[i].length();
				acuan = listKata[i];
			}
		}
		string temp;
		string ans;
		for(j=1;j<=pjgMin;j++){
			temp = acuan.substr(0,j);
			//printf("temp: "); cout<<temp<<endl;
			bool found = false;
			for(i=0;i<n;i++){
				string kata = listKata[i];
				int idx = kata.find(temp);
				if(idx!=0){found = true; break;}
			}
			if(found){break;}
			else{ans = temp;}
		}
		cout<<ans<<endl;

	}
	return 0;
}