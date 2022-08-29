#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

class Translator : public QObject
{
    Q_OBJECT
public:
    explicit Translator(QQmlApplicationEngine *engine, QGuiApplication *app = nullptr, QObject *parent = nullptr);

    Q_INVOKABLE void setLanguage(QString language);


    QString udateLanguage() const;

signals:
private:
    QTranslator m_translator;
    QGuiApplication &m_app;
    QQmlApplicationEngine &m_engine;

    QString m_language;
};

#endif // TRANSLATOR_H
