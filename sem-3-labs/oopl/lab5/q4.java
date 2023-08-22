import java.util.*;

class q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s, num = "";
        System.out.println("Enter a number");
        s = sc.next();
        int l = s.length(), c = 0;
        for (int i = l - 1; i >= 0; i--) {
            num = s.charAt(i) + num;
            c++;
            if (c == 3 && i != 0) {
                num = "," + num;
                c = 0;
            }
        }
        System.out.println("Reformatted number is " + num);
    }
}
