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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string kata;
		string a,b;
		cin>>kata;
		a = kata;
		int n = kata.length();
		bool sudah1 = false;
		for(i=0;i<n;i++){
			b += '0';
			if(kata[i] == '4'){
				a[i]--;
				b[i]='1';
				sudah1 = true;
			}
			if(i == n-1 && !sudah1) {
				if(a[i] == '0') {
					//handle carry
					a[i] = '9';
					b[i] = '1';
					for(j=i-1;j>=0;j--){
						if(a[j] == '0'){
							a[j] = '9';
						}else{
							a[j]--;
							break;
						}
					}
				}else{
					a[i]--;
					b[i] = '1';
					sudah1 = true;
				}
			}
		}
		int awal = -1;
		for(i=0;i<n;i++){
			if(b[i]!='0'){awal = i;break;}
		}
		if(awal == -1){
			cout<<a<<" "<<0<<endl;;
		}else{
			int sudah0 = false;
			for(i=0;i<n;i++){
				if(a[i] != '0'){
					break;
				}
			}
			for(;i<n;i++){
				printf("%c",a[i]);
			}
			printf(" ");
			for(i=awal;i<n;i++)	{
				printf("%c",b[i]);
			}
			printf("\n");
		}
		
	}
	return 0;
};