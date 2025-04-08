#include"mouse.h"
#include<DxLib.h>




//グローバル変数で生成
INPUT_DATA g_inputMouse;


//キー入力の初期化
void InitInputMouse() {
	g_inputMouse.m_nowKey = g_inputMouse.m_PrevKey = 0;
}
//キー入力情報更新
void UpdateInputMouse() {

	//最新情報は1フレーム前の情報になる
	g_inputMouse.m_PrevKey = g_inputMouse.m_nowKey;
	//一旦最新情報は初期化
	g_inputMouse.m_nowKey = 0;

	//最新情報を取得していく

	GetMousePoint(&g_inputMouse.MouseX, &g_inputMouse.MouseY);

	DrawFormatString(32, 64, GetColor(255, 0, 0), "座標X：%d", g_inputMouse.MouseX);
	DrawFormatString(32, 96, GetColor(255, 0, 0), "座標Y：%d", g_inputMouse.MouseY);

	g_inputMouse.m_v.x = g_inputMouse.MouseX;
	g_inputMouse.m_v.y = g_inputMouse.MouseY;
	g_inputMouse.m_v.z = 0.0f;



	//上キー情報取得
	if (CheckHitKey(MOUSE_INPUT_LEFT))
	{
		g_inputMouse.m_nowKey |= KEY_MOUSE;
	}

}
//キー入力判定（通常判定）
bool IsInputRepMouse(unsigned int key) {
	if ((g_inputMouse.m_nowKey & key) != 0)return true;
	else return false;
}
//キー入力判定（トリガー判定）
bool IsInputTrpMouse(unsigned int key) {
	if ((g_inputMouse.m_nowKey & key) &&
		!(g_inputMouse.m_PrevKey & key) == 0)
	{
		return true;
	}
	else return false;
}