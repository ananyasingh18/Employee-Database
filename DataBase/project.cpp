#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <conio.h>
using namespace std;
class employee
{
     private:
     string employee_id , name ,  dept, email, contactno,location; 
     public:
     void opening();
      void menu();
      void insert_record();
      void display_record();
      void update_record();
      void search();
      void delete_record();
       
};

void employee :: opening()
{
    cout<<"\t\t\t\t\t\t************\t\t\t\t";
    cout<<endl;
    cout<<"\t\t\t\t\t\t    DATA MANAGEMENT SYSTEM   \t\t\t\t";
        cout<<endl;
    cout<<"\t\t\t\t\t\t************\t\t\t\t";
        cout<<endl;
    
}
void employee :: insert_record()
{
    fstream  file;
    cout<<"\t\t\t\t\t\t************\t\t\t\t";
    cout<<endl;
    cout<<"\t\t\t\t\t\t      Inserting Records       \t\t\t\t";
        cout<<endl;
    cout<<"\t\t\t\t\t\t************\t\t\t\t";
    cout<<endl;
    cout<<"ADD DETAILS OF EMPLOYEE\n";
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter Employee ID : ";
      cin>>employee_id ;
      cout<<"Enter Department : ";
      cin>>dept; 
      cout<<"Enter Email ID :";
      cin>>email ;
       cout<<"Enter Contact Number :";
      cin>>contactno  ;
       cout<<"Enter Company Branch Location";
      cin>>location ;
      file.open("employeeRecord.dat", ios::binary | ios::app | ios::out);
      file<<" "<<name<<" "<<employee_id<<" "<<dept<<" "<<email<<" "<<contactno<<" "<<location<<"\n";
      file.close();
      
    
}
void employee :: display_record()
{
    fstream file;
    int total=0;
     cout<<"\t\t\t\t\t\t************\t\t\t\t";
    cout<<endl;
    cout<<"\t\t\t\t\t\t        Employee Records       \t\t\t\t";
        cout<<endl;
    cout<<"\t\t\t\t\t\t************\t\t\t\t";
    cout<<endl;
    file.open("employeeRecord.dat", ios::binary | ios::in); 
    if(!file)
    {
        cout<<"\n\t\t\t\t      No records present\n";
        file.close();
    }
    else 
   {
              file>>name>>employee_id>>dept>>email>>contactno>>location;
       
            while(!file.eof())
          {
             cout<<"\n\t\t\t\t Employee "<<total++<<" :"<<endl;
             cout<<"Employee Name        : "<<name<<endl;
             cout<<"Employee ID          : "<<employee_id<<endl;
             cout<<"Department           : "<<dept<<endl;
             cout<<"Employee Email       : "<<email<<endl;
             cout<<"Employee Contact No. : "<<contactno<<endl;
            cout<<"Location             : "<<location<<endl;
            file>>name>>employee_id>>dept>>email>>contactno>>location;
             cout<<"\t\t\t\t\t\t************\t\t\t\t"; 
    
           }
           if (total=0)
           {
               cout<<"\n\t\t\t\t      No records present\n";
            }
   }
   file.close();
}

void employee :: update_record()
{
    fstream file, file1;
    int found = 0;
    string emp;
      cout<<"\t\t\t\t\t\t************\t\t\t\t"; 
      cout<<"\t\t\t\t            Update Record         \t\t\t\t";       
      cout<<"\t\t\t\t\t\t************\t\t\t\t"; 
      cout<<endl;
      file1.open("employeeRecord.dat", ios::binary | ios::in); 
      if(!file)
      {
          cout<<"\t\t\t\t       No Data Present        \t\t\t\t";
          file.close();
      }
      else
      {
          cout<<"\n Enter Employee ID : ";
          cin>>emp;
           file1.open("Record.dat", ios::binary | ios::app | ios::out );   
            file>>name>>employee_id>>dept>>email>>contactno>>location;
            while(!file.eof())
            {
                if(emp !=employee_id)
                 
                {
                    file<<" "<<name<<" "<<employee_id<<" "<<dept<<" "<<email<<" "<<contactno<<" "<<location<<"\n";
                }
                else 
                   {
                         cout<<"Enter name : ";
                         cin>>name;
                         cout<<"Enter Employee ID : ";
                         cin>>employee_id ;
                         cout<<"Enter Department : ";
                         cin>>dept; 
                         cout<<"Enter Email ID :";
                         cin>>email ;
                         cout<<"Enter Contact Number :";
                         cin>>contactno  ;
                         cout<<"Enter Company Branch Location";
                         cin>>location ; 
                         file<<" "<<name<<" "<<employee_id<<" "<<dept<<" "<<email<<" "<<contactno<<" "<<location<<"\n";
                         found++;
                    
                }
            file>>name>>employee_id>>dept>>email>>contactno>>location;
                  if (found==0)
                  {
                      cout<<"\n\t\t\t\tStudent Roll no. not found";
                  }
                  
           }
                  file1.close();     
                  file.close();
                  remove("employeeRecord.dat");
                  rename("Record.dat","employeeRecord.dat");
            
      }
}




void employee :: search()
{
    fstream file;
    int found=0;
    file.open("employeeRecord.dat", ios::binary | ios::in);
    if (!file)
    {
        cout<<"No Data Found";
    }
    else 
    {
        string empno;
        cout<<"\t\t\t\t\t\t************\t\t\t\t"; 
        cout<<"\t\t\t\t            Search Record         \t\t\t\t";       
        cout<<"\t\t\t\t\t\t************\t\t\t\t";
        cout<<endl;
        cout<<"\t\tEnter Employee Id of the record you wish to search\t\t";
        cin>>empno;
          file>>name>>employee_id>>dept>>email>>contactno>>location;
          while(!file.eof())
          {
              if(empno==employee_id)
              {
               cout<<"Employee Name        : "<<name<<endl;
               cout<<"Employee ID          : "<<employee_id<<endl;
               cout<<"Department           : "<<dept<<endl;
               cout<<"Employee Email       : "<<email<<endl;
               cout<<"Employee Contact No. : "<<contactno<<endl;
               cout<<"Location             : "<<location<<endl; 
               found++;
              }
               file>>name>>employee_id>>dept>>email>>contactno>>location;
          }
          if (found==0)
          {
              cout<<"Record not found";
          }
          file.close();
    }
}

void employee :: delete_record()
{
    fstream file,file1;
    string empno;
    int found=0;
      cout<<"\t\t\t\t\t\t************\t\t\t\t"; 
      cout<<"\t\t\t\t            Delete Record         \t\t\t\t";       
      cout<<"\t\t\t\t\t\t************\t\t\t\t";
      cout<<endl;
      file.open("employeeRecord.dat", ios::in);
       if (!file)
    {
        cout<<"No Data Found";
    }
    else 
    {
        cout<<"Enter the Employee ID of Record to be deleted : ";
        cin>>empno;
        file1.open("record.dat", ios::binary |ios::app | ios::out);
        file>>name>>employee_id>>dept>>email>>contactno>>location;
        while(!file.eof())
        {
            if (empno != employee_id )
            {
                  file<<" "<<name<<" "<<employee_id<<" "<<dept<<" "<<email<<" "<<contactno<<" "<<location<<"\n";
            }
             file>>name>>employee_id>>dept>>email>>contactno>>location;
            
        }
        if( found==0)
        {
            cout<<"\n\t\t\t\tEmployee ID not found\n"; 
        }
        file1.close();
        file.close();
        remove("employeeRecord.dat");
        rename("record.dat", "employeeRecord.dat");
    }
}

void employee :: menu()

{
    menustart :
     int choice ;
     char(x);
     cout<<"\t\t\t\tEnter the number corresponding to the command you wish to execute";
     cout<<endl;
 
     cout<<"1.Enter a record\n";
     cout<<"2.Display a record\n";
     cout<<"3.Update a record\n";
     cout<<"4.Search a record\n";
     cout<<"5.Delete a record\n";
     cout<<"6.Exit\n";
     cin>> choice;
     
      
     switch (choice)
     {
         case 1 : 
         do
         {
              insert_record();
             cout<<"Add another record (Y for yes,N for no) :";
             cin>>x;
         } while (x=='y' || x=='Y');
         break;
         case 2:
              display_record();
              break;
              
         case 3:
               update_record();
                break;
         case 4 :
            search();
            break;
         case 5:
          delete_record();
          break;
          case 6 :
          exit(0);
         default:
         cout<<"  \t\t\t\t\t\t************\t\t\t\t\n";
         cout<<"  \t\t\t\t\t\t        Invalid choice        \t\t\t\t\n";
          cout<<"  \t\t\t\t\t\t************\t\t\t\t\n";
          cout<<"\n\n";
        
          
     }
     getch();
     goto menustart;
     
} 



int main()
{
    employee project;
    project.opening();
    project.menu(); 
}