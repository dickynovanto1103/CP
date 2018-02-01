import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int b;
		int a;
		while(true){
			//System.out.println("test");
			a = sc.nextInt(); b = sc.nextInt();
			//System.out.println("a: "+a+" b: "+b);
			if(a==0 && b==0){break;}
			System.out.println(BigInteger.valueOf(a).pow(b));
		}
		
	}
}