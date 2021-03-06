#include "inputform.h"
#include <QFormLayout>
#include <QDateEdit>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QColorDialog>
#include <QSettings>
#include <QVariant>
#include <QPalette>

InputForm::InputForm(QWidget *parent)
    : QDialog(parent)
{
    QSettings s;
    setWindowTitle("QFormlayout demo");
    QVariant v = s.value("color/favorite", QVariant());
    if (!v.isNull()) m_color = v.value<QColor>();

    m_name = new QLineEdit;
    m_birthday = new QDateEdit;
    m_birthday->setDisplayFormat("dd/MM/yyyy");
    m_colorButton = new QPushButton(tr("Choose"));
    m_colorButton->setAutoFillBackground(true);

    m_buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                     QDialogButtonBox::Cancel);

    QVBoxLayout* vbox = new QVBoxLayout;
    QFormLayout* layout = new QFormLayout;

    layout->addRow(tr("Name"), m_name);
    layout->addRow(tr("Birthdate"), m_birthday);
    layout->addRow(tr("Favorite Color"), m_colorButton);

    vbox->addLayout(layout);
    vbox->addWidget(m_buttons);

    Q_ASSERT(vbox->parent() == 0);
    Q_ASSERT(m_birthday->parent() == 0);
    setLayout(vbox);
    Q_ASSERT(vbox->parent() == this);
    Q_ASSERT(m_birthday->parent() == this);

    connect(m_colorButton, SIGNAL(clicked()), this, SLOT(chooseColor()));
    connect(m_buttons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttons, SIGNAL(rejected()), this, SLOT(reject()));
    updateUi();
}

void InputForm::accept()
{
    QSettings s;
    s.setValue("color/favorite", m_color.value());

    QDate birthday = m_birthday->date();
    int days = birthday.daysTo(QDate::currentDate());
    QMessageBox::information(this, tr("Age Guesser"), tr("You are %1 years old.").arg(days / 365));
    QDialog::accept();
}

void InputForm::chooseColor()
{
    m_color = QColorDialog::getColor(m_color, this);
    updateUi();
}

void InputForm::updateUi()
{
    QPalette p = m_colorButton->palette();
    p.setColor(QPalette::Button, m_color);
    m_colorButton->setPalette(p);
}
