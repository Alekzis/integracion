#ifndef INTEGRACION_H
#define INTEGRACION_H

#include <QMainWindow>

namespace Ui {
class integracion;
}

class integracion : public QMainWindow
{
    Q_OBJECT

public:
    explicit integracion(QWidget *parent = 0);
    ~integracion();

private:
    Ui::integracion *ui;
    //declaration of functions
public slots:
    void Procesar();
    void Reinicio();
};

#endif // INTEGRACION_H
