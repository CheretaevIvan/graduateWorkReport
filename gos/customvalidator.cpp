#include "customvalidator.h"

QValidator::State WordValidator::validate(QString &text, int &pos) const
{
    QRegExp regex("^([a-zA-Z0-1]+)*$");
    if (regex.exactMatch(text))
        return Acceptable;
    else return Invalid;
}

QValidator::State Ipv4Validator::validate(QString &text, int &pos) const
{
    QRegExp regex("^(?:(?:25[0-5]|2[0-4]\\d|[01]\\d\d|\\d?\d)(?(?=\\.?\\d)\\.)){4}$");
    if (regex.exactMatch(text))
        return Acceptable;
    else return Invalid;
}

QValidator::State Ipv6Validator::validate(QString &text, int &pos) const
{
    QRegExp regex("/^(?>(?>([a-f0-9]{1,4})(?>:(?1)){7}|(?!(?:.*[a-f0-9](?>:|$)){8,})((?1)(?>:(?1)){0,6})?::(?2)?)|(?>(?>(?1)(?>:(?1)){5}:|(?!(?:.*[a-f0-9]:){6,})(?3)?::(?>((?1)(?>:(?1)){0,4}):)?)?(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])(?>\\.(?4)){3}))$/iD");
    if (regex.exactMatch(text))
        return Acceptable;
    else return Invalid;
}

QValidator::State TextValidator::validate(QString &text, int &pos) const
{
    QRegExp regex("^[a-zA-Z\\s\\d\\?><;,\\{\\}\\[\\]\\-_\\+=!@\\$%^&\\*\\|\\']*$");
    if (regex.exactMatch(text))
        return Acceptable;
    else return Invalid;
}
