#ifndef CARDTABLE_H
#define CARDTABLE_H

#include "cardpics.h"
#include <QWidget>

class CardTable : public QWidget
{
public:
    explicit CardTable(QWidget* parent=0);
private:
    CardPics m_deck;
};

#endif // CARDTABLE_H
