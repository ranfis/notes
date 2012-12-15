#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>

namespace Ui {
class Note;
}

class Note : public QMainWindow
{
    Q_OBJECT
    char* _content;
public:
    explicit Note(QWidget *parent = 0);
    ~Note();
    char* content();
    void set_content(char*);

private slots:

    void on_btn_add_clicked();

    void on_btn_close_clicked();

private:
    Ui::Note *ui;
};

#endif // NOTE_H
