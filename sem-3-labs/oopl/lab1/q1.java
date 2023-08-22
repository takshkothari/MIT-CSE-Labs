import java.util.*;

class q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter 3 numbers");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = largest(a, b, c);
        System.out.println("largest number is " + x);
    }

    static int largest(int a, int b, int c) {
        int d = (a > b) ? a : b;
        d = (d > c) ? d : c;
        return d;
    }
}