#include "bullet_counter_gui.h"

static lv_obj_t *scr_loaded = NULL;

extern const lv_img_dsc_t bullet_counter_loaded;
extern const lv_img_dsc_t bullet_counter_not_loaded;
extern const lv_img_dsc_t bullet;
extern const lv_img_dsc_t bullet_outline;
extern const lv_img_dsc_t bullet_small;
extern const lv_img_dsc_t bullet_outline_small;
extern const lv_img_dsc_t red_outline;
extern const lv_img_dsc_t green_outline;

extern const lv_font_t digifacewide;

static lv_obj_t *scr_counter = NULL;

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

void display_bullet_status(int bullet_cnt, bool is_loaded)
{
    scr_counter = lv_scr_act();
    lv_obj_clean(scr_counter);

    lv_obj_t * label_counter = lv_label_create(scr_counter);
    lv_obj_t * cont_bullets = lv_obj_create(scr_counter);
    lv_obj_t * img_ouline = lv_img_create(scr_counter);
    lv_obj_t * img_bullet = lv_img_create(img_ouline);


    static lv_style_t default_style;
    lv_style_init(&default_style);
    lv_style_set_bg_opa(&default_style, LV_OPA_COVER);
    lv_style_set_bg_color(&default_style, lv_color_black());

    //lv_obj_add_style(scr_counter, &default_style, 0);

    static lv_style_t label_style;
    lv_style_init(&label_style);
    lv_style_set_bg_opa(&label_style, LV_OPA_COVER);
    lv_style_set_text_font(&label_style, &digifacewide);
    lv_style_set_bg_color(&label_style, lv_color_black());
    lv_style_set_text_color(&label_style, lv_color_make(255, 0, 0));


    static lv_style_t cont_style;
    lv_style_init(&cont_style);
    lv_style_set_bg_opa(&cont_style, LV_OPA_COVER);
    lv_style_set_bg_color(&cont_style, lv_color_black());
    lv_style_set_pad_all(&cont_style, 0);


    static lv_style_t img_bullet_style;
    lv_style_init(&img_bullet_style);
    lv_style_set_bg_opa(&img_bullet_style, LV_OPA_COVER);
    lv_style_set_bg_color(&img_bullet_style, lv_color_black());


    char str[5];
    itoa(bullet_cnt, str, 10);
    lv_label_set_text(label_counter, str);
    lv_obj_add_style(label_counter, &label_style, LV_STATE_DEFAULT);
    lv_obj_align(label_counter, LV_ALIGN_TOP_LEFT, 20, 20);


    lv_obj_set_size(cont_bullets, 64, LV_SIZE_CONTENT);
    lv_obj_remove_style_all(cont_bullets);
    lv_obj_add_style(cont_bullets, &cont_style, LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(cont_bullets, LV_FLEX_FLOW_COLUMN);
    lv_obj_align(cont_bullets, LV_ALIGN_TOP_LEFT, 25, 108);


    lv_obj_align(img_ouline, LV_ALIGN_TOP_LEFT, 120, 10);
    if(is_loaded)
        lv_img_set_src(img_ouline, &red_outline);
    else
         lv_img_set_src(img_ouline, &green_outline);
    lv_obj_set_size(img_ouline, 100, 222);

    lv_obj_align(img_bullet, LV_ALIGN_TOP_LEFT, 20, 40);
    if(is_loaded)
        lv_img_set_src(img_bullet, &bullet);
    else
        lv_img_set_src(img_bullet, &bullet_outline);

    for(int i = 0 ; i < bullet_cnt; i++)
    {
        lv_obj_t *img = lv_img_create(cont_bullets);
        lv_img_set_src(img, &bullet_small);
    }

    for(int j = bullet_cnt ; j < 7; j++)
    {
        lv_obj_t *img = lv_img_create(cont_bullets);
        lv_img_set_src(img, &bullet_outline_small);
    }
}