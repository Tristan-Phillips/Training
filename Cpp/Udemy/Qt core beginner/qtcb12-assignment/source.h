#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class source : public QObject
{
    Q_OBJECT
public:
    explicit source(QObject *parent = nullptr);
    void sayHello();
    void doTest();

signals:
    void signal_conversion();
};

#endif // SOURCE_H
