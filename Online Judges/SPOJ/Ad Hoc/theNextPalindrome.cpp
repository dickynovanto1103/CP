#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int tc,i,j;
	string kata,kata1;

	scanf("%d",&tc);
	while(tc--){
		//printf("tc: %d\n",tc);
		cin>>kata1;
		kata="";
		//cout<<"kata: "<<kata<<endl;
		//if(kata=="99999"){printf("100001\n"); continue;}

		int pjg = kata1.length();
		if(pjg==1){
			string ans;
			if(kata1[0]<'9'){kata1[0]++; ans = kata1;}
			else{ans = "11";}
			cout<<ans<<endl; continue;
		}
		bool found = false;
		for(i=0;i<pjg;i++){
			if(!found){
				if(kata1[i]!='0'){found = true; kata+=kata1[i];}
			}else{
				kata+=kata1[i];
			}
			
		}
		if(kata=="99999"){printf("100001\n"); continue;}
		pjg = kata.length();
		
		if(pjg==1){
			string ans;
			if(kata[0]<'9'){kata[0]++; ans = kata;}
			else{ans = "11";}
			cout<<ans<<endl; continue;
		}
		i=0; j = pjg-1;
		int flag = 0;//0 untuk sementara palindrome..1 untuk kiri lebih besar..-1 untuk kiri lebih kecil
		if(pjg%2==0){
			for(i=0;i<pjg/2;i++){
				j = pjg-i-1;
				if(kata[i]!=kata[j]){
					if(kata[i]>kata[j]){flag = 1;}
					else{flag = -1;}
					kata[j] = kata[i];
				}
			}
			if(flag<=0){//palindrome atau lebih kecil
				int bil = kata[i-1]-48;
				if(bil<9){
					bil++;
					kata[i-1] = bil+48; kata[i] = bil+48;
					cout<<kata<<endl;
				}else{
					//iterasi dari tengah ke pinggir
					j = i;
					for(i=j-1;i>=1;i--){
						kata[i] = kata[j] = '0';
						if(kata[i-1]<'9'){kata[i-1]++; kata[j+1]++; break;}
						else{j++;}
					}
					if(i==0){
						kata[i]='0'; kata[j]='0';
						string ans = "1";
						ans+=kata;
						ans[ans.length()-1] = '1';
						cout<<ans<<endl;
					}else{
						cout<<kata<<endl;
					}
				}
			}else{
				cout<<kata<<endl;
			}
		}else{
			for(i=0;i<pjg/2;i++){
				for(i=0;i<pjg/2;i++){
					j = pjg-i-1;
					if(kata[i]!=kata[j]){
						if(kata[i]>kata[j]){flag = 1;}
						else{flag = -1;}
						kata[j] = kata[i];
					}
				}
				if(flag<=0){//palindrome atau lebih kecil
					int bil = kata[i]-48;
					if(bil<9){
						bil++;
						kata[i] = bil+48;
						cout<<kata<<endl;
					}else{
						//iterasi dari tengah ke pinggir
						kata[i] = '0';
						j = i+1; i--;
						for(i=j-2;i>=1;i--){
							kata[i] = kata[j] = '0';
							if(kata[i-1]<'9'){kata[i-1]++; kata[j+1]++; break;}
							else{j++;}
						}
						if(i==0){
							kata[i]='0'; kata[j]='0';
							string ans = "1";
							ans+=kata;
							ans[ans.length()-1] = '1';
							cout<<ans<<endl;
							
						}else{

							cout<<kata<<endl;
						}
					}
				}else{
					
					cout<<kata<<endl;
				}
			}
		}
		
	}
	return 0;
}