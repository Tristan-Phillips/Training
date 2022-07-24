#include "widget.h"
#include "qrcodegen.hpp"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

#include <string.h>
#include <vector>
#include <QImage>
#include <QLabel>

using namespace qrcodegen;

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      m_qrCode(new QLabel),
      m_pushButtonGenerate(new QPushButton("Generate")),
      m_pullValue(new QLineEdit)
{
    setupUi();
    connect(m_pushButtonGenerate, SIGNAL(clicked()), this, SLOT(slot_updateQrCode()));
}

Widget::~Widget()
{
}

void Widget::setupUi()
{
    this->setWindowTitle("Qr Code - Generator");
    QVBoxLayout *vboxLayout = new QVBoxLayout;

    m_pullValue->setPlaceholderText("Input Value");

    vboxLayout->addWidget(m_pullValue);
    vboxLayout->addWidget(m_qrCode);
    vboxLayout->addWidget(m_pushButtonGenerate);

    this->setLayout(vboxLayout);
}

void Widget::slot_updateQrCode()
{
    m_qrCode->setText("");
    QString str = m_pullValue->text();

    this->setWindowTitle(str);
    QrCode qr = QrCode::encodeText(str.toUtf8().data(), QrCode::Ecc::MEDIUM);
    qint32 size = qr.getSize();

    QImage image(size, size, QImage::Format_RGB32);
    QRgb black = qRgb(0,0,0);
    QRgb white = qRgb(255,255,255);

    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            image.setPixel(x,y,qr.getModule(x,y)? black : white);
        }
    }
    m_qrCode->setPixmap(QPixmap::fromImage(image.scaled(256,256,Qt::KeepAspectRatio, Qt::FastTransformation),Qt::MonoOnly));
}

