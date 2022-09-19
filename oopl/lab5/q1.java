import java.util.*;

class stud {
    int regno;
    String name;
    GregorianCalendar doj;
    short sem;
    float gpa, cgpa;
    static int count = 1;

    stud() {
        count++;
    }

    String calcYear(String doj) {
        int c = 0, i = 0;
        int ind = -1;
        while (c != 2) {
            if (doj.charAt(i) == '/') {
                c += 1;
            } else {
                ind = i + 1;
            }
            i += 1;
        }
        return (doj.substring(ind + 1, doj.length()));
    }

    stud(String nam, int d, int m, int y, short semester, float g, float cg) {
        GregorianCalendar greg = new GregorianCalendar(y, m, d);
        String s = Integer.toString(greg.get(1));
        String st = s.substring(2, 4);
        String n = Integer.toString(count);
        String regst = st + n;
        regno = Integer.parseInt(regst);
        name = nam;
        doj = greg;
        sem = semester;
        gpa = g;
        cgpa = cg;
        count += 1;
    }

    void disp() {
        System.out.println("Name: " + name + "\nRegistration No: " + regno);
        System.out.println("Date of Joining: " + doj.get(5) + "/" + doj.get(2) + "/" + doj.get(1));
        System.out.println("Semester: " + sem + "\nGPA: " + gpa + "\nCGPA: " + cgpa);
    }
}

class q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of students. (Minimum 5) ");
        int n = sc.nextInt();
        sc.nextLine();
        stud stds[] = new stud[n];
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for student number " + (i + 1));
            System.out.print("Enter your name ");
            String na = sc.nextLine();
            // System.out.print("Enter date of joining in the format dd/mm/yy ");
            // String DateOJ = sc.nextLine();
            System.out.print("Enter day of DOJ ");
            int d = sc.nextInt();
            System.out.print("Enter month of DOJ ");
            int m = sc.nextInt();
            System.out.print("Enter year of DOJ ");
            int y = sc.nextInt();
            System.out.print("Enter your semester ");
            short semester = sc.nextShort();
            System.out.print("Enter your gpa ");
            float g = sc.nextFloat();
            System.out.print("Enter your cgpa ");
            float cg = sc.nextFloat();
            sc.nextLine();

            stds[i] = new stud(na, d, m, y, semester, g, cg);
        }

        System.out.println("\nDisplaying details of all students:\n");
        for (int i = 0; i < n; i++) {
            System.out.println("\nDisplaying details for student number " + (i + 1));
            stds[i].disp();
        }
    }
}