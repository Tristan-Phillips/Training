#include "account.h"

account::account(char account_name[50], bool account_type){
    priv_accountHolderName[50] = account_name[50];
    priv_accountType = account_type;
}

account::~account(){
}

void account::set_accountBalanceUpdate(int depositWithdrawl){
    priv_accountBalance += depositWithdrawl;
}

void account::set_accountInformation(char accountHolderName[50], bool accountType){
    priv_accountHolderName[50] = accountHolderName[50];
    priv_accountType = accountType;
}

int account::get_accountBalance() const{
    return priv_accountBalance;
}

int account::get_accountNumber() const{
    return priv_accountNumber;
}

bool account::get_accountType() const{
    return priv_accountType;
}

int account::generate_accountNumber(){
    return 1; //Temp ToDo: Account Number Generator based on total accounts
}
