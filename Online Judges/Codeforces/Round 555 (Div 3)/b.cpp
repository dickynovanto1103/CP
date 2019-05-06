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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	string s;
	int a[10];
	scanf("%d",&n);
	cin>>s;
	for(i=1;i<=9;i++){scanf("%d",&a[i]);}
	int start = -1, end = -1;
	for(i=0;i<n;i++){
		int bil = s[i] - '0';
		if(a[bil] > bil){
			if(start == -1){start = i;}
		}else if(a[bil] < bil){
			if(start == -1){continue;}
			else{end = i-1; break;}
		}
	}
	if(start == -1){
		cout<<s<<endl;
	}else{
		if(end == -1){
			for(i=start;i<n;i++){
				int bil = s[i] - '0';
				s[i] = a[bil] + '0';
			}
		}else{
			for(i=start;i<=end;i++){
				int bil = s[i] - '0';
				s[i] = a[bil] + '0';
			}
		}
		cout<<s<<endl;
	}

	return 0;
};