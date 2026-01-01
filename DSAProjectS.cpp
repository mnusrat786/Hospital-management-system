
#include <string>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#include<unistd.h>
#include <fstream>

using namespace std;

int i=0;
char ent ;

int paid[10];
string dis;
int j=0;
int k=0;
void medicineplz();
//"Snake Func."
void run();
void printMap();
void initMap();
void move(int dx, int dy);
void update();
void changeDirection(char key);
void clearScreen();
void generateFood();

char getMapValue(int value);


const int mapwidth = 20;
const int mapheight = 20;

const int size = mapwidth * mapheight;


int map[size];

int score;
int headxpos;
int headypos;
int direction;



int food = 3;


bool running;
//"Snake Func."

//"Node for Linked List "
struct nod
{
	int srno;
	string name;
	int cnc;
	int bill;
	nod *next;
};
class linkedlist
{
	nod *head;
	nod *current;
	
	public:
		linkedlist()
		{
			head=new nod();
			current=head;
		}
		
		void newnod(int cni,string nam)
		{
			j++;
			
			nod *newnod=new nod();
			//cout<<"cool";
			current->next=newnod;
			//cout<<"cooler";
			newnod->cnc=cni;
			newnod->name=nam;
			newnod->srno=j;
		
			newnod->bill=0;
			current=newnod;
		}
		void setbill(int bil)
		{
			current->bill=bil;
		}
		void display()
		{current=head;
		current=current->next;
		cout<<endl<<"\n\n-The List of patients that visited today are: \n\n";
		     cout<<"Srno.  Patient's Name    CNIC     Bill\n";
			while(current!=NULL)
			{
				cout<<endl<<current->srno<<"          "<<current->name<<"        "<<current->cnc<<"     "<<current->bill;
				current=current->next;
			}
		//"File Handling"
		string re;
		cout<<"\n\nDo you want to save this Important List Permanently??\n";
		cin>>re;
		if(re=="yes")
		{
			ofstream myfile;
            myfile.open ("HospitalSafe.txt");
            
            current=head;
		    current=current->next;
		    myfile<<endl<<"\n\n-The List of patients that visited today are: \n\n";
		    myfile<<"Srno.  Patient's Name    CNIC     Bill\n";
			while(current!=NULL)
			{
				myfile<<endl<<current->srno<<"          "<<current->name<<"        "<<current->cnc<<"     "<<current->bill;
				current=current->next;
			}
            myfile.close();
            cout<<"Save Successful";
		}
		else
		{
			cout<<"OK";
		}
			cout<<endl<<endl;
		}
		
};
void manager();
linkedlist patientlist;
string name[10];
//"Node for Tree"
struct node
{
	int cnic[10];
	int data;
	
	struct node* left;
	struct node* right;
	
	void hos()
	{
	
          i++;
          
          if(i==1)
			{
    
         cout<<"Welcome to our Hospital";
       A:  
    
    cout<<"\n\n (use 'e' for emergency and 'n' for normal patient or 'm' to enter manager mode,'q' to exit the program \n"; 
    cout<<"\n\n\n Are you in a state of emergency-1000 or you are a normal patient ";
    cin>>ent;
      
    if(ent=='n')
    {
    		}
	if(ent=='e')
	{
		cout<<"we are equally sorrow in this grieve moment ";
		patientlist.newnod(0,"emergency");
	}
	if(ent=='m')
	{
		manager();
	}
		}
	if(i==2)
	{      
                   B:
    cout<<"\n Enter your CNIC no.(without dashes) ";
                cin>>cnic[k];
      if (cnic[k]>99999 || cnic[k]<10000)
      {
                   cout<<"\nInvalid CNIC ! Try again\n";
                   system("pause");
                     goto B;
                     }
                     
                cout<<"\n Enter your cool name  "<<endl;
				cin>>name[k];
                //cout<<"cool";
                patientlist.newnod(cnic[k],name[k]);
                }
                
        if(i==3)
        {
                cout<<"\n\nWhich type of disease you are sufferring from :    "<<"\nfever - 400rs or heart- 500rs  or lungs-500rs or unknown-700rs \n\n" ;
                  cin.clear();
                fflush(stdin);
				fflush(stdin);
				cin>>dis;
              
                
                cout<<"\nWaiting for doctor to respond\n";
                 int cc=1,bs=9;
                	
                for(int ca=0;ca<9;ca++)
                {
                	for(int ba=0;ba<bs;ba++)
					{
						cout<<" ";
					}
					
                	for(int cb=0;cb<cc;cb++)
                	{		
                		cout<<"*";			
					}
					
				   cc=cc+2;
				   bs--;
				cout<<endl;
				Sleep(1000);
			    }
						int ti;
                ti=rand()%10;
                ti=ti*5000;		
                Sleep(ti);
                
                cout<<"\n\nYes, The required doctor is available now \n\n";
                
                if (dis=="fever") 
                {
                                 cout<<"\nPlz proceed towards room no. 1 \n";
                                 paid[k]=paid[k]+400;
                                 }
                else if (dis=="heart")
                {
                                 cout<<"\nProceed towards room no.2 to meet our world best~! heart speacialist   ";
                                 paid[k]=paid[k]+500;
                                 }
                else if (dis=="lungs")
                {
                                cout<<"\n PRoceed towards room 3 our pulmo expert doctor is sitting thier ";
                                paid[k]=paid[k]+500;
                                }
                
                else{
                     cout<<"\nProceed towards room .4 to meet our Haqeem sahab ";
                    
                     paid[k]=paid[k]+700;
                     }
                     cout<<endl;
                     system("pause");
                }
        if(i==4)
        {
        	string med;
                   cout<<"\n\n\n The medicines are available at discount/lower rate from the market";
                   cout<<"\n\nDo you want medicine also from hospital ?";
                   cin>>med;
                   if(med=="yes")
                   {
                      medicineplz();
                              
                                }
                   else
                   {
                       cout<<"\n As you wish dear patient  ";
                       
                                 }
		}
		
		if(i==5)
		{
			   char gam;
                   cout<<"\n\nPlay a game and win cash prize nOw!!!"<<endl<<"Press Y for yes or anyother key to continue..";
                   cin>>gam;
                   if(gam=='Y')
                   {
                   	 int cash;
                             run();   
                             cash= score*10;
                             cout<<"Congratulations, you have earned "<<cash<<"\n Its yours Enjoy!";
                             
                             paid[k]=paid[k]-cash;
                             Sleep(2000);  
                             
                       }
                   
                   else
                   {
                       cout<<"\nOkay , No problem! You can continue to the counter \n";}
		   }
                
    	if(i==6)
    	{
                       cout<<"\n\nSir Your total bill is   "<<paid[k];
                       patientlist.setbill(paid[k]);
                       cin.ignore();
                       cout<<"\n\nThank you for visiting us, God Bless you";
                       cout<<"\n\nFor any Quiries, Contact:"<<endl<<"Saad Ahmed, Noman Abbasi  "<<endl<<"0340-8157349";
                       system("pause");
                      }
		}		
};

/* Helper function that allocates a new node  */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
							malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void PostorderTraversal( node* node)
{
	if (node == NULL)
	{Z:	return;}

	PostorderTraversal(node->left);

	PostorderTraversal(node->right);
	
	if(ent=='e'||ent=='m')
	{
		goto Z;
	}
	
	printf("%d ", node->data);
	node->hos();
}


int main()
{
	struct node *root = newNode(1);
	root->left		  = newNode(2);
	root->right		  = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	root->right->left =newNode(6);
    
	A:
	printf("\nPostorder traversal of binary tree is \n");
	PostorderTraversal(root);
	getchar();
	string exe;
	cout<<"\n Do you wanna exit \n";
	cin>>exe;
	if(exe=="yes")
	{
		system("pause");
     	return 0;
	}
	else{i=0;
	k++;
	ent='o';
	system("cls");
		goto A;
	}
}

void medicineplz()
{
     S:
     int dose,notes;
     string medtype;
     cout<<"    Medicines available are  "<<endl<<" 1.'Panadol' for fever  ,  rs 100 per dose "<<endl<<" 2.'Buffin' for fever   , es 112 per dose "<<endl<<"3.'DIsprene' for heart , rs 100 per dose"<<endl<<"4.'Caltex' for heart   , rs 15  per dose"<<endl<<"5.'Ogmantun' for lungs , rs 300 per dose"<<endl<<"6.'Honey' for Everthing, rs 500 per dose  ";    
     cout<<endl;
     cin>>medtype;
     cout<<"\nHow much dose of the above medicine do you want ? : ";
     cin>>dose;
     if(medtype=="Panadol")
     {
                           notes=100*dose;
                           paid[k]=paid[k]+notes;
                           }
     if(medtype=="Buffin")
     {
                          notes=112*dose;
                          paid[k]=paid[k]+notes;
                          }
     if(medtype=="DIsprene")
     {
                            notes=100*dose;
                            paid[k]=paid[k]+notes;
                            }
     if(medtype=="Caltex")
     {
                          notes=15*dose;
                          paid[k]=paid[k]+notes;
                          }
     if(medtype=="Ogmantun")
     {
                            notes=300*dose;
                            paid[k]=paid[k]+notes;
                            }
     if(medtype=="Honey")
     {
                         notes=500*dose;
                         paid[k]=paid[k]+notes;
                         }
     string abcd;
     cout<<"If you want anyother medicine also ";
     cin>>abcd;
     if(abcd=="yes")
     {
                    goto S;
                    }
      else
                    {
                        cout<<"Here are your medicines go oN!! much program still left ";                   
                        }
}
void manager()
{
	int givenkey;
                int key=1111;
                cout<<"\nWarning you are entering manager mode if you are foung guility, you will be sent to jail, so you still have time enter 1 in key to retreive \n"; 
                system("pause");
                cout<<"\nEnter the secret key ";
                cin>>givenkey;
                if (givenkey==1)
                {
                    return;
                            }
                if (key==givenkey)
                {
                                 patientlist.display();
                                  system("pause");
                }
                else
                {
                    cout<<"\n Run! the police is after you ";
                    }
}

//"Snake Func."
void run()
{

    initMap();
    running = true;
    while (running) {

        if (kbhit()) {

            changeDirection(getch());
        }

        update();


        clearScreen();


        printMap();


        Sleep(100);
    }

         score=food-3;
    cout << "\t\t Game over!" << endl << "\t\tYour score is: " << score;

         cout<<endl;
        system("pause");
}


void changeDirection(char key) {

    switch (key) {
    case 'w':
        if (direction != 2) direction = 0;
        break;
    case 'd':
        if (direction != 3) direction = 1;
        break;
    case 's':
        if (direction != 4) direction = 2;
        break;
    case 'a':
        if (direction != 5) direction = 3;
        break;
    }
}


void move(int dx, int dy) {

    int newx = headxpos + dx;
    int newy = headypos + dy;


    if (map[newx + newy * mapwidth] == -2) {

        food++;


        generateFood();
    }


    else if (map[newx + newy * mapwidth] != 0) {
        running = false;
    }


    headxpos = newx;
    headypos = newy;
    map[headxpos + headypos * mapwidth] = food + 1;

}


void clearScreen() {

    system("cls");
}


void generateFood() {
    int x = 0;
    int y = 0;
    do {

        x = rand() % (mapwidth - 2) + 1;
        y = rand() % (mapheight - 2) + 1;


    } while (map[x + y * mapwidth] != 0);


    map[x + y * mapwidth] = -2;
}


void update() {

    switch (direction) {
    case 0: move(-1, 0);
        break;
    case 1: move(0, 1);
        break;
    case 2: move(1, 0);
        break;
    case 3: move(0, -1);
        break;
    }


    for (int i = 0; i < size; i++) {
        if (map[i] > 0) map[i]--;
    }
}


void initMap()
{

    headxpos = mapwidth / 2;
    headypos = mapheight / 2;
    map[headxpos + headypos * mapwidth] = 1;


    for (int x = 0; x < mapwidth; ++x) {
        map[x] = -1;
        map[x + (mapheight - 1) * mapwidth] = -1;
    }


    for (int y = 0; y < mapheight; y++) {
        map[0 + y * mapwidth] = -1;
        map[(mapwidth - 1) + y * mapwidth] = -1;
    }


    generateFood();
}


void printMap()
{
    for (int x = 0; x < mapwidth; ++x) {
        for (int y = 0; y < mapheight; ++y) {

            cout << getMapValue(map[x + y * mapwidth]);
        }

        cout <<endl;
    }
}


char getMapValue(int value)
{

    if (value > 0) return 'o';

    switch (value) {
   
    case -1: return 'X';
   
    case -2: return 'O';
    }
}
//"Snake Func."

