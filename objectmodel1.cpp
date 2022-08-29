#include "objectmodel1.h"

ObjectModel12::ObjectModel12(QObject *parent)
    : QAbstractListModel{parent}
{


}

QVariant ObjectModel12::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    const SongModel &item = m_data[index.row()];
    switch (role) {
    case Name:
        return item.getName();
    case Source:
        return item.getSource();
    case Favorites:
        return item.favorites;
    default:
        return QVariant();
    }

}

int ObjectModel12::rowCount(const QModelIndex &parent)const
{
    if(parent.isValid())
    {
        return 0;
    }

    return m_data.count();
}

bool ObjectModel12::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    SongModel &item = m_data[index.row()];
    switch (role) {
    case Name:
        return item.setName(value.toString());
    case Source:
        return item.setSource(value.toString());
    case Favorites:
        return item.favorites;
    default:
        return false;
    }
}

//ham add list source va ten file vao m_data

void ObjectModel12::add_Data(QStringList url, QStringList name)
{
    clear();
    int i=0;
    for(QString temp: url){
        QString tempName = name.at(i++);
        beginInsertRows(QModelIndex(), rowCount(), rowCount() );
        m_data.append(SongModel(temp, tempName) );
        endInsertRows();
    }
    emit layoutChanged();
}

// ham return source theo index

QString ObjectModel12::getdatasource()
{
    if(rowCount()!=0 && Index >= 0){
        emit getsourceChanged(m_data.at(getIndex()).getSource());
        return m_data.at(getIndex()).getSource();
    }
    else{
        return "";
    }
}

//ham getindex
int ObjectModel12::getIndex()
{
    return Index;

}

//ham set index
void ObjectModel12::setIndex(int index)
{

 //check kiem tra co shuffle hay khong

    if(Check){
        Index = index;
        if(Index > rowCount()-1){
            Index =0;
        }
        if(Index == -1){
            Index =rowCount()-1;
        }
    }
    if(!Check){
        if(index != -2){
            int res;
            do{
                srand(time(NULL));
                res = rand() % ((rowCount()-1)  + 1) ;
            }while(Index==res);
            Index=res;
        }
        else{
            Index = index;

        }
    }
  //phat tin hieu da thay doi index
    emit IndexChanged();
    getdatasource();
    emit getindex_player(Index);

}

//ham gan shuffle
void ObjectModel12::check(bool check)
{
    Check = check;

}

//ham clear m_data
void ObjectModel12::clear()
{
    m_data.clear();
    emit layoutChanged();
}

// return data m_Favorites
QStringList &ObjectModel12::getFavorites()
{
    return m_Favorites;
}

// kiem tra them hoac xoa bai hat vao Favorites
void ObjectModel12::loveFavorites(int index)
{
    m_data[index].favorites = !m_data[index].favorites;

    auto itr = std::find(m_Favorites.begin(), m_Favorites.end(), m_data.at(index).getName());
// remove bai da co trong lis Favorites
    if(itr != m_Favorites.end()){
        m_Favorites.removeOne(*itr);
        m_data[index].setFavorites(true);
        for(int i=0; i < indexFavorites.size(); i++){
            if(indexFavorites[i]==index){
                indexFavorites.erase(indexFavorites.begin()+i);
            }
        }
    }
// add bai vao Favorites
    else{
        m_Favorites.append(m_data.at(index).getName());
        m_data[index].setFavorites(false);
        indexFavorites.push_back(index);
    }
    updateFavorites(index, m_data[index]);
    emit FavoritesChanged();
    emit layoutChanged();
}

// update lai danh sanh Favorites
void ObjectModel12::updateFavorites(int m_index, SongModel item)
{
    m_data[m_index] = item;
    emit dataChanged(index(m_index), index(m_index));
    emit layoutChanged();
}

//Index Favorites
void ObjectModel12::setIndexFavorites(int IndexFavorites)
{
        if(indexFavorites.size()>=0){
            indexFavorite = IndexFavorites;
            setIndex(indexFavorites[IndexFavorites]);
            emit IndexFavoritesChanged();
        }

}

int ObjectModel12::getIndexFavorites()
{
    return indexFavorite;
}

void ObjectModel12::setFavorites(const QStringList &newFavorites)
{
    if (m_Favorites == newFavorites)
        return;
    m_Favorites = newFavorites;
    emit FavoritesChanged();
    emit layoutChanged();
}

void ObjectModel12::sortList(bool check)
{
    if (check)
    {
        std::sort(m_data.begin(), m_data.end());
    }
    else
    {
        std::reverse(m_data.begin(), m_data.end());
    }
    emit layoutChanged();
}
