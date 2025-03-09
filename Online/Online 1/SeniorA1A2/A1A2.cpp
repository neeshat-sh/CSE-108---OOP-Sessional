#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Book
{
private:
    string title;
    string author;
    bool available;

public:
    Book()
    {
        title = "";
        author = "";
        available = false;
    }
    Book(string title, string author)
    {
        this->title = title;
        this->author = author;
        available = true;
    }
    ~Book()
    {
        
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setAvailability(bool availability)
    {
        available = availability;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    bool getAvailability()
    {
        return available ? 1 : 0;
    }
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: " << (available ? "Available" : "Not Available") << endl;
        cout << endl;
    }
};

class LibraryMember
{
private:
    string memberName;
    int libraryCardNumber;

public:
    LibraryMember()
    {
        memberName = "";
        libraryCardNumber = -1;
    }
    LibraryMember(string memberName, int libraryCardNumber)
    {
        this->memberName = memberName;
        this->libraryCardNumber = libraryCardNumber;
    }
    ~LibraryMember()
    {
    }
    void setMemberName(string memberName)
    {
        this->memberName = memberName;
    }
    void setLibraryCardNumber(int libraryCardNumber)
    {
        this->libraryCardNumber = libraryCardNumber;
    }
    string getMemberName()
    {
        return memberName;
    }
    int getLibraryCardNumber()
    {
        return libraryCardNumber;
    }
    void display()
    {
        cout << "Name: " << memberName << endl;
        cout << "Library Card Number: " << libraryCardNumber << endl;
        cout << endl;
    }
};

class Library
{
private:
    int memberCount;
    LibraryMember LibraryMembers[100];
    int bookCount;
    Book Books[100];

public:
    Library()
    {
        memberCount = 0;
        bookCount = 0;
    }
    ~Library()
    {
    }
    void addBook(string title, string author)
    {
        if (bookCount < 100)
        {
            Books[bookCount].setTitle(title);
            Books[bookCount].setAuthor(author);
            Books[bookCount].setAvailability(true);
            bookCount++;
        }
    }
    void displayAllBooks()
    {
        cout << "Books in the library:" << endl;
        for (int i = 0; i < bookCount; i++)
        {
            Books[i].display();
        }
        cout << endl;
    }
    void registerMember(string memberName, int libraryCardNumber)
    {
        if (memberCount < 100)
        {
            LibraryMembers[memberCount].setMemberName(memberName);
            LibraryMembers[memberCount].setLibraryCardNumber(libraryCardNumber);
            memberCount++;
        }
    }
    void displayAllMembers()
    {
        cout << "Members in the library:" << endl;
        for (int i = 0; i < memberCount; i++)
        {
            LibraryMembers[i].display();
        }
        cout << endl;
    }
    void borrowBook(string title, int libraryCardNumber)
    {
        int borrowed_by = -1;
        for (int i = 0; i < memberCount; i++)
        {
            if (LibraryMembers[i].getLibraryCardNumber() == libraryCardNumber)
            {
                borrowed_by = i;
                break;
            }
        }
        for (int i = 0; i < bookCount; i++)
        {
            if (Books[i].getTitle() == title)
            {
                Books[i].setAvailability(false);
                cout << "Book '" << Books[i].getTitle() << "' has been borrowed by" << endl;
                LibraryMembers[borrowed_by].display();
                cout << endl;
                return;
            }
        }
    }
    void returnBook(string title, int libraryCardNumber)
    {
        int returned_by = -1;
        for (int i = 0; i < memberCount; i++)
        {
            if (LibraryMembers[i].getLibraryCardNumber() == libraryCardNumber)
            {
                returned_by = i;
                break;
            }
        }
        for (int i = 0; i < bookCount; i++)
        {
            if (Books[i].getTitle() == title)
            {
                Books[i].setAvailability(true);
                cout << "Book '" << Books[i].getTitle() << "' has been returned by" << endl;
                LibraryMembers[returned_by].display();
                cout << endl;
                return;
            }
        }
    }
    void removeBook(const char *title)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (Books[i].getTitle() == title)
            {
                cout << "Book '" << Books[i].getTitle() << "' has been removed from the library.\n\n";
                for (int j = i; j < (bookCount - 1); j++)
                {
                    Books[j].setTitle(Books[j + 1].getTitle());
                    Books[j].setAuthor(Books[j + 1].getAuthor());
                    Books[j].setAvailability(Books[j + 1].getAvailability());
                }
                Books[bookCount - 1].setAuthor("");
                Books[bookCount - 1].setTitle("");
                Books[bookCount - 1].setAvailability(false);
                bookCount--;
                return;
            }
        }
    }
    void removeMember(int libraryCardNumber)
    {
        for (int i = 0; i < memberCount; i++)
        {
            if (LibraryMembers[i].getLibraryCardNumber() == libraryCardNumber)
            {
                cout << "Member '" << LibraryMembers[i].getMemberName()
                     << " (" << LibraryMembers[i].getLibraryCardNumber()
                     << ")' has been removed from the library.\n\n";
                for (int j = i; j < (memberCount - 1); j++)
                {
                    LibraryMembers[j].setMemberName(LibraryMembers[j + 1].getMemberName());
                    LibraryMembers[j].setLibraryCardNumber(LibraryMembers[j + 1].getLibraryCardNumber());
                }
                LibraryMembers[memberCount - 1].setMemberName("");
                LibraryMembers[memberCount - 1].setLibraryCardNumber(-1);
                memberCount--;
                return;
            }
        }
    }
};
int main()
{
    Library library;
    // Adding books
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("Pride and Prejudice", "Jane Austen");
    // Displaying all books
    library.displayAllBooks();
    // Registering members
    library.registerMember("John Doe", 1234);
    library.registerMember("Jane Smith", 5678);
    // Displaying all members
    library.displayAllMembers();
    // Borrowing books
    library.borrowBook("The Great Gatsby", 1234);
    library.borrowBook("To Kill a Mockingbird", 5678);
    // Displaying all books (after borrowing)
    library.displayAllBooks();
    // Returning a book
    library.returnBook("The Great Gatsby", 1234);
    // Displaying all books (after returning)
    library.displayAllBooks();
    // Removing a book
    library.removeBook("Pride and Prejudice");
    // Displaying all books (after removal)
    library.displayAllBooks();
    // Removing a member
    library.removeMember(5678);
    // Displaying all members (after removal)
    library.displayAllMembers();
    return 0;
}