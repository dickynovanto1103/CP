import java.util.Scanner;
import java.math.BigInteger;

class Cetak{
	public void cetakSpasi(int n, int bil){
		int i;
		int cntDigit = banyakDigit(bil);
		for(i=0;i<n-cntDigit;i++){System.out.print(" ");}
	}
	
	public int banyakDigit(int n){
		int cnt = 0;
		if(n>0){
			while(n>0){n/=10; cnt++;}	
		}else{cnt = 1;}
		
		return cnt;
	}
}

class Main{
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		while(true){
			int n = sc.nextInt();
			if(n==0){break;}
			//System.out.println("n terbaca: "+n);
			BigInteger hasil = BigInteger.ONE;
			for(int i=2;i<=n;i++){
				hasil = hasil.multiply(BigInteger.valueOf(i));
			}
			String ans = hasil.toString();
			
			int[] a = new int[10];
			for(int i=0;i<10;i++){a[i] = 0;}
			int ukuran = ans.length();
			char kar;
			int bil;
			
			for(int i=0;i<ukuran;i++){
				kar = ans.charAt(i);
				bil = kar-48;
				a[bil]++;
				//System.out.println("bil: "+bil);
				//System.out.println(ans.charAt(i)-48);
			}
			System.out.println(n+"! --");
			int i, cnt;
			Cetak cetak = new Cetak();
			for(i=0;i<10;i++){
				if(i==5){System.out.println();}
				if(i==0 || i==5){cnt = 4;}
				else{cnt = 5;}
				cetak.cetakSpasi(cnt,1);
				System.out.print("("+i+")");
				cetak.cetakSpasi(5,a[i]);
				System.out.print(a[i]);
			}
			System.out.println();
		}
		
	}
}