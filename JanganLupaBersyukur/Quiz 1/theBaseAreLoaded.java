import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String ans;
		while(sc.hasNext()){
			int b1 = sc.nextInt();
			int b2 = sc.nextInt();
			String angka = sc.next();
			try{
				BigInteger a = new BigInteger(angka,b1);
				ans = a.toString(b2);
				System.out.println(angka+" base "+b1+" = "+ans.toUpperCase()+" base "+b2);
				//System.out.println("a: "+a);	
			}catch(NumberFormatException e) {
				System.out.println(angka+" is an illegal base "+b1+" number");
			}
			
		}
		
	}
}