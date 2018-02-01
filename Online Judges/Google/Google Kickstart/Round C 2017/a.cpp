#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,tt,i;
	string kata;
	scanf("%d",&tc);
	for(tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		cin>>kata;
		int n = kata.length();
		if(n%2==1){printf("AMBIGUOUS\n");}
		else{
			int a[55],b[55];
			for(i=0;i<n;i++){a[i] = kata[i]-65;}
			for(i=0;i<n;i++){b[i] = -1;}
			b[1] = a[0]; b[n-2] = a[n-1];
			for(i=2;i<n-1;i++){//cek yang genap
				if(i%2==0 && b[i+1]==-1){
					int bil = (a[i]-b[i-1])%26;
					if(bil<0){bil = 26 - (-((a[i]-b[i-1])%26));}
					b[i+1] = bil%26;
				}
			}
			for(i=n-2;i>=1;i--){
				if(i%2==1 && b[i-1]==-1){
					int bil = (a[i]-b[i+1])%26;
					if(bil<0){bil = 26 - (-((a[i]-b[i+1])%26));}
					//b[i+1] = bil%26;
					b[i-1] = bil%26;
				}
			}
			
			string decrypted = "";
			for(i=0;i<n;i++){decrypted+=" ";}
			//printf("b:\n");
			for(i=0;i<n;i++){
				decrypted[i] = b[i]+65;
			}
			//printf("\n");
			cout<<decrypted<<endl;
		}
		
	}
	return 0;
}