#include <DxLib.h>
#include <zmouse.h>


#define SCREEN_SIZE_X (640) 
#define SCREEN_SIZE_Y (320)


int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);			// ウィンドウモードにするかどうか
	SetGraphMode(640, 480, 32);		// ウィンドウの解像度を設定する

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理　基本的にはこれより後でDxLib関数を使う
	if (DxLib_Init() == -1) return -1;



	// 一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);	// 画面のちらつきを無くす
	SetTransColor(255, 0, 255);		// 透過色指定　今回は真紫色を透明
	//初期化=======================================

	//=============================================





	//ゲームメインループ
	while (ProcessMessage() != -1)	// 問題が発生したら終了
	{

		// 「escキー」が押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;


		// 画面を一度何もない状態へ
		ClearDrawScreen();

		// ゲーム本体の命令はこれより下に書く


		//毎フレーム行う計算

		//======================================

		//======================================


		//毎フレーム画像描画




		//=====================================
		unsigned int color = GetColor(255, 0, 0);
		DrawCircle(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, 32, color, true);

		//=====================================
		// ゲーム本体の命令はこれより上に書く

		// 作成した画面をモニターへ転送
		ScreenFlip();

	}

	// 終了前処理==================


	DxLib_End();			// ＤＸライブラリ使用の終了処理
	//=============================

	return 0;				// プログラムの終了 
}