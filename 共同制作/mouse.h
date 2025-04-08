#pragma once
#include<DxLib.h>

//キー入力情報に必要なデータをまとめた構造体
typedef struct {
	unsigned int m_nowKey;  //現在のボタン情報
	unsigned int m_PrevKey; //1フレーム前のボタン情報
	int MouseX;
	int MouseY;
	VECTOR m_v;



}INPUT_DATA;




//各キーの割り当て
#define KEY_MOUSE     (0b1)     //上移動


//キー入力の初期化
void InitInputMouse();
//キー入力情報更新
void UpdateInputMouse();
//キー入力判定（通常判定）
bool IsInputRepMouse(unsigned int key);
//キー入力判定（トリガー判定）
bool IsInputTrpMouse(unsigned int key);