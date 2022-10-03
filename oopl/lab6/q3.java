import java.util.Scanner;

abstract class figure {
    int a, b;

    abstract int area();
}

class Rectangle extends figure {
    Rectangle(int x, int y) {
        a = x;
        b = y;
    }

    int area() {
        return (a * b);
    }
}

class Square extends figure {
    Square(int x) {
        a = x;
    }

    int area() {
        return (a * a);
    }
}

class Triangle extends figure {
    Triangle(int x, int y) {
        a = x;
        b = y;
    }

    int area() {
        return ((int) a * b / 2);
    }
}

public class q3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int area = 0, a, b;

        System.out.println("Enter dimensions of rectangle ");
        a = sc.nextInt();
        b = sc.nextInt();
        Rectangle r = new Rectangle(a, b);
        area = r.area();
        System.out.println("The area is: " + area);

        System.out.println("Enter side of square ");
        a = sc.nextInt();
        Square sq = new Square(a);
        area = sq.area();
        System.out.println("The area is: " + area);

        System.out.println("Enter width and height of triangle ");
        a = sc.nextInt();
        b = sc.nextInt();
        Triangle t = new Triangle(a, b);
        area = t.area();
        System.out.println("The area is: " + area);
    }
}