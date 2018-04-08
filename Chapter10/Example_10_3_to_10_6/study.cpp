#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QMessageBox>
#include <QActionGroup>
#include "study.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    Study study;
    study.show();
    return app.exec();
}

//Factory function for creating QActions initialized in a uniform way
QAction* Study::addChoice(QString name, QString text)
{
    QAction* retval = new QAction(text, this);
    retval->setObjectName(name);
    retval->setEnabled(false);
    retval->setCheckable(true);
    actionGroup->addAction(retval);
    return retval;
}

Study::Study(QWidget *parent)
    : QMainWindow(parent)
{
    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(false);
    statusBar();

    QWidget::setWindowTitle("to become a jedi, you wish?");

    QMenu* useMenu = new QMenu("&Use", this);
    QMenu* studyMenu = new QMenu("&Study", this);
    QMenu* fightMenu = new QMenu("&Fight", this);

    useTheForce = addChoice("useTheForce", "Use the &Force");
    useTheForce->setStatusTip("This is the start of a journey...");
    useTheForce->setEnabled(true);
    useMenu->addAction(useTheForce);

    useTheDarkSide = addChoice("useTheDarkSide", "Use the &Dark Side");
    useMenu->addAction(useTheDarkSide);
    useTheDarkSide->setStatusTip("It's unavoidable, like the Apple in eden...");

    studyWithObiWan = addChoice("studyWithObiWan", "&Study With Obi Wan");
    studyMenu->addAction(studyWithObiWan);
    studyWithObiWan->setStatusTip("He will certainly open doors "
                                   "for you...");
    fightObiWan = addChoice("fightObiWan", "Fight &Obi Wan");
    fightMenu->addAction(fightObiWan);
    fightObiWan->setStatusTip("You'll learn some tricks from him "
                               "that way, for sure!");

    studyWithYoda = addChoice("studyWithYoda", "Study with &Yoda");
    studyMenu->addAction(studyWithYoda);
    studyWithYoda->setStatusTip("He's the master, why wouldn't you?");

    fightYoda = addChoice("fightYoda", "Fight Y&oda");
    fightMenu->addAction(fightYoda);
    fightYoda->setStatusTip("What are you, nuts?");

    fightDarthVader = addChoice("fightDarthVader", "Fight Darth &Vader");
    fightMenu->addAction(fightDarthVader);

    fightEmperor = addChoice("fightEmperor", "Fight &Emperor");
    fightMenu->addAction(fightEmperor);

    studyWithEmperor = addChoice("studyWithEmperor", "Study With Empero&r");
    studyMenu->addAction(studyWithEmperor);

    QMainWindow::menuBar()->addMenu(useMenu);
    QMainWindow::menuBar()->addMenu(studyMenu);
    QMainWindow::menuBar()->addMenu(fightMenu);

    toolbar = new QToolBar("Choice ToolBar", this);
    toolbar->addActions(actionGroup->actions());

    QMainWindow::addToolBar(Qt::LeftToolBarArea, toolbar);

    QObject::connect(actionGroup, SIGNAL(triggered(QAction*)),
                     this, SLOT(actionEvent(QAction*)));

    QWidget::move(300, 300);
    QWidget::resize(300, 300);
}

void Study::actionEvent(QAction *act)
{
    QString name = act->objectName();
    QString msg = QString();

    if(act == useTheForce)
    {
        studyWithObiWan->setEnabled(true);
        fightObiWan->setEnabled(true);
        useTheDarkSide->setEnabled(true);
    }

    if(act == useTheDarkSide)
    {
        studyWithYoda->setEnabled(false);
        fightYoda->setEnabled(true);
        studyWithEmperor->setEnabled(true);
        fightEmperor->setEnabled(true);
        fightDarthVader->setEnabled(true);
    }

    if(act == studyWithObiWan)
    {
        fightObiWan->setEnabled(true);
        fightDarthVader->setEnabled(true);
        studyWithYoda->setEnabled(true);
    }

    if(act == fightObiWan)
    {
        if(studyWithEmperor->isChecked())
        {
            msg = "You are victorious!";
        }
        else
        {
            msg = "You lose.";
            act->setChecked(false);
            studyWithYoda->setEnabled(false);
        }
    }

    if(msg != QString())
    {
        QMessageBox::information(this, "Result", msg, "ok");
    }
}

