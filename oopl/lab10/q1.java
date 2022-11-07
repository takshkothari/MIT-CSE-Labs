import java.util.*;

import javax.lang.model.util.ElementScanner6;

class q1 {
    static <T> void swap(T arr[], int a, int b) {
        T c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }

    static <T> void show(T arr[]) {
        for (int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch, n, a, b;
        System.out.println("1. integer\n2. double\n3. character\n4. string\nenter choice");
        ch = sc.nextInt();
        System.out.println("enter size of array ");
        n = sc.nextInt();
        System.out.println("enter indexes to be swapped ");
        a = sc.nextInt();
        b = sc.nextInt();
        if (ch == 1) {
            Integer arr[] = new Integer[n];
            for (int i = 0; i < n; i++) {
                System.out.print("enter value ");
                arr[i] = sc.nextInt();
            }
            swap(arr, a, b);
            show(arr);
        } else if (ch == 2) {
            Double arr[] = new Double[n];
            for (int i = 0; i < n; i++) {
                System.out.print("enter value ");
                arr[i] = sc.nextDouble();
            }
            swap(arr, a, b);
            show(arr);
        } else if (ch == 3) {
            Character arr[] = new Character[n];
            for (int i = 0; i < n; i++) {
                System.out.print("enter value ");
                arr[i] = sc.next().charAt(0);
            }
            swap(arr, a, b);
            show(arr);
        } else if (ch == 4) {
            String arr[] = new String[n];
            for (int i = 0; i < n; i++) {
                System.out.print("enter value ");
                arr[i] = sc.next();
            }
            swap(arr, a, b);
            show(arr);
        } else
            System.out.println("wrong choice");
    }
}