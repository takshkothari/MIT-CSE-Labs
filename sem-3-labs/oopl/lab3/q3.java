import java.util.*;

class Mixer {

    Scanner sc = new Scanner(System.in);
    int n;
    int arr[] = new int[100];

    void accept() {
        System.out.println("enter number of elements");
        n = sc.nextInt();
        System.out.println("enter elements in ascending order");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
    }

    Mixer mix(Mixer m1, Mixer m2) {
        Mixer m = new Mixer();

        m.n = m1.n + m2.n;
        for (int i = 0; i < m.n; i++) {
            if (i < m1.n)
                m.arr[i] = m1.arr[i];
            else
                m.arr[i] = m2.arr[i - m1.n];
        }
        return m;
    }

    void disp() {
        System.out.println("array elements:");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + "\t");
        System.out.println();
    }
}

class q3 {
    public static void main(String[] args) {
        Mixer m1 = new Mixer();
        Mixer m2 = new Mixer();
        Mixer m = new Mixer();

        m1.accept();
        m1.disp();

        m2.accept();
        m2.disp();

        m = m.mix(m1, m2);
        m.disp();
    }
}