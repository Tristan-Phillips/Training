#include <iostream>
#include "c_NodeRPC.h"
#include "c_NetworkTest.h"

using namespace std;

int main()
{
    string networkAddress("nano.nownodes.io");

    cout<<"Testing Connection ..."<<endl;
    c_NetworkTest test(networkAddress);
    if(!test.get_networkConnection()){
        cout<<"Connection to nano.nownodes.io unnavialable"<<endl;
        return 0;
    }

    cout<<"Input your Nano Address: ";
    string temp_address;
    cin>>temp_address;

    cout<<"Input your NOWNodes API Key: ";
    string temp_api;
    cin>>temp_api;

    c_NodeRPC node(temp_address, temp_api);
    cout<<"\n\n"<<endl;

    node.print_accountAll();


    return 0;
}
