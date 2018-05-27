#include "qdynamiccombobox.h"

QDynamicComboBox::QDynamicComboBox(QWidget *parent) : QComboBox(parent)
{
    ResID++;
    comboboxID = ResID;
//    comboboxText =

}

QDynamicComboBox::~QDynamicComboBox()
{

}

int QDynamicComboBox::getID()
{
    return comboboxID;
}

void QDynamicComboBox::resetID()
{
    ResID = 0;
}

//QString QDynamicComboBox::getText()
//{
//    comboboxText = c
//    return comboboxText;
//}



int QDynamicComboBox::ResID = 0;
