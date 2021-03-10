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
	connect(ui.Select_Button_plain, SIGNAL(clicked()), this, SLOT(OnSlecbtn_plain())); //�л���Ϣɢ�м���ҳ��
	connect(ui.Select_Button_file, SIGNAL(clicked()), this, SLOT(OnSlecbtn_file()));  //�л��ļ�ǩ��ҳ��
	connect(ui.Butn_compute, SIGNAL(clicked()), this, SLOT(OnbtnCom())); //����ɢ��ֵ
	connect(ui.btn_computeSHA1, SIGNAL(clicked()), this, SLOT(OnbtnComSHA1()));//����sha1ֵ
	connect(ui.Btn_openfile1, SIGNAL(clicked()), this, SLOT(OnbtnOpen()));     //�ļ���
	connect(ui.Btn_openfile2, SIGNAL(clicked()), this, SLOT(OnbtnOpen2()));

}

//ɢ��ֵ����ҳ��
int HASH::OnSlecbtn_plain()
{
	ui.stackedWidget->setCurrentIndex(0);
	return 0;
}
//�ļ�ǩ������ҳ��
int HASH::OnSlecbtn_file()
{
	ui.stackedWidget->setCurrentIndex(1);
	return 0;
}

void HASH::OnbtnCom()
{
	md5_text.clear();
	ui.plainTextEdit_MD5->clear();
	QString text = ui.input_plaintext->toPlainText();//��ȡ������е����ģ���ʽΪQString
	string plain = text.toStdString();        //��ʽת��Ϊstring
	md5_text = MD5(plain).toStr();           //���md5ֵ��ת��Ϊstring��ʽ
	
	
	ui.plainTextEdit_MD5->setPlainText(QString::fromStdString(md5_text)); //��ʾmd5ֵ����ʽת��ΪQString
	
}

void HASH::OnbtnComSHA1()
{
	sha1_text.clear();
	ui.plainTextEdit_SHA1->clear();
	QString text = ui.input_plaintext_2->toPlainText();
	string plain = text.toStdString();
	char string[100000];
	strcpy(string, plain.c_str());          //�����Ŀ��е�����char����ת��Ϊstring����
	char encoded_sha1[21] = { 0 };
	char hexresult[41];
	SHA1(encoded_sha1, string, strlen(string));
	//����sha1ɢ��ֵ��ֵ��hexresult
	for (int offset = 0; offset < 20; offset++) {

		sprintf_s((hexresult + (2 * offset)), 3, "%02x", encoded_sha1[offset] & 0xff);

	}

	//��sha1���ת��Ϊstring����
	for (int i = 0; i < strlen(hexresult); ++i)
	{
		sha1_text += hexresult[i];
	}
	ui.plainTextEdit_SHA1->setPlainText(QString::fromStdString(sha1_text));//��ʾsha1ֵ����ʽת��ΪQString
}

int HASH::OnbtnOpen()
{
	// ѡ��Ҫ�򿪵��ļ�
	QString filepath = QFileDialog::getOpenFileName(
		this, // ������
		GBK::ToUnicode("ѡ���ļ�") // ����caption
		);

	// Ϊ��ʱ��ʾ�û�ȡ���˲���,û��ѡ���κ��ļ�
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// ���ļ�����ȡ����
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// �ļ��Ĵ�С
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// ��ȡ����
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// ��ʾ���ı�����
			ui.input_plaintext->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // �ͷ��ڴ�
		fclose(fp);  // �ر��ļ�
	}
	return 0;
}

int HASH::OnbtnOpen2()
{
	// ѡ��Ҫ�򿪵��ļ�
	QString filepath = QFileDialog::getOpenFileName(
		this, // ������
		GBK::ToUnicode("ѡ���ļ�") // ����caption
		);

	// Ϊ��ʱ��ʾ�û�ȡ���˲���,û��ѡ���κ��ļ�
	if (filepath.length() > 0)
	{
		string gbk_name = GBK::FromUnicode(filepath);
		if (gbk_name.length() == 0)
		{
			QMessageBox::warning(this, "error",
				"GBK not supported, See 'Change Jian Wen Ti Hui Zong'");
			return -1;
		}

		// ���ļ�����ȡ����
		FILE* fp = fopen(gbk_name.c_str(), "rb");

		// �ļ��Ĵ�С
		fseek(fp, 0, SEEK_END);
		int filesize = ftell(fp);

		// ��ȡ����
		fseek(fp, 0, SEEK_SET);
		char* buf = new char[filesize + 1];
		int n = fread(buf, 1, filesize, fp);
		if (n > 0)
		{
			buf[n] = 0;
			// ��ʾ���ı�����
			ui.input_plaintext_2->setPlainText(GBK::ToUnicode(buf));
		}
		delete[] buf; // �ͷ��ڴ�
		fclose(fp);  // �ر��ļ�
	}
	return 0;
}