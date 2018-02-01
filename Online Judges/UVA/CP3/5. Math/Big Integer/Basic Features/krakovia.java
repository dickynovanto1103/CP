import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		int N,F,test;
		Scanner input = new Scanner(System.in);
		test = 1;
		while(true){
			N = input.nextInt();
			F = input.nextInt();
			if(N==0 && F==0) break;
			BigInteger sum = BigInteger.ZERO;
			for(int i=0;i<N;i++){
				BigInteger bil = input.nextBigInteger();
				//System.out.println("input bilangan: "+bil);
				sum = sum.add(bil);
			}
			System.out.println("Bill #"+(test++) +" costs "+sum+": each friend should pay "+sum.divide(BigInteger.valueOf(F)));
			System.out.println();
		}
		
	}	
}
