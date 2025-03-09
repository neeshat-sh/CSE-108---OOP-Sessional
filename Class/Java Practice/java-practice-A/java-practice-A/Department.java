public class Department {

    private int id;
    private String name;
    private Employee[] employees;
    private int employeeCount;
    // add your code here
    // there can be at most 20 departments
    private static int departmentCount = 0;
    private static Department[] departments = new Department[20];

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];
        // add your code here
        departments[departmentCount] = this;
        departmentCount += 1;
    }

    public void addEmployee(Employee e) {
        employees[employeeCount++] = e;
    }

    // add your code here

    public double getDepartmentSalary() {
        double departmentSalary = 0;
        for (int i = 0; i < this.employeeCount; i++) {
            departmentSalary += this.employees[i].getSalary();
        }
        return departmentSalary;
    }

    public Employee getMaxSalaryEmployee() {
        double maxSalary = Integer.MIN_VALUE;
        int index = -1;
        for (int i = 0; i < this.employeeCount; i++) {
            double salary = this.employees[i].getSalary();
            if (salary > maxSalary) {
                maxSalary = this.employees[i].getSalary();
                index = i;
            }
        }
        return this.employees[index];
    }

    public static double getTotalSalary() {
        double totalSalary = 0;
        for (int i = 0; i < departmentCount; i++) {
            totalSalary += departments[i].getDepartmentSalary();
        }
        return totalSalary;
    }
}