#include <iostream>  //  I/O operations
#include <iomanip>   //  Formatting functions
#include <cstdlib>   //  General use library functions
#include <string>    //  Defines dynamic string stuff
#include <limits>

using namespace std;
void numb_error_scrn();//number error void
void transition();//transition void
void titleScreen();//title screen void
void outputscrn(string ISBN, string BookTitle, string Author,int ExpectedEnrollment, int BookCost, string req, string usednew);
void inputscrn(string ISBN, string BookTitle, string Author, string ExpectedEnrollment, string BookCost, string req, string usednew);
void menuerror();
void exitscrn();
double calculation(double BookCost, int ExpectedEnrollment, string req, string book);
int amountofbooks(int enrolled, string required, string book);


string output_screen(string ISBN, string Author, string BookTitle, 
                   string ExpectedEnrollment, string req, string BookCost, string usednew);

string tolower (string value);

int main()//main void
{
	//--------  Start of variable and object creation ------
	string resp="XXXX";//resp
    string ISBN = "XXXX";//isbn
	string BookTitle = "XXXX";//book title
	string Author = "XXXX";//author
	string ExpectedEnrollment = "XXXX";//expected enrollment
	string BookCost = "XXXX";  //book cost
	string req = "XXXX";  //required
	string usednew = "XXXX";//used or new?
    char men;//delaring men as a char var
    int timelock = 0;



    //--------  Beginning of the Title Screen   -------------------

titleScreen();
	//--------  End of the Title Screen  --------------------------
    cout << "  _________________________________________________  " << endl;//3
    cout << " //_______________________________________________\\ " << endl;//4
    cout << "//                                                 \\" << endl;//5
    cout << "||                                                 ||" << endl;//6
    cout << "||        STOCK INVENTORY MANAGEMENT SYSTEM        ||" << endl;//7
    cout << "||                                                 ||" << endl;//8
    cout << "||                  MAIN MENU                      ||" << endl;//9
    cout << "||                                                 ||" << endl;//10
    cout << "||                                                 ||" << endl;//11
    cout << "||                 <I>NPUT DATA>                   ||" << endl;//12
    cout << "||           OUTPUT THE OUT<P>UT.PRN FILE          ||" << endl;//13           
    cout << "||                       EDI<T>                    ||" << endl;//14
    cout << "||                      <E>XIT>                    ||" << endl;//15
    cout << "||                                                 ||" << endl;//16
    cout << "||       PLEASE ENTER 'I', 'P', 'T',  OR 'E'       ||" << endl;//17
    cout << "||                                                 ||" << endl;//18
    cout << "||                                                 ||" << endl;//19
    cout << "||                                                 ||" << endl;//20
    cout << "||                                     04/03/2023  ||" << endl;//21
    cout << " \\_______________________________________________// " << endl;//22
    cout << "  \\_____________________________________________//  " << endl;//23
    do{
    cin >> men;
    switch(men){

    case 'I':
    case 'i':
        cout << "\x1b[2J";
        inputscrn(ISBN, BookTitle, Author, ExpectedEnrollment, BookCost, req, usednew);
        transition();//transitions
        exitscrn();
        break;

    case 'P':
    case 'p':
        
        string str = string(intStr);
        transition();
        cout << outputscrn(ISBN, BookTitle, Author, ExpectedEnrollment, BookCost, req, usednew);
        cout << " Would you like to print it out onto a file called output.prn? (Y/N)"<< endl;
        string toprint;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, toprint);  
         //initiates, clears previous inputs, then set the toprint variable to the userinput  

        if (tolower(toprint) == "y") {
        ofstream outfile("output.prn", ios::trunc);
        outfile << outputscrn(ISBN, BookTitle, Author, ExpectedEnrollment, BookCost, req, usednew);
        outfile.close();
        transition();
        cout << "file was successfully updated" << endl;
    }
    
        cout << "press enter to continue back to the main menu"<< endl;
        cin.get();
        transition();
        break;

    case 'T':
    case 't':
    transition();
    do{ 
    cout << "  _____________________________________________________  " << endl;//3
    cout << " //___________________________________________________\\ " << endl;//4
    cout << "//                                                     \\" << endl;//5
    cout << "||                                                     ||" << endl;//6
    cout << "||          STOCK INVENTORY MANAGEMENT SYSTEM          ||" << endl;//7
    cout << "||                                                     ||" << endl;//8
    cout << "||                    EDIT SCREEN                      ||" << endl;//9
    cout << "||              What would you like to edit?           ||" << endl;//10
    cout << "||                                                     ||" << endl;//11
    cout << "||'1' for  ISBN/barcode                                ||" << endl;//12
    cout << "||'2' for changing title of the book                   ||" << endl;//13           
    cout << "||'3' for changing the authors name                    ||" << endl;//14
    cout << "||'4' for changing number of students                  ||" << endl;//15
    cout << "||'5' for changing the price of the book               ||" << endl;//16
    cout << "||'6' is to let us know if you want a new or used book ||" << endl;//17
    cout << "||'7' is to let us know if the book is required        ||" << endl;//18
    cout << "||                                                     ||" << endl;//19
    cout << "||                                                     ||" << endl;//20
    cout << "||                                         04/03/2023  ||" << endl;//21
    cout << " \\____________________________________________________// " << endl;//22
    cout << "  \\__________________________________________________//  " << endl;//23
        //tells the user the options they have

        char temp;
        cin >> temp;
        //creates and set the the temp variable to what ever the user inputs

        switch(temp){
            case '1':
            {
                cout << "enter the ISBN (barcode) :   " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, ISBN);
                break;
            }
            case '2':
            {
                cout << "enter the title of the book \n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, BookTitle);
                break;
                
            }
            case '3':
            {
                cout << "enter the authors name " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, Author);    
                break;       
            }
            case '4':
            {
                cout << "enter the number of students in your class " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, ExpectedEnrollment);
                break;
                
            }
            case '5':
            {
                cout << "enter the prices of the book " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, BookCost);  
                break;         
                
            }
            case '6':
            {
                cout << "enter 'new' if you want to book to be new, otherwise type something else " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, usednew);
                break;
                
            }
            case '7':
            {
                cout << "enter 'required' if the book is required, otherwise type something else " << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, req);
                break;
            }
            case 'q':
            {
                break;
            }
            default:
            {
                cout << "sorry the input you entered was not recognized, please enter a number 1-6 to edit or 'q' to quit";
                cout << "you will now be taken back to the main menu" <<endl;
            }
        }

    case 'E':
    case 'e':
        exitscrn();
        break;
    }

    default:{
        menuerror();
    }


}while (timelock <= 0);//end of do while loop
    }//end of do, begin while
    while((toupper(men) != 'E') && (toupper(men) != 'I')); //checking if it is e or E

exitscrn();
	return 0;
}/*
END OF INT MAIN
*/
void transition(){//transition void
string resp = "XXXX";
cout<<"              Press <ENTER> to Continue"; getline(cin,resp); ////printing and getting the enter.
cout << "\x1b[2J";


}//end of transition void

void titleScreen()//title screen void
{
    	cout << endl << endl; //2 blank lines
	cout << "  _________________________________________________  " << endl;//3
    cout << " //_______________________________________________\\ " << endl;//4
    cout << "//                                                 \\" << endl;//5
    cout << "||                                                 ||" << endl;//6
    cout << "||        STOCK INVENTORY MANAGEMENT SYSTEM        ||" << endl;//7
    cout << "||                                                 ||" << endl;//F8
    cout << "||                  TITLE SCREEN                   ||" << endl;//9
    cout << "||                                                 ||" << endl;//10
    cout << "||                                                 ||" << endl;//11
    cout << "||                  JUAN SIERRA                    ||" << endl;//12
    cout << "||                                                 ||" << endl;//13
    cout << "||                                                 ||" << endl;//14
    cout << "||                                                 ||" << endl;//15
    cout << "||                                                 ||" << endl;//16
    cout << "||                                                 ||" << endl;//17
    cout << "||                                                 ||" << endl;//18
    cout << "||                                                 ||" << endl;//19
    cout << "||                                                 ||" << endl;//20
    cout << "||                                     04/03/2023  ||" << endl;//21
    cout << " \\_______________________________________________// " << endl;//22
    cout << "  \\_____________________________________________//  " << endl;//23
}//end of title screen void


void exitscrn()
{   cout << endl << endl; //2 blank lines
	cout << "  _________________________________________________  " << endl;//3
    cout << " //_______________________________________________\\ " << endl;//4
    cout << "//                                                 \\" << endl;//5
    cout << "||                                                 ||" << endl;//6
    cout << "||        STOCK INVENTORY MANAGEMENT SYSTEM        ||" << endl;//7
    cout << "||                                                 ||" << endl;//8
    cout << "||                                                 ||" << endl;//9
    cout << "||                                                 ||" << endl;//10
    cout << "||                                                 ||" << endl;//11
    cout << "||         *****************************           ||" << endl;//12
    cout << "||         *Thanks for shopping with us*           ||" << endl;//13
    cout << "||         *****************************           ||" << endl;//14
    cout << "||                                                 ||" << endl;//15
    cout << "||                                                 ||" << endl;//16
    cout << "||                                                 ||" << endl;//17
    cout << "||                                                 ||" << endl;//18
    cout << "||                                                 ||" << endl;//19
    cout << "||                                                 ||" << endl;//20
    cout << "||                                     04/03/2023  ||" << endl;//21
    cout << " \\_______________________________________________// " << endl;//22
    cout << "  \\_____________________________________________//  " << endl;//23
}//exit screen method


void numb_error_scrn()//numb_error void
{
    string ans ="XXX";//declaring ans var

    cout << "\x1b[2J";//clears
    cout << endl << endl; //2 blank lines
	cout << "  _________________________________________________  " << endl;//3
    cout << " //_______________________________________________\\ " << endl;//4
    cout << "//                                                 \\" << endl;//5
    cout << "||                                                 ||" << endl;//6
    cout << "||       STOCK INVENTORY MANAGEMENT SYSTEM         ||" << endl;//7
    cout << "||                                                 ||" << endl;//8
    cout << "||                                                 ||" << endl;//9
    cout << "||                                                 ||" << endl;//10
    cout << "||                                                 ||" << endl;//11
    cout << "||           *************************             ||" << endl;//12
    cout << "||           *OOPS! AN ERROR OCCURRED*             ||" << endl;//13
    cout << "||           *************************             ||" << endl;//14
    cout << "||                                                 ||" << endl;//15
    cout << "||                                                 ||" << endl;//16
    cout << "||                                                 ||" << endl;//17
    cout << "||            ENTER A NUMERICAL VALUE:             ||" << endl;//18
    cout << "||                                                 ||" << endl;//19
    cout << "||                                                 ||" << endl;//20
    cout << "||                                     04/03/2023  ||" << endl;//21
    cout << " \\_______________________________________________// " << endl;//22
    cout << "  \\_____________________________________________//  " << endl;//23
//prompts user for a numeric value

}//End of void numb_error_scrn()


void outputscrn(string ISBN, string BookTitle, string Author,int ExpectedEnrollment, int BookCost, string req, string usednew) {
    double order_factor = 0;//order factor
	double total=0.00; //total
    usednew=toupper(usednew.at(0));
    req=toupper(req.at(0));
if (usednew == "N"){
    if (req == "Y"){//if required
        order_factor=1.0;
    }//if req=y
    else {
        order_factor=0.35;
    }//if req=no

}//if new
else{
    if (req == "Y"){
        order_factor=0.6;
    }//if required
    else{
        order_factor=0.1;
    }//if not required
}//if not new

double dot = order_factor * ExpectedEnrollment;//calculation
total = dot * BookCost;//total calc
int done = static_cast<int>(dot);

    cout << "  _________________________________________________  " << endl;//1
    cout << " //_______________________________________________\\ " << endl;//2
    cout << "//                                                 \\" << endl;//3
    cout << "||                                                 ||" << endl;//4
    cout << "||        STOCK INVENTORY MANAGEMENT SYSTEM        ||" << endl;//5
    cout << "||ISBN:                           " << ISBN << "||"<<endl;
    cout << "||Book Title:                     " << BookTitle << "||"<<endl;
    cout << "||Author:                         " << Author << "||"<<endl;
    cout << "||Expected Enrollment:            " << ExpectedEnrollment << "||"<<endl;
    cout << "||Book Cost:                      $" << BookCost << "||"<<endl;
    cout << "||Required:                       " << req << "||"<<endl;
    cout << "||Used/New?:                      " << usednew << "||"<<endl;
    cout<<dot<<endl;
    cout<<  "||TOTAL:                          $"<<std::fixed << std::setprecision(2) << total << "||"<<endl;

}//outputscreen method

string outputscrn(string ISBN, string BookTitle, string Author,string ExpectedEnrollment, string BookCost, string req, string usednew){
 double newprice = atof(BookCost.c_str());
    int newenroll = atoi(ExpectedEnrollment.c_str());

    stringstream outputToFile;
    outputToFile << "\t\t\t" << endl;
    outputToFile << "-----------------YOUR INPUTS-------------" <<endl;
    outputToFile << "barcode : " << ISBN << endl;
    outputToFile << "author : " << Author << endl;
    outputToFile << "title : " << BookTitle << endl;
    outputToFile << "# of students : " << ExpectedEnrollment << endl;
    outputToFile << "is or is not required : " << req << endl;
    outputToFile << "-----------------------------------------" <<endl;

    outputToFile << "the price is $" << fixed << setprecision(2) << calculation(newprice, newenroll, req, usednew);
    outputToFile << "\nthe number of books needed is : " << amountofbooks(newenroll, req, usednew);
    
    return outputToFile.str();

}

void inputscrn(string ISBN, string BookTitle, string Author, string ExpectedEnrollment, string BookCost, string req, string usednew) {

    cout << "ISBN: ";
    getline(cin, ISBN);

    cout << "Book Title: ";
    getline(cin, BookTitle);

    cout << "Author: ";
    getline(cin, Author);

    cout << "Expected Enrollment: ";
    getline(cin,ExpectedEnrollment); while((std::atoi(ExpectedEnrollment.c_str())<=0))   // checks the character at position 0
    {
        numb_error_scrn(); getline(cin, ExpectedEnrollment);}//pops up error screen if not int


    cout << "Book Cost: ";
    getline(cin,BookCost); while((std::atoi(BookCost.c_str())<=0))   // checks the character at position 0
    {
        numb_error_scrn(); getline(cin, BookCost);}//pops up error screen if not int

    cout << "required (Y/N): ";
    getline(cin,req);

    cout << "used or new (U/N): ";
    getline(cin,usednew);

    transition();

    outputscrn(ISBN, BookTitle, Author, atoi(ExpectedEnrollment.c_str()), atof(BookCost.c_str()), req, usednew);
}//input screen method

void menuerror(){
    cout << "\x1b[2J";//clears
    cout << endl << endl; //2 blank lines
	cout << "  _________________________________________________  " << endl;//3
    cout << " //_______________________________________________\\ " << endl;//4
    cout << "//                                                 \\" << endl;//5
    cout << "||                                                 ||" << endl;//6
    cout << "||       STOCK INVENTORY MANAGEMENT SYSTEM         ||" << endl;//7
    cout << "||                                                 ||" << endl;//8
    cout << "||                                                 ||" << endl;//9
    cout << "||                                                 ||" << endl;//10
    cout << "||                                                 ||" << endl;//11
    cout << "||           *************************             ||" << endl;//12
    cout << "||           *OOPS! AN ERROR OCCURRED*             ||" << endl;//13
    cout << "||           *************************             ||" << endl;//14
    cout << "||                                                 ||" << endl;//15
    cout << "||                                                 ||" << endl;//16
    cout << "||                                                 ||" << endl;//17
    cout << "||        PLEASE ENTER 'I', 'P', 'T',  OR 'E'      ||" << endl;//18
    cout << "||                                                 ||" << endl;//19
    cout << "||                                                 ||" << endl;//20
    cout << "||                                     04/03/2023  ||" << endl;//21
    cout << " \\_______________________________________________// " << endl;//22
    cout << "  \\_____________________________________________//  " << endl;//23
}


double calculation(double BookCost, int ExpectedEnrollment, string req, string book) {
    double numBooks;
    double factored = 1;
    if (book == "new") {
        if (req == "required") {
            factored = 1.0;   // Book is new and required
        }
        else {
            factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if (req == "required") {
            factored = 0.6;  // Book is not new but is required
        }
        else {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks = ExpectedEnrollment * factored;
    double cost = numBooks * BookCost;
    return cost;
}

int amountofbooks (int enrolled, string required, string book){
    double numBooks = enrolled;
    double factored = 1;
    if(book == "new"){
        if(required == "required"){
         factored = 1.0;   // Book is new and required
        }
        else{
         factored = 0.35;  // Book is new but not required
        }
    }
    else {
        if(required == "required"){
            factored = 0.6;  // Book is not new but is required
        }
        else  {
            factored = 0.1;  // Book is not new and is not required
        }
    }
    numBooks= enrolled * factored;
    return numBooks;
}