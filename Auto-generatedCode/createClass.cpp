#include "createClass.h"
/* 流程解析
 * 1.选择生成方式（1-读文件-默认，2-一个一个输入）
 * 2.获取类参数
 *      A.通过读文件（readParameter）
 *      B.通过输入（getParameter）
 * 3.格式化参数
 *      formatClassName格式化类名
 *      formatFunctionName格式化函数名
 *      formatDataName格式化成员变量
 * 4.生成类文件
 *      writeClassDemo生成文件
 */