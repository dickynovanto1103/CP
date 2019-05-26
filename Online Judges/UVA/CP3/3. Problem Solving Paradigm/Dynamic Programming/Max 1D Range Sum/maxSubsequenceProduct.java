import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[] = new int[120];
		int idx = 0;

		while(sc.hasNext()){
			int bil = sc.nextInt();

			if(bil == -999999){
				BigInteger maks = BigInteger.valueOf(-1000000000);
				for(int i=0;i<idx;i++){
					BigInteger ans = BigInteger.ONE;
					for(int j=i;j<idx;j++){
						ans = ans.multiply(BigInteger.valueOf(a[j]));
						maks = maks.max(ans);
					}
				}
				System.out.println(maks);
				idx = 0;
			}else{
				a[idx++] = bil;
			}
		}
	}
}