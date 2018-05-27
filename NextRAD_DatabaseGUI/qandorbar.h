#ifndef QANDORBAR_H
#define QANDORBAR_H

#include <QHBoxLayout>
#include <QSpacerItem>
#include <qdynamiccombobox.h>

class QAndOrBar : public QWidget
{
    Q_OBJECT
public:
    explicit QAndOrBar(QWidget *parent = 0);
    ~QAndOrBar();
    static int ResID;
    int getID();
    void resetID();
    QDynamicComboBox *combobox;

signals:

public slots:

private:
    int searchID = 0;
    QHBoxLayout *layout;
};

#endif // QANDORBAR_H
