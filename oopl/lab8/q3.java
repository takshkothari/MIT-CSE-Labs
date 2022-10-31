import java.util.*;

class SeatsFilledEx extends Exception {
    String err;

    SeatsFilledEx() {
        err = "SeatsFilledException";
    }

    String getCode() {
        return err;
    }
}

class Student {
    int regno;
    String name;
    GregorianCalendar DOJ;
    short sem;
    float gpa, cgpa;
    static int count = 1;

    Student() {
        count += 1;
    }

    Student(String n, int d, int m, int y, short s, float gp, float cg) throws SeatsFilledEx {
        SeatsFilledEx sfe = new SeatsFilledEx();
        if (count >= 25) {
            throw sfe;
        }
        GregorianCalendar gcal = new GregorianCalendar(y, m, d);
        String st = Integer.toString(gcal.get(1));
        String yst = st.substring(2, 4);
        String x = Integer.toString(count);
        String regnumString = yst + x;
        regno = Integer.parseInt(regnumString);
        name = n;
        DOJ = gcal;
        sem = s;
        gpa = gp;
        cgpa = cg;
        count += 1;
    }

    void display() {
        System.out.println("\nName of student: " + name + "\nRegistration Number: " + regno + "\nDate of joining: "
                + DOJ.get(5) + "/" + DOJ.get(2) + "/" + DOJ.get(1) + "\nSemester: " + sem + "\nGPA: " + gpa + "\nCGPA: "
                + cgpa);
    }
}

class q3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students. (Minimum 5) ");
        int n = sc.nextInt();
        sc.nextLine();
        Student std[] = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student number " + (i + 1));
            System.out.print("Enter name ");
            String fName = sc.nextLine();
            System.out.print("Enter day of DOJ ");
            int d = sc.nextInt();
            System.out.print("Enter month of DOJ ");
            int m = sc.nextInt();
            System.out.print("Enter year of DOJ ");
            int y = sc.nextInt();
            System.out.print("Enter semester ");
            short semester = sc.nextShort();
            System.out.print("Enter gpa ");
            float gpa = sc.nextFloat();
            System.out.print("Enter cgpa ");
            float cgpa = sc.nextFloat();
            sc.nextLine();
            try {
                std[i] = new Student(fName, d, m, y, semester, gpa, cgpa);
            } catch (SeatsFilledEx e) {
                System.out.println("Exception Thrown: " + e.getCode());
            }
        }
        System.out.println("\nDisplaying details of students:\n");
        for (int i = 0; i < n; i++) {
            System.out.println("\nDetails for student number " + (i + 1));
            std[i].display();
        }
    }
}