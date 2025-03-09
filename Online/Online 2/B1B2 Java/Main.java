import java.util.*;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide the number of books as a command line argument.");
            return;
        }
        int numberOfBooks = Integer.parseInt(args[0]);
        System.out.println("Number of books provided from command line: " + numberOfBooks);
        Library library = new Library();
        Scanner myObj = new Scanner(System.in);
        int i = 0;
        while (i < numberOfBooks) {
            Book book = new Book();

            System.out.printf("Enter details for book %d:\n", i + 1);

            System.out.print("Title: ");
            book.setTitle(myObj.nextLine());

            System.out.print("Author: ");
            book.setAuthor(myObj.nextLine());

            System.out.print("ISBN: ");
            book.setISBN(myObj.nextLong());
            myObj.nextLine();

            System.out.print("Total copies: ");
            book.setTotalCopies(myObj.nextInt());
            myObj.nextLine();

            System.out.print("Borrowed copies: ");
            book.setBorrowedCopies(myObj.nextInt());
            myObj.nextLine();

            if (library.invalidISBN(book))
                System.out.println("Error: Must have unique ISBN. Please input again: ");
            else {
                library.addBook(book);
                i++;
            }
        }
        myObj.close();
        library.searchBook("1984");
        library.searchBook("To Kill a Mockingbird");
    }
}