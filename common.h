#ifndef COMMON_H
#define COMMON_H 

#define SCENE_NONE -1 
#define SCENE_TITLE 0 
#define SCENE_GAME 1

// 画面の大きさ
#define SCREEN_W 1280 
#define SCREEN_H 720 

//点滅の間隔
#define BLINK 32

// 変数の宣言
extern int curScene;
extern int nextScene;
extern int title_state;
extern int title_timer;
extern int game_state;
extern int game_timer;

#endif//COMMON_H