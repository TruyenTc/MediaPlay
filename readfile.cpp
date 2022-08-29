#include "readfile.h"
#include<QDir>
#include<QUrl>

readFile::readFile(QObject *parent)
    : QObject{parent}
{

}

void readFile::read_file(QString add, bool flag)
{
    QStringList m_source;
    QString name;
  //  qDebug()<<add;
    m_listName.clear();
        if(directory != add){
            directory = add;
            if(flag){
                QDir directory(QUrl(add).toLocalFile()) ;
                QStringList list = directory.entryList(QStringList("*mp3"));
                for(const QString& music : list){
               //     qDebug()<<music;
                  m_listName.append(music);
                }
                emit readm_Name(m_listName, add);
            }
            else{
                    name =  QUrl(add).fileName();
                  //  qDebug()<<QUrl(add).fileName();
                    emit readSource( name, add);
                }



}

}
