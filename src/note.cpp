#include "include/note.h"
#include "ui_note.h"

Note::Note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::FramelessWindowHint;
    //    flags |= Qt::Window;

    this->setWindowFlags(flags);
}

Note::~Note()
{
    delete ui;
}

void Note::on_pushButton_clicked()
{
    Note *n = new Note;
    n->show();
}

void Note::set_content(char* content){
    this->_content = content;
}

char* Note::content(){
    return this->_content;
}

void Note::on_pushButton_2_clicked()
{
    this->close();
}
