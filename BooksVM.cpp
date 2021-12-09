#include <iostream>
using namespace std;

int failure = 0;
int success = 0;
void Trans(int a)                                 //counts the total failed and successful transaction
{
    if (a == 0)
        failure++;
    else
        success++;
}
class book
{
private:
    int bookcode;
    string author;
    string title;
    double price;
    string genre;
    int stock;
    double pay;
    int quantity;

    void priceUpdate()                                           //to update price
    {
        cout << "\nEnter the new price: ";
        cin >> price;
        cout << endl;
    }
    void stockUpdate()                                             //to update stock
    {
        stock = stock - quantity;
        cout << "\nEnter the new stock: ";
        cin >> stock;
        cout << endl;
    }
public:
    book(int u, string x, string y, string z, double w, int v, double p)            //constructor
    {
        bookcode = u;
        title = x;
        author = y;
        genre = z;
        price = w;
        stock = v;
        pay = p;
    }
    book(int u)                                             //constructor
    {
        bookcode = u;

    }
    int search(book x)                                                  //searching the book in the list
    {
        if (bookcode == x.bookcode)
            return 1;
        else
            return 0;
    }

    void vendingmachinexd()                             //checking no. of copies and calculating the total price
    {
        int ordercode, quantity;
        int n;
        string order;
        double money = 0, pay, change;
        cout << "\nBook Details: " << endl;
        showdetail();
        cout << "\n\n" << " Insert your Money     :";
        cin >> pay;

        cout << "\n" << " Please Enter Quantity : ";
        cin >> quantity;

        cout << "\n" << " Input Bookcode again to confirm your order: ";
        cin >> ordercode;



        switch (ordercode) {
        case 101:
            order = "The Adventure of Sherlock Holmes";
            money = quantity * price;
            break;
        case 102:
            order = "Five little Pigs";
            money = quantity * price;
            break;
        case 103:
            order = " Project Loki";
            money = quantity * price;
            break;
        case 104:
            order = " Thinking Fast and Slow";
            money = quantity * price;
            break;
        case 105:
            order = " Bridge to terabithia";
            money = quantity * price;
            break;

        default:
            cout << "Invalid Input, please try again";
            break;
        }
        if (pay < money)
        {
            cout << " \n       Sorry,We can't complete your Purchase at this time'. ";
            cout << "\n        We have returned your " << pay << " dollar";
            Trans(0);
        }
        else if (quantity > stock) {

            cout << "\n          Required copies is not in stock" << endl;
            cout << "\n        We have returned your " << pay << " dollar";
            Trans(0);
        }

        else
        {
            cout << "\n\n Your order     : ";
            cout << quantity << " pcs - " << order << endl;
            cout << " Total amount   : " << money << "dollar\n";
            change = pay - money;
            cout << " Change        : " << change << endl;
            stock = stock - quantity;
            cout << "\nRemaining stock in a machine updated: " << stock << endl;
            Trans(1);
        }

    }
    void showdetail()                                                     //display book details
    {
        cout << "Book code: " << bookcode << "                      Title: " << title << endl;
        cout << "Book Genre:" << genre << "                         Author: " << author << endl;
        cout << "Price: " << price << "                             The stocks available: " << stock << endl;
        cout << endl;
    }
    void update()                                                           //update price and stock
    {
        int x;
        cout << "Select what to update\n1.Price\n2.Stock" << endl;
        cin >> x;
        if (x == 1)
            priceUpdate();
        else
            stockUpdate();
    }
};

book p1(101, "The Adventure of Sherlock Holmes", " Arthur Conan Doyle", "Crime Fiction", 250, 10, 250);
book p2(102, "Five Little Pigs", "Agatha Christie", "Mystery", 250, 14, 250);
book p3(103, "Project Loki", "AkosiIbarra", "Mystery", 250, 14, 250);
book p4(104, "Thinking Fast and Slow", "Daniel Kahneman", "Psychology", 200, 7, 250);
book p5(105, "Bridge to terabithia", "Katherine Paterson", "Children's Novel", 2500, 4, 250);


void Maintainer()                                                    // maintainer options
{
    int a, n;
    while (1) {
        cout << "Enter ur choice: \n1.Available books list\n2.Update\n3.Transactions\n4.Exit" << endl;
        cin >> a;
        cout << endl;
        switch (a)
        {
        case 1: cout << "\n Available Book Details: " << endl;
            p1.showdetail();
            p2.showdetail();
            p3.showdetail();
            p4.showdetail();
            p5.showdetail();
            break;

        case 2: cout << "Book Update" << endl;
            cout << "Enter the book code which has to be updated: ";
            cin >> n;
            if (n == 101)
                p1.update();
            else if (n == 111)
                p2.update();
            else if (n == 121)
                p3.update();
            else if (n == 131)
                p4.update();
            else if (n == 141)
                p5.update();
            else
                cout << "Invalid" << endl;
            break;

        case 3: cout << "Total failed transaction: " << failure << endl;
            cout << "Total successful transaction: " << success << endl;
            cout << endl;
            break;
        case 4:
            return;
        }
    }
}
void customer()                                             //customer options
{
    int x;
    while (1)
    {
        cout << "\nEnter a option \n1.Show Books\n2.Purchase Books\n3.Exit" << endl;
        cin >> x;
        if (x == 1)
        {
            cout << "\nBook Details: " << endl;
            p1.showdetail();

            p2.showdetail();

            p3.showdetail();

            p4.showdetail();

            p5.showdetail();
        }

        else if (x == 2)
        {

            int a;
            char yesno;
            string order, icon;


            do
            {


                cout << "\n\n         	Welcome to our Book Vending Machine ";
                cout << "\n\n                       Book Selection" << endl;
                cout << "       Book Code                           " << endl;
                cout << "          (101)           The Adventure of Sherlock Holmes                     " << endl;
                cout << "          (102)                 Five little Pigs                               " << endl;
                cout << "          (103)                   Project LOKI                                 " << endl;
                cout << "          (104)           Thinking Fast and Slow                               " << endl;
                cout << "          (105)                Bridge to Terabithia                              \n\n";




                cout << "Please Enter The BookCode of Your Order: ";
                cin >> a;

                book p6 = a;
                if (p6.search(p1) == 1)
                    p1.vendingmachinexd();
                else if (p6.search(p2) == 2)
                    p2.vendingmachinexd();
                else if (p6.search(p3) == 1)
                    p3.vendingmachinexd();
                else if (p6.search(p4) == 1)
                    p4.vendingmachinexd();
                else if (p6.search(p5) == 1)
                    p5.vendingmachinexd();
                else
                {
                    cout << "This book is not available" << endl;
                    Trans(0);
                }


                cout << "\n\n" <<  " Do you want to order again? (y/n): ";
                cin >> yesno;
            }

            while (yesno == 'Y' || yesno == 'y');

            cout << "\n\n Thank you for your purchase, Hope you buy again\n\n";
        }
        else
            return;
    }
}
int main()
{
    int a;
    while (1)
    {
        cout << "\nSelect any one\n1.Operation Center\n2.Vending Machine\n3.Exit" << endl;
        cin >> a;
        cout << endl;
        if (a == 1)
            Maintainer();
        else if (a == 2)
            customer();
        else
            return 0;
    }
}