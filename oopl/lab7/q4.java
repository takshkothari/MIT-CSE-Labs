
import java.util.*;

interface Sports {
    void putGrade(int a);

    int getGrade();
}

class Student {
    int n, marks;

    void putNo(int a) {
        n = a;
    }

    void putMarks(int a) {
        marks = a;
    }

    int getNo() {
        return n;
    }

    int getMarks() {
        return marks;
    }

    class Result implements Sports {
        int sg;

        public void putGrade(int a) {
            sg = a;
        }

        public int getGrade() {
            return sg;
        }

        public void disp() {
            System.out.println("Roll Number: " + getNo() + "\nMarks: " + getMarks() + "\nSports Grade: " + getGrade());
        }
    }
}

public class q4 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        Student s = new Student();
        Student.Result r = s.new Result();

        System.out.print("Enter roll number ");
        s.putNo(sc.nextInt());
        System.out.println("Enter marks ");
        s.putMarks(sc.nextInt());
        System.out.println("Enter sports grade ");
        r.putGrade(sc.nextInt());
        System.out.println("Displaying results:");
        r.disp();
    }
}