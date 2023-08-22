import java.util.Scanner;

class NewThread3 implements Runnable {
    static int goods, end;
    String name;
    Thread t;
    int type, rate;

    NewThread3(String s, int ty, int r, int g) {
        name = s;
        type = ty;
        rate = r;
        goods = g;
        end = -1;
        t = new Thread(this, name);
        t.start();
    }

    public void run() {
        if (type == 1) {
            while (end == -1) {
                try {
                    Thread.sleep(rate);
                    if (end != -1)
                        break;
                    goods += 1;
                    System.out.println("Producer produced a good. Goods: " + goods);
                } catch (InterruptedException e) {
                    System.out.println("Interrupted");
                }
            }
        } else {
            while (end == -1) {
                try {
                    Thread.sleep(rate);
                    if (goods == 0) {
                        System.out.println("Goods ran out");
                        end = 1;
                        break;
                    }
                    goods -= 1;
                    System.out.println("Consumer consumed a good. Goods: " + goods);
                } catch (InterruptedException e) {
                    System.out.println("Interrupted");
                }
            }
        }
    }
}

public class q3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of initial goods available: ");
        int g = sc.nextInt();
        System.out.print("Enter speed of producer (in ms) ");
        int pr = sc.nextInt();
        System.out.print("Enter speed of consumer (in ms) ");
        int cr = sc.nextInt();

        NewThread3 producer = new NewThread3("Producer", 1, pr, g);
        NewThread3 consumer = new NewThread3("Consumer", 2, cr, g);
    }

}
