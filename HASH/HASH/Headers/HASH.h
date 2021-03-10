#pragma once
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include "ui_HASH.h"
#include <iostream>
using namespace std;

class HASH : public QMainWindow
{
	Q_OBJECT

public:
	HASH(QWidget *parent = Q_NULLPTR);

private slots:
	void OnbtnCom();//����hashֵ
	void OnbtnComSHA1();//����sha1ֵ
	int OnSlecbtn_plain(); //��Ϣɢ��
	int OnSlecbtn_file(); //�ļ�ɢ��


private:
	Ui::HASHClass ui;
	//HASH *hash;
	string md5_text, sha1_text;
};
