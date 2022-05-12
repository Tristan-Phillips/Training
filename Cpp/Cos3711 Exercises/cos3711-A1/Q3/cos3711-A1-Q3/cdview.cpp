#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <QTableView>
#include <QVBoxLayout>

#include "cdview.h"
#include "cdmodel.h"

CDView::CDView(QWidget *parent)
    : QWidget(parent),
      m_pullComposer(new QLineEdit(this)),
      m_pullAlbumName(new QLineEdit(this)),
      m_pullCost(new QDoubleSpinBox(this)),
      m_pullRating(new QSpinBox(this)),
      m_submitAdd(new QPushButton("&Add", this)),
      m_submitDelete(new QPushButton("&Delete", this)),
      m_CDModel(new CDModel(this))
{
    setupUI();
}

void CDView::setupUI()
{
    this->setWindowTitle("Music CD's");

    //Constraints
    m_pullRating->setRange(0, 100);
    m_pullCost->setMinimum(0);
    m_pullCost->setDecimals(2);

    //Layout
    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    QVBoxLayout *vBoxLayout_tableView = new QVBoxLayout;

    QLabel *labelComposer(new QLabel("Composer")),
            *labelTitle(new QLabel("Album Title")),
            *labelCost(new QLabel("Replacement Cost")),
            *labelRating(new QLabel("Rating"));

    //Setup label hBox w/ Inputs
    vBoxLayout->addWidget(labelComposer);
    vBoxLayout->addWidget(m_pullComposer);
    vBoxLayout->addWidget(labelTitle);
    vBoxLayout->addWidget(m_pullAlbumName);
    vBoxLayout->addWidget(labelCost);
    vBoxLayout->addWidget(m_pullCost);
    vBoxLayout->addWidget(labelRating);
    vBoxLayout->addWidget(m_pullRating);

    //Add and Delete Record Button
    QHBoxLayout *hBoxLayout_submitButtons = new QHBoxLayout;

    m_submitAdd->setMaximumWidth(m_maxLabelWidth);
    hBoxLayout_submitButtons->addWidget(m_submitAdd, 0, Qt::AlignRight);
    m_submitDelete->setMaximumWidth(m_maxLabelWidth);
    hBoxLayout_submitButtons->addWidget(m_submitDelete, 0, Qt::AlignRight);
    vBoxLayout->addLayout(hBoxLayout_submitButtons);

    //Table View - Add Rigth side
    QTableView *tableView = new QTableView(this);
    tableView->setModel(m_CDModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->resizeColumnsToContents();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->hide();
    tableView->setTabKeyNavigation(false);
    tableView->setMinimumWidth(m_minimumTableLabelWidth);
    tableView->setSortingEnabled(true);

    vBoxLayout_tableView->addWidget(tableView);

    //Add Right side to left side
    hBoxLayout->addLayout(vBoxLayout);
    hBoxLayout->addLayout(vBoxLayout_tableView);

    setLayout(hBoxLayout);

    connect(m_submitAdd, SIGNAL(clicked(bool)), this, SLOT(slot_addCDClicked()));
    connect(m_submitDelete, SIGNAL(clicked(bool)), this, SLOT(slot_deleteCDClicked()));

    //Add some test data
    CDModel *model = qobject_cast<CDModel*>(m_CDModel);
    if (model) {
        model->addCD("Avenged Sevenfold", "City of Evil", 690.69f, 99);
        model->addCD("Evanescence", "Fallen", 420, 82);
        model->addCD("Naked City", "Torture Garden", 420.69f, 69);
    }

    m_pullComposer->setFocus();
}

void CDView::slot_addCDClicked()
{
    //Ensure the model being used is an AlbumListModel
    CDModel *model = qobject_cast<CDModel*>(m_CDModel);
    if (model) {
        model->addCD(m_pullComposer->text(), m_pullAlbumName->text(), static_cast<float>(m_pullCost->value()), m_pullRating->value());
        m_pullAlbumName->clear();
        m_pullComposer->clear();
        m_pullCost->clear();
        m_pullRating->clear();
        m_pullComposer->setFocus();
    }
}

void CDView::slot_deleteCDClicked()
{

}
