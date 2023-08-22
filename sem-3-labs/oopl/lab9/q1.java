import java.util.*;

class NewThread implements Runnable {
    String name;
    Thread t;
    int n;
    String table;

    NewThread(String s, int a) {
        name = s;
        n = a;
        table = "";
        t = new Thread(this, name);
        t.start();
    }

    public void run() {
        for (int i = 1; i <= 10; i++) {
            table = table + " " + (i * n);
        }
    }
}

class Tables {
    NewThread t;

    Tables(int n) {
        String temp = "" + n;
        t = new NewThread(temp, n);
    }
}

class q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("enter number");
        n = sc.nextInt();
        Tables ob = new Tables(n);
        Tables ob1 = new Tables(5);
        Tables ob2 = new Tables(7);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("interrupted");
        }
        System.out.println("multiplicaton table of " + n + ":" + ob.t.table);
        System.out.println("multiplicaton table of 5:" + ob1.t.table);
        System.out.println("multiplicaton table of 7:" + ob2.t.table);
    }
}