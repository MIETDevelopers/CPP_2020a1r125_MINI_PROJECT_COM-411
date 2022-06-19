/*                       STUDENT REPORT MANAGEMENT SYSTEM
                              MINI PROJECT OF C++
          NAME: UJJWAL SHARMA, BHANU PARTAP SINGH MANHAS, NITISH BALORIA, ARJIT MANHAS
          ROLL NUMBER: 2020A1R116, 2020A1R070, 2020A1R125, 2020A1R130
          BRANCH: COMPUTER SCIENCE AND ENGINEERING
          SEMESTER:4TH
*/
#include <iostream> //STANDARD INPUT-OUTPUT STREAM.
#include <fstream>  //STREAM CLASS TO BOTH READ AND WRITE FROM/TO FILES.
#include <iomanip>  //MANIPULATING THE OUTPUT OF ANY C++ PROGRAM.
using namespace std;     //IT WILL PREVENT DUPLICACY

// THE CLASS THAT STORES DATA
class student       //CREATING CLASS
{    //DECLARING DATA MEMBER IN PRIVATE ACCESS MODIFIER
     int rollno;
     char name[50];
     int RDBMS_MARKS, ENTREPRENEURSHIP_MARKS, COA_MARKS, CPP_MARKS;
     double average;
     char grade;

public:   //DECLARING MEMBER FUNCTION IN PUBLIC ACCESS MODIFER
     void getdata();
     void showdata() const;
     void calculate();
     int retrollno() const;
}; // CLASS ENDS HERE

void student::calculate()          //ACCESSING THE MEMBER FUNCTION USING SCOPE RESOLUTION OPERATOR
{
     average = (RDBMS_MARKS + ENTREPRENEURSHIP_MARKS + COA_MARKS + CPP_MARKS) / 4.0;      //FORMULA OF FINDING THE AVERAGE MARKS/PERCENTAGE
     if (average >= 90)
          grade = 'A';
     else if (average >= 75)
          grade = 'B';
     else if (average >= 50)
          grade = 'C';
     else
          grade = 'F';
}

void student::getdata()   //ACCESSING THE MEMBER FUNCTION USING SCOPE RESOLUTION OPERATOR
{
     cout << "\nENTER STUDENT'S ROLL NUMBER : ";
     cin >> rollno;
     cout << "\nENTER STUDENT'S NAME : ";
     cin.ignore();
     cin.getline(name, 50);
     cout << "\nALL MARKS SHOULD BE OUT OF 100";
     cout << "\nENTER MARKS IN RDBMS : ";
     cin >> RDBMS_MARKS;
     cout << "\nENTER MARKS IN ENTREPRENEURSHIP : ";
     cin >> ENTREPRENEURSHIP_MARKS;
     cout << "\nENTER MARKS IN COA : ";
     cin >> COA_MARKS;
     cout << "\nENTER MARKS IN C++ : ";
     cin >> CPP_MARKS;
     calculate();        //CALLING FUNCTION CALCULATE()
}
void student::showdata() const     //ACCESSING THE MEMBER FUNCTION AND CONST KEYWORD SPECIFIES THE VARIABLE'S VALUE IS CONSTANT
{    //SHOWS THE DATA OF THE STUDENT
     cout << "\nROLL NUMBER OF STUDENT : " << rollno;
     cout << "\nNAME OF STUDENT : " << name;
     cout << "\nRDMBS : " << RDBMS_MARKS;
     cout << "\nENTREPRENEURSHIP : " << ENTREPRENEURSHIP_MARKS;
     cout << "\nCOA : " << COA_MARKS;
     cout << "\nC++ : " << CPP_MARKS;
     cout << "\nAVERAGE MARKS : " << average;
     cout << "\nGRADE OF STUDENT IS : " << grade;
}
int student::retrollno() const     //AGAING ACCESSIING THE MEMBER FUNCTION AND CONST KEYWORD SPECIFIES THAT THE VARIABLE'S VALUE IS CONSTANT
{
     return rollno; //RETURNS THE ROLL NUMBER OF THE STUDENT
}
// FUNCTION DECLARATION
void create_student();
void display_sp(int);     // DISPLAY PARTICULAR RECORD
void display_all();       // DISPLAY ALL RECORDS
void delete_student(int); // DELETE PARTICULAR RECORD
void change_student(int); // EDIT PARTICULAR RECORD
// MAIN PROGRAM
int main()
{
     char ch;
     cout.setf(ios::fixed | ios::showpoint); // MAKES COUT PRINT FLOAT WITH A FIXED NUMBER OF DECIMALS.
     cout << setprecision(2);                // PROGRAM OUTPUTS DECIMAL NUMBER TO TWO DECIMAL PLACES
     do        //DO-WHILE LOOP
     {    //IT WILL PRINT THE MENU UNTIL THE INPUT CONDITION FAILS
          int num;
          system("cls");
          cout << "\n\n\n\tMENU";
          cout << "\n\n\t1. CREATE STUDENT RECORD";
          cout << "\n\n\t2. SEARCH STUDENT RECORD";
          cout << "\n\n\t3. DISPLAY ALL STUDENT RECORDS";
          cout << "\n\n\t4. DELETE STUDENT RECORD";
          cout << "\n\n\t5. MDIFY STUDENT RECORD";
          cout << "\n\n\t6. EXIT";
          cout << "\nENTER YOUR CHOICE ::  ";
          cin >> ch;
          system("cls");      //IT IS USED TO MAKE SCREEN/TERMINAL CLEAR
          switch (ch)    //SWITCH CASE
          {
          case '1':
               create_student();        //FUNCTION CALLING
               break;
          case '2':
               cout << "\n\n\tENTER THE ROLL NUMBER : ";
               cin >> num;
               display_sp(num);         //FUNCTION CALLING
               break;
          case '3':
               display_all();      //FUNCTION CALLING
               break;
          case '4':
               cout << "\n\n\tENTER THE ROLL NUMBER : ";
               cin >> num;
               delete_student(num);          //FUNCTION CALLING
               break;
          case '5':
               cout << "\n\n\tENTER THE ROLL NUMBER : ";
               cin >> num;
               change_student(num);     //FUNCTION CALLING
               break;
          case '6':
               cout << "EXITING, THANK YOU!";
               exit(0);       //EXITING THE TERMINAL
          }
     } while (ch != '6');     //IF CONDITION FAILS THE LOOP TERMINATE
     return 0;
} // END OF MAIN FUNCION
// WRITE STUDENT DETAILS TO FILE
void create_student()    //CREATE THE STUDENT DATA
{
     student stud;  //CREATING OBJECT
     ofstream oFile;     //CREATING FILE
     oFile.open("student.dat", ios::binary | ios::app);     //OPENING OF THE FILE
     stud.getdata();
     oFile.write(reinterpret_cast<char *>(&stud), sizeof(student));   //READS THE STUDENT DATA DIRECTLY FROM A FILE INTO THE MEMORY OCCUPIED BY STUD. 
     oFile.close();      //FILE CLOSING
     cout << "\n\nSTUDENT RECORD HAS BEEN CREATED";
     cin.ignore();
     cin.get();
}    //END OF FUNCTION DEFINITON
// READ FILE RECORDS
void display_all()       //DISPLAY ALL THE DETAILS OF THE STUDENT
{
     student stud;
     ifstream inFile;    //CREATING THE FILE
     inFile.open("student.dat", ios::binary);     //OPENING THE FILE
     if (!inFile)   //CONDITION IF FILE HAVE ANY DATA OR NOT
     {
          cout << "FILE COULD NOT BE OPENED !!\nPRESS ANY KEY TO EXIT";
          inFile.close();
          cin.ignore();
          cin.get();
          return;
     }
     cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
     while (inFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))      //READS THE STUDENT DATA DIRECTLY FROM A FILE INTO THE MEMORY OCCUPIED BY STUD.
     {
          stud.showdata();
          cout << "\n\n====================================\n";
     }
     inFile.close();     //CLOSING THE FILE
     cin.ignore();
     cin.get();
}
// READ SPECIFIC RECORD BASED ON ROLL NUMBER
void display_sp(int n)   //DISPLAYING THE PARTICULAR DATA OF THE STUDENT
{
     student stud;
     ifstream iFile;     //CREATING THE FILE
     iFile.open("student.dat", ios::binary);      //OPENING THE FILE
     if (!iFile)    //CONDITION IF FILE CONTAINS ANY DATA OR NOT
     {
          cout << "FILE COULD NOT BE OPENED...!!\nPRESS ANY KEY TO EXIT";
          cin.ignore();
          cin.get();
          return;
     }
     bool flag = false;
     while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))  //READS THE STUDENT DATA DIRECTLY FROM A FILE INTO THE MEMORY OCCUPIED BY STUD.
     {
          if (stud.retrollno() == n)    //IT WILL PRINT THE DATA OF THE STUDENT 
          {
               stud.showdata();
               flag = true;
          }
     }
     iFile.close();      //CLOSING OF THE FILE
     if (flag == false)
          cout << "\n\nRECORD DOESN'T EXISTS";
     cin.ignore();
     cin.get();
}
// MODIFY RECORDS FOR SPECIFIED ROLL NUMBER
void change_student(int n)    //MODIFIES THE DATA OF THE STUDENT
{
     bool found = false;      //DELCALRING THE VALUE OF FOUND OF DATA TYPE BOOL IS FALSE
     student stud;
     fstream fl;    //CREATING THE FILE
     fl.open("student.dat", ios::binary | ios::in | ios::out);   //OPENING OF THE FLE
     if (!fl)       //CONDITION IF FILE CONTAINS ANY DATA OR NOT
     {
          cout << "FILE COULD NOT BE OPENED...\nPRESS ANY KEY TO EXIT";
          cin.ignore();
          cin.get();
          return;
     }
     while (!fl.eof() && found == false)     //WHILE LOOP 
     {
          fl.read(reinterpret_cast<char *>(&stud), sizeof(student));
          if (stud.retrollno() == n)    //IT WILL PRINT THE DATA OF THE STUDENT
          {
               stud.showdata();
               cout << "\nENTER NEW STUDENT DETAILS : " << endl;
               stud.getdata();
               int pos = (-1) * static_cast<int>(sizeof(stud));
               fl.seekp(pos, ios::cur);
               fl.write(reinterpret_cast<char *>(&stud), sizeof(student));
               cout << "\n\n\t RECORD UPDATED";
               found = true;
          }
     }
     fl.close();    //FILE CLOSING
     if (found == false)      //CONDITION IF THERE IS ANY DATA OR NOT
          cout << "\n\n RECORD NOT FOUND ";
     cin.ignore();
     cin.get();
}
// DELETE RECORD WITH PARTICULAR ROLL NUMBER
void delete_student(int n)    //FUNCTION DEFINITION
{
     student stud;
     ifstream iFile;     //CREATING THE FILE
     iFile.open("student.dat", ios::binary);      //OPENING THE FILE
     if (!iFile)         //CONDITION IF THE FILE CNTAINS ANY DATA OR NOT
     {
          cout << "FILE COULD NOT BE OPENED...\nPRESS ANY KEY TO EXIT";
          cin.ignore();
          cin.get();
          iFile.close();      //CLOSING OF FILE
          return;
     }
     ofstream oFile;     //CREATING ANOTHER FILE
     oFile.open("Temp.dat", ios::out);  //OPENING THE FILE
     iFile.seekg(0, ios::beg);     //IT ALLOWS US TO SEEK AN ARBITRARY POSITION IN A FILE
     while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(student)))
     {
          if (stud.retrollno() != n)
          {
               oFile.write(reinterpret_cast<char *>(&stud), sizeof(student));
          }
     }
     oFile.close();      //CLOSING OF THE FILE
     iFile.close();      //CLOSING THE FILE
     remove("student.dat");   //REMOVING THE STUDENT.DAT FILE
     rename("Temp.dat", "student.dat");      //RENAMING TEMP.DAT FILE TO STUDENT.DAT FILE
     cout << "\n\n\t RECORD DELETED SUCCESSFULLY";
     cin.ignore();
     cin.get();
}
// END OF PROGRAM
