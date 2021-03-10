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
	void OnbtnCom();//计算hash值
	void OnbtnComSHA1();//计算sha1值
	int OnSlecbtn_plain(); //消息散列
	int OnSlecbtn_file(); //文件散列


private:
	Ui::HASHClass ui;
	//HASH *hash;
	string md5_text, sha1_text;
};
