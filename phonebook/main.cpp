#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void add_contact(char[]);
void show_contact(char[]);
void search_contact(char[],char[]);
void update_contact(char[],char[]);
void add_favcontact(char[],char[]);
void delete_contact(char[],char[]);
void menu();
 struct contact{
     char name[80];
     string phone_no;
 };
int const size=2;
 contact c[size];
 char filename[50];

int main()
{
   system("color 3E");
    menu();
    system("cls");
    char search_name[50];
    int op;
    do
    {
        cout<<".......PHONE BOOK MENU........"<<endl;
        cout<<"1.ADD CONTACT\n";
        cout<<"2.SHOW CONTACTS\n";
        cout<<"3.SEARCH CONTACT\n";
        cout<<"4.UPDATE CONTACT\n";
        cout<<"5.ADD FAVOURITE  CONTACT\n";
        cout<<"6.DELETE CONTACT\n";
        cout<<"7.EXIT\n";
        cout<<"SELECT UR OPTION(1-7)";
          cin>>op;
        cout<<"\nENTER FILE NAME PLEASE!\n";
        cin.ignore();
        cin.getline(filename,50);
    switch(op)
    {
    case 1:
       add_contact(filename);
         break;
    case 2:
       show_contact(filename);
       break;
   /* case 3:
        cout<<"ENTER THE NAME OF PERSON T0 SEARCH FOR!\n";
        cin.getline(search_name,50);
        search_contact(filename,search_name);
       break;
    case 4:
       cout<<"ENTER THE NAME OF THE PERSON TO UPDATE!\n";
       cin.getline(search_name,50);
       update_contact(filename,search_name);
       break;
    case 5:
       cout<<"ENTER THE NAME OF PERSON TO MARRK AS FAVOURITE!\n";
       cin.getline(search_name,50);
       add_favcontact(filename,search_name);
       break;

    case 6:
       cout<<"ENTER THE NAME OF PERSON TO DELETE!\n";
       cin.getline(search_name,50);
       //delete_contact(filename,search_name);
       break;
    case 7:
       cout<<"EXITING THE PROGRAM\n";
       return 0;
       break;
       */
    default:
    cout<<"INVALID CHOICE,PLEASE TRY AGIN\n";

    }

 }while(op!=7);

    return 0;
}
void menu()
{
    cout<<"..........Phone Book Project Documentation.........."<<endl;
    cout<<"The Phone Book project is a simple program that allows users to store and manage their contacts.\n ";
    cout<<"features like adding new contacts, searching for existing contacts, ";
    cout<<"updating contact information,\n marking contacts as favorites,and delete existing contact."<<endl;
    cout<<"Note:"<<endl;
    cout<<"- Contacts are stored temporarily in memory and will not persist after closing the program.\n";
    cout<<"This is a basic implementation intended for learning purposes and can be customized further to suit \n specific requirements."<<endl;
    cout<<"\n\n PRESS ANY KEY TO GET STARTED!"<<endl;
    cin.get();
}
void add_contact(char filename[])
{
    fstream myfile;
   myfile.open(filename,ios::out|ios::binary);
    if(myfile.fail())
    {
        cerr<<"ERROR OPNING THE FILE";
        exit(1);
    }
    cout<<endl;
    cout<<"..........ENTER CONTACT INFO:..........\n";
    for(int i=0;i<size;i++){
    cout<<"ENTER NAME OF THE PERSON:"<<i+1<<"  "<<endl;
    cin.getline(c[i].name,50);
    cout<<"ENTER PHONE NUMBER:"<<i+1<<"  "<<endl;
    cin>>c[i].phone_no;
    cin.ignore();
    }
    cout<<endl;
    for(int i=0;i<size;i++)
    {
    myfile.write((char*)&c[i],sizeof(contact));
    }
    cout<<"ADDED SUCCESSFULLY!"<<endl;
    myfile.close();

}
void show_contact(char filename[])
{
    ifstream myfile;
    myfile.open(filename,ios::in|ios::binary);
    if(myfile.fail())
    {
        cerr<<"FILE NOT FOUND!\n";
        exit(1);
    }
    int i=0;
        cout<<"..........CONTACT INFO:..........\n";
    while(myfile.read((char*)&c[i],sizeof(contact)))
    {
        cout<<"CONTACT "<<i+1<<endl;
        cout<<"NAME:"<<c[i].name<<endl;
        cout<<"PHONE NUMBER:"<<c[i].phone_no<<endl;
        i++;
    }
    myfile.close();
}

void deleteStudent(char fileName[] , int id){

    if (file.is_open()){
    file.close();
    }

  file.open(fileName, ios :: in | ios :: binary);
  if(!file){
    cerr<< "Error opening the file for writing. ";
    exit(1);
  }
  ofstream tempFile(tempFileName, ios :: out | ios :: binary);
  if(!tempFile){
    cerr<< "Error opening the file for writing. ";
    file.close();
    exit(1);
  }


  bool studentfound = false;
     for(int j=0;j<SIZE;j++) {

   file.read((char *) (&si [j]), sizeof(Student));
   if(si[j].id == id){

     cout << " Sutdent with  ID " << id <<" deleted successfully. " << endl ;

     studentfound = true;
     continue;
   }
  tempFile.write((char *) (&si [j]), sizeof(Student));
  }

 file.close();
 tempFile.close();

  remove(fileName);
  rename (tempFileName , fileName);

 if(!studentfound){
      cout << " Deletion Is Failed " <<endl ;
      cout << " Sutdent not found with  ID " << id <<endl ;
    return;
  }

}
