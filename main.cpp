#include <Novice.h>

#include "SceneManager.h"
#include "Title.h"
#include "Game.h"

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
	//Enemy* enemy;
	EnemyManager* enemyManager = new EnemyManager();
	CManager* manager;

	std::vector<Bullet*> playerBullet_;
	std::vector<Bullet*> enemyBullet_;

	Vector2 range = {};
	float distance = {};
	float radius = {};

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
		//enemy->GetBullets();

		enemyManager->GetEnemy();
		player->GetPlayer();

		if (player->GetBullets().size() > 0) {
			for (int i = 0; i < player->GetBullets().size(); i++) {
				for (int j = 0; j < ENEMY_NUM; j++) {

					range = (player->GetBullets()[i]->GetPos()) - (enemyManager->GetEnemy()[j]->GetPos());
					distance = (range.x * range.x) + (range.y * range.y);
					radius = (player->GetBullets()[i]->GetRadius()) + (enemyManager->GetEnemy()[j]->GetRadius());

					if (distance <= radius * radius) {
						enemyManager->GetEnemy()[j]->ChackHitCircle();
					}

				}
			}
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

	delete player;
	delete enemyManager;
	delete manager;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
