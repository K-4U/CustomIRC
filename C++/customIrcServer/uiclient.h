#ifndef UICLIENT_H
#define UICLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonDocument>

#include "../resources/clslog.h"
#include "../resources/jsoncommand.h"


class uiClient: public QObject{
    Q_OBJECT
public:
    uiClient(QTcpSocket *parent);
    
    void send(QString data);

private:
    jsonCommand checkForJsonCommand(QByteArray &toAdd);
signals:
    void disconnected(uiClient *client);
    void chatReceived(QString message);
    void userQuery(uiClient *client);
    void getEvents(uiClient *client);
    void changeOwnUser(jsonCommand &comm);

public slots:
    void removeConnection();
    void receiveMessage();

private:
    QTcpSocket *sock;
    clsLog log;
    QString *buffer;
    int depth;
};

#endif // UICLIENT_H
