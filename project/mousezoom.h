#ifndef MOUSEZOOM_H
#define MOUSEZOOM_H

#include <QObject>
#include <QGraphicsView>

class MouseZoom : public QObject
{
    Q_OBJECT
public:
    MouseZoom(QGraphicsView* view);
    void gentle_zoom(double factor);
    void set_modifiers(Qt::KeyboardModifiers modifiers);
    void set_zoom_factor_base(double value);

private:
    QGraphicsView* _view;
    Qt::KeyboardModifiers _modifiers;
    double _zoom_factor_base;
    QPointF target_scene_pos, target_viewport_pos;
    bool eventFilter(QObject* object, QEvent* event);

signals:
    void zoomed();
};

#endif // MOUSEZOOM_H
