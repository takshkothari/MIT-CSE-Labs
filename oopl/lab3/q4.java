import java.util.Scanner;

class Stack {
    int[] arr;
    int tos;

    void initialize(int size) {
        tos = -1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    void push(int x) {
        if (tos == arr.length - 1)
            System.out.println("Stack Overflow");
        else {
            tos++;
            arr[tos] = x;
        }
    }

    int pop() {
        int retele = -1;
        if (tos == -1)
            System.out.println("Stack Underflow");
        else {
            retele = arr[tos];
            tos--;
        }
        return retele;
    }

    void disp() {
        System.out.println("array content :");
        for (int i = 0; i < arr.length; i++)
            System.out.println(arr[i] + "\t");
    }
}

class q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack s = new Stack();
        s.initialize(10);
        int ch, t;
        do {
            System.out.println("enter choice:\n1.push\n2.pop");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("enter element to push");
                    t = sc.nextInt();
                    s.push(t);
                    s.disp();
                    break;

                case 2:
                    t = s.pop();
                    System.out.println("the popped element is: " + t);
                    s.disp();
                    break;
            }
            System.out.println("\n1.continue\n2.exit");
            ch = sc.nextInt();
        } while (ch != 2);
    }
}