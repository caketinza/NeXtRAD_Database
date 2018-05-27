#include "qandorbar.h"

QAndOrBar::QAndOrBar(QWidget *parent) :  QWidget(), layout(new QHBoxLayout(this))
{

    ResID++;
    searchID = ResID;

    combobox = new QDynamicComboBox();
    QStringList andor;
    andor << "AND" << "OR";
    combobox->addItems(andor);
    QSpacerItem *spacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *spacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addSpacerItem(spacer1);
    layout->addWidget(combobox);
    layout->addSpacerItem(spacer2);
}

QAndOrBar::~QAndOrBar()
{

}

int QAndOrBar::getID()
{
    return searchID;
}

void QAndOrBar::resetID()
{
    ResID = 0;
    combobox->resetID();
}

int QAndOrBar::ResID = 0;
