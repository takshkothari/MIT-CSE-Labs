package com.course.structure;

import java.util.*;

public class Building {
    Scanner sc = new Scanner(System.in);

    double sqF;
    int st;

    public Building() {
        sqF = 0.0;
        st = 0;
    }

    public void getBuilding() {
        System.out.println("Enter square footage");
        sqF = sc.nextDouble();
        System.out.println("Enter no. of stories");
        st = sc.nextInt();
    }

    public void showBuilding() {
        System.out.println("Square footage: " + sqF + "\nStories: " + st);
    }

    public class House {
        int bed, bath;

        public House() {
            bed = bath = 0;
        }

        public void getHouse() {
            System.out.println("Enter no. of beds");
            bed = sc.nextInt();
            System.out.println("Enter no. of baths");
            bath = sc.nextInt();
        }

        public void showHouse() {
            System.out.println("Square Footage: " + sqF + "\nBeds: " + bed + "\nBaths:" + bath);
        }
    }

    public class School {
        int cr;
        String gl;

        public School() {
            cr = 0;
            gl = "xxx";
        }

        public void getSchool() {
            System.out.println("Enter no. of classrooms");
            cr = sc.nextInt();
            System.out.println("Enter grade level");
            sc.nextLine();
            gl = sc.nextLine();
        }

        public void showSchool() {
            System.out.println("No. of Stories: " + st + "\nGrade level: " + gl + "\nNo. of classrooms: " + cr);
        }
    }
}