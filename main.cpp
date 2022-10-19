#include "all.h" 

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	//�����ݒ�
	GameLib::init(L"�����Ńv���W�F�N�g���쐬", SCREEN_W, SCREEN_H);

	//�Q�[�����[�v
	while (GameLib::gameLoop())
	{
		// �V�[���؂�ւ�����
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

		// ���͂��X�V����
		input::update();

		// �X�V�E�`�揈��
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

		// �f�o�b�O�p������̕\��
		debug::display(1, 1, 1, 1, 1);

		//��ʕ`��
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

	//�I������
	GameLib::uninit();

	return 0;
}