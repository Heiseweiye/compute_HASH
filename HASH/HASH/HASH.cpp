#include "HASH.h"
#include "md5.h"
#include "GBK.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include "sha1.h"

HASH::HASH(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//hash = new HASH;
	connect(ui.Select_Button_plain, SIGNAL(clicked()), this, SLOT(OnSlecbtn_plain())); //切换消息散列计算页面
	connect(ui.Select_Button_file, SIGNAL(clicked()), this, SLOT(OnSlecbtn_file()));  //切换文件签名页面
	connect(ui.Butn_compute, SIGNAL(clicked()), this, SLOT(OnbtnCom())); //计算散列值
	connect(ui.btn_computeSHA1, SIGNAL(clicked()), this, SLOT(OnbtnComSHA1()));//计算sha1值
	connect(ui.Btn_openfile1, SIGNAL(clicked()), this, SLOT(OnbtnOpen()));     //文件打开
	connect(ui.Btn_openfile2, SIGNAL(clicked()), this, SLOT(OnbtnOpen2()));

}

//散列值计算页面
int HASH::OnSlecbtn_plain()
{
	ui.stackedWidget->setCurrentIndex(0);
	return 0;
}
//文件签名计算页面
int HASH::OnSlecbtn_file()
{
	ui.stackedWidget->setCurrentIndex(1);
	return 0;
}

void HASH::OnbtnCom()
{
	md5_text.clear();
	ui.plainTextEdit_MD5->clear();
	QString text = ui.input_plaintext->toPlainText();//获取输入框中的明文，格式为QString
	string plain = text.toStdString();        //格式转换为string
	md5_text = MD5(plain).toStr();           //获得md5值，转化为string格式
	
	
	ui.plainTextEdit_MD5->setPlainText(QString::fromStdString(md5_text)); //显示md5值，格式转化为QString
	
}

void HASH::OnbtnComSHA1()
{
	sha1_text.clear();
	ui.plainTextEdit_SHA1->clear();
	QString text = ui.input_plaintext_2->toPlainText();
	string plain = text.toStdString();
	char string[100000];
	strcpy(string, plain.c_str());          //将明文框中的内容char类型转化为string类型
	char encoded_sha1[21] = { 0 };
	char hexresult[41];
	SHA1(encoded_sha1, string, strlen(string));
	//生成sha1散列值赋值给hexresult
	for (int offset = 0; offset < 20; offset++) {

		sprintf_s((hexresult + (2 * offset)), 3, "%02x", encoded_sha1[offset] & 0xff);

	}

	//将sha1结果转化为string类型
	for (int i = 0; i < strlen(hexresult); ++i)
	{
		sha1_text += hexresult[i];
	}
	ui.plainTextEdit_SHA1->setPlainText(QString::fromStdString(sha1_text));//显示sha1值，格式转化为QString
}

int HASH::OnbtnOpen()
{
	// 选择要打开的文件
	QString filepath = QFileDialog::getOpenFileName(
		this, // 父窗口
		GBK::ToUnicode("选择文件") // 标题caption
		);

	// 为空时表示用户取消了操作,没有选中任何文件
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// 打开文件，读取内容
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// 文件的大小
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// 读取内容
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// 显示到文本框中
			ui.input_plaintext->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // 释放内存
		fclose(fp);  // 关闭文件
	}
	return 0;
}

int HASH::OnbtnOpen2()
{
	// 选择要打开的文件
	QString filepath = QFileDialog::getOpenFileName(
		this, // 父窗口
		GBK::ToUnicode("选择文件") // 标题caption
		);

	// 为空时表示用户取消了操作,没有选中任何文件
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// 打开文件，读取内容
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// 文件的大小
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// 读取内容
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// 显示到文本框中
			ui.input_plaintext_2->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // 释放内存
		fclose(fp);  // 关闭文件
	}
	return 0;
}