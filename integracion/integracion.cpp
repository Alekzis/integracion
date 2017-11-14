#include "integracion.h"
#include "ui_integracion.h"

integracion::integracion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integracion)
{
    ui->setupUi(this);
    //Slots Connections
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(Procesar()));
    connect(ui->Reinicio,SIGNAL(clicked()),this,SLOT(Reinicio()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

integracion::~integracion()
{
    delete ui;
}
//method processing

void integracion::Procesar(){
//declaration of temporary variables, error and integration functions

    QString temp, temp1;
    int i;
    double error=ui->h->value();
    double integ=0, integf=0, integfx=0;
    double M[11];

//arrays

    integf=(error/2)*M[0];
    integfx=(error/2)*M[10];

    for(i=1;i<10;i++){
        integ=integ+((error)*M[i]);
    }

    integ=integ+integf+integfx;
    M[0]=ui->f_1->value();
    M[4]=ui->f_2->value();
    M[6]=ui->f1->value();
    M[7]=ui->f2->value();
    M[8]=ui->f3->value();
    M[9]=ui->f4->value();
    M[10]=ui->f5->value();

//results


    temp.append("El Resultado De La Integral Es:\n").append(temp1.setNum(integ));
    ui->resultados->setText(temp);
}
//the data is reset to zero to restart

void integracion::Reinicio(){
    ui->x->setValue(0.0);
    ui->x_5->setValue(0.0);
    ui->f_2->setValue(0.0);
    ui->f_1->setValue(0.0);
    ui->f1->setValue(0.0);
    ui->f2->setValue(0.0);
    ui->f3->setValue(0.0);
    ui->f4->setValue(0.0);
    ui->f5->setValue(0.0);
    ui->f->setValue(0.0);
    ui->h->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->f_5->setValue(0.0);
    ui->f_4->setValue(0.0);
    ui->f_3->setValue(0.0);
    ui->resultados->clear();
}
