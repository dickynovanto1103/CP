import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i;

		BigInteger[] awal = new BigInteger[1510];
		BigInteger[] akhir = new BigInteger[1510];
		awal[1] = BigInteger.ZERO; akhir[1] = BigInteger.ZERO;
		awal[2] = BigInteger.ONE; akhir[2] = BigInteger.ONE;
		BigInteger satu = BigInteger.ONE; BigInteger dua = BigInteger.valueOf(2);
		for(i=3;i<=1500;i++){
			awal[i] = (awal[i-1].add(awal[i-2])).add(satu);
			akhir[i] = (akhir[i-1].add(akhir[i-2])).add(dua);
		}
		int tc = 1;
		while(true){
			int idx = sc.nextInt();
			if(idx==0){break;}
			System.out.println("Set "+(tc++)+":");
			System.out.println((awal[idx].add(akhir[idx])).divide(dua));
		}
	}
}