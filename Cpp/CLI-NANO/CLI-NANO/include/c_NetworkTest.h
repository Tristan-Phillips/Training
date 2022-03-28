#ifndef C_NETWORKTEST_H
#define C_NETWORKTEST_H
#include <netcon.h>
#include "c_NodeRPC.h"

class c_NetworkTest
{
    public:
        c_NetworkTest(string v_networkAddress);
        virtual ~c_NetworkTest();

        //Getter
        bool get_networkConnection();

        //Setter
        void set_networkAddress(string v_networkAddress);

    protected:

    private:
        string m_networkAddress;
};

#endif // C_NETWORKTEST_H
