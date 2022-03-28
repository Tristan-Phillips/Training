#ifndef C_NANONODE_H
#define C_NANONODE_H


class c_nanoNode
{
    public:
        c_nanoNode();
        virtual ~c_nanoNode();

        //Get Info Classes
        float get_accountBalance();

    protected:

    private:
        string m_publickKey;
        float m_lastUpdatedBalance;
};

#endif // C_NANONODE_H
