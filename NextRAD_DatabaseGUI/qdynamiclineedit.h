#ifndef QDYNAMICLINEEDIT_H
#define QDYNAMICLINEEDIT_H

#include <QLineEdit>

class QDynamicLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit QDynamicLineEdit(QWidget *parent = 0);
    ~QDynamicLineEdit();
    static int ResID;
    int getID();

public slots:

private:
    int lineeditID = 0;
};

#endif // QDYNAMICLINEEDIT_H
