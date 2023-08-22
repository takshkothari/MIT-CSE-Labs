class Student {
    String name;
    int id;

    Student() {
        name = "xxx";
        id = 0;
    }

    class Sports {
        int s_grade;

        Sports() {
            s_grade = 0;
        }
    }

    class Exam {
        int e_grade;

        Exam() {
            e_grade = 0;
        }
    }
}

class Result extends Student {
    String res = "";
    Student s = new Student();
    Student.Sports ss = s.new Sports();
    Student.Exam se = s.new Exam();

    Result() {
        res = "Name: " + name + "\n" + "ID: " + id + "\nSports grade: " + ss.s_grade + "\nExam grade: " + se.e_grade;
    }

    void display() {
        System.out.println(res);
    }
}

class q4 {
    public static void main(String args[]) {
        Result obj = new Result();
        obj.display();
    }
}