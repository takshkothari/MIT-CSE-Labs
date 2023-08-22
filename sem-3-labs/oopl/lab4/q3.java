class Bank {
    String name;
    int acc_no;
    String type;
    static double bal, rate;

    Bank() {
        name = null;
        acc_no = 0;
        type = null;
        bal = 0.0;
        rate = 0.0;
    }

    Bank(String a, int b, String c, double d, double e) {
        name = a;
        acc_no = b;
        type = c;
        bal = d;
        rate = e;
    }

    void deposit(double a) {
        bal += a;
        System.out.println("Account balance is " + bal);
    }

    void withdraw(double a) {
        if (a > bal)
            System.out.println("Insufficient account balance");
        else {
            bal -= a;
            System.out.println("Account balance is " + bal);
        }
    }

    void display() {
        System.out.println("Name :" + name);
        System.out.println("Account No. :" + acc_no);
        System.out.println("Account Type :" + type);
        System.out.println("Balance :" + bal);
    }

    static void dispRate() {
        System.out.println("The rate of interest is " + rate);
    }
}

class q3 {
    public static void main(String[] args) {
        Bank b = new Bank("Taksh", 1234, "Savings", 69420.00, 8.00);
        b.display();
        b.deposit(42895);
        b.withdraw(2390);
        Bank.dispRate();
    }
}
