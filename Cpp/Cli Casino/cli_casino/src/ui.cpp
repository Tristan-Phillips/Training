#include "ui.h"

ui::ui(){
}

ui::~ui(){
}

void ui::set_widthTotal(int widthTotal){
    priv_widthTotal=widthTotal;
}

void ui::print_menuHeader() const{
    std::string casinoName = "CASINO ROYAL\n";

    this->set_widthTotal(sizeof(casinoName));

    std::cout<<casinoName;
    for(int i=0; i<priv_widthTotal; i++){
        std::cout<<"X";
    }
}

void ui::print_gameSelection() const{


}

void ui::print_menuFooter() const{

}
