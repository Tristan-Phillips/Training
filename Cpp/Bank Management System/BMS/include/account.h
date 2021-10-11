#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
    /*The iostream library is an object-oriented library that provides input and output
    functionality using streams [https://www.cplusplus.com/reference/iolibrary/]*/
#include <fstream>
    /*Objects of this class maintain a filebuf object as their internal stream buffer, which performs
    input/output operations on the file they are associated with  [https://www.cplusplus.com/reference/fstream/fstream/]*/
#include <cctype>
    /*This header declares a set of functions to classify and transform individual
    characters [https://www.cplusplus.com/reference/cctype/]*/
#include <iomanip>
    /*iomanip is a library that is used to manipulate the output of C++ program.
    [https://www.tutorialspoint.com/cpp_standard_library/iomanip.htm]*/

class account
{
    public:
        account();
        virtual ~account();
        void create_account();	//function to get data from user
        void show_account() const;	//function to show data on screen
        void modify();	//function to add new data
        void dep(int);	//function to accept amount and add to balance amount
        void draw(int);	//function to accept amount and subtract from balance amount
        void report() const;	//function to show data in tabular format
        int retacno() const;	//function to return account number
        int retdeposit() const;	//function to return balance amount
        char rettype() const;	//function to return type of account


    protected:

    private:
        int acno;
        char name[50];
        int deposit;
        char type;
};

#endif // ACCOUNT_H
