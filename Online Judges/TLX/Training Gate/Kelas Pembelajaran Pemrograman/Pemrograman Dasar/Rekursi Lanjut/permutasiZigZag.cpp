#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int catat[10];
bool visited[10];
vector <int> calonans;
void solve(int kedalaman, int n) {
	int i;
	if(kedalaman > n) {
		int bil = 0;
		for(i=1;i<=n;i++){bil*=10; bil+=catat[i];}
		calonans.push_back(bil);
	}else {
		for(i=1;i<=n;i++){
			if(!visited[i]){
				catat[kedalaman] = i;
				visited[i]=true;
				solve(kedalaman+1, n);
				visited[i]=false;
			}
			

		}
	}
}

string convertToString(int angka, int n) {
	char kata[10];
	int count_digit = n;
	while(angka>0){
		int bil = angka%10;
		kata[count_digit]=bil+'0'; count_digit--;
		angka/=10;
	}
	kata[n+1] = '\0';
	//reverse(kata, kata+n);
	return (string)kata;
}

bool isZigZag(string kata, int n){
	bool found = true;
	for(int i=0;i<n-2 && found;i++) {
		char tengah, kiri, kanan;
		tengah = kata[i+1]; kiri = kata[i]; kanan = kata[i+2];
		if(!(tengah > kanan && tengah > kiri || tengah < kanan && tengah < kiri)){
			found = false;
		}
	}
	return found;
}

int main() {
	int n,i;
	ios_base::sync_with_stdio(false);
	scanf("%d",&n);
	for(i=0;i<n;i++){visited[i]=false;}
	solve(1, n);
	//printf("calon ans:\n");
	int ukuran = calonans.size();
	
	/*for (int i = 0; i < ukuran; ++i)
	{
		printf("%d\n",calonans[i]);
	}*/
	//printf("ukuran: %d\n",ukuran);
	//vector<string> ans;
	for (int i = 0; i < ukuran; ++i)
	{
		//printf("calon ans: %d\n", calonans[i]);
		string kata = convertToString(calonans[i], n-1);
		//cout<<"kata hasil konversi: "<<kata<<endl;
		if(isZigZag(kata,n)){cout<<kata<<endl;}
	}
	
	return 0;
}