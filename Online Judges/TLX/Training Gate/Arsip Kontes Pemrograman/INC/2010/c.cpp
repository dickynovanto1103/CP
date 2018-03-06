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
	int tc,i,j;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		vector<char> v;
		cin>>kata;
		for(i=0;i<kata.length();i++){
			char kar = kata[i];
			if(kar=='+'){
				v.pb(kata[i+1]);
				i++;
			}else{
				reverse(v.begin(),v.end());
			}
		}
		for(i=0;i<v.size();i++){
			printf("%c",v[i]);
		}
		// if(dariDepan){
			
		// }else{
		// 	for(i=v.size();i>=0;i--){
		// 		printf("%c",v[i]);
		// 	}
		// }
		printf("\n");
	}
	return 0;
};