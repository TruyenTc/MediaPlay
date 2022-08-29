#include "folder.h"


// ham mo file hay folder
void folder::acction(bool flag)
{
    m_folder.setFileMode(flag? QFileDialog::Directory: QFileDialog::ExistingFiles);
    m_folder.exec();
}


void folder::openFile()
{
    QString url ;
    m_listName.clear();
    m_ListSource.clear();
//mo folder
    if(m_folder.fileMode() == QFileDialog::Directory){
        url =  QString(m_folder.directoryUrl().toString());
        //kiem tra co trung lai folder cu
        if(url!=urlOld){
            urlOld =url;
            QDir directory(m_folder.directoryUrl().toLocalFile());
            QStringList name = directory.entryList(QStringList("*mp3"));
            for(const QString& music : name){
                m_ListSource.append(url + "/" + music);
                    m_listName.append(music);
            }
            //tat bai dang hat khi doi list nhac
            emit addressChanged(m_ListSource, m_listName);
            emit changIndex(-2);
            emit folderChanged();
        }
    }
    //mo file
    else{
        QStringList url = m_folder.selectedFiles();

        //kiem tra co trung file cu
        if(url != urlList){
            urlList = url;
            for(QString temp : url){
                m_listName<<  QUrl(temp).fileName();
                m_ListSource.append("file:///"+temp);

            }
            //tat bai dang hat khi doi list nhac

            emit addressChanged(m_ListSource, m_listName);
            emit changIndex(-2);
            emit folderChanged();
        }
    }
}

folder::folder(QWidget *parentW, QObject *parent): QObject{parent}, m_folder{parentW}{

    m_folder.setDirectoryUrl(QUrl::fromLocalFile("C:"));
    m_folder.setNameFilter("*.mp3 *.mp4");
    m_folder.setViewMode(QFileDialog::Detail);
    connect(&m_folder , &QFileDialog::accepted, this,&folder::openFile);


}
