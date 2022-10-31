import java.util.*;

class Stack {
    int arr[];
    int top;
    Scanner sc = new Scanner(System.in);

    void define() {
        top = -1;
        System.out.println("enter length");
        int n = sc.nextInt();
        arr = new int[n];
    }

    void push() {
        try {
            System.out.println("enter integer");
            arr[++top] = sc.nextInt();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("stack overflow");
            top -= 1;
        }
    }

    int pop() {
        try {
            return arr[(top--)];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("stack underflow");
            top += 1;
            return 0;
        }
    }
}

class q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        s.define();
        int ch = 1;
        System.out.println("1.push\n2.pop\n3.exit");
        do {
            System.out.println("enter choice");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    s.push();
                    break;
                case 2:
                    System.out.println("popped element is " + s.pop());
                    break;
                case 3:
                    System.out.println("bye");
                    break;
            }
        } while (ch != 3);
    }
}