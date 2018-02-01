import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger b = BigInteger.ZERO;
		BigInteger p = BigInteger.ZERO;
		BigInteger m = BigInteger.ZERO;
		while(sc.hasNext()){
			b = sc.nextBigInteger();
			p = sc.nextBigInteger();
			m = sc.nextBigInteger();
			System.out.println(b.modPow(p,m));
		}
	}
}