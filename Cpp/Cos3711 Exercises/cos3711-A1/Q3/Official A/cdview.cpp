#include "cdview.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QHeaderView>

#include "musicmodel.h"

CDView::CDView(QWidget *parent)
    : QWidget(parent),
      model(new MusicModel(this)),
      view(new QTableView()),
      edtComposer(new QLineEdit),
      edtTitle(new QLineEdit),
      dspCost(new QDoubleSpinBox),
      spnRating(new QSpinBox),
      btnAdd(new QPushButton("Add")),
      btnDelete(new QPushButton("Delete"))
{
    // Setup GUI
    setupGUI();
    setWindowTitle("Music");

    // Setup model / view
    setupView();

    // Connect signals and slots
    connect(btnAdd, &QPushButton::clicked, this, &CDView::addCD);
    connect(btnDelete, &QPushButton::clicked, this, &CDView::deleteCD);
}

void CDView::addCD()
{
    QList<QStandardItem*> row;

    QStandardItem *composer(new QStandardItem(edtComposer->text()));
    row.append(composer);

    QStandardItem *title(new QStandardItem(edtTitle->text()));
    row.append(title);

    QStandardItem *price(new QStandardItem(QString::number(dspCost->value())));
    row.append(price);

    QStandardItem *rating(new QStandardItem(QString::number(spnRating->value())));
    row.append(rating);

    model->appendRow(row);
    view->resizeColumnsToContents();

    // Clear GUI
    edtComposer->clear();
    edtTitle->clear();
    dspCost->setValue(0.00);
    spnRating->setValue(0);
    edtComposer->setFocus();
}

void CDView::deleteCD()
{
    QModelIndex index = view->currentIndex();

    if (!index.isValid()) {

        QMessageBox::warning(this, "Delete CD", "No CD selected");

        return;
    }

    int response = QMessageBox::question(this, "Delete CD", "Are you sure you want to delete CD ?",
                          QMessageBox::Yes | QMessageBox::Cancel);

    if (response == QMessageBox::Yes) {

            int row = index.row();
            model->removeRow(row);
    }

    edtComposer->setFocus();
}

void CDView::setupView()
{
    // Setup headers
    QStringList headers;
    headers << "Composer" << "Album title" << "Replacement cost" << "Rating";
    model->setHorizontalHeaderLabels(headers);

    // Initialize view
    view->setSortingEnabled(true);
    view->setModel(model);
    view->horizontalHeader()->setStretchLastSection(true);
}

void CDView::setupGUI()
{
    QLabel *lblComposer(new QLabel("Composer"));
    QLabel *lblTitle(new QLabel("Album title"));
    QLabel *lblCost(new QLabel("Replacement cost"));
    QLabel *lblRating(new QLabel("Rating"));

    QGridLayout *layout(new QGridLayout(this));
    layout->addWidget(lblComposer, 0, 0);
    layout->addWidget(lblTitle, 0, 1);
    layout->addWidget(lblCost, 0, 2);
    layout->addWidget(lblRating, 0, 3);
    layout->addWidget(edtComposer, 1, 0);
    layout->addWidget(edtTitle, 1, 1);
    layout->addWidget(dspCost, 1, 2);
    layout->addWidget(spnRating, 1, 3);
    layout->addWidget(btnAdd, 1, 4);
    layout->addWidget(view, 2, 0, 1, 5);
    layout->addWidget(btnDelete, 3, 4);

    // Initialize widgets
    dspCost->setRange(0.00, 9999.99);
    dspCost->setAlignment(Qt::AlignRight);
    dspCost->setToolTip("Maximum value 9999.99");
    dspCost->setDecimals(2);

    spnRating->setMinimumWidth(80);
    spnRating->setMaximum(100);
    spnRating->setAlignment(Qt::AlignRight);
    spnRating->setToolTip("Rating 0 - 100");

    edtComposer->setToolTip("Enter composer name");
    edtTitle->setToolTip("Enter album title");
    btnAdd->setToolTip("Add a CD");
    btnDelete->setToolTip("Delete a CD");
    view->setToolTip("Double-click on cell to edit");
}
