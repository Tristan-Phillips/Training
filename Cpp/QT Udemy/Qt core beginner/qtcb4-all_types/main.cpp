#include <QCoreApplication>
#include <QDebug>
#include <array>

struct product
{
    int weight;
    double value;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Booleans can be true or false
    bool boolean = true; // Default is false
    qInfo() << "Boolean: " << boolean;
    boolean = false;
    qInfo() << "Boolean: " << boolean;

    //Integers represent non-decimal numbers
    int x = 10, y = 20;
    qInfo() << "Sum: " << x+y;

    //Characters are 1byte
    char character = 'Y';
    qInfo() << "Do you like tea: " << character;

    //Floating points can be decimal integers
    float pi = 3.14;
    qInfo() << "Pi: " << pi;

    //If you add double before the type it increases the allocateable size for the variable
    double doubleInt = 10;
    qInfo() << "You wont see a difference " << doubleInt;

    // https://www.geeksforgeeks.org/c-data-types/
    /* You also get data modifiers
     * Signed
     * Unsigned
     * Short
     * Long
     */

    //Get the total bytes of memory used
    qInfo() << "Size of int: " << sizeof (x);
    qInfo() << "Size of double: " << sizeof (doubleInt);


    //Const is a property of a variable that means it wont change
    const int id = 215;
    qInfo() << "This value cant change after declaration: " << id;

    //Enums (Create your own type)
    enum Color {red, green, blue = 2};
    Color myColor = Color::green;
    qInfo() << "The colour is indexed at: " << myColor;

    //Structs
    product laptop;
    laptop.weight = 10;
    qInfo() << "The weight is: " << laptop.weight;

    //Arrays
    int ages[4] = {1,2,4,3};
    qInfo() << "This outputs memory location: " << ages;
    ages[1] = 99;
    qInfo() << "Age at position 2 is: " << ages[1]; //Indexes start at 0

    //std -> using namespace std;
    //#Include <array>
    std::array<int, 4> cars;
    qInfo() << "The size of cars array is: " << cars.size();
    qInfo() << "The last elements value is: " << cars[ cars.size() - 1 ]; //-1 because index start at 0

    return a.exec();
}
