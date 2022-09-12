import java.util.*;

class Counter {
    static int count = 0;

    Counter() {
        count++;
    }

    static void showCount() {
        System.out.println("Counter is " + count);
    }
}

class q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch = 0;
        do {
            System.out.println("Menu\n1.Create Object\n2.Show Count\n3.Exit");
            System.out.println("Enter your choice");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    new Counter();
                    break;
                case 2:
                    Counter.showCount();
                    break;
                case 3:
                    System.out.println("Bye Bye");
                    break;
                default:
                    System.out.println("Wrong choice");
                    break;
            }
            System.out.println("\n");
        } while (ch != 3);
    }
}
