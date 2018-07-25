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
	int n,i,j;
	scanf("%d",&n);
	string a,b;
	cin>>a>>b;
	int kiri = 0, kanan = n-1;
	int ans = 0;
	set<char> s;
	while(kiri<kanan){
		
		int counter1[26], counter2[26];
		memset(counter1,0,sizeof counter1); memset(counter2,0,sizeof counter2);
		int kar = a[kiri] - 'a';
		counter1[kar]=1;
		kar = a[kanan] - 'a';
		counter1[kar]=1;
		kar = b[kiri] - 'a';
		counter2[kar]=1;
		kar = b[kanan] - 'a';
		counter2[kar]=1;

		

		int diff = 0;
		for(i=0;i<26;i++){
			if(counter1[i] != counter2[i]){diff++;}
		}
			
		if(diff==4){
			ans+=2;
		}else if(diff==3){
			set<char> s1, s2;
			s1.insert(a[kiri]); s1.insert(a[kanan]); s2.insert(b[kiri]); s2.insert(b[kanan]);	
			if(s1.size()==2 && s2.size()==1){ans+=1;}
			else if(s1.size()==1 && s2.size() == 2){ans+=2;}
		}
		else if(diff==1){ans++;}
		else if(diff==2){
			set<char> s1, s2;
			s1.insert(a[kiri]); s1.insert(a[kanan]); s2.insert(b[kiri]); s2.insert(b[kanan]);	
			if(s1.size()==2 && s2.size()==2){ans+=1;}
		}

		
		// printf("tambah diff: %d ans jd: %d\n",diff, ans);

		kiri++; kanan--;
		
	}
	if(kiri==kanan){
		s.insert(a[kiri]); s.insert(b[kiri]);
		if(s.size()==2){ans++;}
	}
	printf("%d\n",ans);
	return 0;
}; 