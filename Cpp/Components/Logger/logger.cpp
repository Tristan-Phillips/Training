#include "logger.h"

//Initialize static variables
QString Logger::m_filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool Logger::m_logging = false;
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent)
    : QObject{parent}
{

}

void Logger::attach()
{
    Logger::m_logging = true;
    qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(Logger::m_logging){
        QString text;
        switch(type){
        case QtInfoMsg:
            text = QString("Info: %1 in %2").arg(msg);
            break;
        case QtDebugMsg:
            text = QString("Debug: %1").arg(msg);
            break;
        case QtWarningMsg:
            text = QString("Warning: %1").arg(msg);
            break;
        case QtCriticalMsg:
            text = QString("Critical: %1").arg(msg);
            break;
        case QtFatalMsg:
            text = QString("Fatal: %1").arg(msg);
            break;
        }

        QFile file(Logger::m_filename);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream ts(&file);
            ts << QDateTime::currentDateTime().toString() << " - " << text << context.file
               << Qt::endl;
            ts.flush();
            file.close();
        }
    }

    //Passing back to default message handler
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}
