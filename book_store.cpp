#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Book_store
{
private:
    string book_id;
    string book_name;
    string author_name;
    int no_copy;

public:
    void reception()
    {
    system("cls");
    cout<<"-:Reception:-"<<endl;
    cout<<"Add book"<<endl;
    cout<<"Display book"<<endl;
    cout<<"Inspect a particular book"<<endl;
    cout<<"Update a book"<<endl;
    cout<<"Delete a book"<<endl;
    cout<<"Exit"<<endl;
    }
    void Add_book()
    {
    system("cls");
    fstream database;
    cout<<"Add Book";
    cout<<"Book ID ";
    cin>>book_id;
    cout<<"Book Name";
    cin>>book_name;
    cout<<"Author Name";
    cin>>author_name;
    cout<<"No of Books";
    cin>>no_copy;
    database.open("database.xlsx");
    database<<" "<<book_id<<" "<<book_name<<" "<<author_name<<" "<<no_copy <<"\n";
    database.close();
    }
    void Display_book()
    {
        system("cls");
        fstream database;
        cout<<"ALL BOOKS";
        database.open("database.xlsx",ios::in);
        if(!database)
        {
            cout<<"File Opening Error";
        }
        else
        {
            cout<<"book ID"<<"book"<<"Author"<<"No. of books";
            database<<book_id<<book_name<<author_name<<no_copy;
            while (!database.eof())
            {
                cout<<" "<<book_id<<" "<<book_name<<" "<<author_name<<" "<<no_copy<<"\n";
                database>>book_id>>book_name>>author_name>>no_copy;
            }
            system("pause");
            database.close();
        }
    }
    void inspect_book()
    {
        system ("cls");
        fstream database;
        int count=0;
        string book_iid;
        cout<<"check for a particular book";
         database.open("database.xlsx",ios::in);
        if(!database)
        {
            cout<<"File Opening Error";
        }
        else
        {
            cout<<"book ID";
            cin>>book_iid;
            database<<book_id<<book_name<<author_name<<no_copy;
            while (!database.eof())
            {
                if(book_iid==book_id)
                {
                    system("cls");
                    cout<<"Check Paticular Book";
                    cout<<"Book ID : "<<book_id;
                    cout<<"Book Name"<<book_name;
                    cout<<"Author Name"<<author_name;
                    cout<<"Number of Book"<<no_copy;
                    count++;
                    break;
                }
                database>>book_id>>book_name>>author_name>>no_copy;
            }
            system("pause");
        }
    void update_book();
    void remove_book();
    }
};
int main ()
{

}
