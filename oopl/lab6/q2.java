import java.util.*;

class Building {
    Scanner sc = new Scanner(System.in);

    double sqF;
    int st;

    Building() {
        sqF = 0.0;
        st = 0;
    }

    void getBuilding() {
        System.out.println("Enter square footage");
        sqF = sc.nextDouble();
        System.out.println("Enter no. of stories");
        st = sc.nextInt();
    }

    void showBuilding() {
        System.out.println("Square footage: " + sqF + "\nStories: " + st);
    }

    class House {
        int bed, bath;

        House() {
            bed = bath = 0;
        }

        void getHouse() {
            System.out.println("Enter no. of beds");
            bed = sc.nextInt();
            System.out.println("Enter no. of baths");
            bath = sc.nextInt();
        }

        void showHouse() {
            System.out.println("Square Footage: " + sqF + "\nBeds: " + bed + "\nBaths:" + bath);
        }
    }

    class School {
        int cr;
        String gl;

        School() {
            cr = 0;
            gl = "xxx";
        }

        void getSchool() {
            System.out.println("Enter no. of classrooms");
            cr = sc.nextInt();
            System.out.println("Enter grade level");
            sc.nextLine();
            gl = sc.nextLine();
        }

        void showSchool() {
            System.out.println("No. of Stories: " + st + "\nGrade level: " + gl + "\nNo. of classrooms: " + cr);
        }
    }
}

class q2 {
    public static void main(String[] args) {
        Building b = new Building();
        Building.House h = b.new House();
        Building.School s = b.new School();

        b.getBuilding();
        b.showBuilding();
        h.getHouse();
        h.showHouse();
        s.getSchool();
        s.showSchool();
    }
}