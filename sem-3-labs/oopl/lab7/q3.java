import java.util.*;

interface Series {
    int getNext();

    void reset();

    void setStart(int a);
}

class ByTwos implements Series {
    int a;

    public int getNext() {
        a += 2;
        return (a);
    }

    public void setStart(int x) {
        a = x;
    }

    public void reset() {
        a = 0;
    }
}

public class q3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("start is set to 0");
        ByTwos obj = new ByTwos();
        obj.setStart(0);
        int x;
        System.out.println("1.get next\n2.reset\n3.set start\n4.exit");
        do {
            System.out.println("enter choice");
            x = sc.nextInt();
            switch (x) {
                case 1:
                    System.out.println(obj.getNext());
                    break;
                case 2:
                    obj.reset();
                    System.out.println("series was reset");
                    break;
                case 3:
                    System.out.println("enter start ");
                    obj.setStart(sc.nextInt());
                    break;
                case 4:
                    System.out.println("bye");
                    break;
                default:
                    System.out.println("wrong choice");
            }
        } while (x != 4);
    }
}