#include "qsearchbar.h"

QSearchBar::QSearchBar(QWidget *parent) : QWidget(), layout(new QHBoxLayout(this))
{
    ResID++;
    searchID = ResID;

    combobox1 = new QDynamicComboBox();
    QStringList tables;
    tables << "Choose a table" << "Trial" << "Nodes" << "Target" << "Pulse" << "Weather";
    combobox1->addItems(tables);

    combobox2 = new QDynamicComboBox();
    combobox2->addItem("Choose a field");

    combobox3 = new QDynamicComboBox();
    QStringList equators;
    equators << "=" << "<>" << ">" << "<" << ">=" << "<=";
    combobox3->addItems(equators);

    lineedit = new QDynamicLineEdit();
    lineedit->setText(QString::number(lineedit->getID()));

    button = new QDynamicButton();
    button->setText("Delete");

    layout->addWidget(combobox1);
    layout->addWidget(combobox2);
    layout->addWidget(combobox3);
    layout->addWidget(lineedit);
    layout->addWidget(button);
}

QSearchBar::~QSearchBar()
{

}

int QSearchBar::getID()
{
    return searchID;
}

void QSearchBar::resetID()
{
    ResID = 0;

    QDynamicComboBox *combobox = new QDynamicComboBox();
    combobox->resetID();

    lineedit->resetID();
    button->resetID();
}

int QSearchBar::ResID = 0;
