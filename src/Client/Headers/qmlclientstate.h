#ifndef QMLCLIENTSTATE_H
#define QMLCLIENTSTATE_H

#include <QObject>

//Singleton
namespace secure_voice_call{
class QMLClientState : public QObject
{
    Q_OBJECT

    QMLClientState(QObject *parent = nullptr);
    QMLClientState( const QMLClientState&) = default;
    QMLClientState& operator=( QMLClientState& ) = default;

public:
    enum class ClientStates{
        Authorization,
        Online,
        InConversation
    };
    Q_ENUM(ClientStates)
    Q_PROPERTY(ClientStates clientState READ getState WRITE setState NOTIFY stateChanged)
    ClientStates getState() const { return m_clientState; }

    static QMLClientState& getInstance() {
        static QMLClientState  instance;
        return instance;
    }

public slots:
    void setState(ClientStates clientState);

signals:
    void stateChanged(ClientStates clientState);
    void tryAuthorizate(QString str);
    void refreshClientList();
private:
    ClientStates m_clientState = ClientStates::Authorization;
};
}

#endif // QMLCLIENTSTATE_H
