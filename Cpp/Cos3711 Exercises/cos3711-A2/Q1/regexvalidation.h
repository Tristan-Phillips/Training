#ifndef REGEXVALIDATION_H
#define REGEXVALIDATION_H

//Forward Declerations
class QStringList;
class QString;

class RegExValidation
{
public:
    RegExValidation(QString *words);
    QString regexSort();
private:
    //Lists
    QString *toBeChecked;
    //private Function
    QStringList *getXMLElements();
    QString generateOutputString(QStringList *startTags, QStringList *endTags, int emptyElementCount);
    void removeMatchedTags(QStringList *startTags, QStringList *endTags);
};

#endif // REGEXVALIDATION_H
