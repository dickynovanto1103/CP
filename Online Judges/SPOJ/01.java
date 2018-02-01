import java.math.BigInteger;
import java.util.Scanner;

class Main{
	public static final int maxn = 10004;
	public static BigInteger[][] dp = new BigInteger[maxn][2];
	public static int n;
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		int i,j;
		for(i=0;i<maxn;i++){
			for(j=0;j<2;j++){
				dp[i][j] = BigInteger.valueOf(-1);
			}
		}

		n = sc.nextInt();
		BigInteger ans = solve(1,0).add(solve(1,1));
		System.out.println(ans);
	}

	public static BigInteger solve(int idx, int angka){
		if(idx==n){return BigInteger.ONE;}
		if(dp[idx][angka].compareTo(BigInteger.valueOf(-1))!=0){return dp[idx][angka];}
		BigInteger ans = BigInteger.ZERO;
		if(angka==0){
			ans = ans.add(solve(idx+1,1));
		}else{
			ans = ans.add(solve(idx+1,1).add(solve(idx+1,0)));
		}
		dp[idx][angka] = ans;
		return dp[idx][angka];
	}
}