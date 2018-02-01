import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String a = input.next();
			//System.out.println("a: "+a);
			int baseFrom = input.nextInt();
			int baseTo = input.nextInt();
			BigInteger hasil = new BigInteger(a,baseFrom);
			/*System.out.println("hasil: "+hasil);
			String hasilPertama = hasil.toString();
			System.out.println("hasilPertama: "+hasilPertama);
			BigInteger hasilAkhirBigInt = new BigInteger(hasilPertama,baseFrom);*/
			a = hasil.toString(baseTo);
			int panjangText = a.length();
			if(panjangText>7){System.out.println("  ERROR");}
			else{
				int i;
				for(i=0;i<7-panjangText;i++){
					System.out.print(" ");
				}
				System.out.println(a.toUpperCase());
			}
		}
	}
}