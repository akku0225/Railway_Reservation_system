// #include <string>
// #include<cstdio>
// #include <iostream>
// #include <time.h>
// #include <unistd.h>
// #include <ctime>
#include<bits/stdc++.h>
#define ll  long int
using namespace std;
 ll reg_no=202100;
 string waitkey;
struct list_pas{
 string name;
 string notice;
  ll aadhaar_no;
  ll phone_no;
 int age;
 string gender;
 int seat_no;
 int coach_no;
 int reg_no;
 string status;
 struct list_pas *next;//next
};

void create_ticket(struct list_pas **list_fornt,struct list_pas **list_rare,string fname,int age, ll ad_no, ll ph_no,int seat_no,int co_no,int reg_no,string gender,string status)
{
   struct list_pas *temp;
   temp=(struct list_pas *)malloc(sizeof(struct list_pas)); 
   temp->name=fname;
   temp->age=age;
   temp->aadhaar_no=ad_no;
   temp->phone_no=ph_no;
   temp->seat_no=seat_no;
   temp->coach_no=co_no;
   temp->reg_no=reg_no;
   temp->gender=gender;
   temp->status=status;
   temp->notice=" ";
   if(*list_fornt == NULL && *list_rare == NULL)
   {
       *list_rare = temp;
       *list_fornt = *list_rare;
   }
   else
   {
       (*list_rare)->next = temp;
       *list_rare = temp;
        (*list_rare)->next = NULL;
      
   }
  
}
void display_list(struct list_pas **list_fornt,struct list_pas **waiting_list_front)
{
   system("clear");
   struct list_pas *temp,*temp1;
   temp = *list_fornt;
   temp1 = *waiting_list_front;
   cout<<"\n\n-----------------------------------------------------------------------------\n";
   cout<<"\t\t\t\tRESERVED TICKETS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   cout<<"\t  NAME\t\t\tAGE\t\tGENDER\t\tPHONE NO.\t\t\tREG_NO\t\tSTATUS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   while(temp != NULL)
   {
       cout<<"\t"<<temp->name;
       cout<<"\t\t"<<temp->age;
       cout<<"\t\t"<<temp->gender;
       cout<<"\t\t"<<temp->phone_no;
       cout<<"\t\t\t"<<temp->reg_no;
       cout<<"\t\t"<<temp->status;
       cout<<endl;
       temp = temp->next;
   }
   cout<<"\n\n-----------------------------------------------------------------------------\n";
   cout<<"\t\t\t\tWAITING LIST\n";
   cout<<"-----------------------------------------------------------------------------\n";
   cout<<"\t  NAME\t\tAGE\t\tGENDER\t\tPHONE NO.\t\tREG_NO\t\tSTATUS\n";
   cout<<"-----------------------------------------------------------------------------\n";
   while(temp1 != NULL)
   {
       cout<<"\t"<<temp1->name;
       cout<<"\t\t"<<temp1->age;
       cout<<"\t\t"<<temp1->gender;
       cout<<"\t\t"<<temp1->phone_no;
       cout<<"\t\t\t"<<temp1->reg_no;
       cout<<"\t\t"<<temp1->status;
       cout<<endl;
       temp1 = temp1->next;
   }
   cout<<"\n\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
   cin>>waitkey;
   system("clear");
}
 
 
void Cancel_Ticket(struct list_pas** list_fornt,struct list_pas** list_rare,int reg_num,struct list_pas** waiting_list_front,struct list_pas** waiting_list_rare)
{
   struct list_pas *temp = NULL;
   temp = *list_fornt;
   while(temp != *list_rare)
   {
       if(temp->reg_no == reg_num)
       {
           break;
       }
       temp = temp->next;
   }
 
   temp->status="CANCELLED";
    cout<<"\t\tNAME : "<<temp->name<<"\t\t"<<"CONTACT : "<<temp->phone_no<<endl;
    cout<<"\n\t\t---------------------------------------------------------------\n";
    cout<<"\t\tYOUR TICKET HAS BEEN CANCELLED"<<endl;
    cout<<"\n\t\t---------------------------------------------------------------\n";
    cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
    cin>>waitkey;
    //updation in status of waiting list
   (*list_rare)->next=(*waiting_list_front);
   (*list_rare)=(*waiting_list_front);
   (*waiting_list_front)=(*waiting_list_front)->next;
    (*list_rare)->next=NULL;
   (*list_rare)->coach_no=temp->coach_no;
   (*list_rare)->seat_no=temp->seat_no;
   (*list_rare)->status="CONFIRMED";
 
 
}
 
void notice(struct list_pas** list_fornt,struct list_pas** list_rare,string note1,struct list_pas** waiting_list_front,struct list_pas** waiting_list_rare){
    //cancelled all due to notice
 struct list_pas *temp = NULL;
   temp = *list_fornt;
   while(temp != NULL)
   {   temp->status="CANCELLED";
       temp->notice=note1;
    
       temp = temp->next;
   }
 if(*waiting_list_front==NULL){
   temp = *waiting_list_front;
   while(temp != NULL)
   {   temp->status="CANCELLED";
       temp->notice=note1;
    
       temp = temp->next;
   }
 }
 
}
void display_ticket(struct list_pas** list_fornt,struct list_pas** list_rare,struct list_pas** waiting_list_front,struct list_pas** waiting_list_rare,int reg_no)
{
  int t,id=0;
    struct list_pas *temp = NULL,*temp1 = NULL;
    temp = *list_fornt;
    temp1 = *waiting_list_front;
    while(temp != NULL)
    {//see in confirmed
        if(temp->reg_no == reg_no)
        {
          id = 1;
            break;
        }
        temp = temp->next;
    }
    if(id == 0)
    {//see in waiting
      while(temp1 != NULL)
      {
        if(temp1->reg_no == reg_no)
        {
          id = 2;
          break; 
        } 
        temp1 = temp1->next;
      }
    }
    if(id == 0)
    { //didnt find in both
      cout<<"\n\t\tREGISTRATION NUMBER NOT FOUND !"<<endl;
      cout<<"\n\t\t--------------------------------------------------------\n";
      cout<<"\t\tPLEASE ENTER ANY NUMBER TO CONTINUE : ";
      cin>>waitkey;
       
    }
    else if(id == 1)
    {
      id = 0;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      if(temp->notice != " ")
      {
        cout<<"!!!\t\tNOTICE : "<<temp->notice<<"\t\t!!!"<<endl<<endl;
      }
      cout<<"NAME : "<<temp->name<<"\t\t\t"<<"CONTACT : "<<temp->phone_no<<endl<<endl;
      cout<<"AGE : "<<temp->age<<"\t\t"<<"REG_NO : "<<temp->reg_no<<"\t\t"<<"GENDER : "<<temp->gender<<endl<<endl;
      cout<<"AADHAAR_NO : "<<temp->aadhaar_no<<endl<<endl;
      cout<<"SEAT NUMBER : "<<temp->seat_no<<"\t\t"<<"COACH_NO : "<<temp->coach_no<<endl<<endl;
      cout<<"CURRENT STATUS : "<<temp->status<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      cout<<"\n\n\nENTER ANY NUMBER TO CONTINUE : ";
      cin>>t;
    }
    else if(id == 2)
    {
      id = 0;
      cout<<"---------------------------------------------------------------------------------"<<endl;
       cout<<" "<<temp1->notice<<endl;
      cout<<"NAME : "<<temp1->name<<"\t\t\t"<<"CONTACT : "<<temp1->phone_no<<endl<<endl;
      cout<<"AGE : "<<temp1->age<<"\t\t"<<"REG_NO : "<<temp1->reg_no<<"\t\t"<<"GENDER : "<<temp1->gender<<endl<<endl;
    // cout<<"Booking Date : "<<temp->time<<"\t\t"<<endl<<endl;
      cout<<"AADHAAR_NO : "<<temp1->aadhaar_no<<endl<<endl;
      cout<<"SEAT_NUMBER : NA\t\tCOACH_NO : NA"<<temp1->coach_no<<endl<<endl;
      cout<<"CURRENT STATUS : "<<temp1->status<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      cout<<"\n\n\nENTER ANY NUMBER TO CONTINUE : ";
      cin>>t;
    }
}

/////////////////////////////////////////////////MAIN FUN////////////////////////////////////////////////////////////////////
int main()
{
   char ch='-1';
   int data,Admin_count=0,choice_admin=-1,choice_user=-1;
   string pass = "",password = "abc",gender,note;
   ll code=8765;
   struct list_pas *list_fornt = NULL;
   struct list_pas *list_rare = NULL;
   struct list_pas *waiting_list_front=NULL;
   struct list_pas *waiting_list_rare=NULL;
   string fname,lname;
    ll ad_no,ph_no,gen;
   int age,co_no=1,seat_no=0,max_num_nor=0,max_num_citizen=0;
  
   system("clear");

   cout<<"\n\n\n\n\n\n\n\t\t-----------------------------------------------------\n\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
   cout<<"\t\t-----------------------------------------------------\n\n";
   cout<<"\t\t\t\t** RAILWAY RESERVATION SYSTEM **\n\n";
   cout<<"\t\t-----------------------------------------------------\n\t\t|||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
   cout<<"\t\t-----------------------------------------------------\n\n";
   cout<<"\t\t\t\t\t  PRESS ENTER  \n\n";

  getchar();
    
   while(ch!='5')
   {
       entry:  // for goto
       system("clear");
       cout<<"\n\n\n\n\n\n\t\t---------------------------------------------------\n";
       cout<<"\t\t< = = = = = : FACILITIES AVAILABLE : = = = = = =  > ";
       cout<<"\n\t\t---------------------------------------------------\n";
       cout<<"\t\t\t\t1. ADMIN LOGIN.\n\t\t\t\t2. BOOK A TICKET.\n\t\t\t\t3. VIEW TICKET STATUS.\n\t\t\t\t4. CANCEL A TICKET.\n\t\t\t\t5. EXIT\n";
       cout<<"\t\t---------------------------------------------------\n";
       cout<<"\t\t\tPLEASE ENTER A NUMBER : ";
       cin>>ch;
       switch(ch)
       {
       case '1':
           system("clear");
           while(Admin_count <= 2)
           {
               cout<<"\n\n\n\n\t\t-----------------------------------------------\n";
               cout<<"\t\t\t\t||||||||||||||**|||||||||||||||\n";
               cout<<"\t\t-----------------------------------------------\n\n";
               cout<<"\t\t\tPLEASE ENTER PASSWORD : ";
               cin>>pass;
               cout<<"\n\t\t-----------------------------------------------\n";
               cout<<"\t\t\t\t||||||||||||||**|||||||||||||||\n";
               cout<<"\t\t-----------------------------------------------\n";
               if(pass == password)
               {
                   cout<<"\n\t\t\t\t*ADMIN ACCESS GRANTED!\n"<<endl;
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\tPLEASE ENTER ANY KEY TO CONTINUE : ";
                   cin>>waitkey;
                   system("clear");
                   choice_admin=0;
                   while(choice_admin!=5)
                   {   admin_menu:
                       cout<<"\n\n\n\n\n\t\t-------------------------------------------------\n";
                       cout<<"\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\t\tOPTIONS AVAILABLE\n";
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\t1. DISPLAY ALL BOOKINGS."<<endl;
                       cout<<"\t\t\t2. CREATE A NOTICE."<<endl;
                       //cout<<"\t\t\t3. MAIN MENU"<<endl;
                       cout <<"\t\t\t3. CHANGE PASSWORD" << endl;
                       cout <<"\t\t\t4. MAIN MENU" << endl;
                       cout<<"\t\t-------------------------------------------------\n";
                       cout<<"\t\t\tENTER YOUR CHOICE : ";
                       cin>>choice_admin;
                       string local;
                       switch(choice_admin)
                       {
                       case 1:
                           display_list(&list_fornt,&waiting_list_front);
                           break;
                       case 2:
                           cout<<"\t\t\tEnter the notice to be displayed as a reason of cancellation : ";
                           cin>>note;
                           notice(&list_fornt, &list_rare,note,&waiting_list_front, &waiting_list_rare);
                           break;
                       case 3: 
                           cout <<"\t\t\tConfirm Your Old Password"<<endl;
                           cin>>local; 
                            if(local==password)
                            {
                                cout << "\t\t\tCONFIRM YOUR SPECIAL CODE" << endl;
                                cin >> code;
                                if(code==8765)
                                {cout << "\t\t\tENTER YOUR NEW PASSWORD" << endl;
                                  cin>>local;
                                  password=local;
                                  cout << "\t\t\tYOUR PASSWORD HAS BEEN RESET" << endl;
                                }
                               
                                cout << "\t\t\tPRESS 0 FOR MAIN MENU/1 FOR ADMIN MENU" << endl;
                                char c;
                                cin >> c;
                                if(c=='a')
                                 goto admin_menu;
                                else goto entry;
                            }
                           else
                           {
                               cout << "\n\t\t\t    * ACCESS DENIED *\n"
                                    << endl;
                               cout << "\t\t-----------------------------------------------\n";
                               cout << "\t\t-----------------------------------------------\n";
                               cout << "\t\tPLEASE ENTER ANY KEY TO CONTINUE : ";
                               cin >> waitkey;
                               system("clear");
                               goto entry;
                               //Sleep(2000);
                               
                           }

                           break;
                       case 4 : 
                          goto entry;
                           break;
                       default:
                           break;
                       }
                   }
               }
               else
               {
                   cout<<"\n\t\t\t    * ACCESS DENIED *\n"<<endl;
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\t-----------------------------------------------\n";
                   cout<<"\t\tPLEASE ENTER ANY KEY TO CONTINUE : ";
                   cin>>waitkey;
                   //Sleep(2000);
                  
                   Admin_count++;
                   system("clear");
                   //goto entry;
               }
           }
          if(Admin_count == 3)
          {
               Admin_count=0;
               goto entry;
           }
           break;
       case '2':
           system("clear");
           cout<<"\n\n\n\n\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t*******************************************************\n";
           cout<<"\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t\t\t : ENTER DETAILS : \n";
           cout<<"\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t NAME (FIRST_LAST) : ";
           cin>>fname;
           //cout<<"\n\t\t\tLAST NAME : ";
           //cin>>lname;
           cout<<"\n\t\t\tGENDER : 1. MALE\n\t\t\t\t\t 2. FEMALE\n\t\t\t\t\t 3. OTHER\n\t\t\tENTER A NUMBER : ";
           cin>>gen;
           if(gen==1)
               gender="MALE";
           else if(gen==2)
               gender="FEMALE";
           else
               gender="OTHERS";
           cout<<"\n\t\t\tAGE : ";
           cin>>age;
           if(age>=60)
           {
               max_num_citizen++;
           }
           else
           {
               max_num_nor++;
           }
           cout<<"\n\t\t\tADHAAR NUMBER : ";
           cin>>ad_no;
           cout<<"\n\t\t\tPHONE NUMBER : ";
           cin>>ph_no;
          //  cout<<"\n\t\t\tDATE AND TIME : "<<dt<<endl;
           reg_no++;
           if(seat_no<=2 && co_no<=2)
           {
               if(max_num_citizen<=2 && max_num_nor<=2)
               {
                   seat_no++;
                   create_ticket(&list_fornt,&list_rare,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"CONFIRMED");
                   cout<<"\n\t\t-------------------------------------------------------\n";
                   cout<<"\t\t\t\t\tTICKET CONFIRMED!!!!!!";
               }
               else if(max_num_nor>2)
               {
                   if(age<60)
                   {
                       create_ticket(&waiting_list_front,&waiting_list_rare,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"WAITING");
                       cout<<"\n\t\t-------------------------------------------------------\n";
                       cout<<"\t\t\t\t\tTICKET NOT CONFIRMED!!!!!!";
                   }
                   else
                   {
                       seat_no++;
                       create_ticket(&list_fornt,&list_rare,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"CONFIRMED");
                       cout<<"\n\t\t-------------------------------------------------------\n";
                       cout<<"\t\t\t\t\tTICKET CONFIRMED!!!!!!";
                   }
               }
           }
           else
           {
               cout<<"\n\t\t-------------------------------------------------------\n";
               cout<<"\t\t\t\t\tTICKET NOT CONFIRMED!!!!!!";
               create_ticket(&waiting_list_front,&waiting_list_rare,fname,age,ad_no,ph_no,seat_no,co_no,reg_no,gender,"WAITING");
           }
           if(seat_no==2)
           {
               seat_no=0;
               co_no++;
           }
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t\t\tNOTE YOUR TICKET NUMBER : "<<reg_no;
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\n\t\t\t*----DETAILS TAKEN SUCCESSFULLY----*";
           cout<<"\n\t\t-------------------------------------------------------\n";
           cout<<"\t\t*******************************************************\n";
           cout<<"\t\t-------------------------------------------------------\n";
         cout<<"\t\tPLEASE ENTER ANY KEY TO CONTINUE : ";
         int oneone;
         cin>>oneone;
           getchar();
           break;
       case '3':
          system("clear");
          cout<<"\n\n\n\t\t---------------------------------------------------------------";
          cout<<"\n\t\t***************************************************************";
          cout<<"\n\t\t---------------------------------------------------------------";
          cout<<"\n\t\tENTER REGISTRATION NUMBER OF YOUR TICKET : ";
          cin>>reg_no;
          cout<<"\n\t\t---------------------------------------------------------------\n";
          display_ticket(&list_fornt,&list_rare,&waiting_list_front,&waiting_list_rare,reg_no);
          break;
       case '4':
        system("clear");
        cout<<"\n\n\n\t\t---------------------------------------------------------------";
        cout<<"\n\t\t***************************************************************";
        cout<<"\n\t\t---------------------------------------------------------------";
        cout<<"\n\t\tPLEASE ENTER YOUR REGISTRATION NUMBER : ";
        int tic_num;
        cin>>tic_num;
        cout<<"\n\t\t---------------------------------------------------------------\n";
        Cancel_Ticket(&list_fornt,&list_rare, tic_num, &waiting_list_front,&waiting_list_rare);
        break;
      case '5':
        cout<<"\n\t\tTHANK YOU FOR REGISTERING USING OUR PORTAL"<<endl;
        break;
       default:
           system("clear");
           cout<<"\n\n\n\n\n\n\t\t-----------------------------------\n";
           cout<<"\t\t|\t|||||||||||**||||||||||||\t |\n";
           cout<<"\n\t\t (: PLEASE ENTER A VALID NUMBER :)\n\n";
           cout<<"\t\t|\t|||||||||**||||||||||||||||\t |\n";
           cout<<"\t\t-----------------------------------\n";
           cout<<"\t\tENTER ANY KEY TO CONTIUE : ";
           cin>>waitkey; 
            break;
       }
   }
   if(ch != '5')
   {
     goto entry;
   }
}