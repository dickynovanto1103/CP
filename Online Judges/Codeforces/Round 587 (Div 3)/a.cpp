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
	scanf("%d",&n);
	cin>>s;
	int cnta = 0, cntb = 0;
	int cnt = 0;;
	for(i=0;i<n;i++){
		if(s[i] == 'a'){cnta++;}
		else{cntb++;}
		if(i % 2 == 1){
			if(cnta < cntb){
				if(s[i-1] == 'b'){
					s[i-1] = 'a';
					cnta++; cntb--;
				}else if(s[i] == 'b'){
					s[i] = 'a';
					cnta++; cntb--;
				}

				cnt++;
			}else if(cnta > cntb){
				if(s[i-1] == 'a'){
					s[i-1] = 'b';
					cnta--; cntb++;
				}else if(s[i] == 'a'){
					s[i] = 'b';
					cnta--; cntb++;
				}
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	cout<<s<<endl;
	return 0;
};