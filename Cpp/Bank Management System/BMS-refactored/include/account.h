#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "function.h"

class account
{
    public:
        account(char account_name[50], bool account_type=false);
        virtual ~account();

        //Setters
        void set_accountBalanceUpdate(int depositWithdrawl);
        void set_accountInformation(char accountHolderName[50], bool accountType);

        //Getters
        int get_accountBalance() const;
        int get_accountNumber() const;
        bool get_accountType() const;

        //Print
        void print_account() const;

        //Generator
        int generate_accountNumber();

    private:
        int priv_accountBalance;
        int priv_accountNumber;
        char priv_accountHolderName[50];
        bool priv_accountType; //False = Debit ; True = Credit
};

#endif // ACCOUNT_H
