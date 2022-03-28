#ifndef C_NODERPC_H
#define C_NODERPC_H
#include <string>
#include <iostream>

using namespace std;

class c_NodeRPC
{
    public:
        c_NodeRPC(string v_account, string v_api);
        virtual ~c_NodeRPC();

        //Utility Functions
        void print_accountAll();

        //Getter
        string get_account();
        string get_accountRepresentative();
        long int get_accountWeight();
        long int get_balanceConfirmed();
        long int get_balancePending();

        //setter
        void set_account(string v_account);
        void set_api(string v_api);

    protected:
    private:
        string m_account;
        string m_api;
};

#endif // C_NODERPC_H
