#ifndef QPLAYER_H
#define QPLAYER_H
#include<QMediaPlayer>
#include<QMediaMetaData>
#include<QAudioOutput>
#include"objectmodel1.h"
#include<QTime>
#include <QObject>

class Qplayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int position READ getPosition NOTIFY positionChanged)
    Q_PROPERTY(int duration READ getDuration NOTIFY durationChanged)
    Q_PROPERTY(QString positionString READ getpositionString NOTIFY positionChanged)
    Q_PROPERTY(QString durationString READ getdurationString NOTIFY durationChanged)
    Q_PROPERTY(float Volume READ getX_Volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(bool States READ getStates /*WRITE play*/ NOTIFY changedStates)

    Q_PROPERTY(QString name READ getdataname WRITE setdataname  NOTIFY getnameChanged)
    Q_PROPERTY(int TabLibraries  READ getTabLibraries NOTIFY tablibrariesChanged)

public:
    int X;
    int index_music;
    float volume = 0.5;
    QString Source;
    explicit Qplayer(QObject *parent = nullptr);


    Q_INVOKABLE void play(bool state);
    void stop();
    bool getStates();
    QString addressSource;
    void setsource(QString source);

    int getDuration() const;
    int getPosition() const;

    QString getpositionString();
    QString getdurationString();

    QString name;

    QString getdataname();
    void setdataname(QString name);

    Q_INVOKABLE void takeX(float x, float width);
    void setVolume(float x);

    int Tab = 3;
    Q_INVOKABLE void setTabLibraries(int tab);
    int getTabLibraries();
    float getX_Volume();

    Q_INVOKABLE void checkRepeat(bool repeat);
    bool Repeat = true;

signals:

    void positionChanged(qint64);
    void durationChanged(qint64);
    void postionchange();
    void volumeChanged();
    void setIndex_model(int index);
    void changedStates();
    void getnameChanged();
    void tablibrariesChanged();
public slots:
    void onMediaStatusChanged();
    void index_listmodel(int index);


private:
    QMediaPlayer *m_Player;
    QAudioOutput *m_Audio;

};

#endif // QPLAYER_H
