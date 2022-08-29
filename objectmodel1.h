#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H
#include<vector>
using namespace std ;
#include<QAbstractListModel>
#include <QObject>
#include<QDebug>
#include<QList>
#include "SongModel.h"
#include <cstdlib>
#include <ctime>


class ObjectModel12 : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int Index READ getIndex WRITE setIndex NOTIFY IndexChanged)
    Q_PROPERTY(QStringList FavoritesSong READ getFavorites WRITE setFavorites NOTIFY FavoritesChanged)
    Q_PROPERTY(int IndexFavorite READ getIndexFavorites WRITE setIndexFavorites NOTIFY IndexFavoritesChanged)

public:
    explicit ObjectModel12(QObject *parent = nullptr);
    enum music{
        Name = Qt::UserRole + 1,
        Source, Favorites,
    };
    QVariant data(const QModelIndex &index, int role =Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex() ) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void add_Data(QStringList url, QStringList name);

    QString getdatasource();

    int getIndex();
    void setIndex(int index);

    bool Check = true;
    Q_INVOKABLE void check(bool check);

    void clear();

    QStringList &getFavorites();
    void setFavorites(const QStringList &newFavorites);
    Q_INVOKABLE void loveFavorites(int p_index);
    void updateFavorites(int m_index, SongModel item);
    vector<int> indexFavorites;
    int indexFavorite;
    Q_INVOKABLE void setIndexFavorites(int IndexFavorites);
    int getIndexFavorites();
    Q_INVOKABLE void sortList(bool check);
private:
    QList<SongModel> m_data;
    int Index = -1;
    QStringList m_Favorites;

protected:
    QHash<int, QByteArray> roleNames() const override{
        QHash<int, QByteArray> roles;
        roles[Name] = "SongName";
        roles[Source] = "SongSource";
        roles[Favorites] = "Favorites";
        return roles;
    }
signals:
    void IndexChanged();
    void getnameChanged();
    void getsourceChanged(QString source);
    void getindex_player(int index);
    void FavoritesChanged();
    void IndexFavoritesChanged();
};

#endif // OBJECTMODEL_H
