#include <bits/stdc++.h>

using namespace std;

int main(){

	int tc,i,n,a[8],pos[8],j,k,l,m,o,p,q,r;
	bool found;
	scanf("%d",&tc);
	while(tc--){
		found=false;
		memset(pos,0,sizeof pos);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(n==2){if((a[0]==3 && a[1]==0) || (a[0]==1 && a[1]==1) || (a[0]==0 && a[1]==3)){found=true;}}
		else if(n==3){
			for(i=1;i<=3;i++){
				for(j=1;j<=3;j++){
					for(k=1;k<=3;k++){
						if(i==1){pos[0]+=3;}//a menang lawan b
						if(i==2){pos[0]+=1;pos[1]+=1;}
						if(i==3){pos[1]+=3;}
						if(j==1){pos[0]+=3;}//a menang lawan c
						if(j==2){pos[0]+=1;pos[2]+=1;}
						if(j==3){pos[2]+=3;}
						if(k==1){pos[1]+=3;}//b menang lawan c
						if(k==2){pos[1]+=1;pos[2]+=1;}
						if(k==3){pos[2]+=3;}
						//checking
						if((a[0]==pos[0]) && (a[1]==pos[1]) && (a[2]==pos[2])){found=true;}
						if(found){break;}
						else{memset(pos,0,sizeof pos);}
					}
					if(found){break;}
				}
				if(found){break;}
			}
		}else if(n==4){
			for(i=1;i<=3;i++){
				for(j=1;j<=3;j++){
					for(k=1;k<=3;k++){
						for(l=1;l<=3;l++){
							for(m=1;m<=3;m++){
								for(n=1;n<=3;n++){
										if(i==1){pos[0]+=3;}//a menang lawan b
										if(i==2){pos[0]+=1;pos[1]+=1;}
										if(i==3){pos[1]+=3;}
										if(j==1){pos[0]+=3;}//a menang lawan c
										if(j==2){pos[0]+=1;pos[2]+=1;}
										if(j==3){pos[2]+=3;}
										if(k==1){pos[0]+=3;}//a menang lawan d
										if(k==2){pos[0]+=1;pos[3]+=1;}
										if(k==3){pos[3]+=3;}
										if(l==1){pos[1]+=3;}//b menang lawan c
										if(l==2){pos[1]+=1;pos[2]+=1;}
										if(l==3){pos[2]+=3;}
										if(m==1){pos[1]+=3;}//b menang lawan d
										if(m==2){pos[1]+=1;pos[3]+=1;}
										if(m==3){pos[3]+=3;}
										if(n==1){pos[2]+=3;}//c menang lawan d
										if(n==2){pos[2]+=1;pos[3]+=1;}
										if(n==3){pos[3]+=3;}
										//checking
										if((a[0]==pos[0]) && (a[1]==pos[1]) && (a[2]==pos[2]) && (a[3]==pos[3])){found=true;}
										if(found){break;}
										else{memset(pos,0,sizeof pos);}
									}
									if(found){break;}
								}
								if(found){break;}
							}
							if(found){break;}
						}
						if(found){break;}
					}
					if(found){break;}
				}
			}else{//n==5
				for(i=1;i<=3;i++){
					for(j=1;j<=3;j++){
						for(k=1;k<=3;k++){
							for(l=1;l<=3;l++){
								for(m=1;m<=3;m++){
									for(n=1;n<=3;n++){
										for(o=1;o<=3;o++){
											for(p=1;p<=3;p++){
												for(q=1;q<=3;q++){
													for(r=1;r<=3;r++){
														if(i==1){pos[0]+=3;}//a menang lawan b
														if(i==2){pos[0]+=1;pos[1]+=1;}
														if(i==3){pos[1]+=3;}
														if(j==1){pos[0]+=3;}//a menang lawan c
														if(j==2){pos[0]+=1;pos[2]+=1;}
														if(j==3){pos[2]+=3;}
														if(k==1){pos[0]+=3;}//a menang lawan d
														if(k==2){pos[0]+=1;pos[3]+=1;}
														if(k==3){pos[3]+=3;}
														if(l==1){pos[0]+=3;}//a menang lawan e
														if(l==2){pos[0]+=1;pos[4]+=1;}
														if(l==3){pos[4]+=3;}
														if(m==1){pos[1]+=3;}//b menang lawan c
														if(m==2){pos[1]+=1;pos[2]+=1;}
														if(m==3){pos[2]+=3;}
														if(n==1){pos[1]+=3;}//b menang lawan d
														if(n==2){pos[1]+=1;pos[3]+=1;}
														if(n==3){pos[3]+=3;}
														if(o==1){pos[1]+=3;}//b menang lawan e
														if(o==2){pos[1]+=1;pos[4]+=1;}
														if(o==3){pos[4]+=3;}
														if(p==1){pos[2]+=3;}//c menang lawan d
														if(p==2){pos[2]+=1;pos[3]+=1;}
														if(p==3){pos[3]+=3;}
														if(q==1){pos[2]+=3;}//c menang lawan e
														if(q==2){pos[2]+=1;pos[4]+=1;}
														if(q==3){pos[4]+=3;}
														if(r==1){pos[3]+=3;}//d menang lawan e
														if(r==2){pos[3]+=1;pos[4]+=1;}
														if(r==3){pos[4]+=3;}
														//checking
														if((a[0]==pos[0]) && (a[1]==pos[1]) && (a[2]==pos[2]) && (a[3]==pos[3]) && (a[4]==pos[4])){found=true;}
														if(found){break;}
														else{memset(pos,0,sizeof pos);}
														}
														if(found){break;}
													}
													if(found){break;}
												}
												if(found){break;}
											}
											if(found){break;}
										}
										if(found){break;}
									}
									if(found){break;}
								}
								if(found){break;}
							}
							if(found){break;}
						}
					if(found){break;}
				}
			}
			if(found){printf("YES\n");}
			else{printf("NO\n");}
		}
		return 0;
	}
	
