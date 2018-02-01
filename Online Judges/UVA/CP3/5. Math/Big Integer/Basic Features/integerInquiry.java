import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		while(true){
			BigInteger a = input.nextBigInteger();
			if(a.equals(BigInteger.ZERO)) break;
			sum = sum.add(a);
		}
		System.out.println(sum);
		
	}
}