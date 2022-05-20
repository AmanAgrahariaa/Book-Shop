#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<cassert>
#include "bookshopclass.h"
using namespace std;

int main()
{
    system("color 0A");
    BookShop B;
    int choice;
    char x='n';

    while (1)
    {

        B.control_panel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:{
                do {

                  B.add_book();
                  cout << "\n\nWant to add another book? (y/n) : ";
                  cin >> x;
                } while (x == 'y');
                break;
                }

        case 2:
                B.show_book();
                break;

        case 3:
                B.check_availability();
                break;
        case 4:
                B.update_book();
                break;

        case 5:
                B.sell_book();
                break;

        case 6:
                exit(0);
                break;

        default:
                cout << "\n\nINVALID CHOICE\n";
        }
        getch();
    }
    return 0;
}
