# 一个简单的String类练习
## 笔记
### strcpy_s不能复制0？
### [拷贝赋值函数，自赋值](https://github.com/WWKy/practice_c_plus_plus/blob/dcd5faa784d2dc62deab8d24f3cc5d66b7d600f1/string/string/String.h#L42)
 - 在写拷贝赋值函数（赋值运算符重载）时，注意考虑自赋值的情况。不然可能会出现内存泄漏、存储内容错误等情况。
