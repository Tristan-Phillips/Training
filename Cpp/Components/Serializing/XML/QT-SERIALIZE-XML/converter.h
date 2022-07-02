#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>
#include <QVariantMap>
#include <QMap>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "oclass.h"

class Converter : public QObject
{
    Q_OBJECT
public:
    //Explicit to avoid implicit conversion
    explicit Converter(QObject *parent = nullptr);

    static void writeXML(OClass *obj, QString path);
    static OClass *readXML(QString path);

};

#endif // CONVERTER_H
