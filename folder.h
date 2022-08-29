#ifndef FOLDER_H
#define FOLDER_H

#include <QObject>
#include <QVariantList>
#include <QFileDialog>


class folder : public QObject
{
    Q_OBJECT
public:
    explicit folder(QWidget * =nullptr ,QObject *parent = nullptr);

    Q_INVOKABLE void acction(bool flag);

    QString urlOld;
    QStringList urlList;


public slots:

    void openFile();

signals:
    void addressChanged(QStringList url, QStringList name);
    void folderChanged();
    void changIndex(int index);
private:
    QFileDialog m_folder;
    QStringList m_listName;
    QStringList m_ListSource;

};

#endif // FOLDER_H
