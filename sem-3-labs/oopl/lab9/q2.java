import java.util.Scanner;

class NewThread2 implements Runnable {
    String name;
    Thread t;
    int row[];
    int sum, completed;

    NewThread2(String s, int r[]) {
        name = s;
        row = r;
        completed = -1;
        t = new Thread(this, name);
        t.start();
    }

    public void run() {
        sum = 0;
        for (int i = 0; i < row.length; i++) {
            sum += row[i];
        }
        System.out.println("sum of " + name + " = " + sum);
        completed = 1;
    }

    int getSum() {
        return sum;
    }

    int getCompleted() {
        return completed;
    }
}

class q2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter rows: ");
        int r = sc.nextInt();
        System.out.print("enter columns: ");
        int c = sc.nextInt();
        int mat[][] = new int[r][c];
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.printf("enter element at (" + (i + 1) + "," + (j + 1) + ") ");
                mat[i][j] = sc.nextInt();
            }
        }

        NewThread2 rows[] = new NewThread2[r];
        for (int i = 0; i < r; i++) {
            String t = "row " + (i + 1);
            rows[i] = new NewThread2(t, mat[i]);
        }
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("interrupted");
        }
        while (true) {
            int flag = -1;
            for (int i = 0; i < r; i++) {
                flag = 1;
                if (rows[i].getCompleted() == -1)
                    flag = -1;
            }
            if (flag == 1)
                break;
        }

        for (int i = 0; i < r; i++) {
            sum += rows[i].getSum();
        }

        System.out.println("total sum: " + sum);
    }
}