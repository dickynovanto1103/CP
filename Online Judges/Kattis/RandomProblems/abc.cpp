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
	int a[3];
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(i){printf(" ");}
		if(s[i] == 'C'){
			printf("%d",a[2]);
		}else if(s[i] == 'B'){
			printf("%d",a[1]);
		}else{
			printf("%d",a[0]);
		}
	}
	printf("\n");
	return 0;
};