import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true){
			BigInteger n = input.nextBigInteger();
			BigInteger k = input.nextBigInteger();	
			int N = n.intValue();
			int K = k.intValue();
			if(N==0 && K==0){break;}
			if(n==BigInteger.ONE){System.out.println(k);}
			else{
				BigInteger r = n;
				BigInteger a = n;
				BigInteger one = BigInteger.ONE;
				BigInteger sum = BigInteger.ZERO;
				sum = a.multiply(one.subtract(r.pow(k.intValue())));
				//System.out.println("r changes?: "+r);
				sum = sum.divide(one.subtract(r));
				sum = sum.mod(BigInteger.valueOf(1000000007));
				System.out.println(sum);
			}
			
		}
		

	}
}