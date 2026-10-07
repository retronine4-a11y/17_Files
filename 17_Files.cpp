
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
    string name;
    string author;
    string publisher;
    string genre;
    int year;
    double price;
    int id;
};

void SaveAllToFile(Book* books, int size)
{
    ofstream out("C:\\Users\\ACER\\source\\repos\\books.txt");

    for (int i = 0; i < size; i++)
    {
        out << books[i].name << ':';
        out << books[i].author << ':';
        out << books[i].publisher << ':';
        out << books[i].genre << ':';
        out << books[i].year << ':';
        out << books[i].price << ':';
        out << books[i].id << '|';
    }

    out.close();
}

void ReadFromFile(Book*& books, int& size)
{
    ifstream in("C:\\Users\\ACER\\source\\repos\\books.txt");

    if (!in.is_open())
    {
        size = 0;
        books = nullptr;
        return;
    }

    delete[] books;
    books = nullptr;
    size = 0;

    string name;
    string author;
    string publisher;
    string genre;
    string year;
    string price;
    string id;

    while (getline(in, name, ':'))
    {
        if (!getline(in, author, ':')) break;
        if (!getline(in, publisher, ':')) break;
        if (!getline(in, genre, ':')) break;
        if (!getline(in, year, ':')) break;
        if (!getline(in, price, ':')) break;
        if (!getline(in, id, '|')) break;

        Book book;

        book.name = name;
        book.author = author;
        book.publisher = publisher;
        book.genre = genre;
        book.year = stoi(year);
        book.price = stod(price);
        book.id = stoi(id);

        Book* temp = new Book[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = books[i];
        }

        temp[size] = book;

        delete[] books;

        books = temp;
        size++;
    }

    in.close();
}

void Fill(Book* books, Book data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        books[i] = data[i];
    }
}

void Show(Book* books, int size)
{
    system("cls");

    for (int i = 0; i < size; i++)
    {
        cout << "\nBook " << i + 1 << endl;
        cout << "ID: " << books[i].id << endl;
        cout << "Name: " << books[i].name << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
        cout << "Year: " << books[i].year << endl;
        cout << "Price: " << books[i].price << endl;
    }

    cout << "\nPress any key to continue...";
    _getch();
}

void ChangeData(Book* books, int size)
{
    int id;

    cout << "Enter book ID: ";
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            cout << "New name: ";
            cin >> ws;
            getline(cin, books[i].name);

            cout << "New author: ";
            getline(cin, books[i].author);

            cout << "New publisher: ";
            getline(cin, books[i].publisher);

            cout << "New genre: ";
            getline(cin, books[i].genre);

            cout << "New year: ";
            cin >> books[i].year;

            cout << "New price: ";
            cin >> books[i].price;

            SaveAllToFile(books, size);

            cout << "Book updated!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void SearchAuthor(Book* books, int size)
{
    string author;

    cout << "Enter author: ";
    cin >> ws;
    getline(cin, author);

    system("cls");

    for (int i = 0; i < size; i++)
    {
        if (books[i].author == author)
        {
            cout << books[i].name << " | "
                << books[i].author << " | "
                << books[i].price << endl;
        }
    }

    cout << "\nPress any key to continue...";
    _getch();
}

void SearchTitle(Book* books, int size)
{
    string title;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin, title);

    system("cls");

    for (int i = 0; i < size; i++)
    {
        if (books[i].name == title)
        {
            cout << "ID: " << books[i].id << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Price: " << books[i].price << endl;
        }
    }

    cout << "\nPress any key to continue...";
    _getch();
}

void SearchPublisher(Book* books, int size)
{
    string publisher;

    cout << "Enter publisher: ";
    cin >> ws;
    getline(cin, publisher);

    system("cls");

    for (int i = 0; i < size; i++)
    {
        if (books[i].publisher == publisher)
        {
            cout << books[i].name << " | "
                << books[i].author << endl;
        }
    }

    cout << "\nPress any key to continue...";
    _getch();
}

void SearchGenre(Book* books, int size)
{
    string genre;

    cout << "Enter genre: ";
    cin >> ws;
    getline(cin, genre);

    system("cls");

    for (int i = 0; i < size; i++)
    {
        if (books[i].genre == genre)
        {
            cout << books[i].name << " | "
                << books[i].author << endl;
        }
    }

    cout << "\nPress any key to continue...";
    _getch();
}

void ChangePrice(Book* books, int size)
{
    int id;
    double price;

    cout << "Enter book ID: ";
    cin >> id;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            cout << "Enter new price: ";
            cin >> price;

            books[i].price = price;

            SaveAllToFile(books, size);

            cout << "Price updated!" << endl;
            return;
        }
    }

    cout << "Book not found!" << endl;
}

void AddBook(Book*& books, int& size)
{
    Book* newBooks = new Book[size + 1];

    for (int i = 0; i < size; i++)
    {
        newBooks[i] = books[i];
    }

    cout << "Enter ID: ";
    cin >> newBooks[size].id;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin, newBooks[size].name);

    cout << "Enter author: ";
    getline(cin, newBooks[size].author);

    cout << "Enter publisher: ";
    getline(cin, newBooks[size].publisher);

    cout << "Enter genre: ";
    getline(cin, newBooks[size].genre);

    cout << "Enter year: ";
    cin >> newBooks[size].year;

    cout << "Enter price: ";
    cin >> newBooks[size].price;

    delete[] books;

    books = newBooks;
    size++;

    SaveAllToFile(books, size);

    cout << "Book added!" << endl;
}

void DeleteBook(Book*& books, int& size)
{
    int id;

    cout << "Enter ID of the book to delete: ";
    cin >> id;

    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Book not found!" << endl;
        return;
    }

    Book* newBooks = nullptr;

    if (size > 1)
    {
        newBooks = new Book[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
            {
                newBooks[j] = books[i];
                j++;
            }
        }
    }

    delete[] books;

    books = newBooks;
    size--;

    SaveAllToFile(books, size);

    cout << "Book deleted!" << endl;
}

int main()
{
    Book data[10] =
    {
        {"Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy", 1997, 350, 1},
        {"The Hobbit", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy", 1937, 400, 2},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopia", 1949, 300, 3},
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel", 1925, 280, 4},
        {"It", "Stephen King", "Viking Press", "Horror", 1986, 500, 5},
        {"The Alchemist", "Paulo Coelho", "HarperCollins", "Novel", 1988, 320, 6},
        {"Dracula", "Bram Stoker", "Archibald Constable", "Horror", 1897, 270, 7},
        {"Dune", "Frank Herbert", "Chilton Books", "Science Fiction", 1965, 450, 8},
        {"Hamlet", "William Shakespeare", "Penguin", "Drama", 1603, 250, 9},
        {"The Shining", "Stephen King", "Doubleday", "Horror", 1977, 420, 10}
    };

    Book* books = nullptr;
    int size = 0;

    ReadFromFile(books, size);

    if (size == 0)
    {
        size = 10;
        books = new Book[size];

        Fill(books, data, size);

        SaveAllToFile(books, size);
    }

    int choice;

    do
    {
        system("cls");

        cout << "\n===== LIBRARY =====" << endl;
        cout << "1. Show all books" << endl;
        cout << "2. Edit book" << endl;
        cout << "3. Search by author" << endl;
        cout << "4. Search by name" << endl;
        cout << "5. Search by publisher" << endl;
        cout << "6. Search by genre" << endl;
        cout << "7. Change price" << endl;
        cout << "8. Add book" << endl;
        cout << "9. Delete book" << endl;
        cout << "0. Exit" << endl;

        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Show(books, size);
            break;

        case 2:
            ChangeData(books, size);
            break;

        case 3:
            SearchAuthor(books, size);
            break;

        case 4:
            SearchTitle(books, size);
            break;

        case 5:
            SearchPublisher(books, size);
            break;

        case 6:
            SearchGenre(books, size);
            break;

        case 7:
            ChangePrice(books, size);
            break;

        case 8:
            AddBook(books, size);
            break;

        case 9:
            DeleteBook(books, size);
            break;

        case 0:
            cout << "Exit..." << endl;
            break;

        default:
            cout << "Error choice!" << endl;
        }

    } while (choice != 0);

    delete[] books;
}
