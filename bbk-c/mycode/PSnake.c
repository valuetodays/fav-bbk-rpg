#include "inc\dictsys.h"
#include "inc\keytable.h"
#include "inc\stdlib.h"
#include "inc\flash.h"

extern U8 *abc;

extern U8 *gamemain;
extern U8 *s1_1,*s1_2,*s1_3, *arrow;
extern U8 *readme[12];

FAR void showMenu();
FAR void f_readme();
FAR void f_test();

FAR U8 GameTanShiShe()
{
	/*һ������init������ÿ�����򶼱���Ҫ�е�,����������Ϣ�жӺ��ڴ���г�ʼ��������,��û����������ϵͳ����ĳЩ�쳣,����������һ��û���������������ĳ����,�ٽ���ϵͳ�Դ���������,��ᷢ�����������ٶȳ���*/
	GuiInit();					/*Gui OS��ʼ����ʹ��ǰһ��Ҫ����*/
	SysMemInit(MEM_HEAP_START,MEM_HEAP_SIZE);	/*��ʼ����*/
	SysLCDClear();	/*����,�൱��BASIC�е�CLS*/

	showMenu();
	
	return(1);
}

FAR void f_test() {

}


FAR void showMenu() {
	U16 arrow_pos = 1; /* ���ֿ��� 1,2,3 */

reshow:
	SysLCDClear();

	SysPrintString(0,0,gamemain);
	SysPrintString(32,24,s1_1);
	SysPrintString(32,48,s1_2);
	SysPrintString(32,72,s1_3);
	SysPrintString(32, 24 * arrow_pos, arrow);


	MsgType key;
	GuiSetKbdType(SYS_ENG_KBD);
	GuiGetMsg(&key);
	GuiTranslateMsg(&key);
	if (key.type == WM_CHAR_FUN) {
		if (key.param == CHAR_UP) {
			if (arrow_pos > 1) {
				arrow_pos--;
			} else {
				arrow_pos = 3;
			}
		} else if(key.param == CHAR_DOWN) {
			if (arrow_pos < 3) {
				arrow_pos++;
			} else {
				arrow_pos = 1;
			}
		} else if(key.param == CHAR_ENTER){
			if (arrow_pos == 1) {
			} else if (arrow_pos == 2) {
				f_readme();
			} else {
				return ; /* exit */
			}
		} else if(key.param == CHAR_EXIT){
			return ;
		}	
	}

	goto reshow;
}

FAR void f_readme() {
	U16 pos = 1;
	MsgType key;

ius:
	SysLCDClear();
	SysPrintString(0,0,readme[pos]);
	SysPrintString(0,16,readme[pos+1]);
	SysPrintString(0,32,readme[pos+2]);
	SysPrintString(0,48,readme[pos+3]);
	SysPrintString(0,64,readme[pos+4]);
	SysPrintString(0,80,readme[pos+5]);

	GuiSetKbdType(SYS_ENG_KBD);
	GuiGetMsg(&key);
	GuiTranslateMsg(&key);
	if (key.type == WM_CHAR_FUN) {
		if (key.param == CHAR_UP) {
			if (pos > 1) {
				pos--;
			}
		} else if(key.param == CHAR_DOWN) {
			if (pos < 6) {
				pos++;
			} 
		} else if(key.param==CHAR_EXIT){
			pos = 1;
			return ;
		}	
	}
	goto ius;
}

