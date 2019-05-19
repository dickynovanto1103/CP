import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n = sc.nextBigInteger();
		// System.out.println(n);
		int i;
		for(i=1;i<1000000;i++){
			n = n.divide(BigInteger.valueOf(i));
			if(n.equals(BigInteger.ONE)){System.out.println(i); break;}
			// System.out.println(i + " " + val.toString().length());
		}
	}
}