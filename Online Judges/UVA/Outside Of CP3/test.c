#include <stdio.h>

int main() {
  int n,i,j;
  while(scanf("%d",&n)){
    int tujuan = n;
    int nomorKotakSekarang = 0;
    int idx = 1;
    if(n==0){break;}
    for(i=1;;i+=2){
      
      if((n-i)<=0){
        break;
      }
      nomorKotakSekarang+=i;
      idx++;
      n-=i;
    }
    int foundAns = 0;
    if(idx%2==1){

      for(j=1;j<=idx;j++){
        nomorKotakSekarang++;
        if(nomorKotakSekarang==tujuan){
          printf("%d %d\n",idx,j);
          foundAns = 1;
          break;
        }
      }
      if(foundAns==1){continue;}
      for(i=idx-1;i>=1;i--){
        nomorKotakSekarang++;
        if(nomorKotakSekarang==tujuan){
          printf("%d %d\n",i,idx);
          break;
        }
      }
      if(foundAns==1){continue;}
    }else{
      printf("masuk sini\n");
      for(i=1;i<=idx;i++){
        nomorKotakSekarang++;
        printf("nomorKotakSekarang: %d\n",nomorKotakSekarang);
        if(nomorKotakSekarang==tujuan){
          printf("%d %d\n",i,idx);
          foundAns = 1;
          break;
        }
        
      }
      if(foundAns==1){continue;}
      for(j=idx-1;j>=1;j--){
        nomorKotakSekarang++;
        printf("nomorKotakSekarang: %d\n",nomorKotakSekarang);
        if(nomorKotakSekarang==tujuan){
          printf("%d %d\n",idx,j);
          break;
        }
      }
      if(foundAns==1){continue;}
    }
  }
  
  
  return 0; 
}
