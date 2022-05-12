#include <QApplication>
#include "cdview.h"

/*Whats not done
- No color change
- Cant delete entry
- Cant sort by column header
*/

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    CDView form;

    form.show();

    return app.exec();
}
