#include "qdynamiclineedit.h"

QDynamicLineEdit::QDynamicLineEdit(QWidget *parent) : QLineEdit(parent)
{
    ResID++;
    lineeditID = ResID;
}

QDynamicLineEdit::~QDynamicLineEdit()
{

}

int QDynamicLineEdit::getID()
{
    return lineeditID;
}

void QDynamicLineEdit::resetID()
{
    ResID = 0;
}

int QDynamicLineEdit::ResID = 0;
