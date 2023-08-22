import java.util.*;

class q4 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter n");
        int n = sc.nextInt();
        int i = 0, c = 0;
        System.out.println("the first " + n + " prime numbers are:");
        while (c < n) {
            int x = isPrime(i);
            if (x == 1) {
                System.out.println(i);
                c++;
            }
            i++;
        }
    }

    static int isPrime(int n) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                c++;
        }
        if (c == 2)
            return 1;
        else
            return 0;
    }
}