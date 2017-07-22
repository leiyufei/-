#定义 _CRT_SECURE_NO_WARNINGS
#如果未定义__HUFFMAN_CODE_CPP__
#定义 __HUFFMAN_CODE_CPP__

#包括<iostream>
使用 名称空间 性病;
#包括 <assert.h>
#包括 ”FileCompress.h”

FileCompress:FileCompress()
{
	size_t大小=运算符(这- > _info)/运算符(这- > _info[0]);
	为(size_t我=0,我<大小;+ + i)
{
		这- > _info[我]。_ch=我;
		这- > _info[我]。_count=0;
}
}

无效 FileCompress:CompressHuffCode(常量 字符*文件名)
{
	断言(文件名);
	文件*输出信号=打开外部文件(文件名,”rb”);
	断言(输出信号);
	/ /统计字符出现的次数
	字符ch =获取(输出信号);
	而(!feof(输出信号))
{
+ +这- > _info[(无符号 字符)ch]。_count;
ch =获取(输出信号);
}

	/ /建立哈夫曼树
HuffmanTree < CharInfo >huffTree(这- > _info,运算符(这- > _info)/运算符(这- > _info[0]),0);

	/ /生成哈夫曼编码
字符串的代码;
HuffmanNode < CharInfo > *根= huffTree。GetHuffmanNode();
	GenerateHuffmanCode(根,*这、代码);

	/ /生成压缩文件名及配置文件名
字符串fileInName =(string)文件名;/ /压缩文件名
字符串fileConfig = fileInName;/ /配置文件名
	size_tlast_ = fileInName。find_last_of(”。”);
	如果(last_ < fileInName。大小())
{
fileInName。擦除(last_);
fileConfig。擦除(last_);
}
fileInName + =”.huff”;
fileConfig + =”config”;

	/ /fileInName = " E:\ \姚瑶文件压缩文件\ \ yaoyaoh”;
	/ /fileConfig = " E:\ \姚瑶文件压缩文件\ \ yaoyao.config”;

字符串tmp;

	/ /生成压缩配置文件
	文件*fConfig=打开外部文件(fileConfig。c_str(),”白平衡”);
	字符浅黄色(20]= {0};
	为(size_t我=0,我<运算符(这- > _info)/运算符(这- > _info[0]);+ + i)
{
		如果(这- > _info[我]。_count! =0)
{
tmp + =这- > _info[我]。_ch;
tmp + =”:”;
tmp + =(字符串)_itoa((这- > _info[我]。_count),健康的身体,10);
tmp + =”\ n”;
			fputs(tmp。c_str(),fConfig);
tmp。清晰的();
}
}

	/ /对文件进行压缩
	文件*鳍=打开外部文件(fileInName。c_str(),”白平衡”);
	断言(鳍);
	fseek(输出信号,0,SEEK_SET);
	intpos =0;
	无符号 字符显示字符=0;
ch =获取(输出信号);
	而(!feof(输出信号))
{
tmp =这- > _info[(无符号 字符)ch]。_code;
		为(size_t我=0,我< tmp。大小();+ + i)
{
显示字符< < =1;
显示字符| =(tmp[我]”0”);
			如果(+ + pos = =8)
{
				fputc(显示字符,鳍);
pos =0;
显示字符=0;
}
}
ch =获取(输出信号);
}
	如果(pos >0)
{
显示字符< < =(8(pos);
		fputc(显示字符,鳍);
}

	文件关闭(输出信号);
	文件关闭(鳍);
	文件关闭(fConfig);
}

无效 FileCompress:GenerateHuffmanCode(HuffmanNode < CharInfo > *根,FileCompress&文件、字符串代码)
{
	如果(根= =零)
{
		返回;
}
	如果(根- > _left = =零& &根- > _right = =零)
{
文件。_info(根- > _weight。_ch]。_code=代码;
		返回;
}
代码。push_back方法(”0”);
	GenerateHuffmanCode(根- > _left、文件、代码);
代码。pop_back();
代码。push_back方法(”1”);
	GenerateHuffmanCode(根- > _right、文件、代码);
代码。pop_back();
}

无效 FileCompress:UnCompressHuffCode(常量 字符*文件名)
{
	断言(文件名);
	文件*输出信号=打开外部文件(文件名,”rb”);
	断言(输出信号);
	/ /读取文件,
字符串fileConfig =(string)文件名;
字符串fileInName = fileConfig;
	size_tlast_ = fileInName。find_last_of(”。”);
	如果(last_ < fileInName。大小())
{
fileConfig。擦除(last_);
fileInName。擦除(last_);
}
fileConfig + =”config”;
fileInName + =”_Com.txt”;

	/ /fileInName = " E:\ \姚瑶文件压缩文件\ \ yaoyao.txt”;
	/ /fileConfig = " E:\ \姚瑶文件压缩文件\ \ yaoyao.config”;

	文件*鳍=打开外部文件(fileInName。c_str(),”白平衡”);
	断言(鳍);
	文件*fConfig=打开外部文件(fileConfig。c_str(),”rb”);
	断言(fConfig);

	/ /修改_count,注意\ n,有可能代表字符,有可能是行结束标志
	字符浅黄色(20]= {0};
	无符号 字符ch =获取(fConfig);
	而(!feof(fConfig))
{
		获取(fConfig);/ /读取冒号
		函数可以(迷,20,fConfig);
		这- > _info(ch)。_count=(TypeLong)atoi(浅黄色);
ch =获取(fConfig);
}

	/ /重建哈夫曼树
HuffmanTree < CharInfo >树(这- > _info,运算符(这- > _info)/运算符(这- > _info[0]),0);
HuffmanNode < CharInfo > *根=树。GetHuffmanNode();
HuffmanNode < CharInfo > * cur =根;
根- > _weight TypeLong countSum =。_count;/ /记录字符的总个数控制结束
ch =获取(输出信号);
	intpos =7;
	而(countSum >0)
{
		而(pos > =0)
{
			如果((ch &(1< < pos))= =0)/ /向左走
{
坏蛋= cur - > _left;
}
			其他的
{
坏蛋= cur - > _right;
}
			如果(cur - > _left = =零& & cur - > _right = =零)
{
				fputc(cur - > _weight。_ch,鳍);
				/ /cout < < - > _weight._ch;
				
				如果(——countSum = =0)/ /将没有写的字符的次数减1
					打破;
坏蛋=根;
}
——pos;
}
pos =7;
ch =获取(输出信号);
}
	文件关闭(鳍);
	文件关闭(输出信号);
	文件关闭(fConfig);
}

无效 FileCompress:PrintCode()常量
{
	为(int我=0,我<256年;+ + i)
{
		如果(这- > _info[我]。_count! =0)
{
cout < <这- > _info[我]。_ch< <”:>”< <这- > _info[我]。_code< < endl;
}
}
}
#endif
