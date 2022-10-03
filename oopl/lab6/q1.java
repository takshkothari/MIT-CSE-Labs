class Person {
    private String name, dob;

    Person() {
        name = "default";
        dob = "xx/xx/xxxx";
    }

    Person(String a, String b) {
        name = a;
        dob = b;
    }

    void getPerson() {
        System.out.println("Name: " + name + "\nDOB: " + dob);
    }

    class CollegeGraduate {
        private double cgpa;
        private int yog;

        CollegeGraduate() {
            cgpa = 0.0;
            yog = 0;
        }

        CollegeGraduate(double a, int b) {
            cgpa = a;
            yog = b;
        }

        void getCollegeGrad() {
            System.out.println(name + " is a college graduate\nCGPA: " + cgpa + "\nYear of Graduation: " + yog);
        }
    }
}

class q1 {
    public static void main(String[] args) {
        Person p = new Person();
        p.getPerson();
        Person.CollegeGraduate cg = p.new CollegeGraduate();
        cg.getCollegeGrad();
    }
}