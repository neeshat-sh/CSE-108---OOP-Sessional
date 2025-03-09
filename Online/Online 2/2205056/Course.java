public class Course {
    private String name;
    private double credit;

    public Course(String name, double credit) {
        this.name = name;
        this.credit = credit;
    }
    public Course()
    {
        name = null;
        credit = -1;
    }
    public String getName() {
        return name;
    }
    public Double getCredit() {
        return credit;
    }
}
