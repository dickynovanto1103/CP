import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		int n,i;
		Scanner input = new Scanner(System.in);
		n = input.nextInt();
		while(n-->0){
			BigInteger x,y;
			String angka1,angka2;
			x = input.nextBigInteger();
			y = input.nextBigInteger();
			angka1 = x.toString();
			angka2 = y.toString();

			StringBuffer hasil = new StringBuffer();
			int minim = Math.min(angka1.length(),angka2.length());
			//System.out.println("panjang minimal: "+minim);
			int remainder = 0;
			for(i=0;i<minim;i++){
				int bil1 = angka1.charAt(i)-'0';	
				int bil2 = angka2.charAt(i)-'0';
				int sum = bil1+bil2+remainder;

				remainder = sum/10;
				sum%=10;
				//System.out.println("bil1: "+bil1+" bil2: "+bil2+" sum: "+sum);
				char kar = Character.forDigit(sum,10);
				hasil.append(kar);
			}
			if(angka1.length() > angka2.length()){
				for(i=minim;i<angka1.length();i++){
					int bil1 = angka1.charAt(i)-'0';
					int sum = bil1+remainder;
					remainder = sum/10;
					sum%=10;
					char kar = Character.forDigit(sum,10);
					hasil.append(kar);
				}
				char kar = Character.forDigit(remainder,10);
				if(remainder==1){hasil.append(remainder);}
			}else if(angka1.length() < angka2.length()){
				for(i=minim;i<angka2.length();i++){
					int bil1 = angka2.charAt(i)-'0';
					int sum = bil1+remainder;
					remainder = sum/10;
					sum%=10;
					char kar = Character.forDigit(sum,10);
					hasil.append(kar);
				}
				char kar = Character.forDigit(remainder,10);
				if(remainder==1){hasil.append(remainder);}
			}else{
				char kar = Character.forDigit(remainder,10);
				if(remainder==1){hasil.append(remainder);}
			}
			//cetak hasil
			boolean found = false;
			for(i=0;i<hasil.length();i++){
				if(hasil.charAt(i)!='0' && !found){found = true;}
				if(found){System.out.print(hasil.charAt(i));}
			}
			System.out.println();
			/*System.out.println("angka1: "+angka1+" angka2: "+angka2);
			System.out.println("panjang angka1: "+angka1.length()+" angka2: "+angka2.length());*/
		}
	}
}