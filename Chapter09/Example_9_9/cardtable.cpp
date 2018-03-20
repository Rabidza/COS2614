#include "card.h"
#include "cardtable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

CardTable::CardTable(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* rows = new QVBoxLayout();

    QHBoxLayout* row = new QHBoxLayout();
    row->addWidget(new Card("as"));
    row->addWidget(new Card("ah"));
    row->addWidget(new Card("ac"));
    row->addWidget(new Card("ad"));
    rows->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(new Card("td"));
    row->addWidget(new Card("js"));
    row->addWidget(new Card("kc"));
    rows->addLayout(row);
    rows->addStretch(1);
    QVBoxLayout* buttons = new QVBoxLayout();
    buttons->addStretch(1);
    buttons->addWidget(new QPushButton("Deal"));
    buttons->addWidget(new QPushButton("Shuffle"));
    buttons->addSpacing(20);
    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);
    cols->addLayout(rows);
    cols->addLayout(buttons);
    cols->addStretch(0);
}
