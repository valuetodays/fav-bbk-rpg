### 生搬硬套-用bbk AC语言开发包开发HelloWorld

[ from http://eblog.doyourealizethattheimportantisdifficult.cn/article/detail/59 ]


首先从网上下载bbk c开发包，有我提供两种方法：
- 从天际边工作室[http://wstjb.ys168.com/](http://wstjb.ys168.com/)下载；
- 从我的个人小站下载[http://121575024.ys168.com/](http://121575024.ys168.com/)

学习修改之前先看下通宵虫的视频。它可是虫子哥留给我们的宝贵的财富啊。下载地址上面有。我把虫子哥用的“教程”整理成了txt格式。

我把解压后的bbk_C语言开发包放在了桌面上。截图如下：

![](https://gitee.com/valuetodays/ellen/raw/master/blog-attachment/eblog/20190613/file_list.png)

注：我用了传说中的护眼模式，以致窗口背景颜色是如此柔和，以致你们看到不和你们的白色一样，但——请不要惊奇。


按readme.txt中虫子哥的说法，双击os文件夹下的build.bat，Oh~my God！！竟然没有编译成功，出现了如下的截图：

![](https://gitee.com/valuetodays/ellen/raw/master/blog-attachment/eblog/20190613/error.png)

我看到了图片一中的地址栏中的**\桌面\**中“桌面”是中文，抱着试试看的态度，把bbk_C语言开发包移到了C盘根目录下后再执行，结果竟然编译成功了……

![](https://gitee.com/valuetodays/ellen/raw/master/blog-attachment/eblog/20190613/right.png)


哈哈，终于编译成功了。下面我们就开始有名的“HelloWorld！”之旅吧。

我们所做的改动都在os目录下。
按照通宵虫的步骤，我们先把PSnakeData.c清空并写入如下两行内容：
#include "inc\dictsys.h"	
const U8 *str="HelloWorld";
注：我们为方便起见，去掉了注释。说明一下，第一行#include "inc\dictsys.h"即类似C语言中的包含头文件；在第二行中我们定义了一个str指针变量。

然后，我们清空PSnake.c文件并添加如下蓝色内容：

```c
#include "inc\dictsys.h"
extern U8 *str;	
FAR U8 GameTanShiShe()
{
	GuiInit();	
	SysMemInit(MEM_HEAP_START,MEM_HEAP_SIZE);
	MsgType Msg;
	SysLCDClear();
	SysPrintString(11,23,str);	
	GuiGetMsg(&Msg);

	return(1);	
}
```c
	
最后，我们还要清空PSnake.h、PSnakeFar.c两个文件。

最最后，双击运行build.bat，成功了！

注：

- 具体解释请见通宵虫的视频；
- 上面的SysPrintString(11,23,str);中的11和23是将字符串写在屏幕上的位置，自己可以任意换，但不要太大，我试了1000和100后屏幕上什么也不显示，而用171和61竟然有显示。它们是U8类型的数据，不要超过其表达范围，范围如下：

![](https://gitee.com/valuetodays/ellen/raw/master/blog-attachment/eblog/20190613/fillRect.png)

（注：1、我用的是金山wps，上图是读取BIOS.doc的截图；2、为了让图片明显些，特意加了边框。）

2013年4月18日 星期四
