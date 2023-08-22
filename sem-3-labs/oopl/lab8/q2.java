import java.util.*;

class MyExceptions extends Exception {
    private String errCode;

    MyExceptions(String err) {
        errCode = err;
    }

    String getCode() {
        return errCode;
    }
}

class CurrentDate {
    int day, month, year;

    void createDate() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter day ");
        day = sc.nextInt();
        System.out.println("Enter month ");
        month = sc.nextInt();
        System.out.println("Enter year ");
        year = sc.nextInt();
    }
}

class q2 {
    public static void main(String args[]) throws MyExceptions {
        MyExceptions invalMonth = new MyExceptions("InvalidMonthException");
        MyExceptions invalDay = new MyExceptions("InvalidDayException");
        CurrentDate cd = new CurrentDate();
        try {
            cd.createDate();
            if (cd.month > 12 || cd.month < 1)
                throw invalMonth;
            else if (cd.month == 1 || cd.month == 3 || cd.month == 5 || cd.month == 7 || cd.month == 8 || cd.month == 10
                    || cd.month == 12) {
                if (cd.day > 31 || cd.day < 1)
                    throw invalDay;
            } else if (cd.month == 2) {
                if (cd.year % 4 == 0) {
                    if (cd.day > 29 || cd.day < 1)
                        throw invalDay;
                } else {
                    if (cd.day > 28 || cd.day < 1)
                        throw invalDay;
                }
            } else {
                if (cd.day > 30 || cd.day < 1)
                    throw invalDay;
            }
            System.out.println("Date is: " + cd.day + "/" + cd.month + "/" + cd.year);
        } catch (MyExceptions e) {
            System.out.println("Exception thrown: " + e.getCode());
        }
    }
}