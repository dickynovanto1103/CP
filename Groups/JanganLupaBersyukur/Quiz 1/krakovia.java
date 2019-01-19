import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		int n, f;
		Scanner sc = new Scanner(System.in);
		BigInteger bil = BigInteger.ZERO;
		int test = 1;
		while(true){
			BigInteger sum = BigInteger.ZERO;
			n = sc.nextInt(); f = sc.nextInt();
			if(n==0 && f==0) break;
			for(int i=0;i<n;i++){
				bil = sc.nextBigInteger();
				sum = sum.add(bil);
			}
			System.out.println("Bill #"+(test++)+" costs "+sum+": each friend should pay "+sum.divide(BigInteger.valueOf(f)));
			System.out.println();
		}
	}
}