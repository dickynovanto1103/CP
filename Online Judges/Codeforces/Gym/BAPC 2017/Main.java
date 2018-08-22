import java.util.Scanner;
import java.math.BigDecimal;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++){
			String kata1 = sc.next();
			String kata2 = sc.next();
			Double nilai = sc.nextDouble();

			System.out.println("kata1: "+kata1+" kata2: "+kata2+" nilai: "+nilai);	
		}
		
	}
}