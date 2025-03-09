public class Library {

    private int bookCount = 0;
    private Book[] books = new Book[20];

    public Library() {
    }

    public void addBook(Book b) {
        books[bookCount++] = b;
    }

    // add your code here

    public Boolean invalidISBN(Book b) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == b.getISBN())
                return true;
        }
        return false;
    }

    public void searchBook(String title) {
        System.out.println("Search for a book by title: " + title);
        for (int i = 0; i < this.bookCount; i++) {
            if (books[i].getTitle().equals(title))
                books[i].display();
        }
    }
}