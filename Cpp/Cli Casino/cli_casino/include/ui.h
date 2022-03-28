#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
class ui
{
    public:
        ui();
        virtual ~ui();

        void print_menuHeader() const;
        void print_gameSelection() const;
        void print_menuFooter() const;

        void set_widthTotal(int);

    private:
        int priv_widthTotal;
};

#endif // UI_H
