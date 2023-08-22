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

    String changeName(String name) {
        int flag = 0;
        String temp = "", out = "";
        char initial = ' ';
        for (int i = 0; i < name.length(); i++) {
            if (Character.isUpperCase(name.charAt(i))) {
                flag = 1;
                initial = name.charAt(i);
            }
            if (flag == 1) {
                temp = temp + name.charAt(i);
            }
            if (name.charAt(i) == ' ') {
                flag = 0;
                out = out + initial + ". ";
                temp = "";
            }
            if (i == name.length() - 1) {
                out = out + temp;
            }
        }
        return out;
    }

    stud(String nam, int d, int m, int y, short semester, float g, float cg) {
        GregorianCalendar greg = new GregorianCalendar(y, m, d);
        String s = Integer.toString(greg.get(1));
        String st = s.substring(2, 4);
        String n = Integer.toString(count);
        String regst = st + n;
        regno = Integer.parseInt(regst);
        name = changeName(nam);
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

    void sortName(stud stds[], int n) {
        stud s = new stud();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (((stds[i].name).compareTo((stds[j].name))) > 0) {
                    s = stds[i];
                    stds[i] = stds[j];
                    stds[j] = s;
                }
            }
        }
    }

    void sortSem(stud stds[], int n) {
        stud temp = new stud();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (stds[i].sem < stds[j].sem) {
                    temp = stds[i];
                    stds[i] = stds[j];
                    stds[j] = temp;
                } else if (stds[i].sem == stds[j].sem) {
                    if (stds[i].cgpa < stds[j].cgpa) {
                        temp = stds[i];
                        stds[i] = stds[j];
                        stds[j] = temp;
                    }
                }
            }
        }
    }
}

class q123 {
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

        System.out.println("\nDetails of all students:\n");
        for (int i = 0; i < n; i++) {
            System.out.println("\nDetails for student number " + (i + 1));
            stds[i].disp();
        }

        System.out.print("Enter a character ");
        char ch = sc.next().charAt(0);
        System.out.println("The students with their name starting with the character are: ");
        for (int i = 0; i < n; i++) {
            if (stds[i].name.charAt(0) == ch) {
                stds[i].disp();
            }
        }
        System.out.println("1.Sort by Sem and CGPA\n2.Sort by name\n3.Exit");
        int input = sc.nextInt();

        if (input == 1) {
            stds[0].sortSem(stds, n);
            System.out.println("Students sorted by sem and cgpa:\n");
            for (int i = 0; i < n; i++) {
                stds[i].disp();
            }

        } else if (input == 2) {
            stds[0].sortName(stds, n);
            System.out.println("Students sorted by name:\n");
            for (int i = 0; i < n; i++) {
                stds[i].disp();
            }
        } else {
            System.out.println("Bye Bye");
        }
    }
}