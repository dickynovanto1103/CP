import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger a = BigInteger.ZERO;
		BigInteger ten = BigInteger.TEN;
		BigInteger nol = BigInteger.ZERO;
		BigInteger bil = BigInteger.ZERO;
		BigInteger penambahan = BigInteger.ZERO;
		BigInteger sum;
		while(sc.hasNext()){
			a = sc.nextBigInteger();
			int i=1;
			sum = BigInteger.ONE;
			bil = sum.mod(a);
			//System.out.println("bil awal: "+bil);
			while(!bil.equals(nol)){
				penambahan = ten.pow(i);
				//System.out.println("penambahan: "+penambahan);

				sum = sum.add(penambahan);
				//System.out.println("sum: "+sum);
				bil = sum.mod(a);
				//System.out.println("hasil mod dengan "+a+" = "+bil);
				i++;
				//System.out.println("i: "+i);
				
				//System.out.println("bil: "+sum);
				//sum = sum.add(ten.pow(i));
				//System.out.println("a: "+a);
				
				//System.out.println("bil: "+bil);
			}
			String kata = sum.toString();
			System.out.println(kata.length());
		}
	}
}