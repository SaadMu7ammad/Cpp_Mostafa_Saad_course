#include <bits/stdc++.h>
#define loop(start, n) for (int i = start; i < n; i++)
#define endl "\n"

typedef long long ll;
using namespace std;
int cbooks = 0;
int cusers = 0;
const int MAX_BOOKS = 10;
const int MAX_USERS = 10;
bool prefixFind=false;
struct USER
{
    int id;
    string name;
    int borrowed_books_ids[MAX_BOOKS];
    int lenBorowed=0;
};
struct BOOK
{
    int id;
    string name;
    int total_quantity=0;
    int total_borrowed=0;

    void add_book()
    {

        cout << "Enter book info: id & name & total quantity: ";

        cin >> id >> name >>total_quantity;
        ++cbooks;
    }
    void search(string prefix)
    {
        string tmp = name.substr(0, prefix.length());
        if (tmp == prefix)
        {
            prefixFind=true;
            cout << name<<" ";
        }

    }
};
bool cmpId(BOOK a,BOOK b)
{

    return a.id<b.id;
}
bool cmpName(BOOK a,BOOK b)
{

    return a.name<b.name;
}
struct SYSTEM
{


    BOOK books[MAX_BOOKS];
    USER users[MAX_USERS];
    int menu()
    {
        int choice = -1;
        while (choice == -1)
        {
            cout << "\nLibrary Menu;\n";
            cout << "1) add_book\n";
            cout << "2) search_books_by_prefix\n";
            cout << "3) print_who_borrowed_book_by_name\n";
            cout << "4) print_library_by_id\n";
            cout << "5) print_library_by_name\n";
            cout << "6) add_user\n";
            cout << "7) user_borrow_book\n";
            cout << "8) user_return_book\n";
            cout << "9) print_users\n";
            cout << "10) Exit\n";

            cout << "\nEnter your menu choice [1 - 10]: ";
            cin >> choice;

            if (choice < 1 || choice > 10)
            {
                cout << "Invalid choice. Try again\n";
                choice = -1;
            }
        }
        return choice;
    }

    void run()
    {
        while (true)
        {
            int choice = menu();
            if (choice == 1)
            {
                books[cbooks].add_book();
            }
            else if (choice == 2)
            {
                cout << "Enter book name prefix: ";
                string prefix;
                cin >> prefix;
                for (int i = 0; i < cbooks; i++)
                {
                    books[i].search(prefix);
                }
                if(prefixFind==false)
                {
                    cout<<"NOT FOUND "<<endl;

                }
                prefixFind=false;
            }
            else if (choice==3)
            {
                for (int i = 0; i < cusers; i++)
                {
                    if(users[i].lenBorowed!=0)
                    {
                        cout<<users[i].name;
                        for(int j=0; j<users[i].lenBorowed; j++)
                        {
                            cout <<" "<<users[i].borrowed_books_ids[j];

                        }
                        cout<<endl;
                    }

                }
            }
            else if (choice==4)
            {
                sort(books,books+cbooks,cmpId);
                for(int i=0; i<cbooks; i++)
                {
                    cout<<"ID= "<<books[i].id<<" name= "<<books[i].name<<" tot quantity= "<< books[i].total_quantity<<" tot borrowed= "<<books[i].total_borrowed<<endl;
                }
            }
            else if (choice==5)
            {
                sort(books,books+cbooks,cmpName);
                for(int i=0; i<cbooks; i++)
                {
                    cout<<"ID= "<<books[i].id<<" name= "<<books[i].name<<" tot quantity= "<< books[i].total_quantity<<" tot borrowed= "<<books[i].total_borrowed<<endl;
                }
            }
            else if (choice==6)
            {
                cout<<"Enter user name & id : ";
                int id;
                string name;
                cin>>name>>id;
                users[cusers].name=name;
                users[cusers].id=id;
                cusers++;


            }
            else if (choice==7)
            {
                cout<<"Enter user name and book name ";
                string nameuser,namebook;
                cin>>nameuser>>namebook;

                bool flagU=false;
                bool flagB=false;
                int idxUser;
                int idxBook;

                int positionBook;

                for(int i=0; i<cusers; i++)
                {
                    if(nameuser ==users[i].name)
                    {
                        flagU=true;
                        idxUser=i;
                        break;
                    }
                }
                for(int i=0; i<cbooks; i++)
                {
                    if(namebook ==books[i].name)
                    {
                        flagB=true;
                        positionBook=i;
                        idxBook=books[i].id;
                        break;
                    }
                }
                if(flagU&&flagB)
                {
                    if(books[positionBook].total_quantity>books[positionBook].total_borrowed)
                    {

                        users[idxUser].borrowed_books_ids[(users[idxUser].lenBorowed)++]=idxBook;
                        books[positionBook].total_borrowed++;
                    }
                    else
                    {
                        cout<<"You cant borrow this book ,All Copies are borrowed";
                    }


                }
                else
                {
                    cout<<"Invalid input "<<endl;
                }
                flagB=false;
                flagU=false;
            }
            else if (choice==8)
            {
                cout<<"Enter user name and book name ";
                string nameuser,namebook;
                cin>>nameuser>>namebook;
                int idxBook;


                int idxUser;

                int positionBook;


                for(int i=0; i<cbooks; i++)
                {
                    if(books[i].name==namebook)
                    {
                        idxBook=books[i].id;
                        positionBook=i;
                    }
                }

                for(int i=0; i<cusers; i++)
                {
                    if(nameuser ==users[i].name)
                    {
                        for(int j=0; j<users[i].lenBorowed; j++)
                        {
                            int len=users[i].lenBorowed;
                            if(users[i].borrowed_books_ids[j]==idxBook)
                            {
                                for(int k=j; k<users[i].lenBorowed-1; k++)
                                {
                                    users[i].borrowed_books_ids[k]=users[i].borrowed_books_ids[k+1];
                                }

                                users[i].lenBorowed--;
                                books[positionBook].total_borrowed--;
                            }
                        }


                    }

                }
            }
            else if (choice==9)
            {
                for(int i=0; i<cusers; i++)
                {
                    cout<<users[i].name<<" "<<users[i].id<<endl;
                }


            }
            else if (choice==10)
            {
                cout<<"Exit";
                break;

            }

        }
    }
};
int main()
{
    SYSTEM obj;
    obj.run();

    return 0;
}
