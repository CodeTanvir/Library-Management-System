#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Book class to store book details
class Book
{
public:
  string title;
  string author;
  string ISBN;
  int quantity;

  Book()
  {
    quantity = 0;
  }
};

// Library class to manage the library system
class Library
{
private:
  vector<Book> books;

public:
  void addBook(const Book &book)
  {
    books.push_back(book);
  }

  void updateBook(const string &ISBN, const Book &book)
  {
    for (auto &b : books)
    {
      if (b.ISBN == ISBN)
      {
        b = book;
        break;
      }
    }
  }

  void removeBook(const string &ISBN)
  {
    for (auto it = books.begin(); it != books.end(); ++it)
    {
      if (it->ISBN == ISBN)
      {
        books.erase(it);
        break;
      }
    }
  }

  Book *searchBook(const string &title)
  {
    for (auto &book : books)
    {
      if (book.title == title)
      {
        return &book;
      }
    }
    return nullptr;
  }

  void displayBooks()
  {
    for (const auto &book : books)
    {
      cout << "Title: " << book.title << endl;
      cout << "Author: " << book.author << endl;
      cout << "ISBN: " << book.ISBN << endl;
      cout << "Quantity: " << book.quantity << endl;
      cout << "-------------------------------------" << endl;
    }
  }

  // Other member management, borrowing, returning, and reporting functions can be added here
};

// Main function to demonstrate the usage of the Library Management System
int main()
{
  Library library;

  // Load books from a file or database (optional)

  // Menu-driven user interface for the library system
  int choice;
  do
  {
    cout << "===== Library Management System =====" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Update Book" << endl;
    cout << "3. Remove Book" << endl;
    cout << "4. Search Book" << endl;
    cout << "5. Display Books" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      Book book;
      cout << "Enter book title: ";
      cin.ignore();
      getline(cin, book.title);
      cout << "Enter author: ";
      getline(cin, book.author);
      cout << "Enter ISBN: ";
      cin >> book.ISBN;
      cout << "Enter quantity: ";
      cin >> book.quantity;
      library.addBook(book);
      break;
    }
    case 2:
    {
      string ISBN;
      Book book;
      cout << "Enter book ISBN to update: ";
      cin >> ISBN;
      cout << "Enter updated book details:" << endl;
      cout << "Enter book title: ";
      cin.ignore();
      getline(cin, book.title);
      cout << "Enter author: ";
      getline(cin, book.author);
      cout << "Enter quantity: ";
      cin >> book.quantity;
      library.updateBook(ISBN, book);
      break;
    }
    case 3:
    {
      string ISBN;
      cout << "Enter book ISBN to remove: ";
      cin >> ISBN;
      library.removeBook(ISBN);
      break;
    }
    case 4:
    {
      string title;
      cout << "Enter book title to search: ";
      cin.ignore();
      getline(cin, title);
      Book *foundBook = library.searchBook(title);
      if (foundBook)
      {
        cout << "Book found!" << endl;
        cout << "Title: " << foundBook->title << endl;
        cout << "Author: " << foundBook->author << endl;
        cout << "ISBN: " << foundBook->ISBN << endl;
        cout << "Quantity: " << foundBook->quantity << endl;
      }
      else
      {
        cout << "Book not found." << endl;
      }
      break;
    }
    case 5:
    {
      library.displayBooks();
      break;
    }
    case 0:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  // Save books to a file or database (optional)

  return 0;
}
