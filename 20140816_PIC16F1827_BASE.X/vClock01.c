/*************************************************
*  時間計測用Timer1ライブラリファイル
*    vLcd_cmd(cmd)  ----- コマンド出力
*    vLcd_data(data) ----- １文字表示出力
*    cDataTrans(data) ----- I2Cデータ出力共通関数
*************************************************/
#define vClock01_LIB

#include <xc.h>         // XC8 General Include File
#include "vCLOCK01.h"

/*******************************
*  時間変数のクリア
*******************************/
void vClock01_Clear()
{
	sSecc = 0;
	cFlagSec = 0;
	ucSec01= ucMin01= ucHour01=0;
}

/*******************************
*  user interrupt work
*  call this work evry 10msec interrupt.
*******************************/
void vClock01_interrupt()
{
    // for Timer1 interrupted
	cFlag10mSec = 1;
	sSecc++;
	if(sSecc >= 100 ){			// 10msec * 100 = 1sec
			sSecc = 0;
			cFlagSec++;
    }
}

/*******************************
*  時間カウント処理
*******************************/
void vClock01()
{

	if(cFlagSec) {					// 1秒が立っていたら
		ucSec01 += cFlagSec;		// １秒加算
		cFlagSec = 0;
		if(ucSec01 > 59){			// 1分経過(test=5sec)
			ucSec01 = 0;
			ucMin01++;				// 1分加算
			if(ucMin01 > 59){
				ucMin01 = 0;
				ucHour01++;			// 1時間加算
				if(ucHour01 > 23){
					ucHour01 = 0;
				}
			}

		}

	}
}

