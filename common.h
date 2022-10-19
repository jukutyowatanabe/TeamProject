#ifndef COMMON_H
#define COMMON_H 

#define SCENE_NONE -1 
#define SCENE_TITLE 0 
#define SCENE_GAME 1

// ‰æ–Ê‚Ì‘å‚«‚³
#define SCREEN_W 1280 
#define SCREEN_H 720 

//“_–Å‚ÌŠÔŠu
#define BLINK 32

// •Ï”‚ÌéŒ¾
extern int curScene;
extern int nextScene;
extern int title_state;
extern int title_timer;
extern int game_state;
extern int game_timer;

#endif//COMMON_H