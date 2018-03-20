#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QLabel>

class Card : public QLabel
{
    Q_OBJECT
public:
    Card(QString name, QWidget* parent=0);
    int value();
    bool isAce() const;
private:
    QPixmap m_pixmap;
};

#endif // CARD_H
