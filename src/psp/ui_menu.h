/******************************************************************************

	ui_menu.c

	PSP ��˥�`

******************************************************************************/

#ifndef PSP_UI_MENU_H
#define PSP_UI_MENU_H

#define UI_TEXTURE		(void *)(0x44000000 + (((SCR_HEIGHT * 3) << 9) << 2))

#if PSP_VIDEO_32BPP
#define VRAM_FMT	GU_PSM_8888
#else
#define VRAM_FMT	GU_PSM_5551
#endif

void showmenu(void);
#if PSP_VIDEO_32BPP
void show_color_menu(void);
#endif


#define MAX_CHEATS 150
#define MAX_CHEAT_OPTION 140
#define MAX_CHEAT_VALUE 10



typedef struct {
	//int cpu; //mem save
	int address;
	int value;
}cheat_value_t;


typedef struct {
	char *label;
	int num_cheat_values;
	cheat_value_t *cheat_value[MAX_CHEAT_VALUE];
}cheat_option_t;

typedef struct {
	//int type; //mem save
	int curr_option;
	char *cheat_name;
	short int num_cheat_options;
	cheat_option_t *cheat_option[MAX_CHEAT_OPTION];
}gamecheat_t;


int add_new_cheat(int type, char *cheat_name, gamecheat_t** new_cheat);
int add_new_cheat_option(char *label, gamecheat_t* cheat,cheat_option_t** new_cheat_option);
int add_new_cheat_value(int cpu, int address, int value, cheat_option_t *cheat_option);
int cheat_clear(void);
int axtoi(char *str_num);
int parse_cheat_option_line(char *line, gamecheat_t* cheat );
int cheats_init(void);
int menu_cheatcfg(void);
void cheats_load(void);
void cheats_load_file(char *fn);

int get_free_memory(void);
int menu_cheatcfg_memfree(void);

#endif /* PSP_UI_MENU_H */
