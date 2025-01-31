#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPainter>
#include <QPen>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setBack();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isX = true;
QString board[3][3] = {{"","",""},{"","",""},{"","",""}};
int count =0;
int x1=-50;
int x2=-50;
int y1=-50;
int y2=-50;


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText(click());
    board[0][0] = ui->pushButton->text();
    ui->pushButton->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton->setEnabled(false);
    count++;
    check();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText(click());
    ui->pushButton_2->setStyleSheet(color() + "; background: transparent;border:none;");
    board[0][1] = ui->pushButton_2->text();
    ui->pushButton_2->setEnabled(false);
    count++;
    check();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText(click());
    ui->pushButton_3->setStyleSheet(color() + "; background: transparent;border:none;");
    count++;
    board[0][2] = ui->pushButton_3->text();
    ui->pushButton_3->setEnabled(false);
    check();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setText(click());
    ui->pushButton_4->setStyleSheet(color() + "; background: transparent;border:none;");
    count++;
    board[1][0] = ui->pushButton_4->text();
    ui->pushButton_4->setEnabled(false);
    check();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setText(click());
    count++;
    ui->pushButton_5->setStyleSheet(color() + "; background: transparent;border:none;");
    board[1][1] = ui->pushButton_5->text();
    ui->pushButton_5->setEnabled(false);
    check();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setText(click());
    ui->pushButton_6->setStyleSheet(color() + "; background: transparent;border:none;");
    board[1][2] = ui->pushButton_6->text();
    ui->pushButton_6->setEnabled(false);
    count++;
    check();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setText(click());
    ui->pushButton_7->setStyleSheet(color() + "; background: transparent;border:none;");
    board[2][0] = ui->pushButton_7->text();
    ui->pushButton_7->setEnabled(false);
    count++;
    check();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setText(click());
    ui->pushButton_8->setStyleSheet(color() + "; background: transparent;border:none;");
    board[2][1] = ui->pushButton_8->text();
    ui->pushButton_8->setEnabled(false);
    count++;
    check();
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setText(click());
    ui->pushButton_9->setStyleSheet(color() + "; background: transparent;border:none;");
    board[2][2] = ui->pushButton_9->text();
    ui->pushButton_9->setEnabled(false);
    count++;
    check();
}

QString MainWindow::click(){
    if(isX){
        return "X";
    }
    else{
        return "O";
    }
}
QString MainWindow::color(){
    if(isX){
        return "color:blue;";
    }
    else{
        return "color:red;";
    }
}

void MainWindow::check(){
    isX = !isX;
    update();
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != "") {
             ui->label->setText(board[i][0] + "  WINS");
            x1 = 30;
            x2 = 300;
            y1 = i*80+65;
            y2 = y1 ;
            fun(false);
             return;
        }
    }


    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != "") {
            ui->label->setText(board[0][i] + "  WINS");
            x1 =i*100+55;
            x2 =x1;
            y1=60;
            y2=260;
            fun(false);
            return;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != "") {
        ui->label->setText(board[0][0] + "  WINS");
        x1=50;
        y1=50;
        x2=280;
        y2=260;
        fun(false);
        return;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != "") {
        ui->label->setText(board[1][1] + "  WINS");
        x1 =30;
        x2 = 280;
        y1=260;
        y2=50;
        fun(false);
        return;
    }
    if(count ==9){
        ui->label->setText("DRAW");
        return;
    }

}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(QColorConstants::Black);
    pen.setWidth(7);
    painter.setPen(pen);
    painter.drawLine(104,30,104,270);
    painter.drawLine(204,30,204,270);
    painter.drawLine(4,105,304,105);
    painter.drawLine(4,185,304,185);
    QPainter painter1(this);
    QPen pen1(!isX ? Qt::blue : Qt::red);
    pen1.setWidth(3);
    painter1.setPen(pen1);
    painter1.drawLine(x1,y1,x2,y2);
}


void MainWindow::fun(bool arg){
    ui->pushButton->  setEnabled(arg);
    ui->pushButton_2->setEnabled(arg);
    ui->pushButton_3->setEnabled(arg);
    ui->pushButton_4->setEnabled(arg);
    ui->pushButton_5->setEnabled(arg);
    ui->pushButton_6->setEnabled(arg);
    ui->pushButton_7->setEnabled(arg);
    ui->pushButton_8->setEnabled(arg);
    ui->pushButton_9->setEnabled(arg);
}

void MainWindow::setBack(){
    ui->pushButton->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_2->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_3->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_4->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_5->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_6->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_7->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_8->setStyleSheet(color() + "; background: transparent;border:none;");
    ui->pushButton_9->setStyleSheet(color() + "; background: transparent;border:none;");
}


void MainWindow::on_reset_button_clicked()
{

    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            board[i][j] = "";
        }
    }
    //setBack();
    x1=-50;
    x2=-50;
    y1=-50;
    y2=-50;

    isX = true;
    ui->label->setText("");
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    update();



    fun(true);

}

