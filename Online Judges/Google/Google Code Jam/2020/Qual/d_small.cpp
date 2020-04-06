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

int convertToNum(string s) {
	int num = 0;
	for(int i=0;i<s.length();i++){
		num *= 10;
		int bil = s[i] - '0';
		num += bil;
	}
	return num;
}

int main(){
	int tc,b;
	scanf("%d %d",&tc,&b);
	while(tc--){
		int arr[101];
		for(int i=1;i<=b;i++){
			printf("%d\n",i);
			fflush(stdout);
			string s;
			cin>>s;
			if(s == "N"){return 0;}
			int bil = convertToNum(s);
			arr[i] = bil;
		}
		for(int i=1;i<=b;i++){
			printf("%d",arr[i]);
		}
		printf("\n");
		fflush(stdout);
		string ans;
		cin>>ans;
		if(ans == "N"){return 0;}
	}
	
	return 0;
};