
#ifndef input_h
#define input_h	
//=================================================================

	#include "common.h" 
	
	#include <wiiuse/wpad.h>
	#include <wiiuse/wiiuse.h>	
	
//==========================================================
// BUTTON MAP		
	extern bool button_left_held,	button_right_held,	button_down_held,	button_up_held,
	button_shoot_held, button_bomb_held,
	button_menu_held, button_start_held, button_select_held,
	button_1_held, button_2_held, button_accept_held, button_cancel_held, button_a_held, button_b_held, button_r_held, button_l_held,
	button_left_scroll,	button_right_scroll,	button_down_scroll,	button_up_scroll; 
	
	extern bool button_on_wiimote, button_on_classic, button_on_gamecube;
		
	extern bool button_left_up, button_right_up, button_up_up, button_down_up;  
	extern bool button_r_up, button_l_up; 

	extern bool button_shoot_down, button_bomb_down;

	extern bool button_z_held, button_z_up, button_c_held, button_z_down, button_c_down;

	extern bool button_x_held, button_y_held;

	extern bool button_1_down, button_2_down;
	extern bool button_1_up, button_2_up;	//new
	
	extern bool button_a_down, button_b_down;
	extern bool button_a_up, button_b_up;	

	extern bool button_horizontal_wiimote;

	extern float button_motion_roll, button_motion_pitch, button_motion_yaw;
	extern float button_analog_x_left, button_analog_y_left;
	extern float button_analog_x_right, button_analog_y_right;

	extern float button_analog_a_left, button_analog_a_right;

	extern float button_pointer_x, button_pointer_y;
	extern bool button_has_pointer; 
		
	extern bool button_down_down, button_up_down,button_left_down,button_right_down;
	
	extern bool button_accept_up, button_cancel_up;	
	extern bool button_start_up, button_menu_up;
	
	extern bool button_accept_down, button_cancel_down;	
	extern bool button_start_down, button_menu_down;
	
	extern bool button_select_down;	
	extern float button_l_analog, button_r_analog; //2021
	
//==========================================================
	
	void game_updatebuttons(); //old single player style
	
	void input_init();
	
	void input_scan_pads();
	void input_update_wii(int player);
	void input_update_gc(int player);
	void input_reset_all();	

	void input_motion_filtering(bool is_filtered); //2021
//=================================================================

#endif
