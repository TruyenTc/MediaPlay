//#include "objectlistmodel.h"

//objectlistModel::objectlistModel(QObject *parent)
//    : QAbstractListModel{parent}
//{

//}

////void objectlistModel::append(QObject *object)
////{

////}

////QObject *objectlistModel::get(QString data)
////{

////}

//int objectlistModel::rowCount(const QModelIndex &p=QModelIndex()) const
//{
//    Q_UNUSED(p)
//    return m_data.count();
//}

//QVariant objectlistModel::data(const QModelIndex &index, int role) const
//{
//    //  Q_UNUSED(role)
//    switch (role) {
//    case namemusicRole:
//        qDebug()<<m_data.at(index.row());
//        return  m_data.at(index.row());
//        break;
////    case durationRole:
////        return m_data.at(index.row()).duration;
////        break;
//    default:
//        return QVariant();
//        break;
//    }

//}

//int objectlistModel::count() const
//{
//    return m_count;
//}

//void objectlistModel::setCount(int newCount)
//{
//    if (m_count == newCount)
//        return;
//    m_count = newCount;
//    emit countChanged();
//}

//void objectlistModel::add(QStringList add)
//{
//    //beginInsertRows(QModelIndex(),rowCount(), rowCount());
//  //  dataItem temp ;

//    m_data.append(add);

//   // endInsertRows();
//}
