import java.time.LocalDate;
import java.util.*;
import java.math.BigInteger;

class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while(true) {
            int numDays = scanner.nextInt();
            int day = scanner.nextInt();
            int month = scanner.nextInt();
            int year = scanner.nextInt();

            if (!(numDays > 0 || day > 0 || month > 0 || year > 0)) {
                break;
            }

            // System.out.println(numDays + " " + day + " " +  month + " " +  year);

            LocalDate localDate = LocalDate.of(year, month, day);
            localDate = localDate.plusDays(numDays);
            System.out.println(localDate.getDayOfMonth() + " " + localDate.getMonthValue() + " " + localDate.getYear());
        }

    }
}