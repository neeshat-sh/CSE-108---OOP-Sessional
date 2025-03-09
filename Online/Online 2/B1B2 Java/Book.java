public class Book {

    private String title = null;
    private String author = null;
    private long ISBN = -1;
    private int totalCopies = -1;
    private int borrowedCopies = -1;

    public Book(String title, String author, long ISBN, int totalCopies, int borrowedCopies) {
        this.title = title;
        this.author = author;
        this.ISBN = ISBN;
        this.totalCopies = totalCopies;
        this.borrowedCopies = borrowedCopies;
    }

    public Book() {
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setISBN(long ISBN) {
        this.ISBN = ISBN;
    }

    public void setTotalCopies(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    public void setBorrowedCopies(int borrowedCopies) {
        this.borrowedCopies = borrowedCopies;
    }

    public String getTitle() {
        return this.title;
    }

    public String getAuthor() {
        return this.title;
    }

    public long getISBN() {
        return this.ISBN;
    }

    public int getTotalCopies() {
        return this.totalCopies;
    }

    public int getBorrowedCopies() {
        return this.borrowedCopies;
    }

    public void display() {
        System.out.println("Book Details: ");
        System.out.println("- Title : " + this.title);
        System.out.println("- Author: " + this.author);
        System.out.println("- ISBN : " + this.ISBN);
        int availableCopies = this.totalCopies - this.borrowedCopies;
        System.out.println("- Available copies: " + availableCopies);
        if (availableCopies == 0)
            System.out.println("Status: All copies are currently borrowed.");
    }
}