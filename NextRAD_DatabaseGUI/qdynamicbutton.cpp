#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) : QPushButton(parent)
{
    ResID++;
    buttonID = ResID;
}

QDynamicButton::~QDynamicButton()
{

}

int QDynamicButton::getID()
{
    return buttonID;
}

void QDynamicButton::resetID()
{
    ResID = 0;
}

int QDynamicButton::ResID = 0;

