#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <QString>
#include <QImage>
#include <functional>

const int imageSize = 100;

class Load : public std::unary_function<QString, QImage>
{
public:
    QImage operator() (const QString& imageFileName) const
    {
        return QImage(imageFileName);
    }
};

class Scale {
    public:
    typedef QImage result_type;
    QImage operator() (QImage image) const
    {
        for (int i=0; i<10; ++i)
        {
            QImage copy = image.copy();
            copy.scaled(100, 100, Qt::KeepAspectRatio);
        }
        if (image.width() < image.height())
        {
            return image.scaledToHeight(imageSize, Qt::SmoothTransformation);
        }
        else
        {
            return image.scaledToWidth(imageSize, Qt::SmoothTransformation);
        }
    }
};

class LoadAndScale : public std::unary_function<QString, QImage>
{
public:
    Scale scale;
    QImage operator() (const QString& imageFileName) const
    {
        QImage image(imageFileName);
        return scale(image);
    }
};

#endif // FUNCTORS_H
