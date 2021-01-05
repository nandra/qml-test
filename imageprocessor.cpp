...

void ImageProcessor::on_sensorStateChanged()
{
    int state = m_sensor->currentState();
    
    qDebug() << "Sensor state updated to:" << state;
    // update image
    QLabel label;
    QMovie movie(images.value(state));
    label.setMovie(&movie);
    movie.start();
    //
    QImage image;
    image.load(images.value(state));

    
    QPainter p;
    if (!p.begin(&image)) {
        qDebug() << "Cannot begig painter";
    }
    qDebug() << "Drawing glow image";
    p.drawImage(QRect(120, 120, 240, 240), QImage(GLOW_IMAGE_PATH));
    p.end();

    p.setPen(QPen(Qt::white));
    QRect i = image.rect();
    p.drawText(i, Qt::AlignCenter,  "Test text");
    p.end();


    m_imageProvider->setImage(movie.currentImage());
}

...
