#include "api.h"

API::API(QString apiKey)
{
    API::set_apiKey(apiKey);
}

QString API::get_apiKey() const
{
    return mq_apiKey;
}

bool API::set_apiKey(QString apiKey)
{
    //TODO - VALIDATION WITH REGEX
    mq_apiKey = apiKey;
    return true; //ADD CONDITIONS FOR T/F
}
