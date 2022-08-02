#include "listxmlreader.h"
#include "filereader.h"
#include "customerfactory.h"
#include "customer.h"
#include <QStringList>
#include <QString>
#include <QVariant>
#include <QXmlStreamReader>
#include <QFile>
#include <QTextStream>

#include <QMessageBox>

ListXmlReader::ListXmlReader()
{
}

QList<Customer*> ListXmlReader::read(QString fileName) const
{
    // Instantiate customer list and strings
    QList<Customer*> cl;
    QString className, title, name, street, suburb, town, province, postCode, code, balance;
    QStringList address;

    QTextStream cout(stdout);

    // Open file
    QFile inFile(fileName);
    if (!inFile.open(QIODevice::ReadOnly)) {
        // Return empty list
        cout << "Cannot open file: " << fileName << Qt::endl;
        return cl;
    }

    // Declare reader, and set file
    QXmlStreamReader reader(&inFile);

    // Check if the file is a list of customers
    reader.readNextStartElement();
    if (reader.name().toString() == "customers") {

        reader.readNext();
        // Read data from file
        while (!reader.atEnd()) {

            if (reader.isStartElement()) {

                if (reader.name().toString() == "customer") {
                    // Read attribute
                    foreach(const QXmlStreamAttribute &attr, reader.attributes()) {
                        if (attr.name().toString() == "type") {
                            className = attr.value().toString();
                        }
                    }
                }
                else if (reader.name().toString() == "title") {
                    title = reader.readElementText();
                }
                else if (reader.name().toString() == "name") {
                    name = reader.readElementText();
                }
                else if (reader.name().toString() == "street") {
                    street = reader.readElementText();
                }
                else if (reader.name().toString() == "suburb") {
                    suburb = reader.readElementText();
                }
                else if (reader.name().toString() == "town") {
                    town = reader.readElementText();
                }
                else if (reader.name().toString() == "province") {
                    province = reader.readElementText();
                }
                else if (reader.name().toString() == "postcode") {
                    postCode = reader.readElementText();
                }
                else if (reader.name().toString() == "code") {
                    code = reader.readElementText();
                }
                else if (reader.name().toString() == "balance") {
                    balance = reader.readElementText();
                }
            } // End start element

            if (reader.isEndElement()) {

                if (reader.name().toString() == "address") {
                    // End of address input
                    // Clear address stringlist
                    address.clear();

                    // Populate address stringlist
                    address << street << suburb << town << province;
                }
                else if (reader.name().toString() == "customer") {
                    // End of customer input
                    // Instantiate Customer object
                    Customer *customer;
                    CustomerFactory cf;
                    customer = cf.createCustomer(className,
                                      title,
                                      name,
                                      address,
                                      postCode,
                                      code,
                                      balance.toDouble());

                    if (customer != nullptr) {

                        // Ony add Customer to customer list if not null
                        cl.append(customer);
                    }
                }
            } // End end element

            reader.readNext();
         } // End while !reader.atEnd()

    } // End customers list
    else {
        // Not a customer list
        cout << "XML file is not a customer list" << Qt::endl;
    }

    // Close file
    inFile.close();

    // Return customer list - default returns empty customer list
    return cl;
}
