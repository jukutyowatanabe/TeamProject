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
		/////‰Šúİ’è///// 
		game_state++;
		/*fallthrough*/

	case 1:
		/////ƒpƒ‰ƒ[ƒ^‚Ìİ’è///// 
		game_state++;
		/*fallthrough*/

	case 2:
		/////’Êí///// 
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