#include <QPainter>
#include "lifewidget.h"

void LifeWidget::paintEvent(QPaintEvent* evt)
{
    QPainter painter(this);
    if (!m_image.isNull())
        painter.drawImage(QPoint(0,0), m_image);
}

QSize LifeWidget::sizeHint() const
{
    return m_size;
}

void LifeWidget::setImage(const QImage& image)
{
    m_size = image.size();
    m_image = image.scaled(size());
    update();
}

LifeWidget::LifeWidget(QWidget* parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

LifeWidget::~LifeWidget()
{

}
