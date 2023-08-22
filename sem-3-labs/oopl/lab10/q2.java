import java.util.*;

class stack<T> {
    List<T> st;
    int tos, size;

    stack(int n) {
        tos = -1;
        st = new ArrayList<T>(n);
        size = n;
    }

    void push(T x) {
        if (tos == (size - 1)) {
            System.out.println("stack full");
            return;
        }
        st.add(++tos, x);
    }

    T pop() {
        return st.remove(tos--);
    }
}

class student {
    String n;
    int r;

    student(String a, int b) {
        n = a;
        r = b;
    }
}

class employee {
    String n;
    int i;

    employee(String a, int b) {
        n = a;
        i = b;
    }
}

class q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter size of stack");
        int n = sc.nextInt();
        stack<student> std = new stack<>(n);
        stack<employee> emp = new stack<>(n);
        System.out.println("1. push std\n2. pop std\n3. push emp\n4. pop emp\n5. exit");
        int ch;
        student s;
        employee e;
        do {
            System.out.println("enter choice");
            ch = sc.nextInt();
            if (ch == 1) {
                System.out.println("enter name ");
                String t = sc.next();
                System.out.println("enter roll number ");
                s = new student(t, sc.nextInt());
                std.push(s);
            } else if (ch == 2) {
                s = std.pop();
                System.out.println("\npopped contents: \nname: " + s.n + "\troll no: " + s.r + "\n");
            } else if (ch == 3) {
                System.out.println("enter name ");
                String t = sc.next();
                System.out.println("enter employee id ");
                e = new employee(t, sc.nextInt());
                emp.push(e);
            } else if (ch == 4) {
                e = emp.pop();
                System.out.println("\npopped contents:\nname: " + e.n + "\tid: " + e.i + "\n");
            }
        } while (ch != 5);
    }
}