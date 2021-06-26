//Travel agency project
/*
team member:
1- Abanob Fayez
2- Ibrahem Hamed
3- Ibrahem Hassan
4- Ibrahem Ramadan
5- Ibrahem swilm
6- Ibrahem salah
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include <windows.h>
#undef max 
#include<limits>
#include<conio.h>

using namespace std;

int total,price,perday,perseat;
char ch;
char x;
void menu();
struct personal{
	string name;
	string address, date , phone,id;

};
class reservation{
private:
	 personal client;
public:
	void intro(){
	    ifstream star;
		star.open("WELCOME.txt");
		string y;
		while (!star.eof())
		{
			getline(star, y);
			cout << y <<endl;
		}
		star.close();
	}
	void input(){

	ofstream file;
		file.open("CUSTOMER_DATA.txt",ios::app);
		cout<<"\n\n\n";
		cout << setw(8) << "\t\t\tEnter Your Name:- ";
		cin.clear();
        cin.ignore();
		getline (cin,client.name);
		file << client.name<<endl;
		cout << setw(8) << "\t\t\tEnter Your ID Number:- ";
        cin >> client.id;

        for(int i=0;i<client.id.length();i++)
        {

            if(!isdigit(client.id[i])||client.id.length()!=14)
            {
                do{
              cout<< setw(8) << "\a\t\t    *Your ID Number Must Be Numeric And 14 Number*"<<endl;
              cout << setw(8) << "\t\t\tEnter Your ID Number:- ";
              cin>>client.id;
                }while(!isdigit(client.id[i])||client.id.length()!=14);
            }
        }

        string f;
		file << client.id<<endl;
		cout << setw(8) << "\t\t\tEnter Your Address (Summarized):- ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		getline (cin,client.address);
		if(client.address.length()>18)
            {
                do{
              cout<< setw(8) << "\a\t\t    *Your Address Should Be 18 character Or Less*"<<endl;
              cout << setw(8) << "\t\t\tEnter Your Address (Summarized):- ";
		         getline (cin,client.address);
                }while(client.address.length()>18);
            }
		file << client.address<<endl;
		cout << setw(8) << "\t\t\tEnter Your Phone_Number:- ";
		cin >> client.phone;
          for(int i=0;i<client.phone.length();i++)
            {
               if((!isdigit(client.phone[i]))||client.phone.length()!=11)
               {

                do{

					cout<< setw(8) << "\a\t   *Error...!,Your Phone Number Must Be 11 Digits And Numeric*"<<endl;
					cout << setw(8) << "\t\t\tEnter Your Phone Number Again:- ";
					cin>>client.phone;

                  }while((!isdigit(client.phone[i]))||client.phone.length()!=11);
               }
            }
		file << client.phone<<endl;
		cout << setw(8) << "\t\t\tEnter The Date of Flight:- ";
		cin >> client.date;
		for(int i=0;i<client.date.length();i++)
        {
            if(!(client.date[i]=='/'||isdigit(client.date[i])))
            {
                do{
                cout<<"\a\t   *Error...! , The Date Must Be in this form ->> dd/mm/yyyy *"<<endl;
                cout << setw(8) << "\t\t\tEnter The Date of Flight:- ";
                cin >> client.date;
                }while(!(client.date[i]=='/'||isdigit(client.date[i])));
            }

        }
		file << client.date<<endl;
		system("cls");
	}
	void trip_place(){
		int choice,choise2;
		s:
		cout<<"\t\t Choose Type of Your Trip :- "<<endl<<"\t\t\t1- International.\n\t\t\t2- Local.\n\t\t Enter your choice (1,2):- ";
		cin>>choise2;
		system("cls");
		if(choise2==1)
        {
		cout << setw(10) << "\t\t The Available Trips Are: " << endl;
		cout << setw(10) << "\t\t\t1- From Cairo to Hong Kong and its price 25000 " << endl;
		cout << setw(10) << "\t\t\t2- From Cairo to Berlin and its price 9000 " << endl;
		cout << setw(10) << "\t\t\t3- From Cairo to Roma and its price 7000 " << endl;
		cout << setw(10) << "\t\t\t4- From Cairo to London and its price 9000 " << endl;
		cout << setw(10) << "\t\t\t5- From Cairo to Dubai and its price 3000 " << endl;
		cout << setw(10) << "\t\t\t6- From Cairo to Russia and its price 30000 " << endl;
		cout << setw(10)<< "\t\t Enter your choice between 1 and 6:- ";
		cin >> choice;


		while(!(choice>=1&&choice<=6))
		{cout<<setw(10)<<"\t\t Please Enter Number Between 1 and 6:- ";
		cin>>choice;
		}
		system("cls");
		switch (choice){
		case 1:price = 25000;break;
		case 2:price = 9000;break;
		case 3:price = 7000; break;
		case 4:price = 9000; break;
		case 5:price = 3000; break;
		case 6:price = 30000; break;
		}
        }
        else if(choise2==2)
        {
        cout << setw(10) << "\t\t The Available Trips Are: " << endl;
		cout << setw(10) << "\t\t\t1- From Cairo to Alex and its price 1100 " << endl;
		cout << setw(10) << "\t\t\t2- From Cairo to Luxor and its price 1800 " << endl;
		cout << setw(10) << "\t\t\t3- From Cairo to Sharm El_sheikh and its price 1200 " << endl;
		cout << setw(10)<< "\t\t Enter your choice between 1 and 3:- ";
		cin >> choice;
		while(!(choice>=1&&choice<=3))
		{cout<<setw(10)<<"\t\t Please Enter Number Between 1 and 3:- ";
		cin>>choice;
		}
		system("cls");
		switch (choice){
		case 1:price = 1100;break;
		case 2:price = 1800;break;
		case 3:price = 1200; break;

		}
        }
        else
        {

            cout<<"\a\t\tError..!!, Please Enter a valid choice.\n\n ";
            goto s;
        }
	}
	void day(){
		int choi,days;
		cout<<setw(10)<<"\t\t the price for one day = 1000 $"<<endl;
		cout << setw(10) << "\t\t How many days do you like to spend ?" << endl;
		cout << setw(10) << "\t\t\t 1- One week" << endl;
		cout << setw(10) << "\t\t\t 2- More or Less than one week " << endl;
		cout << setw(10) << "\t\t Enter Number your choice (1 or 2) :-  ";
		cin >> choi;
		while(!(choi>=1&&choi<=2))
		{cout<<setw(10)<<" \t\t Please Enter Number your choice (1 or 2) :-  ";
		cin>>choi;
		}
		switch(choi){
			case 1:perday=1000*7;break;
			case 2: cout<<setw(10)<<"\t\t Enter Number Of Days:-";		
				cin>>days;
				perday=days*1000;break;
		}
		       system("cls");
		}
	void seat(){
		int x;
		cout << setw(10) << "\t\t the available seats " << endl;
		cout << setw(10) << "\t\t\t1- Seat For Single passenger " << endl;
		cout << setw(10) << "\t\t\t2- Seats For Double passengers" << endl;
		cout << setw(10) << "\t\t\t3- More Seats " << endl;
		cout << setw(10) << "\t\t Enter your choice between 1 and 3:  " ;
		cin >> x;
		while(!(x>=1&&x<=3))
		{
		cout<<setw(10)<<"\t\t Please Enter Your Number Between 1 and 3:  ";
		cin>>x;
		}
		switch(x)
		{
		    case 1:perseat=1;break;
		    case 2:perseat=2;break;
		    case 3:cout<<setw(10)<<"\t\t Enter Number Of Seat You Are Need:-"; cin>>perseat;break;
		}
		system("cls");
	}
	void airline(){
		int y;
		cout << setw(10) << "\t\t Type of Airlines" << endl;
		cout << setw(10) << "\t\t\t 1- Egyptian Airlines" << endl;
		cout << setw(10) << "\t\t\t 2- Emirates Airlines" << endl;
		cout << setw(10) << "\t\t\t 3- Qatar Airlines" << endl;
		cout << setw(10) << "\t\t  Enter Your Choice Between 1 and 3:  " ;
		cin >> y;
		while(!(y>=1&&y<=3))
		{
		cout<<setw(10)<<"\a\t\tError...! ,Please Enter The Number Between 1 and 3:  ";
		cin>>y;
		}
		system("cls");
	          }
	void classs(){
		int w;
			ofstream file;
			file.open("CUSTOMER_DATA.txt",ios::app);

		cout <<setw(10)<< "\t\t Choose The Class of Your Travel " << endl;
		cout << setw(10) << "\t\t\t1- Business" << endl;
		cout << setw(10) << "\t\t\t2- Best Fare" << endl;
		cout <<setw(10)<< "\t\t Enter Number of Your Choice (1 or 2)  " ;
		cin >> w;
		while(!(w>=1&&w<=2)){
		cout<<setw(10)<<"\a\t\t Error...!,Please Enter Number of Your Choice (1 or 2) : ";
		cin>>w;}
		system("cls");

		switch (w){
		case 1:total =(price+300+perday)*perseat; cout<<setw(10)<< "\t\t Total cost = " << total<<" $" << endl; file<<total<<"$"<<endl;break;

		case 2:total = (price+perday)*perseat; cout<< "\t\t Total cost = " << total <<" $"<< endl; file<<total<<"$"<<endl;break;
		}
		file.close();
	}

};
void display(){
	personal p;
	    cout << "                               ***********************                  " << endl;
        cout << "                                List Of Customer Data                   " << endl;
	    cout << "                               ***********************                  " << endl;
	    cout << "-----------------------------------------------------------------------------------------------------------------------------------\n";
		cout <<left<<setw(20)<<"Name" <<left<<setw(20)<<"ID" <<left<<setw(20)<<"Address" <<left<<setw(20)<< "Phone" <<left<<setw(20)<<"Date"<<left<<setw(20)<<"Cost"<< endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
		ifstream ifile;
		ifile.open("CUSTOMER_DATA.txt",ios::out);
		int count=0;
		while(!ifile.eof()){

			string displaya;
			getline(ifile,displaya);
			cout<<left<<setw(20)<<displaya;
			count++;
			if(count%6==0){cout<<endl;}
		}
		cout<<endl;
		ifile.close();
}
void search(){

    string x[1000];int j=0;
	string y;
	cout<<"Enter Your ID to Find Your Data ";
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cin>>y;
	fstream file;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	file.open("CUSTOMER_DATA.txt");
	while(!file.eof()){

    getline(file,x[j]);
	j++;
	}
bool found=false;
	for(int i=1;i<=j;i+=6){

		if(x[i]==y)
		{
		    found=true;
        cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
		cout <<left<<setw(20)<<"Name" <<left<<setw(20)<<"ID" <<left<<setw(20)<<"Address" <<left<<setw(20)<< "Phone" <<left<<setw(20)<<"Date"<<left<<setw(20)<<"Cost"<< endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int g=i-1;g<i+5;g++)
                {
				    cout<<left<<setw(20)<<x[g];
				}
                break;
	     }

	}
	if(!found)
    {
          cout<<"\n\t****************"<<endl;
            cout<<"\t Data Not Found"<<endl;
           cout<<"\t****************"<<endl;
    }
	cout<<endl;
	}
void modify(){

    int count;
    string x[1000];int j=0;
	string y;
	cout<<"Enter your ID to find your data ";
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	getline(cin,y);
	fstream file;
	file.open("CUSTOMER_DATA.txt",ios::in);
	while(!file.eof()){
	getline(file,x[j]);
	j++;
	}
 bool found;
	for(int i=1;i<=j;i+=6)
	{
		if(x[i]==y)
        { found=true;
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            cout <<left<<setw(20)<<"Name" <<left<<setw(20)<<"ID" <<left<<setw(20)<<"Address" <<left<<setw(20)<< "Phone" <<left<<setw(20)<<"Date"<<left<<setw(20)<<"Cost"<< endl;
            cout << "--------------------------------------------------------------------------------------------------------------"<<endl;
            count=i;
			for(int g=i-1;g<i+5;g++)

			{
			    cout<<left<<setw(20)<<x[g];

			}

    cout<<"\n\n\n";
    cout<<"\t\t\t1- Edit  Name \n";
	cout<<"\t\t\t2- Edit  ID Number \n";
	cout<<"\t\t\t3- Edit  Address \n";
	cout<<"\t\t\t4- Edit  Phone Number \n";
	cout<<"\t\t\t5- Edit  Date \n";
	cout<<"\t\t Enter Your Choice:- ";
	int l;
	cin>>l;
    cout<<"\n\n";
	switch(l){
	case 1:cout<<"\t\t\tEnter New Name ";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');getline(cin,x[count-1]);cout<<"\n";break;
	case 2:cout<<"\t\t\tEnter New ID Number ";cin>>x[count];cout<<"\n";break;
	case 3:cout<<"\t\t\tEnter New Address ";cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');getline(cin,x[count+1]);cout<<"\n";break;
	case 4:cout<<"\t\t\tEnter New Phone Number";cin>>x[count+2];cout<<"\n";break;
	case 5:cout<<"\t\t\tEnter New Date ";cin>>x[count+3];cout<<"\n";break;
	}
     cout<<"\t\t*Your Data Has Been Changed Successfully*\n";
     break;

        }
	}
	if(!found)
    {
        cout<<"\n\t****************"<<endl;
        cout<<"\t Data Not Found"<<endl;
        cout<<"\t****************"<<endl;
    }
	cout<<"\n\n";
	file.close();
	file.open("CUSTOMER_DATA.txt",ios::out);
	int c=0;
	while(true){
	file<<x[c]<<"\n";
	c++;
	if(c==j){break;}
	}
}
void deletea(){


    string x[1000];int j=0;
	string y;
	cout<<"Enter Your ID To Show Your Data Before Delete It ";
	cin>>y;
	fstream file,test;
	file.open("CUSTOMER_DATA.txt",ios::in);
	while(!file.eof()){
	getline(file,x[j]);
	j++;
	}
      bool found=false;
	for(int i=1;i<=j;i+=6){
		if(x[i]==y)
        {
            found=true;
        cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout <<left<<setw(20)<<"Name" <<left<<setw(20)<<"ID" <<left<<setw(20)<<"Address" <<left<<setw(20)<< "Phone" <<left<<setw(20)<<"Date"<<left<<setw(20)<<"Cost"<< endl;
        cout << "---------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int g=i-1;g<i+5;g++)
			{
              cout<<left<<setw(20)<<x[g];
			  x[g]="\0";
			}
			cout<<"\n\n\t\t\t*Your Date Has Been Deleted*\n";
        break;
        }
	}
	 if(!found)
     {
        cout<<"\n\t****************"<<endl;
        cout<<"\t Data Not Found"<<endl;
        cout<<"\t****************"<<endl;
     }
	cout<<"\n";
	file.close();
	file.open("CUSTOMER_DATA.txt",ios::out);
	int c=0;
	while(true)
    {
    if(x[c]!="\0")
    {
	file<<x[c];
	test<<x[c];
	file<<endl;
    }
	c++;
	if(c==j){break;}
	}

}
void About (){

    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t  **************************************"<<endl;
    cout<<"\t\t\t\t  * This Is a Travel Agency Application *"<<endl;
    cout<<"\t\t\t\t  **************************************"<<endl;

    cout<<"\t\t\t Travel Agency As a Program  That Can Manage"<<endl;
    cout<<"\t\t\t The Detail Of Passenger Reservation :- For Example "<<endl;
    cout<<"\t\t\t Airlines Booking, The cost, Airline Enquiry, Ticket Booking.\n"<<endl;
    cout <<"\t\t\t------------------------------------------------------------------\n";
    cout <<"\t\t\t         THIS PROJECT HAS BEEN DEVELOPED BY THIS TEAM :-\n";
    cout <<"\t\t\t------------------------------------------------------------------\n\n";
    cout <<"\t\t\t\t\t1- Abanoub Fayez Kamal Mikhail.\n";
    cout <<"\t\t\t\t\t2- Ibrahim Hamed Abd El Aziz.\n";
    cout <<"\t\t\t\t\t3- Ibrahim Hassan Hanfy.\n";
    cout <<"\t\t\t\t\t4- Ibrahim Ramadan El-sayed.\n";
    cout <<"\t\t\t\t\t5- Ibrahim Swelam Moselhy.\n";
    cout <<"\t\t\t\t\t6- Ibrahim Salah Mohamed.\n";
}
void conclusion(){
	    ifstream thanks;
		thanks.open("THANKS.txt");
		string y;
		while (!thanks.eof())
		{
			getline(thanks, y);
			cout <<"\t\t\t"<< y <<endl;
		}
		thanks.close();
	}
void exitNow(){
	    int _1or_2;
	    cout << "\n\n\n\t\tAre You Sure You Want To Exit The Program\n"<<"\t\t\t1- YES\n\t\t\t2- NO\n";
               cout<<"\t\t   Enter Your Choice:- ";
                 cin>>_1or_2;
        		while(!((_1or_2==1||_1or_2==2)))
		         {cout<<"\t\t   Please Enter Number Between 1 , 2 :-  ";
		            cin>>_1or_2;
                 }
        system("cls");
        switch (_1or_2)
        {
        case 1: conclusion();Sleep(3000);exit(0); break;
        case 2:  menu();break;
        }
	}
void menu (){
           reservation b;
	    do{
        system("COLOR f1");
        cout << "\n";
		cout << "\t\t*************" << endl;
		cout << "\t\t Main menu:- \n";
		cout << "\t\t*************" << endl;
		cout << "\t\t\t 1- Registration\n";
		cout << "\t\t\t 2- Display\n";
		cout << "\t\t\t 3- Search\n";
		cout << "\t\t\t 4- Modify\n";
		cout << "\t\t\t 5- Delete\n";
		cout << "\t\t\t 6- About\n";
		cout << "\t\t\t 7- Exit\n";
		cout << "\t\t Enter your choice:- ";
		x=getch();
		while((!(x>='1' && x<='7')))
		{

        cout<<"\n \t\t Please Enter Number Between 1 , 8 :- \n";
		 x=getch();
		}
		system("cls");
		switch (x){
		case '1': b.input(); b.trip_place(); b.day(); b.seat(); b.airline(); b.classs(); break;
		case '2':display(); break;
		case '3':search();break;
		case '4':modify();break;
        case '5':deletea();break;
        case '6':About();break;
        case '7':exitNow();break;


		}
		cout << "\n\t\t\t\t*************************************************\n";
		cout << "\t\t\t\t If You Want To Return To Main Menu Enter y or Y \n";
        cout << "\t\t\t\t*************************************************\n\t\t\t\t\t\t\t:-  ";
		cin >> ch;
		system("cls");
	}
	while (ch == 'y' || ch == 'Y');
	}

int main(){

	reservation b; int _1or_2;
	b.intro();

        cout<<"\n";
		cout << "\t    ===================================\n";
		cout << "\t\t     Travel Agency\n";
		cout << "\t    ===================================\n";
		menu();
        system("cls");
		cout << endl;
	system("pause");
	return 0;

}
