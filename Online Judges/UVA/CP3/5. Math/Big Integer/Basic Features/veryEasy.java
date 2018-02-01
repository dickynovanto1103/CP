import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()){
			BigInteger n = input.nextBigInteger();
			BigInteger a = input.nextBigInteger();
			BigInteger sum = BigInteger.ZERO;
			BigInteger one = BigInteger.ONE;
			BigInteger i = BigInteger.ONE;
			while(i.compareTo(n)==-1 || i.compareTo(n)==0){
				BigInteger cur = (i.multiply(a.pow(i.intValue())));
				sum = sum.add(cur);
				i = i.add(BigInteger.valueOf(1));
				//System.out.println(sum+" i: "+i);	
			}
			
			System.out.println(sum);
		}
	}
}