import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		BigInteger a = BigInteger.ONE;//constructor
		BigInteger b = BigInteger.valueOf(-1);
		BigInteger c = BigInteger.valueOf(2);
		Scanner sc = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		BigInteger nol = BigInteger.ZERO;
		while(sc.hasNext()){
			BigInteger idx = sc.nextBigInteger();
			ans = a.multiply(idx.multiply(idx)).add(b.multiply(idx)).add(c);
			if(idx.equals(nol)){ans=BigInteger.valueOf(1);}
			System.out.println(ans);
		}
	}
}