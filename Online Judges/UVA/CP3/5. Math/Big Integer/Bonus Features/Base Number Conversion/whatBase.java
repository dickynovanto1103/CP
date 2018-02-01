import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int i,j;
		while(input.hasNext()){
			String a = input.next();
			String b = input.next();
			Boolean found = new Boolean(false);
			//cari max nilai
			//System.out.println(a); System.out.println(b);
			
			//di a
			int minim1 = 0;
			for(i=0;i<a.length();i++){
				char kar = a.charAt(i);
				int ascii = (int) kar;	
				minim1 = Math.max(minim1,ascii);
			}
			//di b
			int minim2 = 0;
			for(i=0;i<b.length();i++){
				char kar = b.charAt(i);
				int ascii = (int) kar;
				minim2 = Math.max(minim2,ascii);
			}
			if(minim1>=65){minim1-=54;}
			else{minim1-=47;}
			if(minim2>=65){minim2-=54;}
			else{minim2-=47;}
			if(minim1 == 1){minim1++;}
			if(minim2 == 1){minim2++;}
			//System.out.println("base: "+minim1+" minim2: "+minim2);
			for(i=minim1;i<=36;i++){
				for(j=minim2;j<=36;j++){
					//System.out.println("i: "+i+"j: "+j);
					BigInteger kata1 = new BigInteger(a,i);
					BigInteger kata2 = new BigInteger(b,j);
					if(kata1.equals(kata2)){System.out.println(a+" (base "+i+") = "+b+" (base "+j+")"); found = true; break;}
				}
				if(found){break;}
			}
			if(!found){System.out.println(a+" is not equal to "+b+" in any base 2..36");}
		}
	}
}