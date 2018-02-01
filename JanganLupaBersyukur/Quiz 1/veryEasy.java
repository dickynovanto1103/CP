import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		int n,a;
		Scanner sc = new Scanner(System.in);
		BigInteger N = BigInteger.ZERO;
		BigInteger A = BigInteger.ZERO;
		BigInteger I = BigInteger.ZERO;
		BigInteger nol = BigInteger.ZERO;
		BigInteger sum;
		while(sc.hasNext()){
			n = sc.nextInt();
			a = sc.nextInt();
			N = BigInteger.valueOf(n); A= BigInteger.valueOf(a);
			sum = nol;
			for(int i=1;i<=n;i++){
				I = BigInteger.valueOf(i);
				sum = sum.add(I.multiply(A.pow(i)));
				//i = I.intValue();
				//System.out.println(i);
			}
			System.out.println(sum);
		}
	}
}