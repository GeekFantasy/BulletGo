#include "stability_training_gui.h"

#define ALERT_BULLET_NUM 2

extern const lv_font_t digifacewide;

static lv_obj_t *scr_training = NULL;
static lv_obj_t *dot;

static lv_obj_t *time_label;
static lv_obj_t *score_label;

static void bk_target_draw(lv_obj_t *parent, lv_coord_t x_center, lv_coord_t y_center, lv_coord_t radius, int levels)
{
    lv_coord_t r_step = radius / levels;

    for (int i = 0; i < levels; i++)
    {
        lv_obj_t *circle = lv_obj_create(parent);
        lv_obj_set_size(circle, 2 * (radius - i * r_step), 2 * (radius - i * r_step));
        lv_obj_align(circle, LV_ALIGN_CENTER, x_center, y_center);
        lv_obj_set_style_bg_color(circle, lv_color_black(), LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(circle, lv_color_white(), LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(circle, 2, LV_STATE_DEFAULT);
        lv_obj_set_style_radius(circle, LV_RADIUS_CIRCLE, LV_STATE_DEFAULT);
    }
}

static void focus_dot_draw(lv_obj_t *screen, lv_color_t color, int x, int y)
{

    // 创建一个基础对象
    dot = lv_obj_create(screen);
    lv_obj_clear_flag(dot, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(dot, 50, 50); // 设置圆的直径为20像素
    lv_obj_set_style_border_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(dot, LV_ALIGN_CENTER, x, y); // 将圆心对齐到屏幕中心

    // 设置圆的背景颜色和透明度
    lv_obj_set_style_bg_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);   // 绿色背景
    lv_obj_set_style_bg_opa(dot, LV_OPA_90, LV_PART_MAIN | LV_STATE_DEFAULT); // 背景透明度60%

    // 设置圆的边框为圆形
    lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 添加光晕效果
    lv_obj_set_style_shadow_width(dot, 25, LV_PART_MAIN | LV_STATE_DEFAULT);      // 光晕宽度
    lv_obj_set_style_shadow_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);   // 光晕颜色
    lv_obj_set_style_shadow_opa(dot, LV_OPA_60, LV_PART_MAIN | LV_STATE_DEFAULT); // 光晕透明度
    lv_obj_set_style_shadow_spread(dot, 15, LV_PART_MAIN | LV_STATE_DEFAULT);     // 光晕扩散
}

static void time_and_score_draw(lv_obj_t *screen, int time, int score)
{
    char time_str[10];
    char score_str[10];

    time_label = lv_label_create(screen);
    snprintf(time_str, sizeof(time_str), "%02d:%02d", time / 60, time % 60);
    lv_label_set_text(time_label, time_str);
    lv_obj_set_style_text_font(time_label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(time_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(time_label, LV_ALIGN_TOP_LEFT, 10, 10); // 左上角，距离边缘10像素

    // 创建数字标签
    score_label = lv_label_create(screen);
    snprintf(score_str, sizeof(score_str), "%d", score);
    lv_label_set_text(score_label, score_str);
    lv_obj_set_style_text_font(score_label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(score_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(score_label, LV_ALIGN_TOP_RIGHT, -10, 10); // 右上角，距离边缘10像素
}

static void time_and_score_update(int second, int score)
{
    char time_str[10];
    char score_str[10];
    if (NULL != time_label && NULL != score_label)
    {
        snprintf(time_str, sizeof(time_str), "%02d:%02d", second / 60, second % 60);
        lv_label_set_text(time_label, time_str);
        lv_obj_move_foreground(time_label);

        snprintf(score_str, sizeof(score_str), "%d", score);
        lv_label_set_text(score_label, score_str);
        lv_obj_move_foreground(score_label);  
    }
}

static void focus_dot_redraw(lv_color_t color, int x, int y)
{
    if (NULL != dot)
    {
        lv_obj_set_style_border_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_align(dot, LV_ALIGN_CENTER, x, y);

        lv_obj_set_style_bg_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);     // 绿色背景
        lv_obj_set_style_shadow_color(dot, color, LV_PART_MAIN | LV_STATE_DEFAULT); // 光晕颜色
    }
}

void stability_training_gui_init()
{
    lv_obj_t *act_obj = lv_scr_act();
    if (act_obj == scr_training)
        return;
    lv_obj_clean(act_obj);

    if (NULL != scr_training)
        lv_obj_del(scr_training);

    scr_training = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_training, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);

    bk_target_draw(scr_training, 0, 0, 105, 5);
    focus_dot_draw(scr_training, STABILITY_TRAINING_DOT_GREEEN, 0, 0);
    time_and_score_draw(scr_training, 00, 100);
    lv_scr_load(scr_training);
}

void stability_training_gui_release(void)
{
    if (scr_training != NULL)
    {
        lv_obj_clean(scr_training);
        scr_training = NULL;
        dot = NULL;
    }
}

void stability_training_gui_del(void)
{
    stability_training_gui_release();
}

void stability_training_gui_update(lv_color_t color, int dot_x, int dot_y, uint32_t second, int score)
{
    if (scr_training != NULL)
    {
        focus_dot_redraw(color, dot_x, dot_y);
        time_and_score_update(second, score);
    }
}
