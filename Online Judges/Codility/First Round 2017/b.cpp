// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>

using namespace std;

int ToInt(string a){
	int bil = 0;
	for(int i=0;i<a.length();i++){
		bil*=10; bil+=a[i]-'0';
	}
	return bil;
}

int solution(string &S) {
    int jadwal[10081],i,j;
    int idxAwal, idxAkhir;
    for(i=0;i<10081;i++){jadwal[i] = 0;}
    for(i=0;i<S.length();i++){
    	string hari  = S.substr(i,3);
    	//printf("hari terbaca: "); cout<<hari<<endl;
    	//printf("kar: %c\n",S[i+4]);
    	int h1 = ToInt(S.substr(i+4,2));
    	int m1 = ToInt(S.substr(i+7,2));
    	int h2 = ToInt(S.substr(i+10,2));
    	int m2 = ToInt(S.substr(i+13,2));
    	//printf("h1: %d m1: %d h2: %d m2: %d hari: ",h1,m1,h2,m2); cout<<hari<<endl;
    	int idx;
    	if(hari=="Mon"){idx=0;}
    	else if(hari=="Tue"){idx=1;}
    	else if(hari=="Wed"){idx=2;}
    	else if(hari=="Thu"){idx=3;}
    	else if(hari=="Fri"){idx=4;}
    	else if(hari=="Sat"){idx=5;}
    	else if(hari=="Sun"){idx=6;}
    	
    	idxAwal = idx*1440;
    	idxAwal+=h1*60;
    	idxAwal+=m1;
    	//printf("idxAwal sekarang: %d\n",idxAwal);
    	idxAkhir = idx*1440;
    	idxAkhir+=h2*60;
    	idxAkhir+=m2;
    	//printf("idxawal: %d idxakhir: %d\n",idxAwal, idxAkhir);
    	for(j = idxAwal;j<idxAkhir;j++){jadwal[j] = 1;}
  		i+=15;
    }
    int counter = 0, ans = 0;
    for(i=0;i<10080;i++){
    	if(jadwal[i]==0){counter++;}
    	else{ans = max(ans, counter); counter=0;}
    }
    ans = max(ans,counter);
    //printf("%d\n",ans);
    return ans;

    // write your code in C++14 (g++ 6.2.0)
}

int main(){
	int n,i,h1,m1,h2,m2;
	string kata;
	getline(cin,kata);
	int ans = solution(kata);
	printf("%d\n",ans);
}