#include "include/note.h"
#include "ui_note.h"

Note::Note(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = 0;
    flags |= Qt::FramelessWindowHint;

    this->setWindowFlags(flags);
    QSizeGrip *g = new QSizeGrip(this);
    g->setStyleSheet("background-color:0;");
    ui->verticalLayout->addWidget(g, 0, Qt::AlignBottom | Qt::AlignRight);
    ui->note_text->setFrameShape(QFrame::NoFrame);
}

Note::~Note()
{
    delete ui;
}

void Note::set_content(char* content){
    this->_content = content;
}

char* Note::content(){
    return this->_content;
}


void Note::on_btn_add_clicked()
{
    Note *n = new Note;
    n->show();
}

void Note::on_btn_close_clicked()
{
    this->close();
}

void Note::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        _is_moving = true;
        _last_point = event->globalPos();
    }
}

void Note::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && _is_moving)
    {

        this->move(this->pos() + (event->globalPos() - _last_point));
        _last_point = event->globalPos();
    }
}

void Note::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        _is_moving = false;
    }
}
