#include "bullet_counter_gui.h"

static lv_obj_t *scr_loaded = NULL;
static lv_obj_t *scr_not_loaded = NULL;

void bullet_counter_gui_init()
{

}

void bullet_counter_gui_release(void)
{
    // if (scr_1 != NULL)
    // {
    //     lv_obj_clean(scr_1);
    //     scr_1 = NULL;
    //     weatherImg = NULL;
    //     cityLabel = NULL;
    //     btn = NULL;
    //     btnLabel = NULL;
    //     txtLabel = NULL;
    //     clockLabel_1 = NULL;
    //     clockLabel_2 = NULL;
    //     dateLabel = NULL;
    //     tempImg = NULL;
    //     tempBar = NULL;
    //     tempLabel = NULL;
    //     humiImg = NULL;
    //     humiBar = NULL;
    //     humiLabel = NULL;
    //     spaceImg = NULL;
    // }

    // if (scr_2 != NULL)
    // {
    //     lv_obj_clean(scr_2);
    //     scr_2 = NULL;
    //     chart = NULL;
    //     titleLabel = NULL;
    //     ser1 = NULL;
    //     ser2 = NULL;
    // }
}

void bullet_counter_gui_del(void)
{
    bullet_counter_gui_release();

    // 手动清除样式，防止内存泄漏
    // lv_style_reset(&default_style);
    // lv_style_reset(&chFont_style);
    // lv_style_reset(&numberSmall_style);
    // lv_style_reset(&numberBig_style);
    // lv_style_reset(&btn_style);
    // lv_style_reset(&bar_style);
}

void display_bullet_status()
{
    scr_loaded = lv_scr_act();
    
    //lv_obj_t* img_loaded = lv_img_create(scr_loaded);
    //lv_img_set_src(img_loaded, &bullet_counter_not_loaded);
}