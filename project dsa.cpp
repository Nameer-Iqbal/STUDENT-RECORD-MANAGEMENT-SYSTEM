#include <iostream>
using namespace std;  
class Node {
public:
    int roll;
    string Name;
    string Dept;
    int Marks;
    Node* next;
    
};
 

Node* head = new Node();
 

bool check(int x)
{
    
    if (head == NULL)
        return false;
 
    Node* t = new Node;
    t = head;
 

    while (t != NULL) {
        if (t->roll == x)
            return true;
        t = t->next;
    }
 
    return false;
}
 

void Insert_Record(int roll, string Name,
                   string Dept, int Marks)
{

    if (check(roll)) {
    	 cout<<"\n--------------------------------\n";
        cout << "Student with this "
             << "record Already Exists\n";
         cout<<"\n--------------------------------\n";
		return;
    }
 
   
    Node* t = new Node();
    t->roll = roll;
    t->Name = Name;
    t->Dept = Dept;
    t->Marks = Marks;
    t->next = NULL;
 
   
    if (head == NULL
        || (head->roll >= t->roll)) {
        t->next = head;
        head = t;
    }
 


    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->roll < t->roll) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
 cout<<"\n--------------------------------\n";
    cout << "Record Inserted "
         << "Successfully\n";
 cout<<"\n--------------------------------\n";
}
 

void Search_Record(int roll)
{
  
    if (!head) {
    	 cout<<"\n--------------------------------\n";
        cout << "No such Record "
             << "Available\n";
             cout<<"\n please try again";
              cout<<"\n--------------------------------\n";
        return;
    }
 


    else {
        Node* p = head;
        
        while (p) 
		{
            if (p->roll == roll) 
			{
				
                cout << "Roll Number\t"
				     << p->roll << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Department\t"
                     << p->Dept << endl;
                cout << "Marks\t\t"
                     << p->Marks << endl;
                return;
            }
            p = p->next;
        }
        
 
        if (p == NULL)
         cout<<"\n--------------------------------\n";
            cout << "No such Record "
                 << "Available\n";
                  cout<<"\n--------------------------------\n";
    }
}
 



int Delete_Record(int roll)
{
    Node* t = head;
    Node* p = NULL;
 
    
    if (t != NULL
        && t->roll == roll) {
        head = t->next;
        delete t;
 
          cout<<"\n--------------------------------\n";
        cout << "Record Deleted "
             << "Successfully\n";
              cout<<"\n--------------------------------\n";
        return 0;
    }
 

    while (t != NULL && t->roll != roll) {
        p = t;
        t = t->next;
        
    }
    if (t == NULL)
	 {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;
 
        delete t;
         cout<<"\n--------------------------------\n";
        cout << "Record Deleted "
             << "Successfully\n";
              cout<<"\n--------------------------------\n";
 
        return 0;
    }
    
    
}
 


void Show_Record()

{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }
    else {
        cout << "Roll number \tName\tCourse"
             << "\tMarks\n";
 
    
    
        while (p != NULL) {
            cout << p->roll << "    \t"
                 << p->Name << "\t"
                 << p->Dept << "\t"
                 << p->Marks << endl;
            p = p->next;
        }
    }
}
 


int main()
{
    head = NULL;
    string Name, Course;
    int Roll, Marks;
 
  
    while (true) {

          
		  cout<<"\n\tWELCOME TO THE STUDENT RECORD SYSTEM "<<endl;
		       cout<<"\n\tselect the following options";
			   cout<<"\n\t1 to create a new student record"; 
			   cout<<"\n\t2 to delete a student record";
			   cout<<"\n\t3 to search a student record";
			   cout<<"\n\t4 to view all the student records";
			   cout<<"\n\t5 to Exit\n";
        cout << "\n\tEnter your Choice\n";
        int Choice;
 
      
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "\nEnter Roll Number of Student\n";
            cin >> Roll;
            cout << "\nEnter Course of Student \n";
            cin >> Course;
            cout << "\nEnter Total Marks of Student\n";
            cin >> Marks;
            Insert_Record(Roll, Name, Course, Marks);
        }
        else if (Choice == 2) {
            cout << "\nEnter Roll Number of Student whose "
                    "record is to be deleted\n";
            cin >> Roll;
            Delete_Record(Roll);
        }
        else if (Choice == 3) {
            cout << "\nEnter Roll Number of Student whose "
                    "record you want to Search\n";
            cin >> Roll;
            Search_Record(Roll);
        }
        else if (Choice == 4) {
            Show_Record();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
