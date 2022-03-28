#include "c_NodeRPC.h"

//Setter
void c_NodeRPC::set_account(string v_account){

}
void c_NodeRPC::set_api(string v_api){

}

c_NodeRPC::c_NodeRPC(string v_account, string v_api)
{
    set_account(v_account);
    set_api(v_api);
}

c_NodeRPC::~c_NodeRPC()
{
    //dtor
}

//Getters
string c_NodeRPC::get_account(){

}
string c_NodeRPC::get_accountRepresentative(){

}
long int c_NodeRPC::get_accountWeight(){

}
long int c_NodeRPC::get_balanceConfirmed(){

}
long int c_NodeRPC::get_balancePending(){

}
void c_NodeRPC::print_accountAll(){
    cout << "ACCOUNT INFORMATION\n===================" << endl;

}
