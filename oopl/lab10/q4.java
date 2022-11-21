import java.util.*;

class q4 {

    public static void disp(List<?> list) {
        for (Object obj : list) {
            System.out.print(obj + " ");
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Menu\n1. integer\n2. string\n3. double\nenter choice");
        int ch = sc.nextInt();

        if (ch == 1) {
            List<Integer> arr = Arrays.asList(6, 9, 4, 2, 0);
            disp(arr);
        } else if (ch == 2) {
            List<String> arr = Arrays.asList("what", "why", "who", "when", "where");
            disp(arr);
        } else if (ch == 3) {
            List<Double> arr = Arrays.asList(1.5, 7.3, 6.9, 3.8);
            disp(arr);
        } else
            System.out.println("invalid input");
    }
}