#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	//a.erase(a.begin()+idx);
	bool visited[101];
	while(scanf("%d",&n),n){
		int ans = 1;
		bool found = false;
		int k=1;
		while(!found){
			memset(visited,false,sizeof visited);
			int jumlah = n-1; visited[1] = true;
			int i=2;
			while(jumlah>1){
				int temp = k-1;
				
				while(temp){//ketika masih jalan
					if(k==5) printf("temp: %d k: %d\n",temp,k);
					if(!visited[i]){temp--;}//klo blm kebunuh,keitung
					i++;
					if(i>=n){i=1;}//reset
				}
				while(visited[i]){i++;}//pas di titik itu udah kebunuh..lanjut
				visited[i] = false;
				if(k==5) printf("i: %d\n",i);
				jumlah--;
				if(k==5) printf("jumlah: %d\n",jumlah);
			}
			
			if(visited[13]){
				printf("%d\n",k); found = true;
			}else{k++;}//cari k baru
		}
		
	}
	
	return 0;
}