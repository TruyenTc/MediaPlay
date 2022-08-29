#include "qplayer.h"


//khai bao va connect signal
Qplayer::Qplayer(QObject *parent)
    : QObject{parent}
{
    m_Player = new QMediaPlayer;
    m_Audio = new QAudioOutput;
    m_Player->setAudioOutput(m_Audio);
    QObject::connect((this->m_Player), SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
                     this, SLOT(onMediaStatusChanged()));

    QObject::connect((this->m_Player), SIGNAL(positionChanged(qint64)),
                     this, SIGNAL(positionChanged(qint64)));

    QObject::connect((this->m_Player), SIGNAL(durationChanged(qint64)),
                     this, SIGNAL(durationChanged(qint64)));
    m_Audio->setVolume(volume);
}

//ham set source
void Qplayer::setsource(QString source)
{
    Source = source;
    m_Player->setSource(Source);

}

//ham kiem tra play hoac pause
void Qplayer::play(bool state)
{
    if(Source != ""){
        if(!state){
            m_Player->pause();
        }
        else if(state){
            m_Player->play();
        }
        emit changedStates();
    }


}
//ham stop
void Qplayer::stop()
{
        m_Player->stop();
    emit changedStates();
}

// ham tra ve states media
bool Qplayer::getStates()
{
    if(m_Player->playbackState()==1){
        return true;
    }
    else if(m_Player->playbackState()==2){
        return false;
    }
}
//ham kiem tra het bai
void Qplayer::onMediaStatusChanged()
{
//Repeat kiem tra co repeat hay khong
    if(m_Player->mediaStatus()==QMediaPlayer::EndOfMedia){

        if(!Repeat){
            m_Player->play();
        }
        else if(Repeat){
            emit setIndex_model(index_music+1);
            m_Player->play();
        }
    }


    else if(m_Player->mediaStatus()==QMediaPlayer::LoadedMedia) {
       QMediaMetaData content = m_Player->metaData();
        setdataname(content.stringValue(QMediaMetaData::Title));
    }


}
//index cua bai dang hat
void Qplayer::index_listmodel(int index)
{
    index_music = index;
}
// thoi gian cua bai hat
int Qplayer::getDuration() const
{
    return m_Player->duration();
}
// thoi gian da hat
int Qplayer::getPosition() const
{
    return m_Player->position();
}

//postion string
QString Qplayer::getpositionString()
{

    int s = m_Player->position()/1000;
    int m = s / 60;
    s = s % 60;
    return QTime(0,m, s).toString("mm:ss");
}
//duaration string
QString Qplayer::getdurationString()
{
    int s = m_Player->duration()/1000;
    int m = s / 60;
    s = s % 60;
    return QTime(0,m, s).toString("mm:ss");
}
//return name
QString Qplayer::getdataname()
{
    return name;
}

void Qplayer::setdataname(QString Name)
{
    name = Name;
    emit getnameChanged();
}

//position theo x
void Qplayer::takeX(float x, float width)
{

    m_Player->setPosition( x/width*(m_Player->duration()));
    getPosition();
    emit postionchange();
}
//volume theo x
void Qplayer::setVolume(float x)
{
    volume = (float(1)/float(80))*x;
    m_Audio->setVolume(volume);
    emit volumeChanged();
}
// tab dang hien thi ben labraries
void Qplayer::setTabLibraries(int tab)
{
    Tab = tab;

    emit tablibrariesChanged();
    getTabLibraries();
}
//return tab dang hien thi
int Qplayer::getTabLibraries()
{
  return Tab;
}
//return location x
float Qplayer::getX_Volume()
{
    return volume*80;
}
//thay doi Repeat
void Qplayer::checkRepeat(bool repeat)
{
    Repeat = repeat;
}




