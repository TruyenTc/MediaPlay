
#include <QString>

class SongModel
{
public:
    SongModel():m_Name(), m_Source(), favorites(0) {}
    SongModel(QString p_Source, QString p_name): m_Source(p_Source), m_Name(p_name){}



    bool favorites ;

    bool setFavorites(const bool p_Favorites) {;
        if(favorites == p_Favorites)
        {
            return false;
        }
        favorites = p_Favorites;
        return true;
    }

    QString getName() const {
        return m_Name;
    }
    bool setName(const QString p_Name) {;
        if(m_Name == p_Name)
        {
            return false;
        }
        m_Name = p_Name;
        return true;
    }

    QString getSource() const {
        return m_Source;
    }
    bool setSource(const QString p_Source)
    {
        if(m_Source == p_Source)
        {
            return false;
        }
        m_Source = p_Source;
        return true;
    }

    //ham sap sep
    bool operator>(const SongModel& item)
    {
        return QString::compare(m_Name, item.m_Name) > 0;
    }

    bool operator<(const SongModel& item)
    {
        return QString::compare(m_Name, item.m_Name) < 0;
    }



private:
    QString m_Name, m_Source, m_Album, m_Artist;

};
