/*

				              _______  _________            _______   _______
                            |   _   | |    ____|          |   _   | |   _   |
                            |  | |  | |   |____    _____  |  | |  | |  | |  |
                            |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |
                            |   ____| |  |_____           |_____  | |  ___  |
                            |  |      |_______|                 | | | |   | |
                            |__|                                |_| |_|   |_|

	__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
		|																		|
		|	AHMAD QAYYUM FIKRI BIN AHMAD JAZIMIN (200359)	                    |
	    |  	EISYATUL HANNIE BINTI MOHAMMAD RUSHDAN (202785)                     |
   	    |   NURUL AIDA BINTI ZAIROL AKMAR (203732)                              |
   	    |   NIK MUHAMMAD FARHAN BIN OWI SIONG KIAT @ RUSTAM AL (203733)         |
   	    |   AIDIL HARITH ANWAR BIN AZMI (202788)								|
		--------------------------------------------------------------------------------------------------------

		The link that we refer to complete project :

		_____________________________________________________________________________________________
		|	Credit to People us helped us to complete this Project :								|
		|																							|
		|	> PROF MADYA DR SYAMSIAH BT MASHOHOR													|
		|	> https://www.youtube.com/watch?v=nDdKIxnEyh0 (INTRO CONSOLE GAME)						|
		|	> http://cncpp.divilabs.com/2013/12/c-code-for-mario-theme-intro-song.html (SONG)		|
		|	> lAB 6 by AHMAD QAYYUM FIKRI BIN AHMAD JAZIMIN (200359)	 							|
		|	> https://www.youtube.com/watch?v=xDzPmc8yvZY (STUDY MODE - GRAPH THEORY )				|
		|   > https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/ (GRAPH THEORY)		|
		|	> Programming Hub (RightSol Pte. Ltd) Android App (STUDY MODE)							|
		|	> https://www.youtube.com/watch?v=xKlVrwP3G4M (SHOPPING)								|
		|	> https://www.youtube.com/watch?v=KrH1qNVYKO0 (TIC TAC TOE)								|
		|   > https://code-projects.org/fortune-teller-c-source-code/ (C++ SOURCE)					|
		|	> https://www.youtube.com/watch?v=6OSVutwm_Uk&t=966s (ATM SYSTEM)						|
		|___________________________________________________________________________________________|
	__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
*/


//THE LIBRARIES USED BY PEQA.EXE
#include <iostream>							//Used for standard C++ compliler
#include <fstream>							//Used to handle data (wav files)
#include <time.h> 							//Used for time function
#include <cstdlib>							//Used for C standard library
#include <string>							//Used for string
#include <sstream>							//Used for allowing a string object to be treated as a stream
#include <bits/stdc++.h>					//Used for C++ coding
#include <windows.h>						//Used for windows function such as animation and sound
#include <conio.h>							//Used for console output
#include <unistd.h>							//Used for UNIX function such as sleep(2)
#include <tr1/functional> 					//Used for hashing data
#include <tchar.h>							//Used for console title
#include <strsafe.h>						//Used for console title
using namespace std;

//GLOBAL DECLARATION TO MAKE IT EASIER FOR ALL FUNCTION TO READ
int peqa,option,mode,topic,gtheory;			//Used for integer options
char gtheory2;								//Used for character options
int search(int);							//Used in search function
int display(); 								//Used for prompting data
int i,temp,j,k,p,q, array_Sort; 			//Used in Study Mode (Global Declaration)
string check(int);       					//Used for checking quantity for admin-customer (shopping)

//------------------------------START PROGRAMME-----------------------------------//
//------------------------------ANIMATION START-----------------------------------//

//REFERENCE : https://www.youtube.com/watch?v=nDdKIxnEyh0
bool gaming1;
bool gaming2=false;
int gaming3;

//THIS FUNCTION IS TO MAKE THE CMD.EXE FULSCREEN FOR BETTER USER EXPERIENCE
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void music()
{
	 char audiofile_char[50]="PE-QA.wav";
  string audiofile_str;
  fstream fp;
  
  fp.open(audiofile_char, ios::in);
    if (fp != NULL)
    {
      /* open function doesn't work with a variable of string type and PlaySound function doesn't work with char array hence first we used char array and here we are converting it to a string. so that we can use it in PlaySound function */ 
      string audiofile_str =audiofile_char;  
      
  /* PlaySound function is used to play a sound specified by the given file name. */
  /* SND_SYNC : play sound synchronously */
  /* .c_str() function is used to return a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object. */
  PlaySound(audiofile_str.c_str(), NULL, SND_FILENAME||SND_ASYNC||SND_LOOP);
  }

  fp.close();
}

//THIS FUNCTION IS USED FOR COORDINATION
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
	 COORD coord;
	 coord.X = x;
	 coord.Y = y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//THIS FUNCTION IS USED FOR COORDINATION
class gotoxyclass{
protected:
    void gotoxy(int x, int y){
        COORD cord;// creating a object of COORD class
        cord.X = x;// initializing value
        cord.Y = y;// initializing value
        HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
        //for exception, which is (-1,-20);
        if (!SetConsoleCursorPosition(hc, cord)){
            cout << "out of cordinate";
        }
    }
};

//This function is used for animation coordination
class animationenter :public gotoxyclass{
private:
    void count100(){
        gotoxy(34, 12);
        for (int i = 1; i <= 6; i++){
            gotoxy(34, 12);
            cout << "|  |  |  |  |   ";
            Sleep(100);
            gotoxy(34, 12);
            cout << "/  /  /  /  /     ";
            Sleep(100);
            gotoxy(34, 12);
            cout << "-- -- -- -- --";
            Sleep(100);
            gotoxy(34, 12);
            cout << "\\ \\ \\ \\  \\    ";
            Sleep(100);
        }
        gotoxy(34, 12);
        cout << " PE-QA.exe \a" << endl;
        Sleep(1000);
        system("cls");
        gotoxy(34, 11);
        cout << " PE-QA.exe \a" << endl;
        gotoxy(35, 12);
        cout << "ECC3112 : ENGINEERING ALGORITHM\a";
        Sleep(400);
        system("cls");
        gotoxy(34, 11);
        cout << " PE-QA.exe \a" << endl;
        gotoxy(35, 12);
        cout << "ECC3112 : ENGINEERING ALGORITHM\a";
        gotoxy(35, 13);
        cout << "UNIVERSITI PUTRA MALAYSIA\a\a\a";
        Sleep(1000);
        system("cls");

    }
public:
    void mainenter(){
        count100();
    }
};

//THIS FUNCTION IS USED FOR BOOTING UP LOADING INTRO
void load()
{
	
	int timer =5+ rand()%20;
    int row,col,r,c,q;
 	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\nBOOTING UP..." <<endl;
    for(r=1;r<=timer;r++)
	{
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);
	}
    Sleep(1500);
    system("cls");
}

//------------------------------ANIMATION END-----------------------------------//

//REAL-TIME CLOCK
void realclock()
{    	

	int sec_prev=0;
	while(sec_prev!=5&&sec_prev!=10&&sec_prev!=15&&sec_prev!=20&&sec_prev!=25&&sec_prev!=30&&sec_prev!=35&&sec_prev!=40&&sec_prev!=45&&sec_prev!=50&&sec_prev!=55)
	{
	    int seconds, minutes, hours;
	    string str;
	  
	    //storing total seconds
	    time_t total_seconds=time(0);
	  
	    //getting values of seconds, minutes and hours
	    struct tm* ct=localtime(&total_seconds);
	  
	    seconds=ct->tm_sec;
	    minutes=ct->tm_min;
	    hours=ct->tm_hour;
	    
	    //converting it into 12 hour format
	    if(hours>=12)
	
	      str="PM";
	    else
	   
	      str="AM";
	    hours=hours>12?hours-12:hours;
	    
	    
	    //printing the result
	    if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
	    {
	      system("CLS");
	      cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str <<endl;
	    }
	    
	    sec_prev=seconds;
	}
}

//USE TO DISPLAY GAMING MAIN MENU AT THE STARTING
void menu()
{
    char c='0';
    int wybrane=2;
    gaming2=false;
    system("CLS");
    while ((gaming1==false) && (gaming2==false))
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    gotoxy(55,14);
    cout<<char(24);
    gotoxy(55,15);
    cout<<"W";

    gotoxy(55,28);
    cout<<char(25);
    gotoxy(55,27);
    cout<<"S";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(52,19);
  	cout<<" CLOCK "; 
    gotoxy(52,21); 
	cout<<" START ";
    gotoxy(52,23);
    cout<<"AUTHORS";

    while (c!=char(13))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        gotoxy(49,19+wybrane);
        cout<<"->";
        gotoxy(60,19+wybrane);
        cout<<"<-";
        gotoxy(0,0);
        c=getch();
        gotoxy(49,19+wybrane);
        cout<<"  ";
        gotoxy(60,19+wybrane);
        cout<<"  ";
        if (c=='s')
        {
            if (wybrane<4)
            {
                wybrane+=2;
            }
        }
        if (c=='w')
        {
            if (wybrane>0)
            {
                wybrane-=2;
            }
        }
    }
    if (wybrane==0)
    {
        gotoxy(23,14);
        realclock();
        gaming1=true;
    }
    if (wybrane==2)
    {	 gaming1=true;
	    }
    if (wybrane==4)
    {
        system("CLS");
    	gotoxy(23,14);
    	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    	cout<<">>>----Project Implemented By-----<<<"<<endl;
	    gotoxy(23,15);
	   	cout<<"AHMAD QAYYUM FIKRI BIN AHMAD JAZIMIN (200359)"<<endl<<endl;
	   	gotoxy(23,16);
	   	cout<<"EISYATUL HANNIE BINTI MOHAMMAD RUSHDAN (202785)"<<endl<<endl;
	   	gotoxy(23,17);
	   	cout<<"NURUL AIDA BINTI ZAIROL AKMAR (203732)"<<endl<<endl;
	   	gotoxy(23,18);
	   	cout<<"NIK MUHAMMAD FARHAN BIN OWI SIONG KIAT @ RUSTAM AL (203733)"<<endl<<endl;
	   	gotoxy(23,19);
	   	cout<<"AIDIL HARITH ANWAR BIN AZMI (202788)"<<endl<<endl;
	   	cout << endl;
		system("pause");
    }
    wybrane=2;
    c=' ';
    system("CLS");
    }
}
//------------------------------INTRO END-----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------ADMIN-CUSTOMER DATABASE MANAGEMENT (SHOPPING) START ----------------------------------////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------START ANIMATION----------------------
void animation()
{
	for (int i=45; i>=1; i--)
	{
		Sleep(30);
		gotoxy(1,i);
	}
	for (int i=1; i<=20; i++)
	{
		Sleep(40);
		gotoxy(1,i);
	}
}
//-------------------------------------------END ANIMATON------------------------------------------


//------------------------------------------------QUEUE FUNCTION------------------------------------------
//DATA STRUCTURE OF SHOPPING
struct Shopping
{
	string cname;
	Shopping *link;
};

Shopping *front = NULL;
Shopping *rear = NULL;

//FUNCTION TO CHECK IF QUEUE IS EMPTY OR NOT
bool isempty()
{
	if(front == NULL && rear == NULL)
		return true;
	else
		return false;
}

//FUNCTION TO ENTER ELEMENTS IN QUEUE
void enqueue ( string name )
{
	Shopping *ptr = new Shopping();
	ptr->cname= name;
	ptr->link = NULL;
	
	//If inserting the first element
	if( front == NULL )
	{
	 	front = ptr;
	 	rear = ptr;
	}
	else
	{
	 	rear ->link = ptr;
	 	rear = ptr;
	}
}

//FUNCTION TO DELETE/REMOVE ELEMENT FROM QUEUE
void dequeue ( )
{
	if( isempty() )
		cout<<"\t\t\t\t\t\t\t\tQueue is empty\n";
	else
	 
	//only one element/Item in queue.
	if( front == rear)
	{
	 	free(front);
	 	front = rear = NULL;
	}
	else
	{
		Shopping *ptr = front;
		front = front->link;
		free(ptr);
	}
}

//FUNCTION TO SHOW THE ELEMENT AT FRONT
void showfront( )
{
	if( isempty())
		cout<<"\t\t\t\t\t\t\t\tQueue is empty\n";
 	else
		cout<<"\t\t\t\t\t\t\t\telement at front is:"<<front->cname<<"\n";
}

//FUNCTION TO DISPLAY QUEUE
void displayQueue()
{  
	if (isempty())
		cout<<"\t\t\t\t\t\t\t\tQueue is empty\n";
	else
	{
		Shopping *ptr = front;
	  while( ptr !=NULL)
	{
		cout<<"\t"<<ptr->cname<<"\t  "<<endl;
		ptr= ptr->link;
  }
 }
}
//-----------------------------------------END QUEUE FUNCTION---------------------------------


//----------------------------------------------STACKS FUNCTION---------------------------------------
//STRUCTURE OF TROLLEY 
struct Trolley
{ 
	int data; 
	Trolley* link; 
};
    
struct Trolley* top; 
 
//INSERT NEW DATA
void push(int data) 
{  
	struct Trolley* temp; 
	temp = new Trolley(); 

	if (!temp) { 
		cout << "\n\t\t\t\t\t\t\t\tHeap Overflow"; 
		exit(1); 
	} 

	temp->data = data; 
	temp->link = top; 

	top = temp; 
} 
 
//CHECK WHETHER ITS EMPTY OR NOT
int isEmpty() 
{ 
	return top == NULL; 
} 

//CHECK WHETHER ITS EMPTY OR NOT
int peek() 
{ 
	 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 

//DELETE DATA
void bpop() 
{ 
	struct Trolley* temp; 

	
	if (top == NULL) { 
		cout << "\n\t\t\t\t\t\t\t\tStack Underflow" << endl; 
		exit(1); 
	} 
	else { 
		
		temp = top; 
		top = top->link;  
		temp->link = NULL; 
		
		// release memory of top Item 
		free(temp); 
		
	}
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\tYour Trolli No is :"<<top->data<<endl; 
	cout<<"\t\t\t\t\t\t\t\t                  ___"<<endl;
    cout<<"\t\t\t\t\t\t\t\t                 /  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t  ______________/   --"<<endl;
    cout<<"\t\t\t\t\t\t\t\t |___/__ /___/_|     "<<endl;     
    cout<<"\t\t\t\t\t\t\t\t |__/___/___/__|     "<<endl;     
    cout<<"\t\t\t\t\t\t\t\t |_/___/___/___|     "<<endl;     
    cout<<"\t\t\t\t\t\t\t\t    _______/         "<<endl;
    cout<<"\t\t\t\t\t\t\t\t     O   O           "<<endl;


} 

//DISPLAY DATA
void bdisplay() 
{ 
	struct Trolley* temp; 

	 
	if (top == NULL) { 
		cout << "\n\t\t\t\t\t\t\t\tStack Underflow"; 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL){ 
	cout << temp->data << " ";  
			temp = temp->link; 
		} 
	} 
} 
//---------------------------------------------END STACK FUNCTION--------------------------------

//THE STRUCTURE OF ITEM
struct Item
{
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct Item* next;
};

struct Item *head=NULL;

//INSERT NEW ITEM
void bag()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	int id,quant;           //  quant    for quantity
	string name;
	double new_price;            //  new_price for price
	struct Item *t=new Item;
	struct Item *p=head;

	cout<<"\t\t\t\t\t\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\t\t\t\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\t\t\t\t\t\tEnter product price:-";
	cin>>new_price;
	t->prePrice=new_price;
	cout<<"\t\t\t\t\t\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	else
	{
		while(p->next!=NULL)
    {
		p=p->next;
                        }
        p->next=t;
        t->next=NULL;
		
	}	
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tThis product is Inserted!\n\n\n";
    Sleep (3000);
    system("CLS");
	}

	//For search item in list
	int search(int id)                    
 	{
 	int count=1;
 	struct Item *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
	}

//DELETE PRODUCT
void delPro()
{
	system("cls");
	display();
	int id;
	struct Item *cur=head;
	struct Item *new_price=head;
	
	cout<<"\n\n\t\t\t\t\t\t\t\tEnter ID to delete that product:\n\n";
	cin>>id;
	
	if (head == NULL)
	{
		system("cls");
    	cout<<"\t\t\t\t\t\t\t\tList is empty"<<endl;
	}
	
	int pos=0;							// Position is set to 0
	int count=display();				// To load the number of items
	pos=search(id);						// To check weather desire Item is exist or not
	if(pos<=count){
	
	while(cur->ID!=id){					// To delete middle area products
		new_price=cur;
		cur=cur->next;
	}
	
		new_price->next=cur->next;
		system("cls");
	//Prompt "is deleted" after the item deleted	
	cout<<"\n\t\t\t\t\t\t\t\t<<item is deleted>>\n";
	}
	
	//If no item, it will print out not found
	else{
		cout<<"\n\t\t\t\t\t\t\t\t<<<Not found>>\n\n";
	}
}

//EDIT PRODUCT
void modify()
	{
		int id;
		double new_price;				//new_price for price
		string new_name;				//new_name for new name
		int nid; int nq;     
		if (head == NULL)
    {
    	system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t\tList is empty"<<endl;
    }
         else
	{    
	    display();
		cout<<"\n\n\t\t\t\t\t\t\t\tEnter ID to modify product Name and its price:\n";
		cin>>id;
		
		struct Item *cur=head;
		int pos=0;
		int count=display();				//To load no of Items
	    pos=search(id);
	    
	    //To check weather desire Item is exist or not
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"\n\t\t\t\t\t\t\t\tOld ID : "<<cur->ID<<endl;
		cout<<"\n\t\t\t\t\t\t\t\tOld Name : "<<cur->proName<<endl;
		cout<<"\n\t\t\t\t\t\t\t\tOld Price : "<<cur->prePrice<<endl;
		cout<<"\n\t\t\t\t\t\t\t\tOld Quantity : "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"\t\t\t\t\t\t\t\tEnter new ID:";
		cin>>nid;
		cur->ID=nid;
		cout<<"\t\t\t\t\t\t\t\tEnter new Name:";
		cin>>new_name;
		cur->proName=new_name;
		cout<<"\t\t\t\t\t\t\t\tEnter new Price:";
		cin>>new_price;
		cur->prePrice=new_price;
	
		cout<<"\t\t\t\t\t\t\t\tEnter new Quantity:";
		cin>>nq;
		cur->quantity=nq;
	}

	    else
    {
		cout<<id<<"\t\t\t\t\t\t\t\t is <<<Not found>>\n\n";
	}
	}
}

//DISPLAY EXISTING PRODUCT
int display()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	int c=0;				//c for count products
	struct Item *p=head;
	cout<<"\t\t\t\t\t\t\t\tExisting products are:\n";
	cout<<"\t\t\t\t\t\t\t\tID\t\tProduct Name\t\tPrice\t\tQuantity\n";
	cout<<"\t\t\t\t\t\t\t\t=================================================================|\n";
	while(p!=NULL)
	{
		cout<<"\t\t\t\t\t\t\t\t"<< p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
		p=p->next;
		c=c+1;
	}
	cout<<"\n\t\t\t\t\t\t\t\tTotal products in our store is : "<<c<<"\n\n\n";
	return c;
    }
    
//CHECK FUNCTION    
string check(int quant)
{    
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

    if(quant<=0)
    	return "out of stock!";
    	
    else
    	return quantity;
}

//BUY FUNCTION
void buy()
{
	system("cls");
	display();					//Display
	string products[20];
	
	//To display sold items
	int pay=0,no,c=0,price,id,i=1;
	
	if(head==NULL)
	{
	cout<<"\n\t\t\t\t\t\t\t\t<<<<There is no items to buy>>>>\n\n";
	system("PAUSE");
	system("CLS");
	}
	
	else
	{
	cout<<"\t\t\t\t\t\t\t\tHow many items you wanna to buy? : ";
	cin>>no; 
	int count=display();			//To store no of Items in c
	while (i<=no)
	{
		struct Item *cur=head;
	    int quant,cho;   			//quant = quantity  and cho = choice
	    
		a:          
	    cout<<"\t\t\t\t\t\t\t\tEnter id of item that you want to buy : ";
	    int id,pos=0;
	    cin>>id;
	    if(id==-1){
		system("cls"); 
		return;	
		}
		
	    pos=search(id);
	
	//If item is available in store    
	if(pos<=count)
	{
	                   
	 	while(cur->ID!=id){
		cur=cur->next;
	 }
	 
	   cout<<"\t\t\t\t\t\t\t\tHow many quantities you want:";
	   cin>>quant;
	   
	   if(cur->quantity<quant)
	   {
	       cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t----The Quantity You Entered is not available---"<<endl;
	       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
	       goto a;  
	   }
	   
	   products[c]=cur->proName;  					//This will conatin the items buy names in array; 
	   c++;   
	   
	   pay=pay+(cur->prePrice*quant);				//Calculate Bill
	   cur->quantity=cur->quantity-quant;			//Change quantity
	   i++;
	 }
	 
	else
	{        
	cout<<"\n\t\t\t\t\t\t\t\t<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	}
	
	}
	
	string customer;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t Enter Your Name :"; cin>>customer;
	enqueue(customer);
	system("cls");
	
	//Show that item you have bought
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYou have bought : ";
	for(int i=0;i<no;i++)
	{              
	cout<<products[i]<<",";
	}
	price=pay*(0.90);							//With 10% discount
	cout<<"\n\n\t\t\t\t\t\t\t\tOriginal price : "<<pay;
	cout<<"\n\t\t\t\t\t\t\t\t with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";
	  }
	    }

//ADMIN SECTION    
void administator()
{
	system("cls");
	int ch;

	do {
		
    //Choice for below message
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t============================================"<<endl;
	cout<<"\t\t\t\t\t\t\t\t|          ADMINISTATOR PORTAL              |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t============================================"<<endl;

	cout<<"\t\t\t\t\t\t\t\t     Enter 1 : ADD A NEW PRODUCT    "<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 2 : DISPLAY ALL PRODUCTS   "<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 3 : EDIT EXISTING PRODUCT"<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 4 : DELETE ANY PRODUCT ITEM"<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 5 : CUSTOMERS LIST "<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 6 : DEQUEUE CUSTOMER"<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Enter 0 : MAIN MENU"<<endl;

	cout<<"\n\t\t\t\t\t\t\t\tEnter Your choice >>>";   
	cin>>ch;
	
	switch(ch){
	
	//Add product	
	case 1:
		bag();
		break;

	//Prompt product
	case 2:
		system("cls");
	    display();
	    break;
	
	//Edit product
	case 3:
		modify();
		system("cls");
		break;
		
	//Delete product
	case 4:
		delPro();
		cout<<"\n\t\t\t\t\t\t\t\t-------Product is Deleted-------\n";	
		break;
	
	//Customers list (queue)
	case 5:
		system("cls");
		cout<<"\t\t\t\t\t\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
		displayQueue();
		break;
		   
	//Customers list (dequeue)
	case 6:
		system("cls");
		cout<<"\t\t\t\t\t\t\t\t|============CUSTOMERS NAMES LIST==============|"<<endl;
		dequeue();
		displayQueue();
		break;
	
	default: system("cls");

	}
}
while(ch!=0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------ADMIN-CUSTOMER DATABASE MANAGEMENT (SHOPPING) END----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------BANK SYSTEM - START----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////

void welcome();
void peqa_bank();

//INTRO
void welcome()
{  
	  cout<<"\n\n\n\n\n\n\n ";
	  system("color A");
	  cout<<"\t\t\t\t\t\t                              ______                  ______     ______                 _______             "<<endl;
	  cout<<"\t\t\t\t\t\t   \\                      /  |          |            |          |      |   |\\      /|   | "<<endl; 
	  cout<<"\t\t\t\t\t\t    \\                    /   |          |            |          |      |   | \\    / |   |       "<<endl; 
	  cout<<"\t\t\t\t\t\t     \\        /\\        /    |          |            |          |      |   |  \\  /  |   |       "<<endl;
	  cout<<"\t\t\t\t\t\t      \\      /  \\      /     |______    |            |          |      |   |   \\/   |   |______   "<<endl;
	  cout<<"\t\t\t\t\t\t       \\    /    \\    /      |          |            |          |      |   |        |   |       "<<endl;
	  cout<<"\t\t\t\t\t\t        \\  /      \\  /       |          |            |          |      |   |        |   |        "<<endl;
	  cout<<"\t\t\t\t\t\t         \\/        \\/        |_______   |________    |______    |______|   |        |   |________  "<<endl;
	  cout<<endl;
	  sleep(3);
	  system("color E");
	  cout<<endl<<endl<<endl<<endl<<endl;
	  cout<<"\t\t\t\t\t\t                             ____________      _______     "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |       |    "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |       |    "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |       |    "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |       |    "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |       |    "<<endl;
	  cout<<"\t\t\t\t\t\t                                   |          |_______|    "<<endl;
	  sleep(2);
	  system("color B");
	  cout<<endl<<endl<<endl<<endl<<endl;
	  peqa_bank();
	  sleep(2); 
	  system("color BC");
	  sleep(1);
	  system("color 7");
}
 
//INTRO
void peqa_bank()
{
  cout<<"\t\t\t\t\t\t      _______   _____         _______   ______      \t         _______             _                                            "<<endl;
  cout<<"\t\t\t\t\t\t      |      | |             |       | |      |     \t        |        |          / \\        |\\      |   |    /                         "<<endl;
  cout<<"\t\t\t\t\t\t      |      | |             |       | |      |     \t        |         |        /   \\       | \\     |   |   /                            "<<endl;
  cout<<"\t\t\t\t\t\t      |      | |             |       | |      |     \t        |        |        /     \\      |  \\    |   |  /                           "<<endl;
  cout<<"\t\t\t\t\t\t      |______| |_____   __   |       | |______|     \t        |  -----         /-------\\     |   \\   |   | /                                 "<<endl;
  cout<<"\t\t\t\t\t\t      |        |             |      || |      |     \t        |        |      /         \\    |    \\  |   |  \\                             "<<endl;
  cout<<"\t\t\t\t\t\t      |        |             |______|| |      |     \t        |         |    /           \\   |     \\ |   |   \\                               "<<endl;
  cout<<"\t\t\t\t\t\t      |        |_____               |  |      |     \t        |_______ |    /             \\  |      \\|   |    \\                                  "<<endl;
}

//FUNCTION USED
class Transaction;
void main_menu(Transaction&);
char trans(Transaction&);
using namespace std;

//DATA STRUCTURE USED BY PE-QA.EXE BANK
class user          
{
	protected:
	char name[25];
	char email[25];
	int age,i;
	char mobi[12];
  
	public:

	//GET USER DATA SUCH AS NAME, EMAIL, AGE, PHONE NUMBER
    void usergetdata()
    { 
    	//Enter name
		cout<<"\n\t\t\t\t\t Enter Full Name : ";
		for(i=0;i<25;i++)
		{
	 	   name[i]=0;
		}
		i=0;
		fflush(stdin);
		cin >> name;
				
		//Enter Email
		cout<<"\n\t\t\t\t\t Enter Email-ID : ";
		for(i=0;i<25;i++)
		{
	 	   email[i]=0;
		}	
		i=0;
		cin>>email;
		
		//Enter age
		cout<<"\n\t\t\t\t\t Enter Age : ";
		cin>>age;
		
		//Enter phone number
		cout<<"\n\t\t\t\t\t Enter Mobile No : ";
		for(i=0;i<12;i++)
		{
	 	   mobi[i]=0;
		}	
		i=0;
      	cin>>mobi;
    }
    	
    //DISLPAY NAME
	void bank_name()       
    {
      cout<<name;
    }
 };
 
 
//ACCOUNT CLASS ,USE CLASS INHERIT
class Account : public user     
{
	protected:
	char accnt[16],type,password[18],yes;
	int blnc,i;
	public:
  	
  	//Get user account data
    void accntgetdata()
	{
	  usergetdata();
	  cout<<"\n\t\t\t\t\t Enter Account No : ";
	  for(i=0;i<16;i++)
      {
	  	   accnt[i]=0;
	   }
		i=0;
	  cin>>accnt;

	  //label if Amount less 
	  retry:     
	  cout<<"\n\t\t\t\t\t Enter type of Account (C/S) : ";
	  cin>>type;
	  
	  blnc=0;
	  if(type=='s' || type =='S')
	  {
	   five:
	   cout<<"\n\t\t\t\t\t Enter Initial Amount (>= RM 500) : ";
	   cin>>blnc;
	   if(blnc<500){
	     cout<<"\n\t\t\t\t Please Enter greater than RM 500"<<endl;
	     goto five;
	     }
	   }
	  else if(type=='C' || type =='c')
	  {
	    ten:
	    cout<<"\n\t\t\t\t\t Enter Initial Amount (>= RM 200) : ";
		cin>>blnc;
		if(blnc<200){
	     cout<<"\n\t\t\t\t Please Enter greater than RM 200"<<endl;
		  goto ten;
		  }
	  }
	  
	  else
	  {
	    cout<<"\n\t\t\t\t Try Again Press 'c' for Current Account , 's' for Saving Account"<<endl;
		goto retry;
	  }	 
	  cout<<"\n\t\t\t\t\t Create Password : ";
	  for(i=0;i<18;i++)
      {
	  	   password[i]=0;
	   }
	   i=0;
	  while((password[i]=getch())!='\r')     
    {
		  printf("*");
    	  i++;
	}
	   system("cls");
	   
	   peqa_bank();
	   cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Press 'Y' to Confirm 'N' to retry  : ";
	   cin>>yes;
	   
	   //Account created
	   if(yes=='y' || yes=='Y')    
	   {
	      cout<<"\n\n\n\t\t\t\t\t    Account Successfully Created ";
	      getch();
	    }
		else
		{
		     system("cls");
		     peqa_bank();
		     cout<<endl<<endl<<endl<<endl;
			 accntgetdata(); 
		}
		  	  
	} 
  
};
	
// CLASS TRANSACTION  , ACCOUNT INHERIT
class Transaction : public Account 
{
	int amnt,p,t;
	float r,ci;
	
	public:
	
	//DO TRANSACTION
	Transaction()
	{
     amnt=0;
    }
    
	//DISPLAY ACCOUNT
	void displ()
    {
      cout<<"\n\n\t\t Account Name is "<<name;
	  cout<<"\n\t\t\t Balance is "<<blnc;
	  getch();
	  }     
	  
	//DEPOSIT FUNCTION
    void deposit()   
    {
		dep:
		cout<<"\n\n\t\t\t\t\t\t\t  Enter amount to Deposit : ";
		cin>>amnt;
      
		if(amnt>=10)
		{
			blnc=blnc+amnt; 
		}
	   
	   else
	    {
		 cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tAmount Should be Greater than equal RM 10 "<<endl<<endl<<endl;
		 goto dep;
		}
		
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t You have Deposited Successfully ";
		cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t Current Balance is RM "<<blnc;
		getch(); 
	  }   
	  
	  //WITHDRAW
	  void withdraw() 
	  {
	    with:
		cout<<"\n\n\t\t\t\t\t\t\t  Enter amount to Withdraw : ";
        cin>>amnt;
      
        if(amnt>=10)
         {
			if(blnc-amnt<0)
            {
			cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t Insufficient Balance ";
            getch();
			return;
			}
			        
			else
	        blnc=blnc-amnt;
	     }
	     
	    else
	    {
			cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tAmount Should be Greater than equal RM 10 "<<endl<<endl<<endl;
			goto with;
		}
		
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\t You have Withdrawl Successfully ";
		
		if(type=='c' || type=='C')
		{
			if(blnc<1000)
		    {
				cout<<"\n\n\n\t\t\t\t\t\t Your have cross the limit of minimum balance charges may apply ";
		    	blnc=blnc-100;
		    }
		}
		
		cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t Current Balance is RM "<<blnc;
		getch(); 
		} 
	   
	  //BALANCE ENQUIRY
	  void blncenquiry()    
	  {
	    cout<<"\n\t\t\t\t\t\t\t   Name : "<<name;
		cout<<"\n\n\t\t\t\t\t\t\t   Account No : "<<accnt;
		
		if(type=='s' || type== 'S')
			cout<<"\n\n\t\t\t\t\t\t\t   Type of Account : Saving";
		
		else
			cout<<"\n\n\t\t\t\t\t\t\t   Type of Account : Current"; 
	    
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   Your Available balance is RM "<<blnc;
		getch();
	   } 
	   
	   //CHECK BOOK FACILITY AVAILABLITY
	   void checkbk()
	   {
	     if(type=='c' || type=='C')
	     {
			system("cls");
	        peqa_bank();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Check Book Facility Available";
	        getch();
		  }
		  
		  else
		  {
		    system("cls");
		    peqa_bank();
		    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Check Book Facility Not Available";
		    getch();
		  }
		}
		 
		//CALCULATE COMPOUND
		void compound()
		{
			system("cls");
		    peqa_bank();
		    
		    if(type=='s' || type=='S')
		    {
		     cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t   Enter Principle Amount : ";
			 cin>>p; 
			 cout<<"\n\n\t\t\t\t\t\t\t   Enter the rate of interest : ";
             cin>>r;
             cout<<"\n\n\t\t\t\t\t\t\t   Enter the time : ";
             cin>>t;  
             ci=p*(pow((1+r/100),t));
             cout<<"\n\n\n\t\t\t\t\t\t\t\t\t The Compound Interest is : "<<ci<<endl;
             }
             
             else
                cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Compound Interest Not Available in Current Account";
                
           getch();
		}  
		  
		//DISPLAY INFO
		void info()
		{
			system("cls");
			peqa_bank();
			system("color d");
			cout<<"\n\n\n\n\n\n\n";
			cout<<"\n\n\t\t\t\t\t\t\t\t Name : "<<name;
			cout<<"\n\n\t\t\t\t\t\t\t\t Account No : "<<accnt;
			cout<<"\n\n\t\t\t\t\t\t\t\t Age : "<<age;
			cout<<"\n\n\t\t\t\t\t\t\t\t Email-Id : "<<email;
			cout<<"\n\n\t\t\t\t\t\t\t\t Mobile NO : "<<mobi;
			
			if(type=='S' || type=='s')
			cout<<"\n\n\t\t\t\t\t\t\t\t Type of Account : Saving";
			
			else
			cout<<"\n\n\t\t\t\t\t\t\t\t Type of Account : Current";
			cout<<"\n\n\t\t\t\t\t\t\t\t Available Balance : RM "<<blnc;
			
			getch();
			system("color 7");
		  }  
          
	  friend char check(Transaction a1,char accnt2[],char password2[]);   
};

//ACCOUNT LOGIN - BYPASS
//If the password and username are true, can enter
char check(Transaction a1,char accnt2[],char password2[])
{
   char sign;
   
	if(strcmp(a1.accnt,accnt2)==0 && strcmp(a1.password,password2)==0)
    { 
		system("cls");
		peqa_bank();
		cout<<endl<<endl<<endl<<endl;
    	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Welcome ";a1.bank_name();
		sleep(2);
		sign=trans(a1);
         
		return sign;
	}
	
    else
    {
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t Invalid Account No OR Wrong Password ";
		getch();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------BANK SYSTEM - END----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------TIC TOE GAME- START----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////


//DATA STRUCTURE OF TIC TAC TOE
class tictoe
{
	private:
			int gameboard[3][3];  
			int entry;						// to get entry form players
			int player;						
			int player_no;  
			int store_entryLocation[9];		/* array to store entry location for 
											checking is location valid or not */
			
	public:
			tictoe(); 
			void set_values();				// To set values
			void print_board();				// To print gameboard
			void get_entry();				// To get players entry location
			void check_entry();				// To check entry location is valid or not
			void set_entry();				// To set entry  
			int check_win();				// To check game status
};

//CONSTRUCTURE DEFINITION
tictoe::tictoe()  
{
	set_values();
	print_board();
	get_entry();
}

//SET VALUES FUNCTION DEFINITION
void tictoe::set_values()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\t\t\t\t\t\t\tTictok Game"<<endl;
	cout<<"\n\t\t\t\t\t\t\tWho want to start game : "<<endl;
	cout<<"\t\t\t\t\t\t\tPlayer one or Player two (select '1' or '2') :"<<endl;
	cin>>player_no;	
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			
		gameboard[i][j]=0;
	
	  }
	}
	for(int i=0;i<9;i++)
	{
	   store_entryLocation[i]=0;	
	}		
}

//FUNCTION TO PRINT GAMEBOARD
void tictoe::print_board()  
{
	cout<<"\n\t\t\t\t\t\t\tTictok Game"<<endl;

	cout << "\t\t\t\t\t\t\t\t _________________" << endl;
	cout << "\t\t\t\t\t\t\t\t|     |     |     |" << endl;
	cout << "\t\t\t\t\t\t\t\t|  " << gameboard[0][0] << "  |  " <<gameboard[0][1]<< "  |  " << gameboard[0][2] <<"  |" << endl;

	cout << "\t\t\t\t\t\t\t\t|_____|_____|_____|" << endl;
	cout << "\t\t\t\t\t\t\t\t|     |     |     |" << endl;

	cout << "\t\t\t\t\t\t\t\t|  " << gameboard[1][0] << "  |  " <<gameboard[1][1]<< "  |  " << gameboard[1][2]<<"  |" << endl;

	cout << "\t\t\t\t\t\t\t\t|_____|_____|_____|" << endl;
	cout << "\t\t\t\t\t\t\t\t|     |     |     |" << endl;

	cout << "\t\t\t\t\t\t\t\t|  " <<gameboard[2][0] << "  |  " <<gameboard[2][1] << "  |  " <<gameboard[2][2] <<"  |" << endl;

	cout << "\t\t\t\t\t\t\t\t|_____|_____|_____|" << endl << endl;
}

//FUNCTION TO GET ENTRY LOCATION FROM PLAYERS
void tictoe::get_entry()    
{
	cout<<"\t\t\t\t\t\t\tPlayer "<<player_no<<" : ";
	cin>>entry;
	
	check_entry();
	 
}

// TO CHECK ENTRY LOCATION IS VALID OR NOT
void tictoe::check_entry()  
{
	if(entry<1||entry>9)
    {
		cout<<"\n\t\t\t\t\t\t\tInvalid Location"<<endl;
		get_entry();
	}
	else 
	{	
    	if(store_entryLocation[entry]!=0)
    	{
    		cout<<"\n\t\t\t\t\t\t\tThis location is already occupied"<<endl;
			get_entry();
    	
		}
		else
		{
			store_entryLocation[entry]=entry;
			if(player_no==1)
   		    {
		 	   player_no=2;
			   player=1;
			   set_entry();
    		}
    		else
    		{
   	   		  player_no=1;
			  player=2;
			  set_entry();
    		}
		}
	}
}

//FUNCTION TO SET PLAYER ENTRY
void tictoe::set_entry() 
{
		switch(entry)
		 {
			case 1:
				gameboard[0][0]=player;
				break;
			case 2:
				gameboard[0][1]=player;
				break;
			case 3:
				gameboard[0][2]=player;
				break;
			case 4:
				gameboard[1][0]=player;
				break;
			case 5:
				gameboard[1][1]=player;
				break;
			case 6:
				gameboard[1][2]=player;
				break;
			case 7:
				gameboard[2][0]=player;
				break;
			case 8:
				gameboard[2][1]=player;
				break;
			case 9:
				gameboard[2][2]=player;
				break;			
		 }
		 
	//Checking Status Of Game 
	switch(check_win())
	{
	   case 0:  
	   			//  if game is continue
		    	system("CLS");   //to clear screen
		    	print_board();
		    	get_entry();
		    	system("PAUSE");
		    	break;
		case 1:
				//  if player wins
				system("CLS");   //to clear screen
		    	print_board();
				cout<<"\n\t\t\t\t\t\t\tPlayer "<<player<<" wins the game"<<endl;
				system("PAUSE");
				break;
		case 2: 
				//  if game draw
				system("CLS");   //to clear screen
		    	print_board();
				cout<<"\n\t\t\t\t\t\t\tGame has been drawn"<<endl;
				system("PAUSE");
				break;	
	}
}

//CHECK WINNTER
int tictoe::check_win()
{
	int Continue=0,win=1,draw=2;
		
	if (gameboard[0][0] == gameboard[0][1] && gameboard[0][0] == gameboard[0][2]&&gameboard[0][0]!=0)
		return win;
		
	else if (gameboard[1][0] == gameboard[1][1] && gameboard[1][0] == gameboard[1][2]&&gameboard[1][0]!=0)
		return win;
		
	else if (gameboard[2][0] == gameboard[2][1] && gameboard[2][0] == gameboard[2][2]&&gameboard[2][0]!=0)
		return win;
		
	else if (gameboard[0][0] ==gameboard[1][0] && gameboard[0][0] == gameboard[2][0]&&gameboard[0][0]!=0)
		return win;
	
	else if (gameboard[0][1] ==gameboard[1][1] && gameboard[0][1] == gameboard[2][1]&&gameboard[0][1]!=0)
		return win;
		
	else if (gameboard[0][2] ==gameboard[1][2] && gameboard[0][2] == gameboard[2][2]&&gameboard[0][2]!=0)
		return win;
	
	else if (gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2]&&gameboard[0][0]!=0)
		return win;
		
	else if (gameboard[0][2] ==gameboard[1][1] && gameboard[0][2] == gameboard[2][0]&&gameboard[0][2]!=0)
		return win;

		int check=0;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		if(gameboard[i][j]!=0)
		{
			check+=1;
		}
	  }
	}
	  if(check==9)
		{
			return draw;
		}
	  
		else
		{

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		if(gameboard[i][j]==0)
		{
			return Continue;
		}
	   }
	 }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------TIC TAC TOE - END----------------------------------//

////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
//Data structure for the main
struct PeQa_social{
	
		//These are the list data of data structure
		string name;
		string age;
		string gender;
		string telephone;
		string email;
		
		struct PeQa_social *next_social;
	
	//The pointers are being used to connect the nodes later	
	}*person1,*person2,*person3,*person4,*person5,*person6,*person7,*head_social,*tail_social,*temp_social;

//Graph Functions
// A structure to represent an adjacency list node 
struct AdjListNode 
{ 
    int mutual; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList 
{ 
    struct AdjListNode *head_adj;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int mutual) 
{ 
    struct AdjListNode* newNode = new AdjListNode;
    newNode -> mutual = mutual;
    newNode -> next = NULL; 
    return newNode; 
} 
  
// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V;
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array = new AdjList[V * sizeof(struct AdjList)]; 
  
    // Initialize each adjacency list as empty by  
    // making head_adj as NULL 
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head_adj = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int mutual) 
{ 
    // Add an edge from src to mutual.  A new node is  
    // added to the adjacency list of src.  The node 
    // is added at the beginning 
    struct AdjListNode* newNode = newAdjListNode(mutual); 
    newNode->next = graph->array[src].head_adj; 
    graph->array[src].head_adj = newNode; 

} 
// A utility function to print the adjacency list  
// representation of graph 

void DisplayState(int data) //Function to Print State Represented by Number
{
	switch(data)
    {
        case 1: cout << " Aida "; break;      		
        case 2: cout << " Aidil "; break;		
        case 3:	cout << " Piee ";	break;
        case 4: cout << " Hannie "; break;	
        case 5: cout << " Qayyum ";	break;       	
	}
}

void mutual_friends(struct Graph* graph)
{
	int n = 1;
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Aida" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Aidil" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Piee" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t4. Hannie" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t5. Qayyum" << endl;
	
	cout <<  "\n\t\t\t\t\t\t\t\t\t\tWhich are the mutual friends? : ";
  	cin >> n;
  	cout << endl;
  	
  	while(n < 1 || n > 5)
	{
		cout << "\t\t\t\t\t\t\t\tPlease Enter a Valid Number: ";
		cin >> n;
	}
  	
        struct AdjListNode* current = graph->array[n].head_adj; 
		cout << "\t\t\t\t\t\t\t\t\t\tMutual Friends :";
		DisplayState(n);
		cout << endl;
        while (current) 
        {        	
        	cout << "\t\t\t\t\t\t\t\t\t\t - ";
			DisplayState(current->mutual);
			cout << endl;
            current = current->next;
        } 
    
	system("PAUSE");
}


//correction display
void printPeQa_social(struct PeQa_social *head_social)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\tGiven a linked list data of 7 of our classmates" << endl;
	system("cls");
	temp_social = head_social;
	
	//Looping to display the list
	int i = 0;
	cout << endl;
	cout << "\t\t\t\t\t\t\t- - - - - - - - - - - - - - - - - -  SOCIAL DETAIL  - - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
	cout << "\t\t\t\t\t\t\t|No. |    NAME    | AGE |  GENDER  |     TELEPHONE      |          EMAIL          |";
	cout << endl << endl;
	while (temp_social != NULL)  
	{	
		i++;
		cout<<"\t\t\t\t\t\t\t" <<setw(3)<<i<<internal <<setw(12)<< temp_social -> name  <<setw(7)<<temp_social -> age<<right << setw(12)<<temp_social -> gender;
		cout<<setw(18)<<temp_social -> telephone<<setw(30)<<temp_social -> email;
		cout<<endl;
		temp_social = temp_social -> next_social;
	} 	
	cout << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//END SIMULATION MODE
//////////////////////////////////////////////////////////////////////////////////////////////////////
/*

					________  ________  
					|			 |       |     |        |  |     |
					|______      |       |     |        |  |    |
						  |		 |		 |	   |   _____|   |  |
						  |      |       |     |  |     |    |
                    ______|      |       |_____|  |_____|    |

*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
void study_Array()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tImagine a box of cookies. If you look closely, you will notice below things." << endl;
	Sleep (2000);	
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tCookie Box is a container which is holding all the cookies" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tSince it's a cookie box, only chocolates are kept or stored in it" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tEach cookie in on the is at the unique position, we can give numbers to cookies from 1 to 5" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\tEach cookie can be picked up by its numeric position, like if you want to eat cookie number 4 then pick up the cookie at 4th position" << endl;
	Sleep (3000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system ("color 02");
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tThe answer is by using Array" << endl;
	Sleep (4000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tIn array, we use two terms : Index(Position) and Elements(Value)" << endl;
	Sleep (2000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tThe number of elements in an array is called Array size which always start from 0" << endl;
	Sleep (2000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tThe Array format -> type arrayName [arraySize]" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\tFor eg : ";
	Sleep (2000);
	cout << "\n\n\t\t\t\t\t\t\t\t\tint matricNumber [5] = {200359, 202785, 203732, 203773, 202788}" << endl;
	Sleep (4000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tIt is easy right? Let's try to fill it yourself" << endl;
	Sleep (2000);
	
	
	//Programming (insertion and display)
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tInsert 5 number" << endl;
	int testNumber[5] = {};
	for (i=0;i<5;i++){
		cin >> testNumber[i];
	}
	Sleep(1500);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t  Now wait 3 seconds for your array to display\n" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tYour array is Array[5] = {" ;
	for (i=0;i<5;i++){
		cout << testNumber[i] ;
		for (j=0;j<1;++j)
			cout << ",";
		}
	cout << "}";
	Sleep (6000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tCongrats!! You have successfully created your own array" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\tDo you know that you can sort an array too?" << endl;
	Sleep (2000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tYes, you can. Choose [1] or [2] to sort :\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t1. Sort in ascending" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t2. Sort in descending" << endl;
	cin >> array_Sort;
	
	if (array_Sort==1)
	{
	//sorting - ASCENDING ORDER
	for(i=0;i<5;i++)
	{		
		for(j=i+1;j<5;j++)
		{
			if(testNumber[i]>testNumber[j])
			{
				temp=testNumber[i];
				testNumber[i]=testNumber[j];
				testNumber[j]=temp;
			}
		}
	}
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\tSorted (Ascending Order) Array elements:\n\n"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\t";
	for(i=0;i<5;i++)
	cout<<testNumber[i]<<"\t";
	cout<<endl;
	}
	
	else if (array_Sort==2)
	{
	//sorting - DESCENDING ORDER
	for(i=0;i<5;i++)
	{		
		for(j=i+1;j<5;j++)
		{
			if(testNumber[i]<testNumber[j])
			{
				temp=testNumber[i];
				testNumber[i]=testNumber[j];
				testNumber[j]=temp;
			}
		}
	}
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\tSorted (Descending Order) Array elements:\n\n"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\t";
	for(i=0;i<5;i++)
	cout<<testNumber[i]<<"\t";
	cout<<endl;
	}
	cout << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 1: Array" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
}


void study_QueueStacks()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tImagine you are lining up. The front will dequeue while the last person will line up" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tThis is called Queue. Its popular with the name of FIFO" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tFIFO = First In, First Out" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tImagine you have a staks of file. The file will be added and removed on the toppest element" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tThis is called Stacks. Its popular with the name of LIFO" << endl;
	Sleep (3000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tLIFO = Last In, First Out" << endl;
	Sleep (3000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system ("color 02");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	
	cout << "\t\t\t\t\t\t\t\t\t\t\tThe answer is by using Stacks and Queue" << endl;
	Sleep (4000);
	system ("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	
	cout << "\t\t\t\t\t\t\t\t\t\tYou will learn more about it in Linked List topic" << endl;
	Sleep (4000);
	system ("CLS");
}


void study_Sorting()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tImagine you are want to arrange something from smallest to biggest. Or vice versa." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tThis is called sorting." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tWe have a lot of sorting types" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	//Insertion Sort
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. INSERTION SORT : " << endl;
	Sleep (2000);
	cout << "\t\t\t\t\t\t\t\t\t\t\tKey in 5 numbers : " << endl;
	int b[100], i, p, ptr, temp;

    for (i = 1; i <= 5; i++)
    {
        cin >> b[i];
    }

    b[0] = 0;

    for (p = 2; p <= 5; p++)
    {
        temp = b[p];
        ptr = p - 1;

        while (temp < b[ptr])
        {
            b[ptr + 1] = b[ptr];
            ptr--;
        }

    b[ptr + 1] = temp;
    }
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAfter Sorting : \n";
    cout << "\t\t\t\t\t\t\t\t\t\t";
    for (i = 1; i <= 5; i++)
    {
        cout << b[i] << "\t";
    }
	system("PAUSE");
	
	
	//Selection Sort
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. SELECTION SORT : " << endl;
	Sleep (2000);
	int a[100] , k, min, loc;

    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter Elements=\n";
    for (i = 1; i <= 5; i++)
    {
        cin >> a[i];
    }

    for (p = 1; p <= 4; p++)
    {
        min = a[p];
        loc = p;

        for (k = p + 1; k <= 5; k++)
        {
            if (min > a[k])
            {
                min = a[k];
                loc = k;
            }
        }
        temp = a[p];
        a[p] = a[loc];
        a[loc] = temp;
    }

    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAfter Sorting : \n";
	cout << "\t\t\t\t\t\t\t\t\t\t";
    for (i = 1; i <= 5; i++)
    {
        cout << a[i] << "\t";
    }
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 3: Sorting" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
}

struct List
{
	string data;
	struct List *next;
}*tempLL,*tail,*newnode;

void study_LinkedList (struct List* head)
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tImagine you want to have the data linked together from first data to the second data" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tThe data are the same, but you can assign, delete and edit data from the list" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);	
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tWe will use Linked List!!" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\tLet say you want to build a list. There are list1, list2 and list3. It some kind of similar like array where it stores data, but linked list uses pointers." << endl;
	Sleep (3000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tThe structure of Linked List is : " << endl;
	cout << endl;
	Sleep (1500);
	cout << "\t\t\t\t\t\t\t\t\t\tstruct List{" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t    string data;" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t    struct List *next" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t }" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tNow imagine we have a table. This are the list of name of three person :" << endl;
	Sleep (2000);
	tempLL = head;
	i=0;
	cout<< "\n\t\t\t\t\t\t\t\t\t\t|No.|     Name    |  "<< endl<<endl;
	while (tempLL!=NULL){
		
	i++;
	
	cout<<"\t\t\t\t\t\t\t\t\t\t"<<setw(2)<<i<<setw(13)<< internal<< tempLL -> data << endl;
	tempLL=tempLL->next;
	}

	Sleep(5000);
	
	cout <<"\n\t\t\t\t\t\t\t\t\t\tBy using Linked List, you can delete current data " << endl;
	Sleep(2000);
	system("CLS");
}

void print_study_LinkedList(struct List *head)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	tempLL = head;
	i=0;
	cout<< "\n\t\t\t\t\t\t\t\t\t\t|No.|     Name    |  "<< endl<<endl;
	while (tempLL!=NULL){
		
	i++;
	cout<<"\t\t\t\t\t\t\t\t\t\t"<<setw(2)<<i<<setw(13)<< internal<< tempLL -> data << endl;
	tempLL=tempLL->next;
	}
	Sleep(3000);
}


void end_LinkedList()
{
	Sleep(2000);
	cout << "You can also insert and edit your data by using Linked List. Visit our website to know more!!" << endl;
	Sleep (2500);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 4: Linked List" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
}


// C++ code to linearly search x in arr[]. If x 
// is present then return its location, otherwise 
// return -1 
int search(int arr[], int n, int x) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
} 

void study_Searching()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tImagine you have a bag of marbles with different number from 1 to 9" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tHow can you find the marbles? You'll need to find the selected marbles number in the bag one by one though." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	
	cout << "\t\t\t\t\t\t\t\t\t\t\tWe will use Search!!" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tThere are many types of searching methods" << endl;
	Sleep (1500);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Linear Search" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Binary Search" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Sublist Search" << endl;
	Sleep (1000);
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t...and MANY MORE!!" << endl;
	Sleep (1000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tIn this course, we will learn Linear Search" << endl;
	Sleep (1500);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tYou're given an array of 10,23,44,99,18" << endl;
	Sleep (1500);
	cout << "\t\t\t\t\t\t\t\t\t\tNow, try to search the value above to check whether it exist or not" << endl;
	
	int arr[] = { 10, 23, 44, 99, 18 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x;
	char response;
	cout << "\n\t\t\t\t\t\t\t\t\t\tEnter a number to search" << endl;
	cin >> x;

	int result = search(arr, n, x); 
	(result == -1)? cout<<"\n\t\t\t\t\t\t\t\t\t\tElement is not present in array" : cout<<"\n\t\t\t\t\t\t\t\t\t\tElement is present at index " <<result << endl; 
	cout << endl;
	Sleep (2000);

	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tDo you want to try again? (Y/N)" << endl;
	cin >> response;
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	if (response == 'y' || response == 'Y'){
	cout << "\n\t\t\t\t\t\t\t\t\t\tEnter a number to search" << endl;
	cin >> x;

	int result = search(arr, n, x); 
	(result == -1)? cout<<"\n\t\t\t\t\t\t\t\t\t\tElement is not present in array" : cout<<"\n\t\t\t\t\t\t\t\t\t\tElement is present at index " <<result << endl; 
	cout << endl;
	Sleep (2000);
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 5: Searching" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
	}
	
	else {
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 5: Searching" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
	}

}


void study_Hashing()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\tImagine we want to store a data fast, constant and efficient. We would need a special zone to store the data." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tWe will use hashing with the Big-O Notation of O(1)" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tThere are few methods of hashing such as: " << endl;
	Sleep (1500);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Linear Probing" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Quadratic Probing" << endl;
	Sleep (1000);	
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Double Hashing" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t4. Fibonacci Hashing Method" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t5. Chaining Hashing Method" << endl;
	Sleep (1000);
	cout << endl;	
	cout << "\t\t\t\t\t\t\t\t\t\t\tAny many more!!" << endl;
	Sleep (3000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHave a preview on the chaining method below" << endl;
	system("CLS");
}

void end_Hashing()
{
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tThis is chaining method by applying linked list in it." << endl;
	Sleep(1500);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tWhat is happening here is the hash table was made by using formula Hash Value = data % size" << endl;
	Sleep (2000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tThen the hash value was inserted to the hash table based on its unique value" << endl;
	Sleep (2000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tThe number that has the same Hash Value will be chained. This is Chaining Method" << endl;
	Sleep (2000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tThis method is really good to understad as we do not need to use any extra hash table position" << endl;
	Sleep (2000);
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 6: Hashing" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
}


class Hash 
{ 
	int BUCKET; // No. of buckets 

	// Pointer to an array containing buckets 
	list<int> *table; 
public: 
	Hash(int V); // Constructor 

	// inserts a key into hash table 
	void insertItem(int x); 

	// deletes a key from hash table 
	void deleteItem(int key); 

	// hash function to map values to key 
	int hashFunction(int x) { 
		return (x % BUCKET); 
	} 

	void displayHash(); 
}; 

Hash::Hash(int b) 
{ 
	this->BUCKET = b; 
	table = new list<int>[BUCKET]; 
} 

void Hash::insertItem(int key) 
{ 
	int index = hashFunction(key); 
	table[index].push_back(key); 
} 

void Hash::deleteItem(int key) 
{ 
// get the hash index of key 
int index = hashFunction(key); 

// find the key in (inex)th list 
list <int> :: iterator i; 
for (i = table[index].begin(); 
		i != table[index].end(); i++) { 
	if (*i == key) 
	break; 
} 

// if key is found in hash table, remove it 
if (i != table[index].end()) 
	table[index].erase(i); 
} 

// function to display hash table 
void Hash::displayHash() { 	
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
for (int i = 0; i < BUCKET; i++) { 
	cout << "\t\t\t\t\t\t\t" << i; 
	for (auto x : table[i]) 
	cout << "--> " << x; 
	cout << endl; 
} 
} 

void study_Graph()
{
	//Explanation
    Beep (330,100);Sleep(100);
    Beep (330,100);Sleep(300);
    Beep (330,100);Sleep(300);
    Beep (262,100);Sleep(100);
    Beep (330,100);Sleep(300);
	Beep (392,100);Sleep(700);
	Beep (196,100);Sleep(700);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tATTENTION : THE SYSTEM IS AUTOPLAY.\n\n\n\n\n\n\n\n\n\n" << endl;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHI YOU WILL LEARN A NEW TOPIC TODAY" << endl;
	Sleep(2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tWhat is graph?" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\tYes, right. The graph is the data that has its own coordinates. In other words, its own destination." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tHow can you achieve by using C++ Language?" << endl;
	Sleep (4000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tWe will use Graph Theory!!" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tGraph Theory have directed and undirected methods." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tThere are many types of Graph Theory data structure such as" << endl;
	Sleep (1500);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Adjacency Matrix Representation" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Adjacency List Representation" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Edge List Representation" << endl;
	Sleep (1000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\tThere are also many types of Graph Theory algorithms such as" << endl;
	Sleep(2500);
	cout << "\t\t\t\t\t\t\t\t\t\t\t1. Breadth-First Search" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t2. Depth-First Search" << endl;
	Sleep (1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t3. Shortest-Paths Algorithms" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t\t\tNow today we will learn one of them. Let's learn adjacency matrix representation" << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tAn adjacency-matrix representation of a graph is a 2-dimensional V x V array." << endl;
	Sleep (2000);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\tKey in the data below to see the graph representation :" << endl;
	cout << endl;
	Sleep (1500);
	system("CLS");
}

void PrintMat(int mat[][10], int n)
{
	int i,j;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t";
	cout << "\n\n" << setw(4)<< " ";
	for (i=0;i<n;i++)
	{
		cout << setw(3) << "("<<i+1<<")" ;}
		
		cout << "\n\n";
		
	//Print 1 if the corresponding vertexes are connected otherwise 0
	for (i=0;i<n;i++)
	{
		cout << setw(3) << "("<<i+1<<")" ;
		for (j=0;j<n;j++){
			cout << setw(4) << mat[i][j];
		}
		cout << "\n\n";
	}
}

void end_Graph()
{
	system("PAUSE");
	cout << "\t\t\t\t\t\t\t\t\tThis is Adjacency Matrix Representation graph" << endl;
	Sleep(1500);
	cout << "\t\t\t\t\t\t\t\t\t\tNow, you get the idea right?" << endl;
	Sleep (2000);
	cout << "\t\t\t\t\t\t\t\t\tYou can learn more on our website" << endl;
	Sleep (2000);
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\tCongratulations!! You have completed Chapter 7: Graph Theory" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tPress enter to get your certificate\n" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	system ("PAUSE");
	system("cmd/c start https://linktr.ee/peqa_ccse"); 
	system("CLS");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//Main function
int main()
{	
	//Console title
	SetConsoleTitle(_T("PE-QA.exe"));
			
	//Assigning list to NULL (STUDY MODE - LINKED LIST)
	struct List *head;
	List *list1 = NULL;
	List *list2 = NULL;
	List *list3 = NULL;
	List *tempLL =  NULL;
	
	
	//Assigning list to new struct list
	list1 = new struct List;
	list2 = new struct List;
	list3 = new struct List;
	tempLL = new struct List;

	//Assign data
	list1 -> data = "Kevin";
	list1 -> next = list2;
	
	list2 -> data = "David";
	list2 -> next = list3;

	list3 -> data = "Mitnick";
	list3 -> next = NULL;
	
	head=list1;
	tail=list3;
	
	//Graph Theory (Simulation Mode)
	//Initialising Pointers and Memory Allocation
	PeQa_social *person1 = NULL;
	PeQa_social *person2 = NULL;
	PeQa_social *person3 = NULL;
	PeQa_social *person4 = NULL;
	PeQa_social *person5 = NULL;
	PeQa_social *person6 = NULL;
	PeQa_social *person7 = NULL;

	//Assigning list to new struct PeQa_social
	person1 = new struct PeQa_social;
	person2 = new struct PeQa_social;
	person3 = new struct PeQa_social;
	person4 = new struct PeQa_social;
	person5 = new struct PeQa_social;
	person6 = new struct PeQa_social;
	person7 = new struct PeQa_social;

	//Assign data
	*person1 = {"Aida","20","Female","+60192942852","203732@student.upm.edu.my"};
	person1 -> next_social = person2;
	*person2 = {"Aidil","21","Male","+601110030341","202788@student.upm.edu.my"};
	person2 -> next_social = person3;
	*person3 = {"Piee","20","Male","+60179794300","203733@student.upm.edu.my"};
	person3 -> next_social = person4;
	*person4 = {"Hannie","20","Female","+60106586298","202785@student.upm.edu.my"};
	person4 -> next_social = person5;
	*person5 = {"Qayyum","20","Male","+60174866248","200359@student.upm.edu.my"};
	person5 -> next_social = person6;
	*person6 = {"Hussin","20","Male","+601110040864","200530@student.upm.edu.my"};
	person6 -> next_social = person7;
	*person7 = {"Soad","20","Male","+601133343490","204529@student.upm.edu.my"};
	person7 -> next_social = NULL;
	
	//Assigning head
	head_social = person1;
	tail_social = person7;
	
	//Vertex of Graph is set to 5
	int V = 5; 
	
	//Create Graph
    struct Graph* graph = createGraph(V); 
    
    //Assign edges of the graphs
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 5); 
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3); 
    addEdge(graph, 2, 4);  
    addEdge(graph, 2, 5); 
    addEdge(graph, 3, 2); 
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 1);
    addEdge(graph, 5, 2);
    
    
	//Animation
	system("COLOR 70"); //Change coding colour4
    animationenter c;
    c.mainenter();
	load();
	Beep(523.2511,500);  // 523.2511 hertz (C5) for 500 milliseconds
	Beep(587.3295,500);
	Beep(659.2551,500);
	Beep(698.4565,500);
	Beep(783.9909,500);
	system("CLS");
	music();
	system("color 0C");     //  for console color
	gotoxy(17,5);
	cout<<"--------------------------------------------------"<<endl;
	gotoxy(17,7);
	cout<<"||                    PE-QA.exe                   ||"<<endl;
	gotoxy(17,9);
	cout<<"--------------------------------------------------"<<endl;
   	gotoxy(17,11);
   	cout<<"|LECTURER ->> DR SYAMSIAH <<-- |\n"<<endl;
   	gotoxy(17,13);
   	cout<<">>>----Project Implemented By-----<<<"<<endl;
    gotoxy(23,15);
   	cout<<"AHMAD QAYYUM FIKRI BIN AHMAD JAZIMIN (200359)"<<endl<<endl;
   	gotoxy(23,16);
   	cout<<"EISYATUL HANNIE BINTI MOHAMMAD RUSHDAN (202785)"<<endl<<endl;
   	gotoxy(23,17);
   	cout<<"NURUL AIDA BINTI ZAIROL AKMAR (203732)"<<endl<<endl;
   	gotoxy(23,18);
   	cout<<"NIK MUHAMMAD FARHAN BIN OWI SIONG KIAT @ RUSTAM AL (203733)"<<endl<<endl;
   	gotoxy(23,19);
   	cout<<"AIDIL HARITH ANWAR BIN AZMI (202788)"<<endl<<endl;
   	cout << endl;
	system("pause");
	system("cls");
	cout << "This program was made by PE-QA team. Press enter to continue" << endl;
	cin.ignore();
	cout << "NOTE : W (up), S(down)." << endl;
	cin.ignore();
	fullscreen();
	menu();

	//Mode Select
	mode_select:
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << endl;
	cout << "\t\t\t\t\t\t\t        	_______  _________            _______   _______            " << endl;
    cout << "\t\t\t\t\t\t\t               |   _   | |    ____|          |   _   | |   _   |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  | |  | |   |____    _____  |  | |  | |  | |  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |   ____| |  |_____           |_____  | |  ___  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |      |_______|                 | | | |   | |           " << endl;
    cout << "\t\t\t\t\t\t\t               |__|                                |_| |_|   |_|           " << endl;
    cout << endl;

    cout << "\t\t\t\t\t\t\t                                  WELCOME to PE-QA.exe" << endl;
    cout << "\t\t\t\t\t\t\t               A MALAYSIAN ALGORITHM APPLICATION DURING COVID-19 OUTBREAK" << endl;
    cout << endl;
	cout << "\t\t\t\t\t\t\t\t\tMODE SELECT:" << endl;
	cout << "\t\t\t\t\t\t\t\t\t[1] STUDY MODE" << endl;
	cout << "\t\t\t\t\t\t\t\t\t[2] SIMULATION MODE" << endl;
	cout << "\t\t\t\t\t\t\t\t\t[3] CREATE YOUR FIRST CODE" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t||>> ";
	cin >> mode;
	Beep(800,500);
	cout << endl;
	system ("cls");
	
	//STUDY MODE MODE SELECTION
	do{
	
	while(mode!=4) 
	{
	if (mode == 1)
	{	while (topic!=8){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\tSELECT TOPIC\n" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[1] ARRAY" << endl;
 	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[2] QUEUE AND STACKS" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[3] SORTING" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[4] LINKED LIST" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[5] SEARCHING" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[6] HASHING" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[7] GRAPH THEORY" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t[8] MAIN MENU" << endl;
	cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		
		cin >> topic;
		Beep(1000,500);
		switch(topic){
		case 0 : continue;
		case 1 : study_Array();  //array topic
				 break;
		case 2 : study_QueueStacks();  //queue and stacks
				 break;
		case 3 : study_Sorting();  //sorting
				 break;
		case 4 : {
					study_LinkedList(head);  //linked list
					cout << endl;
					
					//The deletion working
					tempLL=head;
					head=head->next;
					delete tempLL;
					
					//Print data
					print_study_LinkedList(head);
					system("PAUSE");
					end_LinkedList();
					break;
				 }
	
		case 5 : study_Searching();  //searching
				 break;
		case 6 : {	//Hashing
					study_Hashing();
					// array that contains keys to be mapped 
					int c[] = {15, 11, 27, 8, 12}; 
					int n = sizeof(c)/sizeof(c[0]); 
					
					// insert the keys into the hash table 
					Hash h(7); // 7 is count of buckets in 
								// hash table 
					for (int i = 0; i < n; i++) 
						h.insertItem(c[i]); 
					
					// delete 12 from hash table 
					h.deleteItem(12); 
					
					// display the Hash table 
					h.displayHash();   
					end_Hashing();
					 break;	 
					}
		
		
		case 7 : { study_Graph();  //Graphical Analysis
			 	
				 int i,j,v;
				 cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				 cout << "\t\t\t\t\tEnter the number of vertexes: ";
				 cin >> v;
				
				 int mat[10][10];
				 cout << "\n";
				
			 	 //Take input of the adjacency of each pair of vertexes
				 for (i=0;i<v;i++){
			     for (j=i;j<v;j++){
					if (i!=j){
						cout << "\t\t\t\t\tEnter 1 if vertex "<<i+1 << " is adjacent to "<< j+1 << " , otherwise 0: "; 
						cin >> mat[i][j];
						mat[j][i]= mat[i][j];
					}
					else 
						mat[i][j]=0;
					}
				 }
				 PrintMat(mat,v);
					
			    end_Graph();
				break;}
	
		case 8 : system ("CLS");
				 goto mode_select;
				
					
				}}
		system("cls");
	}
	
	//SIMULATION MODE SELECTION
	else if (mode == 2)
	{
	simulation:
	system("CLS");
	Beep(1000,500);
	Beep(900,500);
	Beep(1000,500);
	Beep(950,500);
	Beep(500,500);
	Beep(700,500);
	Beep(800,500);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t        	_______  _________            _______   _______            " << endl;
    cout << "\t\t\t\t\t\t\t               |   _   | |    ____|          |   _   | |   _   |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  | |  | |   |____    _____  |  | |  | |  | |  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |   ____| |  |_____           |_____  | |  ___  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |      |_______|                 | | | |   | |           " << endl;
    cout << "\t\t\t\t\t\t\t               |__|                                |_| |_|   |_|           " << endl;
    cout << endl;
    
    
    cout << "\t\t\t\t\t\t\t                                  WELCOME to PE-QA.exe" << endl;
    cout << "\t\t\t\t\t\t\t               A MALAYSIAN ALGORITHM APPLICATION DURING COVID-19 OUTBREAK" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t                       1. ADMIN-CUSTOMER DATABASE MANAGEMENT (SHOPPING)" << endl;
    cout << "\t\t\t\t\t\t\t                       2. ATM SYSTEM" << endl;
    cout << "\t\t\t\t\t\t\t                       3. GAME - TIK TAC TOE" << endl;
    cout << "\t\t\t\t\t\t\t                       4. HASH THE PASSWORD" << endl;
    cout << "\t\t\t\t\t\t\t                       5. PEQA SOCIAL MEDIA (CHECK MUTUAL FRIENDS) " << endl;
    cout << "\t\t\t\t\t\t\t                       6. SOURCE CODE? VISIT OUR WEBSITE" << endl;
    cout << "\t\t\t\t\t\t\t                       7. BACK TO MODE SELECTION" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t                       ||>> ";
    cin >> peqa;
    
    //ADMIN-CUSTOMER DATABASE MANAGEMENT
    if (peqa == 1)
    {
    	

     for(int i=0;i<=51;i++)
     {
     
     	push(i);
	 }

	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("color 0C");     //  for console color
	gotoxy(17,5);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------------"<<endl;
	gotoxy(17,7);
	cout<<"\t\t\t\t\t\t\t||                    PE-QA.exe                   ||"<<endl;
	gotoxy(17,9);
	cout<<"\t\t\t\t\t\t\t--------------------------------------------------"<<endl;
   	gotoxy(17,11);
   	cout<<"\t\t\t\t\t\t\t|LECTURER ->> DR SYAMSIAH <<-- |\n"<<endl;
   	gotoxy(17,13);
   	cout<<"\t\t\t\t\t\t\t>>>----Project Implemented By-----<<<"<<endl;
    gotoxy(23,15);
   	cout<<"\t\t\t\t\t\t\tAHMAD QAYYUM FIKRI BIN AHMAD JAZIMIN (200359)"<<endl<<endl;
   	gotoxy(23,16);
   	cout<<"\t\t\t\t\t\t\tEISYATUL HANNIE BINTI MOHAMMAD RUSHDAN (202785)"<<endl<<endl;
   	gotoxy(23,17);
   	cout<<"\t\t\t\t\t\t\tNURUL AIDA BINTI ZAIROL AKMAR (203732)"<<endl<<endl;
   	gotoxy(23,18);
   	cout<<"\t\t\t\t\t\t\tNIK MUHAMMAD FARHAN BIN OWI SIONG KIAT @ RUSTAM AL (203773)"<<endl<<endl;
   	gotoxy(23,19);
   	cout<<"\t\t\t\t\t\t\tAIDIL HARITH ANWAR BIN AZMI (202788)"<<endl<<endl;
   	cout << endl;
	system("pause");
	system("cls");
	system("color F0"); 

    int ch;
	while(ch!=3){
	
	//Choice for below message
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t        	_______  _________            _______   _______            " << endl;
    cout << "\t\t\t\t\t\t\t               |   _   | |    ____|          |   _   | |   _   |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  | |  | |   |____    _____  |  | |  | |  | |  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |   ____| |  |_____           |_____  | |  ___  |           " << endl;
    cout << "\t\t\t\t\t\t\t               |  |      |_______|                 | | | |   | |           " << endl;
    cout << "\t\t\t\t\t\t\t               |__|                                |_| |_|   |_|           " << endl;
    cout << endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t|----------<Main Menu>---------|";
    cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t 1)ADMINISTRATOR OF MARKET\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t 2)CUSTOMER               \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t 3)EXIT                    \n";
	cout<<"\t\t\t\t\t\t\t\t\t\t 4)RETURN TO SIMULATION MODE                    \n";
	cout<<"\n\t\t\t\t\t\t\t\t\t ||>>";
	cin>>ch;
	
	switch(ch){
	
	//ADMINISTRATOR OF MARKET
	case 1:
		administator();
		break;

	//CUSTOMER BUY
	case 2:
		cout<<endl<<endl;
		bpop();
		system("pause");
	    buy();
	    break;

	//EXIT
    case 3:
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tThank You\t\t\t\t";
    	system("CLS");
  	  	system("color 02");
  	  	system ("CLS");
    	goto simulation;
    
	//RETURN TO SIMULATION MODE	
    default : 
    	system ("CLS");
		system("color 02");
		goto simulation;
	}
	}
	}

	//ATM BANK MODE
	else if (peqa == 2)
	{
		system("cls");
		Transaction a1; 
		main_menu(a1);
		getch();
    	system ("CLS");
		goto simulation; 
 	 }
	
	//TIC TAC TOE GAME MODE
	else if (peqa ==3)
	{
		system ("CLS");
		tictoe game;
		system ("CLS");
	}
	
	//HASHING MODE
	else if (peqa == 4)
	{
		//----------------------- Start Animation --------------------------//
		system("CLS");
		system ("color e");
		
			HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //just once
	        SetConsoleTextAttribute(color, 10);
	        cout<<"\nBY ";
	        SetConsoleTextAttribute(color, 13);
	        cout<<"\nPE-QA.exe";
	        SetConsoleTextAttribute(color, 11);
	        cout<<"\nUNIVERSITI PUTRA MALAYSIA"<<endl;
	        cout << endl;
	        SetConsoleTextAttribute(color, 14);
	
		//----------------------- End Animation --------------------------//
		
		
		
	    //Assigning existed data (Hard-coded)
		char hash_text[100];
	
		
		//Convert char to string
		string str (hash_text);
	
		tr1::hash<string> str_hash; //Hash the input
	
		//Prompt user to key in the input
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t        	_______  _________            _______   _______            " << endl;
	    cout << "\t\t\t\t\t\t\t               |   _   | |    ____|          |   _   | |   _   |           " << endl;
	    cout << "\t\t\t\t\t\t\t               |  | |  | |   |____    _____  |  | |  | |  | |  |           " << endl;
	    cout << "\t\t\t\t\t\t\t               |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |           " << endl;
	    cout << "\t\t\t\t\t\t\t               |   ____| |  |_____           |_____  | |  ___  |           " << endl;
	    cout << "\t\t\t\t\t\t\t               |  |      |_______|                 | | | |   | |           " << endl;
	    cout << "\t\t\t\t\t\t\t               |__|                                |_| |_|   |_|           " << endl;
	    cout << endl;
	    cout << "\n\t\t\t\t\t\t\t\t\t\t   Now choose your option\n" << endl;
	    cout << "\t\t\t\t\t\t\t\t\t\t1. Insert Text to hash" << endl;
	    cout << "\t\t\t\t\t\t\t\t\t\t2. Hash it" << endl;
	    cout << "\t\t\t\t\t\t\t\t\t\t3. Exit" ;
		cin >> option; 
		cin.ignore();
		//do-while and while loops are being used to loop the main menu
		do{
		while (option!=4) {
			
			//Display hard-coded data
		    if (option == 1)
		    {
		  		cout << "Enter your text to hash " << endl;
		  		cin >> hash_text;
			}
		
			//Display hashing value
			else if (option == 2)
			{
				system("CLS");
				cout << "HASHED TEXT :" << str_hash(str)<< endl;
				cout << endl;		
				Sleep (3500);
			}
			
			else if (option ==3)
			{
				system("CLS");
				system("color 02");
				goto simulation;
				
			}
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\t\t\t\t        	_______  _________            _______   _______            " << endl;
		    cout << "\t\t\t\t\t\t\t               |   _   | |    ____|          |   _   | |   _   |           " << endl;
		    cout << "\t\t\t\t\t\t\t               |  | |  | |   |____    _____  |  | |  | |  | |  |           " << endl;
		    cout << "\t\t\t\t\t\t\t               |  |_|  | |   ____|   |____|  |  |_|  | |  |_|  |           " << endl;
		    cout << "\t\t\t\t\t\t\t               |   ____| |  |_____           |_____  | |  ___  |           " << endl;
		    cout << "\t\t\t\t\t\t\t               |  |      |_______|                 | | | |   | |           " << endl;
		    cout << "\t\t\t\t\t\t\t               |__|                                |_| |_|   |_|           " << endl;
		    cout << endl;
		    cout << "\n\t\t\t\t\t\t\t\t\t\t   Now choose your option\n" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t1. Insert Text to hash" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t2. Hash it" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t3. Exit" << endl;
			cin >> option;

			}}while (option == 4 && option ==1);

			return 0;
			}
		
		//PE-QA SOCIAL (FIND MUTUAL FRIENDS GRAPH THEORY)		
		else if (peqa == 5)
		{
	    	system ("CLS");
	    	//Print out linked list
			printPeQa_social(head_social);
	    	
   			cout << "\n\n\n\n";
		    cout << "\t\t\t\t\t\t\t\t\t\t\tGraph Representation:\n\n"<< endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t\t1-------2-------3   \n";
		    cout << "\t\t\t\t\t\t\t\t\t\t\t|   |   |       |   \n";
		    cout << "\t\t\t\t\t\t\t\t\t\t\t5----   4--------   \n";
		    cout << endl;
		    system("PAUSE");
		    graph_representation:
		    system("CLS");
			printPeQa_social(head_social);
		    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tGraph Representation: \n\n"<< endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t   Aida-------Aidil-------Piee   \n";
		    cout << "\t\t\t\t\t\t\t\t\t\t    |     |     |          |   \n";
		    cout << "\t\t\t\t\t\t\t\t\t\t  Qayyum---   Hannie--------   \n";
		    cout << endl << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t  1. Check Mutual Friends" << endl;
		    cout << "\t\t\t\t\t\t\t\t\t\t  2. Back to main menu" << endl;
		    cout << "\n\t\t\t\t\t\t\t\t\t\t  ||>> ";
		    cin >> gtheory;
		    cout << endl;
		    
		    switch (gtheory){
		    	//Find mutuals
				case 1 : mutual_friends(graph); 
						 break;
						 
				case 2 : system("CLS"); goto simulation;
				default : system("CLS"); goto simulation;
			}
			cout << "\t\t\t\t\t\t\t\t\t\tDo you want to try again? \n\t\t\t\t\t\t\t\t\t\t(Y/N)\n\t\t\t\t\t\t\t\t\t\t";
			cin >> gtheory2;	
			
			
			switch (gtheory2 == 'y' || gtheory2 == 'Y'){
				case 1 : system("CLS"); goto graph_representation;
				default : system("CLS"); goto simulation;
	
			}
		}
		
		//OPEN WEBSITE
		else if (peqa == 6)
		{
   	    	system ("CLS");
			system("cmd/c start https://linktr.ee/peqa_ccse");
		}
		
		//RETURN TO MODE SELECTION MENU
		else if (peqa == 7)
		{
			system ("CLS");
			goto mode_select;
		}			
			
		}
		
		//Direct to online compiler
		else if (mode==3)
		{
			while (option!=3){
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tNow make sure you have the C++ code with you. Do you have any C++ code? " << endl;
			cout << "\t\t\t\t\t\t\t\t_____________________________________________________________________________" ;
			cout << "\n\n\t\t\t\t\t\t\t\t[1]Yes, I have the code with me" << endl;
			cout << "\t\t\t\t\t\t\t\t[2]No, I need a code" << endl;
			cout << "\t\t\t\t\t\t\t\t[3]Back to Mode Select" << endl;
			cin >> option;
			
			
			
			switch (option)
			{
				case 0 : continue;
				case 1 : cout << "Now copy your C++ code and paste it on the online compiler" << endl;
						 system ("PAUSE");
						 cout << "Redirecting to C++ online compiler..." << endl;
						 Sleep(2000);
						 system("cmd/c start https://www.onlinegdb.com/online_c++_compiler");
						 system ("CLS");
						 break;
				
				
				case 2 : system("cmd/c start https://linktr.ee/peqa_ccse");
						 system ("CLS");
						 break;
						 
				case 3 : system ("CLS");
						Beep (196,100);Sleep(125);
				        Beep (262,100);Sleep(125);
				        Beep (330,100);Sleep(125);
				        Beep (392,100);Sleep(125);
				        Beep (523,100);Sleep(125);
				        Beep (660,100);Sleep(125);
				        Beep (784,100);Sleep(575);
				        Beep (660,100);Sleep(575);
				        Beep (207,100);Sleep(125);
				        Beep (262,100);Sleep(125);
				        Beep (311,100);Sleep(125);
				        Beep (415,100);Sleep(125);
				        Beep (523,100);Sleep(125);
				        Beep (622,100);Sleep(125);
				        Beep (830,100);Sleep(575);
				        Beep (622,100);Sleep(575);
				        Beep (233,100);Sleep(125);
				        Beep (294,100);Sleep(125);
				        Beep (349,100);Sleep(125);
				        Beep (466,100);Sleep(125);
				        Beep (587,100);Sleep(125);
				        Beep (698,100);Sleep(125);
				        Beep (932,100);Sleep(575);
				        Beep (932,100);Sleep(125);
				        Beep (932,100);Sleep(125);
				        Beep (932,100);Sleep(125);
				        Beep (1046,675);  
						 goto mode_select;
				

			}}
		
		}
	
	
		}}while(mode == 4 &&mode ==1);
		//END
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";		
		cout<<"	|\t\t\t\t _____ _                 _                        \t\t\t\t|"<< endl;
		cout<<"	|\t\t\t\t|_   _| |__   __ _ _ __ | | __  _   _  ___  _   _ \t\t\t\t|"<< endl;
		cout<<"	|\t\t\t\t  | | | '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | |	\t\t\t\t|"<< endl;
		cout<<"	|\t\t\t\t  | | | | | | (_| | | | |   <  | |_| | (_) | |_| |	\t\t\t|"<< endl;
		cout<<"	|\t\t\t\t  |_| |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_|	\t\t\t\t|"<< endl;
		cout<<"	|\t\t\t\t                                |___/             	\t\t\t|"<< endl;
		
		//Outro from Super Mario Song			
		Beep (196,100);Sleep(125);
        Beep (262,100);Sleep(125);
        Beep (330,100);Sleep(125);
        Beep (392,100);Sleep(125);
        Beep (523,100);Sleep(125);
        Beep (660,100);Sleep(125);
        Beep (784,100);Sleep(575);
        Beep (660,100);Sleep(575);
        Beep (207,100);Sleep(125);
        Beep (262,100);Sleep(125);
        Beep (311,100);Sleep(125);
        Beep (415,100);Sleep(125);
        Beep (523,100);Sleep(125);
        Beep (622,100);Sleep(125);
        Beep (830,100);Sleep(575);
        Beep (622,100);Sleep(575);
        Beep (233,100);Sleep(125);
        Beep (294,100);Sleep(125);
        Beep (349,100);Sleep(125);
        Beep (466,100);Sleep(125);
        Beep (587,100);Sleep(125);
        Beep (698,100);Sleep(125);
        Beep (932,100);Sleep(575);
        Beep (932,100);Sleep(125);
        Beep (932,100);Sleep(125);
        Beep (932,100);Sleep(125);
        Beep (1046,675);  
	    return 0;
}

//FUNCTION FROM BANK
//MAIN MENU
void main_menu(Transaction &a1)
{
  welcome();
  char ch,sign;
  int i=0;
  while(ch!=3)
  {
   system("cls");
   peqa_bank();
   cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t MAIN MENU "<<endl<<endl;
   cout<<"\t\t\t\t\t   1. Create Account"<<endl<<endl;
   cout<<"\t\t\t\t\t   2. Sign in"<<endl<<endl;
   cout<<"\t\t\t\t\t   3. Exit"<<endl<<endl;
   cout<<"\n\n\t\t\t\t\t Enter your choice : ";
   cin>>ch;
   switch(ch)
    {
       case '1':system("cls");
                peqa_bank();
                cout<<endl<<endl<<endl<<endl;
	            a1.accntgetdata();
                break;
       case '2':system("cls");
                peqa_bank();
                char accnt2[16],password2[18];
            
                 cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Enter Account No : ";
			     cin>>accnt2;
			     cout<<"\n\n\n\t\t\t\t\t\t\t\t\t Enter Password : ";
	
				for(i=0;i<18;i++)
				{
			       password2[i]=0;
			       }
			        i=0;
			    while((password2[i]=getch())!='\r')
                {
		           printf("*");
    	            i++;
	             }
			     sign=check(a1,accnt2,password2);
                 if(sign=='s'|| sign=='S')
                  continue;
			     break;
              
       case '3':system("cls");
                peqa_bank();
	            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   Thank You";
	            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   Have a great day!!";
	            sleep(2);
				goto b;
       default:cout<<"\n\n\t\t\t\t\t Invalid Choice";
                getch();
    }  
  } 
  b:{ system("CLS");system("color 02");}
}
 
//TRANSACTION OPTIONS (BANK) 
char trans(Transaction &a1)
{ 
    char ch;
    int i=0;
    while(1)
   {
     system("cls");
     peqa_bank();
     cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t 1. Deposit Amount ";
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 2. Withdraw Amount ";
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 3. Balance Enquiry ";
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 4. Check Book Facility";
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 5. Calculate Compound Interest ";
     cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t 6. Account Info";
     cout<<"\n\n\n\n\t  Exit(e)   \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Sign Out(s)";
     cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t  Enter your choice : ";
     cin>>ch;
    
     switch(tolower(ch))
     { 
       case'1':system("cls");
                peqa_bank();
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	            a1.deposit();
                break;
       case'2':system("cls");
                peqa_bank();
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	            a1.withdraw();
                break;
       case'3':system("cls");
                peqa_bank();
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	            a1.blncenquiry();
                break;
       case '4': a1.checkbk();
                break;
       case'5':a1.compound();
                break;
       case '6':a1.info();
	            break;         
       case 'e':system("cls");
                peqa_bank();
                system("color c");
	            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t   Thank You";
	            sleep(2);
	            exit(0);
       case 's':cout<<"\n\n\n\n\n\n\n\n\n\n\t";
	             for(i=0;i<8;i++)
	             {
	              sleep(1);
                  cout<<"===== ===== ==== ==== ==== ";
                  
                  }
	            return 's';
       default: cout<<"\n\n\n\t\t\t Invalid Choice ";
     }
    }
    getch();
}
