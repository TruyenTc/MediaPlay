//#ifndef OBJECTLISTMODEL_H
//#define OBJECTLISTMODEL_H
//#include <QAbstractListModel>
//#include <QObject>
//#include <QList>
//#include "dataItem.h"
//#include<QDebug>

//#include <QtCore>
//#include <QtGui>


//class objectlistModel : public QAbstractListModel

//{
//    Q_OBJECT
//    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
//    Q_PROPERTY(objectlistModel list1 READ add  WRITE data NOTIFY dataChanged)
//public:
//    explicit objectlistModel(QObject *parent = nullptr);

//    enum ModelRoles{
//        namemusicRole=Qt::UserRole+1,
//   //     durationRole
//    };

//    //    Q_INVOKABLE void append(QObject* object);
//    //    Q_INVOKABLE QObject* get(QString data);

//    virtual int rowCount(const QModelIndex &parent) const override;
//    virtual QVariant data(const QModelIndex &index, int role) const override;

//    int count() const;
//    void setCount(int newCount);

//    //protected:
//    QHash<int, QByteArray> roleNames() const override{
//        QHash<int, QByteArray> roles;
//        roles[namemusicRole] = "nameMusic";
//     //   roles[durationRole] = "duration";
//        return roles;
//    }

//signals:
//    void countChanged();
//    void dataChanged();

//public slots:
//    void add(QStringList add);

//private:
//    int m_count;
//    QList<QStringList> m_data;
//};

//#endif // OBJECTLISTMODEL_H
