#ifndef QSEARCHBAR_H
#define QSEARCHBAR_H

#include <QHBoxLayout>
#include <qdynamicbutton.h>
#include <qdynamiccombobox.h>
#include <qdynamiclineedit.h>

class QSearchBar : public QWidget
{
    Q_OBJECT
public:
    explicit QSearchBar(QWidget *parent = 0);
    ~QSearchBar();
    static int ResID;
    int getID();
    void resetID();
    void getInfo();
    QDynamicButton *button;
    QDynamicComboBox *combobox1, *combobox2, *combobox3;
    QDynamicLineEdit *lineedit;

signals:

public slots:

private:
    int searchID = 0;
    QHBoxLayout *layout;
//    QDynamicButton *button;
//    QDynamicComboBox *combobox1, *combobox2, *combobox3;
//    QDynamicLineEdit *lineedit;
};

#endif // QSEARCHBAR_H
