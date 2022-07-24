#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string.h>

class QLabel;
class QPushButton;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setupUi();

public slots:
    void slot_updateQrCode();
private:
    QLabel *m_qrCode;
    QPushButton *m_pushButtonGenerate;
    QLineEdit *m_pullValue;
};
#endif // WIDGET_H
