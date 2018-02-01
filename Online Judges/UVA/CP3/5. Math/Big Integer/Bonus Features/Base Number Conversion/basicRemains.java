import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true){
			int base = input.nextInt();
			if(base==0) break;
			BigInteger p = new BigInteger(input.next(),base);
			//System.out.println("p: "+p);
			BigInteger m = new BigInteger(input.next(),base);
			//System.out.println("m: "+m);
			System.out.println(p.mod(m).toString(base));	
		}
		
	}
}