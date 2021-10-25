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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		int n = s.length();
		string str = "";
		bool valid = true;
		for(int i=0;i<n;i++){
			char c = i + 'a';
			string temp = str;
			temp += c;
			if(s.find(temp) != -1){
				str = temp;
				continue;
			}

			temp = str;
			temp = c + temp;
			if(s.find(temp) != -1){
				str = temp;
				continue;
			}
			valid = false;
			break;
		}
		if(valid){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
};