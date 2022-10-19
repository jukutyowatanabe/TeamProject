#include "all.h" 

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	//初期設定
	GameLib::init(L"自分でプロジェクトを作成", SCREEN_W, SCREEN_H);

	//ゲームループ
	while (GameLib::gameLoop())
	{
		// シーン切り替え処理
		if (curScene != nextScene)
		{
			switch (curScene)
			{
			case SCENE_TITLE:
				title_deinit();
				break;

			case SCENE_GAME:
				game_deinit();
				break;
			}

			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;

			case SCENE_GAME:
				game_init();
				break;
			}

			curScene = nextScene;
		}

		// 入力を更新する
		input::update();

		// 更新・描画処理
		switch (curScene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;

		case SCENE_GAME:
			game_update();
			game_render();
			break;
		}

		// デバッグ用文字列の表示
		debug::display(1, 1, 1, 1, 1);

		//画面描画
		GameLib::present(1, 0);
	}

	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;

	case SCENE_GAME:
		game_deinit();
		break;
	}

	//終了処理
	GameLib::uninit();

	return 0;
}