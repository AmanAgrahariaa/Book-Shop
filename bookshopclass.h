#include<bits/stdc++.h>
#include<fstream>
#include<cassert>
using namespace std;


//function for printing = symbol
void design(short size,char symbol)
{
	for(short i=0;i<size;i++)
	   cout << symbol;
}


//class for bookshop
class BookShop
{
    int BookID,NoOfCopy;
    string BookName,AuthorName;
    float price_per_book;
    public:
    void control_panel();
    void add_book();
    void show_book();
    void check_availability();
    void update_book();
    void sell_book();

};



//funtion for displaying MENU of book shop
void BookShop::control_panel()
{
        system("CLS");

        design(120,'=');
        cout << "\n\n\t\t\t ######################## CONTROL PANEL ######################## \n";
        design(120,'_');
        cout << endl << endl;

		cout << "\n\t Enter 1 for add book ";
		cout << "\n\t Enter 2 for show book ";
		cout << "\n\t Enter 3 for check Availability ";
		cout << "\n\t Enter 4 for update book ";
		cout << "\n\t Enter 5 to Sell book ";
		cout << "\n\t Enter 6 to exit";
        cout << endl;

        design(120,'=');
		return ;
}



//function for adding new book in records
void BookShop::add_book()
{
    system("CLS");

    design(120,'=');
    cout << endl << endl;
    cout << "\t\t\t ######################## Add Only New Books in Shop ########################\n";
    design(120,'_');
    cout << "\n\n";

    cout << "\n\t Enter Book ID : ";
    cin >> BookID;
    cout << "\n\t Enter Book Name : ";
    getline(cin>>ws,BookName);
    cout << "\n\t Enter Author Name : ";
    getline(cin>>ws,AuthorName);
    cout << "\n\t Enter No Of It's Copies : ";
    cin >> NoOfCopy;
    cout << "\n\t Enter Price per Book : ";
    cin >> price_per_book;
    ofstream fout("BookData.txt",ios::out | ios::app);
    if(fout.is_open())
    {
        fout << BookID<<"\n" << BookName << "\n" << AuthorName << "\n" << NoOfCopy << "\n" << price_per_book << "\n\n";
        cout << "\n\t _  Books are added in shop _\n";
    }
    else{
        cout << "\n\t _  Error in opening file __ \n";
    }
    fout.close();
    cout<<"\n";
    design(120,'=');
    return ;
}



//function for displaying record of books
void BookShop::show_book()
{
     system("CLS");

     design(120,'=');
     cout << "\n\n";
     cout << "\t\t\t ######################## Show All Books of Shop ########################\n";
     design(120,'_');
     cout << endl << endl;

    ifstream fin("BookData.txt",ios::in);
    if(fin.is_open()){
            cout << "\n\n"<<setw(15) << "Book ID" << setw(25) << "Book Name"<<setw(25) << "Author Name"<<setw(15) << "NoOfCopies" << setw(20) << "price per book" << "\n\n";
            fin >> BookID;
            getline(fin>>ws,BookName);
            getline(fin>>ws,AuthorName);
            fin>>NoOfCopy;
            fin>>price_per_book;
    while(!fin.eof())
    {
         cout<<setw(15)<<BookID<<setw(25)<<BookName<<setw(25)<<AuthorName<<setw(15)<<NoOfCopy<<setw(15)<<price_per_book<<"\n";
         fin>>BookID;
         getline(fin>>ws,BookName);
         getline(fin>>ws,AuthorName);
         fin >> NoOfCopy;
         fin >> price_per_book;
    }
    cout << "\n";
    design(120,'=');
    system("pause");
    }
    else{
        cout << "\n\t _ Error in File Opening _\n";
    }
    fin.close();
    return ;

}



//function for checking book present or not
void BookShop::check_availability()
{
     system("CLS");

     design(120,'=');
     cout << "\n\n \t\t\t ######################## Check Book ######################## \n";
     design(120,'_');
     cout << "\n\n";
     int flag=0;
     int Bid;

    cout << "\n Enter Book Id to search ";
    cin >> Bid;
    ifstream fin("BookData.txt",ios::in);
    if(fin.is_open()){
    fin >> BookID;
    getline(fin>>ws,BookName);
    getline(fin>>ws,AuthorName);
    fin >> NoOfCopy;
    fin >> price_per_book;
    while(!fin.eof())
    {

        if(Bid==BookID)
        {
            cout << "\n\n"<<setw(15) << "Book ID"<<setw(25) << "Book Name"<<setw(25) << "Author Name"<<setw(15) << "NoOfCopies"<< setw(25) << "price per book " << "\n\n";
            cout << setw(15) << BookID << setw(25) << BookName << setw(25) << AuthorName << setw(15) << NoOfCopy << setw(15) << price_per_book << "\n";
            flag=1;
            break;
        }
        fin >> BookID;
            getline(fin>>ws,BookName);
            getline(fin>>ws,AuthorName);
            fin >> NoOfCopy;
            fin >> price_per_book;
    }
    if(flag==0)
        { cout << "\n\t _ Book Is Not Available __\n";}
    }
    else{
        cout << "\n\t _ Error in File Opening ___\n";
    }
    cout << endl;
    design(120,'=');
    fin.close();
    return ;
}



//function for deleting copy of book
void BookShop::sell_book()
{
    int ct=0;
    int Bid;
    int no;
    system("CLS");
    design(120,'=');
    cout << "\n";
    cout << "\n \t\t\t ######################## Delete Book ######################## \n";

    design(120,'_');
    cout << endl;
    cout << "\n Enter Book Id that has to be purchased ";
    cin >> Bid;
    cout << "\n Enter no of copies you wanna purchase ";
    cin >> no;
    ifstream fin("BookData.txt",ios::in);
    ofstream fout("BookData1.txt",ios::app);

    if(fin.is_open())
    {

         fin >> BookID;
            getline(fin>>ws,BookName);
            getline(fin>>ws,AuthorName);
            fin >> NoOfCopy;
            fin >> price_per_book;
        while(!fin.eof()){

            if(BookID==Bid)
            {
                ct=1;
                if(no<NoOfCopy)
                {

                   fout << BookID<<"\n" << BookName << "\n" << AuthorName << "\n" << (NoOfCopy-no ) << "\n"<<price_per_book<<"\n\n";
                   cout<<"\n\t __ Books Are Purchased Successfully __ \n";
                }
                else if(no>NoOfCopy)
                {

                  fout << BookID << "\n" << BookName << "\n" << AuthorName << "\n" << (NoOfCopy) << "\n" << price_per_book << "\n\n";
                  cout << "\n\t __ Only " << NoOfCopy << " Books are/is available in shop___ \n";
                }
                else
                {
                  cout << "\n\t __All the Books of BookID " << BookID << " has been purchased __ \n";
                }

            }
            else
            {
                fout << BookID << "\n" << BookName << "\n" << AuthorName << "\n" << (NoOfCopy) << "\n" << price_per_book << "\n\n";
            }
        fin >> BookID;
        getline(fin>>ws,BookName);
        getline(fin>>ws,AuthorName);
        fin >> NoOfCopy;
        fin >> price_per_book;
        }
        if(ct==0)
        {
            cout << "\n\t _ Book Not Available  __\n";
        }
    }
    else
    {
        cout << "\n\t _ Error in File Opening __\n";
    }
    cout << "\n";
    design(120,'=');

    fout.close();
    fin.close();
    remove("BookData.txt");
    rename("BookData1.txt","BookData.txt");
    return ;
}



//function for updating book information in record
void BookShop::update_book()
{
     system("CLS");
     design(120,'=');
     cout << "\n \n\t\t\t ######################## Update Existing Book  ########################\n";
     design(120,'_');
     cout << endl;
     int flag=0;
     string B_name,A_name;
     int Bid,no;
     float price;
     cout << "\n\t Enter Book ID ";
     cin >> Bid;
     cout << "\n\t Enter Book Name ";
     getline(cin>>ws,B_name);
     cout << "\n\t Enter Author Name ";
     getline(cin>>ws,A_name);
     cout << "\n\t Enter No Of It's Copies ";
     cin >> no;
     cout << "\n\t Enter Price per Book ";
     cin >> price;
     ifstream fin("BookData.txt",ios::in);
     ofstream fout("BookData1.txt",ios::app);

     if(fin.is_open())
     {
            fin>>BookID;
            getline(fin>>ws,BookName);
            getline(fin>>ws,AuthorName);
            fin >> NoOfCopy;
            fin >> price_per_book;
            while(!fin.eof())
            {

               if(BookID==Bid)
                {
                   fout << Bid << "\n" << B_name << "\n" << A_name << "\n" << no << "\n" << price << "\n\n";
                   flag=1;
                }
                else
                {
                   fout << BookID << "\n" << BookName << "\n" << AuthorName << "\n" << (NoOfCopy) << "\n" << price_per_book << "\n\n";
                }
                fin >> BookID;
                getline(fin>>ws,BookName);
                getline(fin>>ws,AuthorName);
                fin >> NoOfCopy;
                fin >> price_per_book;
            }
            if(flag==0)
            {
                cout << "\n\t _ That Book is unavailable __\n";
            }
            else
            {
                cout << "\n\t _ Books Are Updated __ \n";
            }
    }
    else
    {
        cout << "\n\t _ Error in File Opening _\n";
    }
    cout << endl << endl;
    design(120,'=');
    fout.close();
    fin.close();
    remove("BookData.txt");
    rename("BookData1.txt","BookData.txt");
    return ;
}
