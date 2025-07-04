//=========================================================================================================================
//
//６月１７日：画面遷移を実装する[Result.cpp]
//Author:ShinaTaiyo
//
//=========================================================================================================================

//=============================================================
//インクルード
//=============================================================
#include "Result.h"
#include "bg.h"
#include "manager.h"
#include "input.h"
#include "ui.h"
#include "fade.h"
#include "camera.h"
#include "game.h"
#include "player.h"
//=========================================================================================================================

//=============================================================
//コンストラクタ
//=============================================================
CResult::CResult()
{

}
//=========================================================================================================================

//=============================================================
//デストラクタ
//=============================================================
CResult::~CResult()
{

}
//=========================================================================================================================

//=============================================================
//初期化処理
//=============================================================
HRESULT CResult::Init()
{
	CScene::Init();             //シーン初期化処理
	CBg::Create(CBg::TYPE::RESULT);//リザルト背景を生成	
	CUi* pUi = nullptr;         //UIへのポインタ

	CCamera* pCamera = CManager::GetCamera(); // カメラへのポインタ
	pCamera->SetRot(D3DXVECTOR3(0.0f, 0.0f, 0.0f)); // 向きを前に設定

	if (CGame::GetGameClear() == true)
	{//ゲームをクリアしていたら
		//「ゲームクリア」のUIを生成
		pUi = CUi::Create(CUi::UITYPE::GAMECLEAR_000,false,CObject2D::POLYGONTYPE::SENTERROLLING, 600.0f, 600.0f, 10, false, D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		pUi->SetUseBlinking(true, 30, 0.0f);//点滅させる
		pUi->SetUseDeath(true);             //死亡フラグを使用する
	}
	else
	{//ゲームに負けていたら
		//「負け」のUIを生成
		pUi = CUi::Create(CUi::UITYPE::LOSE_000, false, CObject2D::POLYGONTYPE::SENTERROLLING, 600.0f, 600.0f, 10, false, D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f),
			D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		pUi->SetUseBlinking(true, 30, 0.0f);//点滅させる
		pUi->SetUseDeath(true);             //死亡フラグを使用する
	}
	return S_OK;
}
//=========================================================================================================================

//=============================================================
//終了処理
//=============================================================
void CResult::Uninit()
{
	CScene::Uninit();//シーン終了処理
}
//=========================================================================================================================

//=============================================================
//更新処理
//=============================================================
void CResult::Update()
{
	CScene::Update();//シーン更新処理
	CInputKeyboard* pInputKeyboard = CManager::GetInputKeyboard();//キー入力情報へのポインタ
	CInputJoypad* pInputJoypad = CManager::GetInputJoypad();      //ジョイパッド入力情報へのポインタ
#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoypad->GetTrigger(CInputJoypad::JOYKEY::START) == true)
	{//ENTERキー又はジョイパッドのスタートボタンを押していたら
		CManager::GetSceneFade()->SetSceneFade(CFade::FADEMODE_IN, CScene::MODE_EDIT);//エディットモードにする
	}
#else
	if (CManager::GetInputKeyboard()->GetTrigger(DIK_RETURN) == true || CManager::GetInputJoypad()->GetTrigger(CInputJoypad::JOYKEY::START) == true)
	{//ENTERキー又はジョイパッドのスタートボタンを押していたら
		CManager::GetSceneFade()->SetSceneFade(CFade::FADEMODE_IN, CScene::MODE_TITLE);//タイトルモードにする
	}
#endif // _DEBUG
}
//=========================================================================================================================

//=============================================================
//描画処理
//=============================================================
void CResult::Draw()
{
	CScene::Draw();//シーン描画処理
}
//=========================================================================================================================