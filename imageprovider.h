#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QImage>

class ImageProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage image MEMBER m_image READ image WRITE setImage NOTIFY imageChanged)

    QImage m_image;

public:
    explicit ImageProvider(QObject *parent = nullptr);
    void setImage(QImage const &image);
    QImage image() const;

signals:
    void imageChanged();
};

#endif // IMAGEPROVIDER_H
