#ifndef MD5_H
#define MD5_H

/* һЩMD5�Ĳ��� */
#define s11 7
#define s12 12
#define s13 17
#define s14 22
#define s21 5
#define s22 9
#define s23 14
#define s24 20
#define s31 4
#define s32 11
#define s33 16
#define s34 23
#define s41 6
#define s42 10
#define s43 15
#define s44 21
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROTATELEFT(num, n) (((num) << (n)) | ((num) >> (32-(n))))

#define FF(a, b, c, d, x, s, ac) { \
  (a) += F ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
  (a) += G ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
  (a) += H ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
  (a) += I ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}

#include <string>
#include <cstring>

using std::string;

typedef unsigned char byte;
typedef unsigned int bit32;

class MD5 {
public:
	/* ʹ���ַ�������MD5���� */
	MD5(const string& message);

	/* ����md5ժҪ */
	const byte* getDigest();

	/* ��ʽת��string */
	string toStr();

private:
	/* ��ʼ��md5���󣬴�����һ����Ϣ��,�����������ġ�*/
	void init(const byte* input, size_t len);

	/* MD5�����任�����ڿ�任״̬��*/
	void transform(const byte block[64]);

	/* ������(ussigned long)����Ϊ���(�ֽ�)�� */
	void encode(const bit32* input, byte* output, size_t length);

	/* ������(�ֽ�)����Ϊ���(ussigned long)�� */
	void decode(const byte* input, bit32* output, size_t length);

private:
	/* ����Ƿ������ɡ� */
	bool finished;

	/* ״̬(ABCD)��*/
	bit32 state[4];

	/* λ�����ͽ������ȡ� */
	bit32 count[2];

	/* ���뻺������ */
	byte buffer[64];

	/* ��ϢժҪ��*/
	byte digest[16];

	/* Ϊ������䡣 */
	static const byte PADDING[64];

	/* ʮ����������*/
	static const char HEX_NUMBERS[16];
};

#endif // MD5_H