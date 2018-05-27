#ifndef QDYNAMICCOMBOBOX_H
#define QDYNAMICCOMBOBOX_H

#include <QComboBox>

class QDynamicComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit QDynamicComboBox(QWidget *parent = 0);
    ~QDynamicComboBox();
    static int ResID;
    int getID();
    void resetID();

public slots:

private:
    int comboboxID = 0;
//    QString comboboxText = "";
};

#endif // QDYNAMICCOMBOBOX_H
