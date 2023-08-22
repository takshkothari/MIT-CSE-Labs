import java.util.*;

class q2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, d, ch;
        double x1, x2;
        System.out.println("enter coeffs of quadratic equation");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = b * b - 4 * a * c;
        if (d > 0)
            ch = 1;
        else if (d < 0)
            ch = -1;
        else
            ch = 0;
        switch (ch) {
            case 1:
                x1 = (-1 * b + Math.sqrt(d)) / (2 * a);
                x2 = (-1 * b - Math.sqrt(d)) / (2 * a);
                System.out.println("the real and distinct roots are " + x1 + " and " + x2);
                break;
            case 0:
                x1 = (-1 * b) / (2 * a);
                System.out.println("the real and equal root is " + x1);
                break;
            default:
                x1 = (-1 * b) / 2 * a;
                x2 = Math.sqrt(-1 * d) / (2 * a);
                System.out.println("imaginary roots whose real and imaginary parts are " + x1 + " and i" + x2);
                break;
        }
    }
}