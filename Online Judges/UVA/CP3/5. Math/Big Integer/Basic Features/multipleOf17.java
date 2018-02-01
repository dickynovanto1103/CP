import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		/*BigInteger b = BigInteger.valueOf(24);
		System.out.println("b: "+b.mod(BigInteger.valueOf(17)));*/
		while(true){
			BigInteger a = input.nextBigInteger();
			if(a.equals(BigInteger.valueOf(0))) break;
			BigInteger satuan = a.mod(BigInteger.valueOf(10));
			satuan = satuan.multiply(BigInteger.valueOf(5));
			a = a.divide(BigInteger.valueOf(10));
			if((a.subtract(satuan)).mod(BigInteger.valueOf(17))==BigInteger.valueOf(0)){System.out.println("1");}
			else{System.out.println("0");}
			//BigInteger
			//System.out.println("satuan: "+satuan);
		}
	}
}