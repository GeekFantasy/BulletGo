#include "bullet_counter_gui.h"

#define  ALERT_BULLET_NUM   2

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
static lv_obj_t *label_counter = NULL;
static lv_obj_t *cont_bullets = NULL;
static lv_obj_t *img_frame = NULL;
static lv_obj_t *img_bullet = NULL;
static lv_obj_t *img_bullet_outline = NULL;

static lv_anim_t anim_shoot;
static lv_anim_t anim_load;

static bool prev_load_state = true;
static int prev_bullet_cnt = 0;

void display_not_loaded(lv_anim_t * a)
{
    lv_img_set_src(img_frame, &green_outline);
    lv_obj_clear_flag(img_bullet_outline, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(img_bullet, LV_OBJ_FLAG_HIDDEN);
}

void display_loaded(lv_anim_t * a)
{
    lv_img_set_src(img_frame, &red_outline);
}

void bullet_counter_gui_init()
{
    lv_obj_t *act_obj = lv_scr_act();
    if (act_obj == scr_counter)
        return;
    lv_obj_clean(act_obj);

    if (NULL != scr_counter)
        lv_obj_del(scr_counter);
    scr_counter = lv_obj_create(NULL);

    label_counter = lv_label_create(scr_counter);
    cont_bullets = lv_obj_create(scr_counter);
    img_frame = lv_img_create(scr_counter);
    img_bullet = lv_img_create(img_frame);
    img_bullet_outline = lv_img_create(img_frame);

    static lv_style_t default_style;
    lv_style_init(&default_style);
    lv_style_set_bg_color(&default_style, lv_color_black());
    lv_obj_add_style(scr_counter, &default_style, LV_STATE_DEFAULT);

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

    lv_label_set_text(label_counter, "0");
    lv_obj_add_style(label_counter, &label_style, LV_STATE_DEFAULT);
    lv_obj_align(label_counter, LV_ALIGN_TOP_LEFT, 20, 20);

    lv_obj_set_size(cont_bullets, 64, LV_SIZE_CONTENT);
    lv_obj_remove_style_all(cont_bullets);
    lv_obj_add_style(cont_bullets, &cont_style, LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(cont_bullets, LV_FLEX_FLOW_COLUMN);
    lv_obj_align(cont_bullets, LV_ALIGN_TOP_LEFT, 25, 108);

    lv_obj_align(img_frame, LV_ALIGN_TOP_LEFT, 120, 10);
    lv_obj_set_size(img_frame, 100, 222);
    lv_img_set_src(img_frame, &green_outline);

    lv_obj_align(img_bullet, LV_ALIGN_TOP_LEFT, 20, 40);
    lv_img_set_src(img_bullet, &bullet);
    lv_obj_add_flag(img_bullet, LV_OBJ_FLAG_HIDDEN);
    lv_obj_align(img_bullet_outline, LV_ALIGN_TOP_LEFT, 20, 40);
    lv_img_set_src(img_bullet_outline, &bullet_outline);
    //lv_obj_add_flag(img_bullet_outline, LV_OBJ_FLAG_HIDDEN);
    
    for (int j = 0; j < 7; j++)
    {
        lv_obj_t *img = lv_img_create(cont_bullets);
        lv_img_set_src(img, &bullet_outline_small);
    }

    // Animation
    lv_anim_init(&anim_shoot);
    lv_anim_set_exec_cb(&anim_shoot, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&anim_shoot, img_bullet);
    lv_anim_set_time(&anim_shoot, 350);
    lv_anim_set_values(&anim_shoot, 50, -170);
    lv_anim_set_ready_cb(&anim_shoot, display_not_loaded);

    lv_anim_init(&anim_load);
    lv_anim_set_exec_cb(&anim_load, (lv_anim_exec_xcb_t) lv_obj_set_y);
    lv_anim_set_var(&anim_load, img_bullet);
    lv_anim_set_time(&anim_load, 350);
    lv_anim_set_values(&anim_load, 220, 50);
    lv_anim_set_ready_cb(&anim_load, display_loaded);

    lv_scr_load(scr_counter);
}

void bullet_counter_gui_release(void)
{
    if (scr_counter != NULL)
    {
        lv_obj_clean(scr_counter);
        scr_counter = NULL;
    }
}

void bullet_counter_gui_del(void)
{
    bullet_counter_gui_release();
}

void display_bullet_status(int bullet_cnt, bool is_loaded)
{
    int bullet_sum = is_loaded ? (bullet_cnt + 1) : bullet_cnt;

    char str[5];
    itoa(bullet_sum, str, 10);
    lv_label_set_text(label_counter, str);
    if(bullet_sum <= ALERT_BULLET_NUM)
        lv_obj_set_style_text_color(label_counter, lv_color_make(255, 0, 0), LV_STATE_DEFAULT);
    else
        lv_obj_set_style_text_color(label_counter, lv_color_make(0, 255, 0), LV_STATE_DEFAULT);

    if((is_loaded != prev_load_state) && prev_load_state == true )
    {
        lv_anim_start(&anim_shoot);
        prev_load_state = is_loaded;
    }
    else if((is_loaded != prev_load_state) && prev_load_state == false)
    {
        lv_obj_add_flag(img_bullet_outline, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(img_bullet, LV_OBJ_FLAG_HIDDEN);
        lv_anim_start(&anim_load);
        prev_load_state = is_loaded;
    }


    if(prev_bullet_cnt != bullet_cnt) // check if bullet count changed
    {
        lv_obj_clean(cont_bullets);
        for (int i = 0; i < bullet_cnt; i++)
        {
            lv_obj_t *img = lv_img_create(cont_bullets);
            lv_img_set_src(img, &bullet_small);
        }

        for (int j = bullet_cnt; j < 7; j++)
        {
            lv_obj_t *img = lv_img_create(cont_bullets);
            lv_img_set_src(img, &bullet_outline_small);
        }
        prev_bullet_cnt = bullet_cnt;
    }    
}