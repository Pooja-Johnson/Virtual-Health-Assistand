#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>

class hstaff
    {
      public:
	       char pname[20];
	       int age;
	       char pbgroup[5];
	       int pno;
	       char phoneno[13];
	       char symptoms[30];
		hstaff()
		 {
		    strcpy(pname,"NULL");
		    age=0;
		    strcpy(pbgroup,"NULL");
		    pno=0;
		    strcpy(phoneno,"NULL");
		    strcpy(symptoms,"NULL");
		 }
		  void add()
		     {
			cout<<"Enter Patient's name ";
			gets(pname);
			cout<<"\nEnter Patient's age ";
			cin>>age;
			cout<<"\nEnter Patient's blood group ";
			gets(pbgroup);
			cout<<"\nEnter Patient no. ";
			cin>>phoneno;
			cout<<"\nEnter Phone number ";
			gets(phoneno);
		     }
		   void put()
		    {
		       cout<<"Patient's Name "<<pname;
		       cout<<"\nPatient's Age "<<age;
		       cout<<"\nBlood Group "<<pbgroup;
		       cout<<"\nPatient no. "<<pno;
		       cout<<"\nPhone number "<<phoneno;
		    }
		int returnpno()
		  {
		    return(pno);
		  }
		  void psymptoms()
			{
		       //ifstream fin;
		       //fin.open("ff.dat",ios::binary|ios::in);
		       //while(fin.read(char*)&p,sizeof(p)))
			int page;
			cout<<"Enter your age ";
			cin>>page;
			   if(page<12)
			    {
			     cout<<"Dr.Ravi";
			     cout<<"Paediatrician";
			    }
			   else
			    {
				cout<<"\n\n Enter your symptoms";
				cin>>symptoms;
				if(strcmpi(symptoms,"nausea")==0)
				  {
				  cout<<"\n\nDr.Pankaj ";
				  cout<<"\n\n General Physician";
				  }
				else if(strcmpi(symptoms,"fever")==0)
				  {
				  cout<<"\n\nDr.Raghuram ";
				  cout<<"\n\n General Physician";
				  }
				else if(strcmpi(symptoms,"Redness")==0)
				  {
				  cout<<"\n\nDr.Gupta";
				  cout<<"\n\nDermatologist";
				  }
				else if(strcmpi(symptoms,"    ")==0)
				 {
				 cout<<"\n\nDr.Neerav";
				 cout<<"\n\n";
				 }
				else if(strcmpi(symptoms,"    ")==0)
				{
				cout<<"\n\nDr.Induja";
				cout<<"\n\n";
				}

				else if(strcmpi(symptoms,"    ")==0)
				{
				cout<<"\n\nDr.Elizabeth";
				cout<<"\n\n";
				}
				else if(strcmpi(symptoms,"    ")==0)
				{
				cout<<"\n\nDr.Jakes";
				cout<<"\n\n";
				}
				else
				{
				cout<<"\n\nDr.Tanvi";
				cout<<"\n\nGeneral Physician";
				}
			    }

			   cout<<"\n\nWould you like to make an appointment with the doctor:";
			   cout<<"\n\n1.YES";
			   cout<<"\n\n2.NO";
			   int ch;
			   cout<<"\n\nEnter choice:";
			   cin>>ch;
			   switch(ch)
			   {
			     case 1:cout<<"\n\nYour appointment with the doctor is fixed.";
				    cout<<"\n\nDate:29/12/2020";
				    cout<<"\n\nTime: 05:00pm";
				    cout<<"\n\nAs we are all going through a tough time we request you to follow social norms and other hospital regulations while visiting the hospital";
				    break;
			     case 2:cout<<"Thank you for using our program!!";
				    getch();
				    exit(0);
			     default:cout<<"Please enter valid choice";
				     getch();
				     exit(0);

			   }
		   }

		}p;
	void insert()
	    {
	      int n,i;
	      ofstream fout;
	      fout.open("ff.dat",ios::out|ios::binary|ios::app);
	      cout<<"Enter the number of patient's data to be entered ";
	      cin>>n;
	      for(i=0;i<n;i++)
		      {
			  p.add();
			  fout.write((char*)&p,sizeof(p));
		      }
	      fout.close();
	    }

 void edit()
   {
     ifstream fin;
     fin.open("ff.dat",ios::in|ios::binary);
     ofstream fout;
     fout.open("temp.dat",ios::in|ios::binary|ios::out|ios::app);
     /*if(out.fail())
     {cout<<"\n\nPATIENT RECORD NOT FOUND";
      getch();
      return();
     } */
   int flag=0;
   int e;
   cout<<"\nEnter patient no. to be edited:";
   cin>>e;
   while(fin.read((char*)&p,sizeof(p)))
	{
	  if(p.returnpno()==e)
	    {
	      flag=1;
	      clrscr();
	      cout<<"\nPLEASE CHANGE THE PATIENT DETAILS:";
	      p.add();
	    }
	  fout.write((char*)&p,sizeof(p));

	}
     fin.close();
     fout.close();
      if(flag==0)
      {
	cout<<"\n\nPATIENT RECORD NOT FOUND!!";
	getch();
	exit(0);
      }
   remove("ff.dat");
   rename("temp","ff.dat");
   clrscr();
   cout<<"\n\nPATIENT RECORD EDITED.";
 }

 void search()
 {
   int flag=0;
   int r;
   cout<<"\n Enter patient no to be searched ";
   cin>>r;
   ifstream fin;
   fin.open("ff.dat",ios::in|ios::binary);
   while(fin.read((char*)&p,sizeof(p)))
    {
      if(p.returnpno()==r)
	{
	  flag=1;
	  p.put();
	  break;
	}
	}
	if(flag==0)
	cout<<"\n\nEnter correct data";
  }
  void display()
  {
	ifstream fin;
	fin.open("ff.dat",ios::in|ios::binary);
	while(fin.read((char*)&p,sizeof(p)))
	    {  p.put();
	    }
	fin.close();
  }
  void pat()
   {
    int flag=0;
    int r;
    cout<<"\n Enter patient no to be searched ";
    cin>>r;
    ifstream fin;
    fin.open("ff.dat",ios::in|ios::binary);
    while(fin.read((char*)&p,sizeof(p)))
      {
       if(p.returnpno()==r)
	 {
	  flag=1;
	  p.put();

	  p.psymptoms();
	  break;
	 }
      }
       if(flag==0)
	{
	cout<<"Patient not found";
	exit(0);
	}
   }

 void admin()
  {
    char pass[20];
    int n;
    cout<<"Enter the Password";
    cin>>pass;
    if(strcmp(pass,"admin@123")==0)
    {
      cout<<"1.Add your Account\n2.Edit your Account\n3.View your Account\n4.Search";
      cout<<"\nEnter your Choice";
      cin>>n;
      switch(n)
      {
	case 1:insert();
	       break;
	case 2:edit();
	       break;
	case 3:display();
	       break;
	case 4:search();
	       break;
        default:cout<<"select any one from the above options";break;
     }
    }
    else
    cout<<"WRONG PASSWORD.PLEASE ENTER THE CORRECT PASSWORD";
  }

  void main()
   {
   int choice;
   clrscr();
   cout<<"Welcome to the program";
   cout<<"\nWho are you?";
   cout<<"\n1.Patient";
   cout<<"\n2.Hospital staff";
   cout<<"\n3.Exit";
   cin>>choice;
   switch(choice)
	{
	case 1:pat();
	       break;
	case 2:admin();
	       break;
	case 3:exit(0);
	default:cout<<"Please enter correct option ";
		exit(0);
	}
   getch();
   }