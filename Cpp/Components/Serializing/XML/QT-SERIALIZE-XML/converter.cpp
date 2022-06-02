#include "converter.h"

Converter::Converter(QObject *parent)
    : QObject{parent}
{

}

void Converter::writeXML(OClass *obj, QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "Could not write to file!";
        qCritical () << file.errorString();
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);

    /*1*/stream.writeStartDocument();
    /*2*/stream.writeStartElement("Parent");
    stream.writeAttribute("Attribute", obj->objectName());

    /*3*/stream.writeStartElement("Child");
    foreach(QString key, obj->get_map().keys()){
        /*4*/stream.writeStartElement("Siblings");
        stream.writeAttribute("Key", key);
        stream.writeAttribute("Value", obj->get_map().value(key));
        /*4*/stream.writeEndElement();
    }

    /*3*/stream.writeEndElement();
    /*2*/stream.writeEndElement();
    /*1*/stream.writeEndDocument();

    file.flush();
    file.close();
}

OClass *Converter::readXML(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not read from file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QXmlStreamReader stream(data);
    OClass *obj = new OClass();
    QMap<QString, QString> map;

    while (!stream.atEnd()) {
        QXmlStreamReader::TokenType token = stream.readNext();
        switch (token) {
        case QXmlStreamReader::Comment:
            break;
        case QXmlStreamReader::DTD:
            break;
        case QXmlStreamReader::Characters:
            break;
        case QXmlStreamReader::ProcessingInstruction:
            break;
        case QXmlStreamReader::EntityReference:
            break;
        case QXmlStreamReader::NoToken:
            break;
        case QXmlStreamReader::Invalid:
            break;
        case QXmlStreamReader::EndDocument:
            obj->set_map(map);
            break;
        case QXmlStreamReader::StartElement:
            if(stream.name() == "Parent"){
               QString name = stream.attributes().value("Attribute").toString();
               obj->set_name(name);
            }
            if(stream.name() == "Siblings"){
                QString key = stream.attributes().value("Key").toString();
                QString value = stream.attributes().value("Value").toString();
                map.insert(key,value);
            }
            break;
        case QXmlStreamReader::EndElement:
            break;
        }
    }
    return obj;
}
