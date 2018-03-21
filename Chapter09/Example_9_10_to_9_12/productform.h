#ifndef PRODUCTFORM_H
#define PRODUCTFORM_H

#include <QDialog>
class Product;
class Ui_ProductForm;
class QWidget;
class QAbstractButton;


class ProductForm : public QDialog
{
    Q_OBJECT
public:
    explicit ProductForm(Product* product = 0, QWidget* parent=0);
    void setModel(Product* model);
public slots:
    void accept();
    void commit();
    void update();
private:
    Ui_ProductForm *m_ui;
    Product* m_model;
};

#endif // PRODUCTFORM_H
