#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isX = true;
QString board[3][3] = {{"0","0","0"},{"0","0","0"},{"0","0","0"}};

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText(click());
    ui->pushButton->setStyleSheet(color());
    board[0][0] = ui->pushButton->text();
    isX = !isX;
    ui->pushButton->setEnabled(false);
    check();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText(click());
    ui->pushButton_2->setStyleSheet(color());
    board[0][1] = ui->pushButton_2->text();
    isX = !isX;
    ui->pushButton_2->setEnabled(false);
    check();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText(click());
    ui->pushButton_3->setStyleSheet(color());
    board[0][2] = ui->pushButton_3->text();
    ui->pushButton_3->setEnabled(false);
    isX = !isX;
    check();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setText(click());
    ui->pushButton_4->setStyleSheet(color());
    board[1][0] = ui->pushButton_4->text();
    ui->pushButton_4->setEnabled(false);
    isX = !isX;
    check();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setText(click());
    ui->pushButton_5->setStyleSheet(color());
    board[1][1] = ui->pushButton_5->text();
    ui->pushButton_5->setEnabled(false);
    isX = !isX;
    check();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setText(click());
    ui->pushButton_6->setStyleSheet(color());
    board[1][2] = ui->pushButton_6->text();
    ui->pushButton_6->setEnabled(false);
    isX = !isX;
    check();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_7->setText(click());
    ui->pushButton_7->setStyleSheet(color());
    board[2][0] = ui->pushButton_7->text();
    isX = !isX;
    ui->pushButton_7->setEnabled(false);
    check();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_8->setText(click());
    ui->pushButton_8->setStyleSheet(color());
    board[2][1] = ui->pushButton_8->text();
    ui->pushButton_8->setEnabled(false);
    isX = !isX;
    check();
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_9->setText(click());
    ui->pushButton_9->setStyleSheet(color());
    board[2][2] = ui->pushButton_9->text();
    ui->pushButton_9->setEnabled(false);
    isX = !isX;
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

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != "0") {
                ui->label->setText(board[i][0] + "  WINS");
                fun(false);
            }
        }

        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != "0") {
                ui->label->setText(board[0][i] + "  WINS");
                fun(false);
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != "0") {
            ui->label->setText(board[0][0] + "  WINS");
            fun(false);
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != "0") {
            ui->label->setText(board[1][1] + "  WINS");
            fun(false);
        }

}

void MainWindow::on_pushButton_10_clicked()
{
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            board[i][j] = "0";
        }
    }
    isX = true;
    ui->label->setText(" ");
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
    fun(true);
}

void MainWindow::fun(bool arg){
    ui->pushButton->setEnabled(arg);
    ui->pushButton_2->setEnabled(arg);
    ui->pushButton_3->setEnabled(arg);
    ui->pushButton_4->setEnabled(arg);
    ui->pushButton_5->setEnabled(arg);
    ui->pushButton_6->setEnabled(arg);
    ui->pushButton_7->setEnabled(arg);
    ui->pushButton_8->setEnabled(arg);
    ui->pushButton_9->setEnabled(arg);
}
