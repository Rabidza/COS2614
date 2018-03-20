#ifndef CARDPICS_H
#define CARDPICS_H

#include <QMap>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QObject>

class CardPics : public QObject
{
    Q_OBJECT

public:
    explicit CardPics(QObject* parent=0);
    ~CardPics();
    static CardPics* instance();
    QImage get(QString card) const;
    static const QString values;
    static const QString suits;
protected:
    static QString fileName(QString card);
private:
    QMap<QString, QImage> m_images;
};

#endif // CARDPICS_H
