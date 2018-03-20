#include "card.h"
#include "cardtable.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

CardTable::CardTable(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* row = new QHBoxLayout();
    row->addWidget(new Card("ah"));
    row->addWidget(new Card("qd"));
    row->addWidget(new Card("ks"));
    row->addWidget(new Card("8c"));

    QVBoxLayout* rows = new QVBoxLayout();
    rows->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(new Card("qs"));
    row->addWidget(new Card("js"));
    row->addWidget(new Card("td"));
    rows->addLayout(row);

    QVBoxLayout* buttons = new QVBoxLayout();
    buttons->addWidget(new QPushButton("Deal"));
    buttons->addWidget(new QPushButton("Shuffle"));

    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);
    cols->addLayout(rows);
    cols->addLayout(buttons);
}
