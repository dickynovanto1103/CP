import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		BigInteger[] a = new BigInteger[2010];
		int i;
		a[1] = BigInteger.ONE;
		a[2] = BigInteger.valueOf(3);
		for(i=3;i<=2000;i++){a[i] = (a[2].multiply(a[i-1])).subtract(a[i-2]);}
		//for(i=1;i<=10;i++){System.out.println(a[i]);}
		Scanner sc = new Scanner(System.in);
		while(true){
			int bil = sc.nextInt();
			if(bil==0){break;}
			System.out.println(a[bil]);
		}
	}
}