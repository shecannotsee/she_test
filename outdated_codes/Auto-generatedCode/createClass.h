#ifndef _CREATE_CLASS_HPP_
#define _CREATE_CLASS_HPP_

#include <string>
#include <vector>

namespace she{

class CreateClass
{
public:
    CreateClass();
    ~CreateClass();

public:
    //执行
    int run();
    int run(int);

private:
    //根据文件读取类参数
    int readParameter();
    int readParameter(std::string);
    //根据输入添加类参数
    int getParameter();
private:
    //类名格式化
    std::string formatClassName(const std::string&);
    //函数名格式化
    std::string formatFunctionName(const std::string&);
    //类成员变量名格式化
    std::string formatDataName(const std::string&);
private:
    //生成类相应文件
    int writeClassDemo();

private:
    //过滤字符串左右空格
    std::string strTrim(std::string&);
    //

private:
    std::string readFileName;//读取文件名

    int createByWhat;//生成方式，0-报错，1-读文件，2-手动输入

    std::string namespaceName;//命名空间
    int isTemplate;//0为非泛型，1为泛型类
    std::string className;//类名
    std::vector<int> functionAccessSpecifiers;//函数访问修饰符，1-public，2-private-3-protect
    //std::vector<std::string> functionReturn;//函数返回值设置为void
    std::vector<std::string> functionName;//函数名

    std::vector<int> dataAccessSpecifiers;//数据访问修饰符，1-public，2-private-3-protect
    std::vector<std::string> dataName;//数据名



};//class CreateClass

};//namespace

#endif//!_CREATE_CLASS_HPP_