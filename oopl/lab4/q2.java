class Time {
    int hours;
    int mins;
    int secs;

    Time() {
        hours = 0;
        mins = 0;
        secs = 0;
    }

    Time(int h, int m, int s) {
        hours = h;
        mins = m;
        secs = s;
    }

    void disp() {
        System.out.println("the time is " + hours + ":" + mins + ":" + secs);
    }

    Time add(Time t1, Time t2) {

        Time sum = new Time();

        sum.hours = t1.hours + t2.hours;
        sum.mins = t1.mins + t2.mins;
        sum.secs = t1.secs + t2.secs;

        if (sum.secs > 59) {
            sum.mins++;
            sum.secs = sum.secs % 60;
        }
        if (sum.mins > 59) {
            sum.hours++;
            sum.mins = sum.mins % 60;
        }
        if (sum.hours > 23)
            sum.hours = sum.hours % 24;

        return sum;
    }

    Time sub(Time t1, Time t2) {
        Time diff = new Time();

        diff.hours = t1.hours - t2.hours;
        diff.mins = t1.mins - t2.mins;
        diff.secs = t1.secs - t2.secs;

        if (diff.secs < 0) {
            diff.mins--;
            diff.secs += 60;
        }
        if (diff.mins < 0) {
            diff.hours--;
            diff.mins += 60;
        }
        if (diff.hours < 0)
            diff.hours += 24;

        return diff;
    }

    int cmp(Time t1, Time t2) {
        if (t1.hours > t2.hours)
            return 1;
        else if (t1.hours < t2.hours)
            return -1;
        else {

            if (t1.mins > t2.mins)
                return 1;
            else if (t1.mins < t2.mins)
                return -1;
            else {

                if (t1.secs > t2.secs)
                    return 1;
                else if (t1.secs < t2.secs)
                    return -1;
                else
                    return 0;
            }
        }
    }
}

class q2 {
    public static void main(String[] args) {
        Time t1 = new Time(3, 16, 19);
        Time t2 = new Time();
        Time s = new Time();
        Time d = new Time();

        t1.disp();
        t2.disp();

        s = s.add(t1, t2);
        System.out.print("time after addition :");
        s.disp();

        d = d.sub(t1, t2);
        System.out.print("time after subtraction :");
        d.disp();

        int x = s.cmp(t1, t2);
        if (x == 1)
            System.out.println("first time is greater");
        else if (x == -1)
            System.out.println("second time is greater");
        else
            System.out.println("both times are the same");

    }
}