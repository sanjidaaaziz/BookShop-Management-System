//BOOKSHOP MANAGEMENT SYSTEM//
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class bookshop
{
   public:
       void control_panel();
       void add_book();
       void show_books();
       void check_book();
       void update_book();
       void del_book();
};

   void bookshop::control_panel()
   {
       system("cls");
       cout<<"\n\n\t\t\t\t\t  _______________________________";
       cout<<"\n\t\t\t\t\t  ||BOOK SHOP MANAGEMENT SYSTEM||";
       cout<<"\n\t\t\t\t\t  *******************************";
       cout<<"\n\n\n\t\t\t\t\t\t 1. Add New Book";
       cout<<"\n\n\t\t\t\t\t\t 2. Display Books";
       cout<<"\n\n\t\t\t\t\t\t 3. Check Specific Book";
       cout<<"\n\n\t\t\t\t\t\t 4. Update Book";
       cout<<"\n\n\t\t\t\t\t\t 5. Delete Book";
       cout<<"\n\n\t\t\t\t\t\t 6. Exit";
   }

   void bookshop::add_book()
   {
       system("cls");
       fstream file;
       int no_copy;
       string b_name,a_name,b_id;
       cout<<"\n\n\n\t\t\t\t\t\t |Add New Book|";
       cout<<"\n\t\t\t\t\t\t----------------";
       cout<<"\n\n Book ID : ";
       cin>>b_id;
       cout<<"\n\n Book Name : ";
       cin>>b_name;
       cout<<"\n\n Author Name : ";
       cin>>a_name;
       cout<<"\n\n No. of Copies : ";
       cin>>no_copy;
       file.open("D://book.txt",ios::out|ios::app);
       file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
       file.close();
    }

    void bookshop::show_books()
    {
        system("cls");
        fstream file;
        int no_copy;
        string b_name,b_id,a_name;
        cout<<"\n\n\n\t\t\t\t\t\t |Display Books|";
        cout<<"\n\t\t\t\t\t\t-----------------";
        file.open("D://book.txt",ios::in);
        if(!file)
            cout<<"\n\n File Opening Error!";
        else
        {
          cout<<"\n\n Book ID\t\tBook Name\t\tAuthor Name\t\tNo. of Copies\n\n";
          file>>b_id>>b_name>>a_name>>no_copy;
          while(!file.eof())
          {
              cout<<"  "<<b_id<<"\t\t\t"<<b_name<<"\t\t\t"<<a_name<<"\t\t\t"<<no_copy<<"\n\n";
              file>>b_id>>b_name>>a_name>>no_copy;
          }
          file.close();
        }
    }

    void bookshop::check_book()
    {
        system("cls");
        fstream file;
        int no_copy,count=0;
        string b_id,b_name,a_name,b_idd;
        cout<<"\n\n\n\t\t\t\t\t\t |Check Specific Book|";
        cout<<"\n\t\t\t\t\t\t-----------------------";
        file.open("D://book.txt",ios::in);
        if(!file)
            cout<<"\n\n File Opening Error!";
        else
        {
            cout<<"\n\n\n Book ID : ";
            cin>>b_idd;
            file>>b_id>>b_name>>a_name>>no_copy;
            while(!file.eof())
            {
                if(b_idd==b_id)
                {
                    system("cls");
                    cout<<"\n\n\t\t\t\t\t\t  Check Specific Book";
                    cout<<"\n\n Book ID : "<<b_id;
                    cout<<"\n\n Name : "<<b_name;
                    cout<<"\n\n Author Name : "<<a_name;
                    cout<<"\n\n No. of Copies : "<<no_copy;
                    count++;
                    break;
                }
                file>>b_id>>b_name>>a_name>>no_copy;
            }
            file.close();
            if(count==0)
             cout<<"\n\n Book ID Not Found!";
        }
    }

    void bookshop::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
        cout<<"\n\n\n\t\t\t\t\t\t |Update Book Record|";
        cout<<"\n\t\t\t\t\t\t----------------------";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Opening Error!";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id==b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\t\tUpdate Book Record";
					cout<<"\n\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n Author Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count==0)
            cout<<"\n\n Book ID Not Found!";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}

	void bookshop::del_book()
	{
	    system("cls");
	    fstream file,file1;
	    int no_copy,count=0;
	    string b_id,b_idd,b_name,a_name;
	    cout<<"\n\n\n\t\t\t\t\t\t |Delete Book Record|";
        cout<<"\n\t\t\t\t\t\t----------------------";
        file1.open("D://book1.txt",ios::app|ios::out);
        file.open("D://book.txt",ios::in);
        if(!file)
            cout<<"\n\n File Opening Error!";
        else
        {
            cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id==b_idd)
                {
                  system("cls");
                  cout<<"\n\n\t\t\t\tDelete Book Record";
                  cout<<"\n\n Selected Book is Successfully Deleted!";
                  count++;
                }
                else
                file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
	        }
	        if(count==0)
            cout<<"\n\n Book ID Not Found!";
        }
        file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}

int main()
{
    int choice;
    char x;
    bookshop b;
    p:
    b.control_panel();
    cout<<"\n\n\n\t\t\t\t\t\t Enter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1:
          do
          {
           b.add_book();
           cout<<"\n\n Do you want to add another Book? (y or n) : ";
           cin>>x;
          }while(x=='Y');

        break;
      case 2:
          b.show_books();
        break;
      case 3:
          b.check_book();
        break;
      case 4:
          b.update_book();
        break;
      case 5:
          b.del_book();
        break;
      case 6:
        break;
        exit(0);
      default:
        cout<<"\n\n\t\t\t\t\t\t Invalid Value, Please try again!";
    }
    getch();
    goto p;
}

