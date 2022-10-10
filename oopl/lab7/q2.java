import myPackages.p1.Maximum;
import java.util.*;

public class q2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Maximum ob = new Maximum();

        System.out.println("Menu\n1.Int\n2.Float\n3.Array\n4.Matrix");
        int ch = sc.nextInt();

        switch (ch) {
            case 1:
                System.out.println("Enter three integers");
                int a = sc.nextInt();
                int b = sc.nextInt();
                int c = sc.nextInt();
                int w = ob.max(a, b, c);
                System.out.println("Max is: " + w);
                break;

            case 2:
                System.out.println("Enter three floats");
                float d = sc.nextFloat();
                float e = sc.nextFloat();
                float f = sc.nextFloat();
                float x = ob.max(d, e, f);
                System.out.println("Max is: " + x);
                break;

            case 3:
                System.out.println("Enter n");
                int n = sc.nextInt();
                int arr[] = new int[n];
                System.out.println("Enter elements");
                for (int i = 0; i < n; i++)
                    arr[i] = sc.nextInt();
                int y = ob.max(arr);
                System.out.println("Max is: " + y);
                break;

            case 4:
                System.out.println("Enter rows ");
                int l = sc.nextInt();
                System.out.println("Enter columns ");
                int m = sc.nextInt();
                int mat[][] = new int[l][m];
                System.out.println("Enter elements");
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < m; j++)
                        mat[i][j] = sc.nextInt();
                }
                int z = ob.max(mat);
                System.out.println("Max is: " + z);
                break;

            default:
                System.out.println("wrong input");
        }
    }
}