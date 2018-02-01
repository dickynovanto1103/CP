import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] a = new BigInteger[110];
		BigInteger bil;
		BigInteger dummy = BigInteger.valueOf(-999999);
		while(sc.hasNext()){
			int cnt = 0;
			bil = sc.nextBigInteger();
			while(bil.compareTo(dummy)==1){
				a[cnt] = bil;
				cnt++;
				bil = sc.nextBigInteger();
			}	
			int i,j;
			BigInteger maks = dummy;
			//if(cnt==1){maks = a[0];}
			for(i=0;i<cnt;i++){
				bil = a[i];
				if(maks.compareTo(bil)==-1){maks = bil;}
				for(j=i+1;j<cnt;j++){
					bil = bil.multiply(a[j]);
					if(maks.compareTo(bil)==-1){//maks lebih kecil
						maks = bil;
					}
					//maks = Math.max(maks,bil);
				}
			}
			System.out.println(maks);

		}
		
	}
}