#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int findIdx(int startidx, string a, string b){
	int i,j;
	int pjga = a.length(), pjgb = b.length();
	bool found = false;
	//printf("cari a: "); cout<<a; printf(" cari b: "); cout<<b<<endl; printf("startidx: %d\n",startidx);

	for(i=startidx;i<=pjga-pjgb;i++){
		int starti = i;
		bool salah = false;
		//printf("starti awal: %d\n",starti);
		for(j=0;j<pjgb;j++){
			//printf("starti: %d j: %d\n",starti,j);
			if(a[starti]!=b[j]){
				//printf("ketemu beda\n");
				salah = true; break;
			}
			else{
				//printf("masih sama\n");
				starti++;
			}
		}
		if(!salah){
		//	printf("ketemu idx bener: %d\n",i);
			found = true; return i;
		}
		
	}
	//printf("ga ketemu return -1\n");
	return -1;
}

int main() {
	string s,a,b;
	cin>>s>>a>>b;
	int i=0,j=0;
	int pjga = a.length(), pjgb = b.length(), pjgs = s.length();
	while(true){
		int idx1 = findIdx(i,s,a);
		int idx2 = findIdx(i,s,b);
		//printf("idx1: %d idx2: %d i: %d\n",idx1,idx2,i);
		if(idx1==-1 && idx2==-1){break;}
		if(idx1==-1 && idx2!=-1){//masih ada b
			//string setelah b disimpen dulu
			string dum="";
			string sawal = "";
			for(i=0;i<idx2;i++){
				char kar = s[i];
				sawal+=kar;
			}
			for(j=idx2+pjgb;j<pjgs;j++){
				char kar = s[j];
				dum+=kar;
			}
			//cout<<"sawal: "<<sawal<<" a: "<<a<<" dum: "<<dum<<endl;
			s = sawal+a+dum;
			i = idx2+pjga;
			//printf("i jd: %d\n",i);
		}else if(idx1!=-1 && idx2==-1){//ketemu a
			string dum="";
			string sawal = "";
			for(i=0;i<idx1;i++){
				char kar = s[i];
				sawal+=kar;
			}
			for(j=idx1+pjga;j<pjgs;j++){
				char kar = s[j];
				dum+=kar;
			}
			s = sawal+b+dum;
			i = idx1+pjgb;
			// printf("i jd: %d\n",i);
			// cout<<"sawal: "<<sawal<<" b: "<<b<<" dum: "<<dum<<endl;
		}else{//ketemu dua"nya
			if(idx1<idx2){//a ketemu dulu
				string dum="";
				string sawal = "";
				for(i=0;i<idx1;i++){
					char kar = s[i];
					sawal+=kar;
				}
				for(j=idx1+pjga;j<pjgs;j++){
					char kar = s[j];
					dum+=kar;
				}
				s = sawal+b+dum;
				i = idx1+pjgb;
				/*printf("i jd: %d\n",i);
				cout<<"sawal: "<<sawal<<" b: "<<b<<" dum: "<<dum<<endl;*/
			}else{
				string dum="";
				string sawal = "";
				for(i=0;i<idx2;i++){
					char kar = s[i];
					sawal+=kar;
				}
				for(j=idx2+pjgb;j<pjgs;j++){
					char kar = s[j];
					dum+=kar;
				}
				s = sawal+a+dum;
				i = idx2+pjga;
				// printf("i jd: %d\n",i);
				// cout<<"sawal: "<<sawal<<" a: "<<a<<" dum: "<<dum<<endl;

			}
		}

		
	}
	cout<<s<<endl;
	return 0;
}