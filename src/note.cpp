#include "include/note.h"
#include "ui_note.h"
#include <QMouseEvent>
#include <QMessageBox>

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
    ui->note_text->setPlainText("Hello World, \n \nMy Name Is Ranfis");
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
    if(ui->note_text->toPlainText().size()<1){
        this->close();
        return;
    }
    if(QMessageBox::question(this, tr("Close"), tr("Close this Note?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton) == QMessageBox::Yes){
        this->close();
    }
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

void Note::on_pushButton_clicked()
{
    if(ui->note_text->toPlainText().size()<1){
        return;
    }
    if(QMessageBox::question(this, tr("Clear"), tr("Clear the contents of this Note?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton) == QMessageBox::Yes){
        ui->note_text->setPlainText("");
    }

}
