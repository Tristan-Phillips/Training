#ifndef API_H
#define API_H
#include <QObject>

//Public API: https://rapidapi.com/baskarm28/api/chain/

class API : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mq_apiKey READ get_apiKey WRITE set_apiKey)
public:
    API(QString apiKey);
    //Getter
    QString get_apiKey() const;
    //Setter
    bool set_apiKey(QString apiKey);
};

#endif // API_H
