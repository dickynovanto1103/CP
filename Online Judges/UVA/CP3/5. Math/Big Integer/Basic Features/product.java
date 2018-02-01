import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			BigInteger a = input.nextBigInteger();
			BigInteger b = input.nextBigInteger();
			System.out.println(a.multiply(b));
		}
	}
}