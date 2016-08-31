#ifndef _INCLUDE_FUNCTION_
#define _INCLUDE_FUNCTION_

//main
bool Update();
void Draw();
void Initialize();
void Finalize();


//startmenu
void startmenu_update();
void startmenu_draw();
void startmenu_initialize();
void startmenu_finalize();

//condition
void condition_update();
void condition_draw();
void condition_initialize();
void condition_finalize();

//power
void power_update();
void power_draw();
void power_initialize();
void power_finalize();

//timing
void timing_update();
void timing_draw();
void timing_initialize();
void timing_finalize();

//result
void result_update();
void result_draw();
void result_initialize();
void result_finalize();
void ranking(int get);//V‚µ‚¢‹L˜^‚ğ‘}“ü
void restart();


//record
void record_update();
void record_draw();
void record_initialize();
void record_finalize();
void create_char();//•¶š—ñ‚É•ÏŠ·

//music
void music_initialize();
void music_finalize();
void start_music(int h);//‰¹Šy‚ğ–Â‚ç‚·
void stop_music(int h);//‰¹Šy‚ğ~‚ß‚é


//save
void save_update();
void save_draw();
void save_initialize();
void save_finalize();
void save_load();//‹L˜^‚ğ“Ç‚İ‚ŞŠÖ”
void save_output();//‹L˜^‚ğo—Í‚·‚éŠÖ”

#endif