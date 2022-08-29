#include "translator.h"



Translator::Translator(QQmlApplicationEngine *engine, QGuiApplication *app, QObject *parent)
    : QObject{parent},  m_app(*app), m_engine(*engine)
{
        m_translator.load("VN.qm", ":/language");
        m_app.installTranslator(&m_translator);
        m_engine.retranslate();
}

void Translator::setLanguage(QString language)
{
    m_translator.load(language, ":/language");
    m_app.installTranslator(&m_translator);
    m_engine.retranslate();
}

QString Translator::udateLanguage() const
{
    return m_language;
}
