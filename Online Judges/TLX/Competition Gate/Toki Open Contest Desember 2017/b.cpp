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

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int n,jumlah,batas;

	int a[100],i,j;
	scanf("%d %d %d",&n,&jumlah,&batas);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int batasTemp = batas;
	batas = 200000;
	sort(a,a+n,cmp);
	// for(i=0;i<n;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",a[i]);
	// }
	// printf("\n");
	int ans = 0;
	int idx = 0;
	multiset<int> sa;
	int k,l,m,o,p,q,r,s;
	if(jumlah==1){
		
		for(i=0;i<n;i++){
			ans = a[i];
			idx++; sa.insert(ans);
			if(idx==batas){
				goto FINAL;
			}
		}
		
		
	}else if(jumlah==2){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				ans = a[i] + a[j];
				//printf("yang diinsert: %d\n",ans);
				idx++; sa.insert(ans);
				if(idx==batas){goto FINAL;}		
			}
		}
	}else if(jumlah==3){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					ans = a[i] + a[j] + a[k];
					idx++; sa.insert(ans);
					if(idx==batas){goto FINAL;}
				}
			}
		}
	}else if(jumlah==4){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						ans = a[i] + a[j] + a[k] + a[l];
						idx++; sa.insert(ans);
						if(idx==batas){goto FINAL;}	
					}
				}
			}
		}
	}else if(jumlah==5){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							ans = a[i] + a[j] + a[k] + a[l] + a[m];
							idx++; sa.insert(ans);
							if(idx==batas){goto FINAL;}		
						}
						
					}
				}
			}
		}
	}else if(jumlah==6){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							for(o=m+1;o<n;o++){
								ans = a[i] + a[j] + a[k] + a[l] + a[m] + a[o];
								idx++; sa.insert(ans);
								if(idx==batas){goto FINAL;}			
							}
						}
					}
				}
			}
		}
	}else if(jumlah==7){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							for(o=m+1;o<n;o++){
								for(p=o+1;p<n;p++){
									ans = a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p];
									idx++; sa.insert(ans);
									if(idx==batas){goto FINAL;}				
								}
								
							}
						}
					}
				}
			}
		}
	}else if(jumlah==8){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							for(o=m+1;o<n;o++){
								for(p=o+1;p<n;p++){
									for(q=p+1;q<n;q++){
										ans = a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q];
										idx++; sa.insert(ans);
										if(idx==batas){goto FINAL;}					
									}
									
								}
								
							}
						}
					}
				}
			}
		}
	}else if(jumlah==9){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							for(o=m+1;o<n;o++){
								for(p=o+1;p<n;p++){
									for(q=p+1;q<n;q++){
										for(r=q+1;r<n;r++){
											ans = a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r];
											idx++; sa.insert(ans);
											if(idx==batas){goto FINAL;}						
										}
										
									}
									
								}
								
							}
						}
					}
				}
			}
		}
	}else if(jumlah==10){
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				for(k=j+1;k<n;k++){
					for(l=k+1;l<n;l++){
						for(m=l+1;m<n;m++){
							for(o=m+1;o<n;o++){
								for(p=o+1;p<n;p++){
									for(q=p+1;q<n;q++){
										for(r=q+1;r<n;r++){
											for(s=r+1;s<n;s++){
												ans = a[i] + a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r] + a[s];
												idx++; sa.insert(ans);
												if(idx==batas){goto FINAL;}							
											}
											
										}
										
									}
									
								}
								
							}
						}
					}
				}
			}
		}
	}
	FINAL:
	multiset<int>::iterator it;
	vi listBil;
	for(it=sa.begin();it!=sa.end();it++){
		int bil = *it;
		listBil.pb(bil);
	}
	batas = batasTemp;
	int nilai = 0;
	for(i=listBil.size()-1;i>=0;i--){

		nilai++;
		if(nilai==batas){printf("%d\n",listBil[i]);}
	}
	//printf("%d\n",ans);
	return 0;
};