import java.math.BigInteger;
import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		int tc;
		BigInteger a,b;
		Scanner sc = new Scanner(System.in);
		tc = sc.nextInt();
		while(tc-->0){
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			BigInteger bil1 = a.subtract(BigInteger.ONE);
			BigInteger bil2 = b.subtract(BigInteger.ONE);
			BigInteger ans1 = (a.multiply(bil1)).divide(BigInteger.valueOf(2));
			BigInteger ans2 = (b.multiply(bil2)).divide(BigInteger.valueOf(2));
			System.out.println(ans1.multiply(ans2));
		}
	}
}