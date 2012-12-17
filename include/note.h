#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>
#include <QSizeGrip>
#include "csv.h"

namespace Ui {
class Note;
}

class Note : public QMainWindow
{
    Q_OBJECT
private:
    char* _content;
    QPoint _last_point;
    bool _is_moving;
    CSV* csv;
public:
    explicit Note(QWidget *parent = 0);
    ~Note();
    char* content();
    void set_content(char*);
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:

    void on_btn_add_clicked();

    void on_btn_close_clicked();

    void on_pushButton_clicked();

private:
    Ui::Note *ui;
};

#endif // NOTE_H
