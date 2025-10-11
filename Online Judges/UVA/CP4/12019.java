import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.*;
import java.math.BigInteger;

class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        for(int tt=0;tt<tc;tt++) {
            int month = scanner.nextInt();
            int day = scanner.nextInt();
            LocalDate localDate = LocalDate.of(2011, month, day);
            
            DayOfWeek dayOfWeek = localDate.getDayOfWeek();
            // System.out.println(month + " " + day + " dayOfWeek: " + dayOfWeek);
            String ans = new String();
            switch (dayOfWeek) {
                case MONDAY:
                    ans = "Monday";
                    break;
                case TUESDAY:
                    ans = "Tuesday";
                    break;
                case WEDNESDAY:
                    ans = "Wednesday";
                    break;
                case THURSDAY:
                    ans = "Thursday";
                    break;
                case FRIDAY:
                    ans = "Friday";
                    break;
                case SATURDAY:
                    ans = "Saturday";
                    break;
                case SUNDAY:
                    ans = "Sunday";
                    break;
            }

            System.out.println(ans);
        }
    }
}