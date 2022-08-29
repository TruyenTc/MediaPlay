#ifndef READFILE_H
#define READFILE_H

#include <QObject>

class readFile : public QObject
{
    Q_OBJECT
public:
    explicit readFile(QObject *parent = nullptr);
    QString directory;


signals:
    void readm_Name(QStringList &name, QString &add);

    void readSource(QString name,QString &add );


public slots:
    void read_file(QString add, bool flag);
private:
    QStringList m_listName;



};

#endif // READFILE_H
