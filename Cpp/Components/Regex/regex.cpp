#include "regex.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

regex::regex()
{}

bool regex::checkMatch(QString str){
    QRegularExpression singleCapitalLetter("^[A-Z]$");
    QRegularExpressionMatch regexMatch = singleCapitalLetter.match(str);
    if(regexMatch.hasMatch()){
        return true;
    }else{
        return false;
    }
}
