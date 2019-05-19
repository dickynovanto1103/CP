import java.util.Scanner;
import java.math.BigInteger;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

class Main{
	public static void main(String[] args) {

		Date val = isDateValid("15/10/1582", "dd/MM/yyyy");
		Date val2 = isDateValid("4/10/1582", "dd/MM/yyyy");
		Date val3 = new Date(1582, 10, 4);
		System.out.println("val3: "+val3);
		System.out.println("val " + val + " val2: " + val2 + " boolean: " + val2.after(val));
	}

	public static Date isDateValid(String dateToValidate, String dateFormat) {
        if(dateToValidate == null){
            return null;
        }

        SimpleDateFormat sdf = new SimpleDateFormat(dateFormat);
        sdf.setLenient(false);
        Date date;
        try {
            date = sdf.parse(dateToValidate);
        } catch (ParseException e) {
            return null;
        }

        return date;
    }
}