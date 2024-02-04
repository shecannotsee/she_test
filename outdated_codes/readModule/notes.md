读写文件
1.声明文件
ofstream	创建文件并向文件里写
ifstream	从文件读信息
fstream	    包括以上两种

2.打开文件
函数原型     void open(const char *filename, ios::openmode mode);
ios::app    追加模式。所有写入都追加到文件末尾。
ios::ate    文件打开后定位到文件末尾。
ios::in     打开文件用于读取。
ios::out    打开文件用于写入。
ios::trunc  如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。

3.进行操作
ofstream<<  写入文件
ifstream>>  从文件中读
fstream     可写可读

4.进阶