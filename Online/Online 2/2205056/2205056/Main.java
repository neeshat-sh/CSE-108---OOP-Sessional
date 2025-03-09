import java.util.*;

public class Main {
    public static void main(String[] args) {
        if(args.length == 0)
        {
            return;
        }
        int howManyStudents = Integer.parseInt(args[0]);
        int howManyCourses = Integer.parseInt(args[1]);

        Scanner scanner = new Scanner(System.in);

        Course[] courses = new Course[howManyCourses];
        for(int i = 0; i < howManyCourses; i++)
        {
            courses[i] = new Course();
            String name = scanner.nextLine();
            double credit = scanner.nextDouble();
            scanner.nextLine();

            Course c = new Course(name, credit);
            courses[i] = c;
        }

        Student[] students = new Student[howManyStudents];
        for(int i = 0; i < howManyStudents; i++)
        {
            String name = scanner.nextLine();
            Double[] marks = new Double[howManyCourses];
            for(int j = 0; j < howManyCourses; j++)
            {
                marks[j] = scanner.nextDouble();
                while(marks[j] < 0 || marks[j] > 100)
                {
                    System.out.printf("Input Again: ");
                    marks[j] = scanner.nextDouble();
                }
            }
            scanner.nextLine();
            students[i] = new Student(name, courses, marks);
        }
        Boolean runningCommands = true;
        while(runningCommands)
        {
            String Line = scanner.nextLine();
            String[] Command = Line.split(" ", 2);
            switch(Command[0]) 
            {
                case "display":
                {
                    for(int i = 0; i < howManyStudents; i++)
                    {
                        if(students[i].getName().equals(Command[1]))
                        {
                            students[i].display();
                            break;
                        }
                    }
                }
                case "delete":
                {
                    // int toDelete = -1;
                    // for(int i = 0; i < howManyStudents; i++)
                    // {
                    //     if(students[i].getName().equals(Command[1]))
                    //     {
                    //         toDelete = i;
                    //         break;
                    //     }
                    // }
                    // Student[] studentsAfterDelete = new Student[students.length - 1];
                    // for(int i = 0; i < howManyStudents; i++)
                    // {
                    //     if(toDelete == i)
                    //     {
                    //         break;
                    //     }
                    // }
                }
                case "exit":
                {
                    runningCommands = false;
                }
            }
        }
        scanner.close();
    }
}