
package myPackages.p1;

public class Maximum {
    public int max(int a, int b, int c) {
        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    }

    public float max(float a, float b, float c) {
        return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    }

    public int max(int a[]) {
        int x = a[0];
        for (int i = 0; i < a.length; i++) {
            if (a[i] > x)
                x = a[i];
        }
        return x;
    }

    public int max(int a[][]) {
        int x = a[0][0];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] > x)
                    x = a[i][j];
            }
        }
        return x;
    }
}