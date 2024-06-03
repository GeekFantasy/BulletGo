#include "firing_stability_gui.h"

static lv_obj_t *scr_stability = NULL;
static lv_obj_t *chart = NULL;
static lv_obj_t *num_label = NULL;
static lv_obj_t *score_label = NULL;

static lv_chart_series_t *ser_acc_x = NULL;
static lv_chart_series_t *ser_acc_y = NULL;


void firing_stability_gui_init(int16_t aver_x, int16_t aver_y, int number, int score)
{
    lv_obj_t *act_obj = lv_scr_act();
    if (act_obj == scr_stability)
        return;
    lv_obj_clean(act_obj);

    if (NULL != scr_stability)
        lv_obj_del(scr_stability);

    scr_stability = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_stability, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(scr_stability, LV_OBJ_FLAG_SCROLLABLE);

    char num_str[10];
    num_label = lv_label_create(scr_stability);
    snprintf(num_str, sizeof(num_str), "No. %d", number);
    lv_label_set_text(num_label, num_str);
    lv_obj_set_style_text_font(num_label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(num_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(num_label, LV_ALIGN_TOP_LEFT, 10, 10); // 左上角，距离边缘10像素

    chart = lv_chart_create(scr_stability);
    lv_obj_set_size(chart, 220, 150);
    lv_chart_set_point_count(chart, 50);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_obj_center(chart);

    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, aver_x - 250, aver_x + 250);   // 第一组数据的范围
    lv_chart_set_range(chart, LV_CHART_AXIS_SECONDARY_Y, aver_y - 250, aver_y + 250); // 第二组数据的范围
    ser_acc_x = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    ser_acc_y = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_SECONDARY_Y);

    char score_str[12];
    score_label = lv_label_create(scr_stability);
    snprintf(score_str, sizeof(score_str), "Score: %d", score);
    lv_label_set_text(score_label, score_str);
    lv_obj_set_style_text_font(score_label, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(score_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(score_label, LV_ALIGN_BOTTOM_RIGHT, -10, -10); // 右下角，距离边缘10像素

    lv_scr_load(scr_stability);
}

void firing_stability_gui_release(void)
{
    if (scr_stability != NULL)
    {
        lv_obj_clean(scr_stability);
        scr_stability = NULL;

        chart = NULL;
        ser_acc_x = NULL;
        ser_acc_y = NULL;
    }
}

void firing_stability_gui_del(void)
{
    firing_stability_gui_release();
}

void firing_stability_gui_update(int x, int y)
{
    if (scr_stability != NULL && chart != NULL && ser_acc_x != NULL && ser_acc_y != NULL)
    {
        lv_chart_set_next_value(chart, ser_acc_x, x);
        lv_chart_set_next_value(chart, ser_acc_y, y);
        lv_chart_refresh(chart);
    }
}
