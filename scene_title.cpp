#include "all.h"

int title_state;
int title_timer;

Sprite* sprCar;
void title_init()
{
	title_state = 0;
	title_timer = 0;
}

void title_deinit()
{
	safe_delete(sprCar);
}

void title_update()
{
	switch (title_state)
	{
	case 0:
		/////‰Šúİ’è///// 
		sprCar = sprite_load(L"./Data/Images/right.png");
		title_state++;
		/*fallthrough*/

	case 1:
		/////ƒpƒ‰ƒ[ƒ^‚Ìİ’è///// 
		GameLib::setBlendMode(Blender::BS_ALPHA);
		title_state++;
		/*fallthrough*/

	case 2:
		/////’Êí///// 
		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_GAME;
			break;
		}
		break;
	}

	title_timer++;
}

void title_render()
{
	GameLib::clear(0, 0, 0);
	sprite_render(sprCar, 200, 200);

	text_out(2, "ECC COMP", 100, 100, 2, 2, 1, 1, 1);
	text_out(2, "Game Programming I", 130, 160, 1, 1, 1, 1, 1);

	if (title_timer / BLINK % 2 == 1)
	{
		text_out(2, "Push Enter Key", 150, 500, 2, 2, 1, 1, 1);
	}

	debug::setString("title_state: %i", title_state);
	debug::setString("title_timer: %i", title_timer);
	debug::setString("title_timer / BLINK    : %i", title_timer / BLINK);
	debug::setString("title_timer / BLINK %% 2: %i", title_timer / BLINK % 2);
}