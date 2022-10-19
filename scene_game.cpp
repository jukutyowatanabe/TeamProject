#include "all.h"

int game_state;
int game_timer;

void game_init()
{
	game_state = 0;
	game_timer = 0;
}

void game_deinit()
{
}

void game_update()
{
	switch (game_state)
	{
	case 0:
		/////�����ݒ�///// 
		game_state++;
		/*fallthrough*/

	case 1:
		/////�p�����[�^�̐ݒ�///// 
		game_state++;
		/*fallthrough*/

	case 2:
		/////�ʏ펞///// 
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
			break;
		}
		break;
	}

	game_timer++;
}

void game_render()
{
	GameLib::clear(0, 0.5f, 0.5f);
	debug::setString("game_state: %i", game_state);
	debug::setString("game_timer: %i", game_timer);
}