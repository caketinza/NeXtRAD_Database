#ifndef SEARCHBAR_H
#define SEARCHBAR_H

//#include <qdynamicbutton.h>
//#include <qdynamiccombobox.h>
//#include <qdynamiclineedit.h>
//#include <QHBoxLayout>
//#include <QStringList>

class SearchBar : public SearchBar
{
    Q_OBJECT
public:
    explicit SearchBar(QWidget *parent = 0);
    ~SearchBar();
    static int ResID;
    int getID();

public slots:

private:
    int searchID = 0;
};

#endif // SEARCHBAR_H
