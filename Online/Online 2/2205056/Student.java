public class Student {
    private String name;
    Course[] courses;
    Double[] marks;

    public Student(String name, Course[] c, Double[] marks) {
        this.name = name;
        courses = c;
        this.marks = marks;
    }

    public String getName() {
        return name;
    }

    public double getGPA() {
        double totalMarks = 0;
        double credits = 0;
        for (int i = 0; i < courses.length; i++) {
            totalMarks += courses[i].getCredit() * getGrade(i);
            credits += courses[i].getCredit();
        }
        return (totalMarks / credits);
    }

    public double getGrade(int i) {
        double Marks = marks[i];
        if (Marks >= 80)
            return 4.00;
        else if (Marks >= 70)
            return 3.75;
        else if (Marks >= 60)
            return 3.5;
        else if (Marks >= 50)
            return 3.0;
        else if (Marks >= 40)
            return 2.5;
        else
            return 0.0;
    }

    public void display() {
        System.out.printf("Grades for %s: ", name);
        for (int i = 0; i < courses.length; i++) {
            System.out.printf("Course: %s, Grade: %f", courses[i].getName(), getGrade(i));
        }
    }
}
