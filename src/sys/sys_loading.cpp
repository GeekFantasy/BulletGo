#include "sys_loading.h"

// 定义动画时长（单位：毫秒）
#define PROGRESS_ANIM_DURATION 2600
#define TEXT_ANIM_DURATION 600
#define SCREEN_FADE_IN_DURATION 800

lv_obj_t *progress_bar;
lv_obj_t *label;
lv_obj_t * label_shadow;
lv_obj_t *progress_label;
sys_loading_ready_cb_t loading_ready_cb = NULL;

// 进度条动画回调函数
void progress_anim_cb(void *var, int32_t v)
{
    lv_bar_set_value((lv_obj_t *)var, v, LV_ANIM_ON);

    // 动态改变进度条颜色
    lv_color_t start_color = lv_color_hex(0x0000FF);                       
    lv_color_t end_color = lv_color_hex(0xFF0000);                          
    lv_color_t color = lv_color_mix(start_color, end_color, v * 255 / 100); // v 为进度值 0-100
    lv_obj_set_style_bg_color(progress_bar, color, LV_PART_INDICATOR);

    // 更新百分比标签
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", v);
    lv_label_set_text(progress_label, buf);
    lv_obj_align_to(progress_label, progress_bar, LV_ALIGN_OUT_TOP_MID, 0, -5);
}

// 文字渐显动画回调函数
void text_anim_cb(void *var, int32_t opa)
{
    lv_obj_t *label = (lv_obj_t *)var;
    lv_obj_set_style_opa(label, opa, 0);
}

// 屏幕渐亮动画回调函数
void screen_fade_in_cb(void *var, int32_t v)
{
    lv_color_t color = lv_color_make(v, v, v);
    lv_obj_set_style_bg_color(lv_scr_act(), color, 0);
}

// 文字渐显完成回调函数
void screen_text_show_complete_cb(lv_anim_t *a)
{
    if (NULL != loading_ready_cb)
        loading_ready_cb();
    lv_obj_clear_flag(label_shadow, LV_OBJ_FLAG_HIDDEN);
}

// 屏幕渐亮完成回调函数
void screen_fade_in_complete_cb(lv_anim_t *a)
{
    // 创建渐显的文字动画
    lv_anim_t text_anim;
    lv_anim_init(&text_anim);
    lv_anim_set_var(&text_anim, label);
    lv_anim_set_exec_cb(&text_anim, text_anim_cb);
    lv_anim_set_time(&text_anim, TEXT_ANIM_DURATION);
    lv_anim_set_values(&text_anim, LV_OPA_TRANSP, LV_OPA_COVER);
    lv_anim_set_ready_cb(&text_anim, screen_text_show_complete_cb);
    lv_anim_start(&text_anim);
}

// 进度条加载完成回调函数
void progress_anim_complete_cb(lv_anim_t *a)
{
    lv_obj_add_flag(progress_bar, LV_OBJ_FLAG_HIDDEN);   // 隐藏进度条
    lv_obj_add_flag(progress_label, LV_OBJ_FLAG_HIDDEN); // 隐藏百分比标签

    // 创建屏幕渐亮动画
    lv_anim_t screen_anim;
    lv_anim_init(&screen_anim);
    lv_anim_set_var(&screen_anim, lv_scr_act());
    lv_anim_set_exec_cb(&screen_anim, screen_fade_in_cb);
    lv_anim_set_time(&screen_anim, SCREEN_FADE_IN_DURATION);
    lv_anim_set_values(&screen_anim, 0, 255);
    lv_anim_set_ready_cb(&screen_anim, screen_fade_in_complete_cb);
    lv_anim_start(&screen_anim);
}

void start_loading_animation(sys_loading_ready_cb_t ready_cb)
{
    loading_ready_cb = ready_cb;

    // 获取当前屏幕
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_black(), 0);
    lv_obj_set_style_opa(scr, LV_OPA_COVER, 0);

    // 创建进度条
    progress_bar = lv_bar_create(scr);
    lv_obj_set_size(progress_bar, 200, 20);
    lv_obj_align(progress_bar, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_range(progress_bar, 0, 100);
    lv_bar_set_value(progress_bar, 0, LV_ANIM_OFF);
    lv_obj_set_style_border_width(progress_bar, 0, 0);
    lv_obj_set_style_radius(progress_bar, 10, 0);
    lv_obj_set_style_bg_color(progress_bar, lv_color_black(), 0);

    // 创建百分比标签
    progress_label = lv_label_create(scr);
    lv_label_set_text(progress_label, "0%");
    lv_obj_set_style_text_font(progress_label, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(progress_label, lv_color_white(), 0);
    lv_obj_align_to(progress_label, progress_bar, LV_ALIGN_OUT_TOP_MID, 0, -15);

    // 创建进度条动画
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, progress_bar);
    lv_anim_set_exec_cb(&a, progress_anim_cb);
    lv_anim_set_time(&a, PROGRESS_ANIM_DURATION);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_ready_cb(&a, progress_anim_complete_cb); 
    lv_anim_start(&a);

    // 创建阴影层
    label_shadow = lv_label_create(scr);
    lv_label_set_text(label_shadow, "Cyber Gun");
    lv_obj_set_style_text_color(label_shadow, lv_color_hex(0x0000FF), 0); // 光晕颜色
    lv_obj_set_style_text_opa(label_shadow, LV_OPA_30, 0); // 光晕不透明度
    lv_obj_set_style_text_font(label_shadow, &lv_font_montserrat_30, 0);
    lv_obj_align(label_shadow, LV_ALIGN_CENTER, 3, 3); // 稍微偏移以创建光晕效果
    lv_obj_add_flag(label_shadow, LV_OBJ_FLAG_HIDDEN);   

    // 创建渐显的文字
    label = lv_label_create(scr);
    lv_label_set_text(label, "Cyber Gun");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, 0);
    lv_obj_center(label);
    lv_obj_set_style_opa(label, LV_OPA_TRANSP, 0);
    lv_obj_set_style_text_color(label, lv_color_hex(0x0000FF), 0); 
}