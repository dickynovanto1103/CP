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
	int tc,i,j,n;
	scanf("%d",&tc);
	char minim[5000];
	int idx[5000];
	while(tc--){
		string s,t;
		cin>>s>>t;
		if(s < t){cout<<s<<endl; continue;}
		n = s.length();
		minim[n-1] = s[n-1];
		idx[n-1] = n-1;
		for(i=n-2;i>=0;i--){
			minim[i] = min(minim[i+1], s[i]);
			if(minim[i] != minim[i+1]){
				idx[i] = i;
			}else{
				idx[i] = idx[i+1];
			}
		}
		bool found = false;
		string temp = s;
		for(i=0;i<n-1;i++){
			if(s[i] > minim[i+1]){
				int idxSetelah = idx[i+1];
				swap(s[i], s[idxSetelah]);
				if(s < t){
					cout<<s<<endl;
					found = true; break;
				}else{
					s = temp;
				}
			}
		}
		if(!found)
			cout<<"---"<<endl;
	}
	return 0;
};