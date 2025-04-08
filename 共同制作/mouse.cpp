#include"mouse.h"
#include<DxLib.h>




//�O���[�o���ϐ��Ő���
INPUT_DATA g_inputMouse;


//�L�[���͂̏�����
void InitInputMouse() {
	g_inputMouse.m_nowKey = g_inputMouse.m_PrevKey = 0;
}
//�L�[���͏��X�V
void UpdateInputMouse() {

	//�ŐV����1�t���[���O�̏��ɂȂ�
	g_inputMouse.m_PrevKey = g_inputMouse.m_nowKey;
	//��U�ŐV���͏�����
	g_inputMouse.m_nowKey = 0;

	//�ŐV�����擾���Ă���

	GetMousePoint(&g_inputMouse.MouseX, &g_inputMouse.MouseY);

	DrawFormatString(32, 64, GetColor(255, 0, 0), "���WX�F%d", g_inputMouse.MouseX);
	DrawFormatString(32, 96, GetColor(255, 0, 0), "���WY�F%d", g_inputMouse.MouseY);

	g_inputMouse.m_v.x = g_inputMouse.MouseX;
	g_inputMouse.m_v.y = g_inputMouse.MouseY;
	g_inputMouse.m_v.z = 0.0f;



	//��L�[���擾
	if (CheckHitKey(MOUSE_INPUT_LEFT))
	{
		g_inputMouse.m_nowKey |= KEY_MOUSE;
	}

}
//�L�[���͔���i�ʏ픻��j
bool IsInputRepMouse(unsigned int key) {
	if ((g_inputMouse.m_nowKey & key) != 0)return true;
	else return false;
}
//�L�[���͔���i�g���K�[����j
bool IsInputTrpMouse(unsigned int key) {
	if ((g_inputMouse.m_nowKey & key) &&
		!(g_inputMouse.m_PrevKey & key) == 0)
	{
		return true;
	}
	else return false;
}