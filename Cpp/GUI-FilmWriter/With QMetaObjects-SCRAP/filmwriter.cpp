#include "filmwriter.h"
#include <QMetaObject>

FilmWriter::FilmWriter(QString filePath)
{
    m_filePath = filePath;
}

bool  FilmWriter::saveFilm(Film &film)
{
    //GET metaobject
    const QMetaObject *metaObject = film.metaObject();
    QString className = metaObject->className();
    int propertyCount = metaObject->propertyCount();

    for(int i = 0; i < propertyCount; i++){
        QMetaProperty metaProperty = metaObject->property(i);
        QString propertyName = QString(metaProperty.name());
        //const char *propertyName = QString(metaProperty.name());

        QVariant value = film.property(propertyName);
    }

    QFile file(m_filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);

        QString title = film.property("m_title").toString();
        QString director = film.property("m_director").toString();
        int duration = film.property("m_duration").toInt();
        QDate releaseDate = film.property("m_releaseDate").toDate();

        QString result = QString("Title: %1, Director: %2, Duration: %3, Release Date: %4")
                .arg(title)
                .arg(director)
                .arg(duration)
                .arg(releaseDate.toString("dd-MM-yyyy"));

//        out << film.toString();
          out << result;
        return true;
    }
    return false;
}
