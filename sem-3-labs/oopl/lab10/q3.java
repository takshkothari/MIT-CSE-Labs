import java.util.*;

class node<T> {
    T data;
    node<T> next;

    node(T inp) {
        data = inp;
        next = null;
    }
}

class list<T> {
    node<T> head;

    list() {
        head = null;
    }

    void insertNode(T inp) {
        node<T> node1 = new node<T>(inp);

        if (head == null)
            head = node1;
        else {
            node<T> list = head;
            while (list.next != null)
                list = list.next;
            list.next = node1;
        }
    }

    void disp() {
        node<T> node1 = head;
        while (node1 != null) {
            System.out.print(node1.data + " ");
            node1 = node1.next;
        }
    }
}

public class q3 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Menu\n1. integer\n2. string\nenter choice");
        int ch = sc.nextInt();
        System.out.println("enter size");
        int n = sc.nextInt();
        if (ch == 1) {
            list<Integer> list1 = new list<>();
            for (int i = 0; i < n; i++) {
                System.out.println("enter data ");
                list1.insertNode(sc.nextInt());
            }
            System.out.println("list: ");
            list1.disp();
        } else if (ch == 2) {
            list<String> list1 = new list<>();
            for (int i = 0; i < n; i++) {
                System.out.println("enter data ");
                list1.insertNode(sc.next());
            }
            System.out.println("list: ");
            list1.disp();
        } else
            System.out.println("invalid input");
    }
}