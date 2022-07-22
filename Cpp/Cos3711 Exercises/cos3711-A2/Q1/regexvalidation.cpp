#include "regexvalidation.h"
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

RegExValidation::RegExValidation(QString *words) :
    toBeChecked{words}
{}

QString RegExValidation::regexSort()
{
    QStringList *xmlElements = getXMLElements();
    QStringList *startTagList = new QStringList,
            *endTagList = new QStringList;
    int emptyElementCount = 0;

    QRegularExpression regex_startTag("<[a-zA-Z\\d_]+>"); //Fix These Regexes
    QRegularExpression regex_endTag("</[a-zA-Z\\d_]*>");
    //QRegularExpression regex_emptyTag("<( |/?)>");
    QRegularExpression regex_emptyTag("<[a-zA-Z\\d_]*/>");

    for(int i = 0; i < xmlElements->size(); i++){
        QString currentWord = xmlElements->at(i);
        QRegularExpressionMatch match_startTag = regex_startTag.match(currentWord);
        QRegularExpressionMatch match_endTag = regex_endTag.match(currentWord);
        QRegularExpressionMatch match_emptyElements = regex_emptyTag.match(currentWord);

        if(match_startTag.hasMatch()){
            startTagList->append(currentWord);
        }
        if(match_endTag.hasMatch()){
            endTagList->append(currentWord);
        }
        if(match_emptyElements.hasMatch()){
            emptyElementCount++;
        }
    }

    QString result = generateOutputString(startTagList, endTagList, emptyElementCount);
    return result;
}

//Finds all regexMatches in QString and returns them appended to a QStrinList
QStringList *RegExValidation::getXMLElements()
{
    QStringList *xmlElements = new QStringList;
    QRegularExpression regex_XMLElements("(<.+?>)");

    QRegularExpressionMatchIterator regex_iterator = regex_XMLElements.globalMatch(toBeChecked);
    while(regex_iterator.hasNext()){
        QRegularExpressionMatch regex_match = regex_iterator.next();
        xmlElements->append(regex_match.captured(0));
    }
    return xmlElements;
}

QString RegExValidation::generateOutputString(QStringList *startTags, QStringList *endTags, int emptyElementCount)
{
    QString result;
    removeMatchedTags(startTags, endTags);
    if(!startTags->empty()){
        result += "START TAGS WITH NO END TAGS\n";
        for(int i = 0; i < startTags->size(); i++){
            result += startTags->at(i)+"\n";
        }
    }
    if(!endTags->empty()){
        result += "END TAGS WITH NO START TAGS\n";
        for(int i = 0; i < endTags->size(); i++){
            result += endTags->at(i)+"\n";
        }
    }
    if(emptyElementCount != 0){
        result += "EMPTY TAGS\n";
        for(int i = 0; i < emptyElementCount; i++){
            result += "<empty_element_"+QString::number(i)+"/>\n";
        }
    }
    return result;
}

void RegExValidation::removeMatchedTags(QStringList *startTags, QStringList *endTags)
{
    for(int startTagIterator = 0; startTagIterator < startTags->size(); startTagIterator++){
        for(int endTagIterator = 0; endTagIterator < endTags->size(); ++endTagIterator){
            QString currentStartTag = startTags->at(startTagIterator);
            QString currentEndTag = endTags->at(endTagIterator);
            currentEndTag.remove("/");
            if(currentStartTag == currentEndTag){
                startTags->removeAt(startTagIterator);
                endTags->removeAt(endTagIterator);
                startTagIterator = 0;
                endTagIterator = 0;
            }
        }
    }
}
