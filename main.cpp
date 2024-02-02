#include <Novice.h>

#include "SceneManager.h"
#include "Title.h"

#include "Player.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Bullet.h"

//やること　当たり判定,敵復活,ゲームシーン内で敵と自機を出す,ゲームループ,(シーン(クリア、ゲームオーバー))

const char kWindowTitle[] = "LC1B_05_オザワ_ユウト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player();
	EnemyManager* enemyManager = new EnemyManager();
	CManager* manager;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};		
	
	manager = new CManager(keys);
	manager->scene = new CTitle(manager);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);


		///
		/// ↓更新処理ここから
		///
		
		manager->Update();
		player->Update(keys);
		enemyManager->Update();
		
		player->GetBullets();
		enemyManager->GetEnemy();

		for (int i = 0; i < player->GetBullets().size(); i++) {
			Vector2 range = *player->GetBullets()[i]->GetPos(); 
			Vector2 range = *enemyManager->GetEnemy()[i].GetPos();

		}


		///
		/// ↑更新処理ここまで
		///
		
		manager->Draw();
		player->Draw();
		enemyManager->Draw();

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
