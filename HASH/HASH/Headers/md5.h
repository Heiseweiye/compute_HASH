#ifndef MD5_H
#define MD5_H

/* 一些MD5的参数 */
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
	/* 使用字符串构造MD5对象 */
	MD5(const string& message);

	/* 生成md5摘要 */
	const byte* getDigest();

	/* 格式转换string */
	string toStr();

private:
	/* 初始化md5对象，处理另一个消息块,并更新上下文。*/
	void init(const byte* input, size_t len);

	/* MD5基本变换。基于块变换状态。*/
	void transform(const byte block[64]);

	/* 将输入(ussigned long)编码为输出(字节)。 */
	void encode(const bit32* input, byte* output, size_t length);

	/* 将输入(字节)解码为输出(ussigned long)。 */
	void decode(const byte* input, bit32* output, size_t length);

private:
	/* 标记是否计算完成。 */
	bool finished;

	/* 状态(ABCD)。*/
	bit32 state[4];

	/* 位数，低阶字优先。 */
	bit32 count[2];

	/* 输入缓冲区。 */
	byte buffer[64];

	/* 消息摘要。*/
	byte digest[16];

	/* 为计算填充。 */
	static const byte PADDING[64];

	/* 十六进制数字*/
	static const char HEX_NUMBERS[16];
};

#endif // MD5_H