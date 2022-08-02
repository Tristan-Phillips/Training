#include "listxmlwriter.h"
#include "filewriter.h"
#include <QDomDocument>
#include <QMetaProperty>

ListXmlWriter::ListXmlWriter(CustomerTableModel *model)
    : ctm(model)
{
}

bool ListXmlWriter::write(QString fileName)
{
    // Check if there are Customers in the model
    int numRows = ctm->rowCount(QModelIndex());

    if (numRows == 0) {
        return false;
    }

    QString outStr;

    QDomDocument doc;
    QDomElement root(doc.createElement("customers"));
    doc.appendChild(root);

    // Using model
    for (int row = 0; row < numRows; row++) {

        QDomElement customer(doc.createElement("customer"));
        QString className = ctm->getList().at(row)->metaObject()->className();
        customer.setAttribute("type", className);
        root.appendChild(customer);

        QDomElement title(doc.createElement("title"));
        QDomText titleText(doc.createTextNode(ctm->data(ctm->index(row,0), Qt::DisplayRole).toString()));
        customer.appendChild(title);
        title.appendChild(titleText);

        QDomElement name(doc.createElement("name"));
        QDomText nameText(doc.createTextNode(ctm->data(ctm->index(row,1), Qt::DisplayRole).toString()));
        customer.appendChild(name);
        name.appendChild(nameText);

        QDomElement address(doc.createElement("address"));
        QDomElement street(doc.createElement("street"));
        QDomText streetText(doc.createTextNode(ctm->data(ctm->index(row,2), Qt::DisplayRole).toString()));

        customer.appendChild(address);
        address.appendChild(street);
        street.appendChild(streetText);

        QDomElement suburb(doc.createElement("suburb"));
        QDomText suburbText(doc.createTextNode(ctm->data(ctm->index(row,3), Qt::DisplayRole).toString()));
        address.appendChild(suburb);
        suburb.appendChild(suburbText);

        QDomElement town(doc.createElement("town"));
        QDomText townText(doc.createTextNode(ctm->data(ctm->index(row,4), Qt::DisplayRole).toString()));
        address.appendChild(town);
        town.appendChild(townText);

        QDomElement province(doc.createElement("province"));
        QDomText provinceText(doc.createTextNode(ctm->data(ctm->index(row,5), Qt::DisplayRole).toString()));
        address.appendChild(province);
        province.appendChild(provinceText);

        QDomElement postcode(doc.createElement("postcode"));
        QDomText postcodeText(doc.createTextNode(ctm->data(ctm->index(row,6), Qt::DisplayRole).toString()));
        customer.appendChild(postcode);
        postcode.appendChild(postcodeText);

        QDomElement code(doc.createElement("code"));
        QDomText codeText(doc.createTextNode(ctm->data(ctm->index(row,7), Qt::DisplayRole).toString()));
        customer.appendChild(code);
        code.appendChild(codeText);

        QDomElement balance(doc.createElement("balance"));
        QDomText balanceText(doc.createTextNode(ctm->data(ctm->index(row,8), Qt::DisplayRole).toString()));
        customer.appendChild(balance);
        balance.appendChild(balanceText);

    }

    outStr = doc.toString();

/*
    QString outStr, lineStr, valStr;

    // Using QMetaObject
    const QMetaObject *meta;
    int numProperties;
    QMetaProperty metaProp;

    foreach(Customer *cust, *list->getList()) {
        meta = cust->metaObject();
        numProperties = meta->propertyCount();

        // Start from 1, omit objectName property
        for (int count = 1; count < numProperties; count++) {
            metaProp = meta->property(count);
            const char *name = metaProp.name();
            QVariant value = cust->property(name);

            //qDebug() << "write()  name " << name << Qt::endl;
            if (strcmp(name, "address") == 0) {
                valStr = value.toStringList().join("*");
            }
            else {
                valStr = value.toString();
            }

            lineStr.append(valStr);
            lineStr.append("#");
        }

        // Remove last #
        lineStr.chop(1);
        // Add newline
        lineStr.append("\n");

        outStr.append(lineStr);
    }
*/
/*  // Using getters()
    foreach(Customer *cust, list->getList()) {
        outStr.append(QString("%1#%2#%3#%4#%5#%6\n")
                      .arg(cust->getTitle())
                      .arg(cust->getName())
                      .arg(cust->getAddress().join("*"))
                      .arg(cust->getPostCode())
                      .arg(cust->getCode())
                      .arg(QString::number(cust->getBalance(), 'f', 2)));  // Convert double
    }
*/

    FileWriter fw(fileName);
    if (!fw.write(outStr)) {
        return false;
    }

    return true;
}
