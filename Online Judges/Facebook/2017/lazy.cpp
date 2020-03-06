#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,j,i,n,cnt,sum,curidx,temp,jumlah,counter,idx;
	vector <int> a;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		cnt=sum=0;
		scanf("%d",&n);
		for(j=0;j<n;j++){scanf("%d",&temp); a.push_back(temp);}
		sort(a.begin(),a.end());
		printf("Case #%d: ",i);
		/*printf("array awal:");
		for(j=0;j<a.size();j++){printf(" %d",a[j]);}
		printf("\n");*/
		for(j=0;j<n;j++){if(a[j]>=50){idx=j;break;}}
		for(j=0;j<n;j++){
			//printf("j: %d\n",j);

			if(a[j]>=50){cnt++; a.erase(a.begin()+idx);}
			/*printf("array sesudah diseleksi awal:");
			for(int k=0;k<a.size();k++){printf(" %d",a[k]);}
			printf("\n");
			printf("cnt awal: %d\n",cnt);*/
		}
		/*printf("array sesudah diseleksi awal:");
		for(j=0;j<a.size();j++){printf(" %d",a[j]);}
		printf("\n");
		printf("cnt awal: %d\n",cnt);*/
		//sisa yg kurang dr 50
		while(!a.empty()){
			sum=a[a.size()-1];
			jumlah=2;
			counter=0;
			if(a.size()<2){jumlah=1;}
			if(sum*jumlah>=50){
				cnt++; a.erase(a.begin()+(a.size()-1)); jumlah--;
				while(jumlah){a.erase(a.begin()+counter); counter++; jumlah--;}
				/*printf("arr setelah dihapus:");
				for(j=0;j<a.size();j++){printf(" %d",a[j]);}
				printf("\n");*/
			}else{
				jumlah=1;
				sum=a[a.size()-1];
				counter=0;
				while(a.size()>jumlah && jumlah*sum < 50){jumlah++;}
				//printf("jumlah: %d\n",jumlah);
				//jumlah = a.size() atau jumlah*sum >=50
				if(jumlah*sum>=50){
					//printf("tes lebih dari 50\n");
					cnt++; a.erase(a.begin()+(a.size()-1)); jumlah--;
					//printf("jumlah sekarang: %d\n",jumlah);
					counter=0;
					while(jumlah){
						//printf("counter sekarang: %d\n",counter);
						a.erase(a.begin()+counter); 

						/*printf("arr setelah dihapus sebagian:");
						for(j=0;j<a.size();j++){printf(" %d",a[j]);}
						printf("\n");*/
						jumlah--;
						//printf("jumlah sekarang: %d\n",jumlah);
					}
					/*printf("arr setelah dihapus:");
				for(j=0;j<a.size();j++){printf(" %d",a[j]);}
				printf("\n");*/
				}else{//jumlah = a.size() adan jumlahnya ga sampe a.size();
					//printf("tes kurang dari 50\n");
					counter=0;
					while(!a.empty()){a.erase(a.begin()+counter);counter++;}
				}
			}
		}
		printf("%d\n",cnt);
		a.clear();
	}
	return 0;
}