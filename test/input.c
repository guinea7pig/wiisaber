//did not write this i stole it from the owen guy but we should rewrite it foroursleleves
//headers
	#include "input.h"
	#include "engine.h"

	
//==========================================================
// EXTERNS BUTTON MAP		
	bool button_left_held,	button_right_held,	button_down_held,	button_up_held,
	button_shoot_held, button_bomb_held,
	button_menu_held, button_start_held, button_select_held,
	button_1_held, button_2_held, button_accept_held, button_cancel_held, button_a_held, button_b_held, button_r_held, button_l_held,
	button_left_scroll,	button_right_scroll,	button_down_scroll,	button_up_scroll; 
	
	bool button_on_wiimote, button_on_classic, button_on_gamecube;
		
	bool button_left_up, button_right_up, button_up_up, button_down_up;  
	bool button_r_up, button_l_up; 

	bool button_shoot_down, button_bomb_down;

	bool button_z_held, button_z_up, button_c_held, button_z_down, button_c_down;

	bool button_x_held, button_y_held;

	bool button_1_down, button_2_down;
	bool button_1_up, button_2_up;	//new
	
	bool button_a_down, button_b_down;
	bool button_a_up, button_b_up;	

	bool button_horizontal_wiimote;

	float button_motion_roll, button_motion_pitch, button_motion_yaw;
	float button_analog_x_left, button_analog_y_left;
	float button_analog_x_right, button_analog_y_right;

	float button_analog_a_left, button_analog_a_right;

	float button_pointer_x, button_pointer_y;
	bool button_has_pointer; 
	
	bool button_down_down, button_up_down,button_left_down,button_right_down;
	
	bool button_accept_up, button_cancel_up;	
	bool button_start_up, button_menu_up;
	
	bool button_accept_down, button_cancel_down;	
	bool button_start_down, button_menu_down;
	
	bool button_select_down;
	
	float button_l_analog, button_r_analog; //2021
	
//================================================================
	
	#define INPUT_MAX_CTRLS 4
	
	static WPADData *wd[INPUT_MAX_CTRLS];  //ir
	//static u32 wpadprobe[INPUT_MAX_CTRLS];
	//static u32 wpaddown[INPUT_MAX_CTRLS];
	//static u32 wpadheld[INPUT_MAX_CTRLS];
	//static u32 wpadup[INPUT_MAX_CTRLS];
	//static ir_t ir[INPUT_MAX_CTRLS];
	//static vec3w_t accel[INPUT_MAX_CTRLS];
	//static u32 probeType;
	//static orient_t orient;
	struct expansion_t data; //nunchuk

//=================================================================

	static float analog_margin=0.071f;  //0.055f //tolerance of the sticks

	u32  WPAD_Down ,  WPAD_Held, WPAD_Up;
	float la, ra;
	static float r,p,y,diff,ts=0.015f;
	static bool tu, tr, td, tl;
	static bool is_filtered_motion=true;

//=================================================================

void input_init(){
	PAD_Init();
	WPAD_Init();
	WPAD_SetDataFormat(WPAD_CHAN_ALL, WPAD_FMT_BTNS_ACC_IR);  //ir
	WPAD_SetVRes(WPAD_CHAN_ALL, engine_screen_width(), engine_screen_height() );  //ir

	SYS_SetResetCallback(reset_call); // esto es para que puedas salir al pulsar boton de RESET
	SYS_SetPowerCallback(reset_call);
	WPAD_SetPowerButtonCallback(reset_call);
}

//=================================================================

void input_reset_all(){
	//reset all button states to default
	button_left_held=false;	button_right_held=false;	button_down_held=false;	button_up_held=false;
	button_shoot_held=false; button_bomb_held=false;
	button_menu_held=false;	button_start_held=false; button_select_held=false;
	button_a_held=false; button_b_held=false; button_r_held=false; button_l_held=false;
	button_1_held=false; button_2_held=false; button_accept_held=false; button_cancel_held=false;
	button_left_scroll=false; button_right_scroll=false; button_down_scroll=false; button_up_scroll=false;
	button_on_wiimote=false;
	button_on_classic=false;	
	button_on_gamecube=false;	

	button_left_up=false; button_right_up=false; button_up_up=false; button_down_up=false;  //new
	button_r_up=false; button_l_up=false; //new2
	
	button_shoot_down=false; button_bomb_down=false;

	button_1_down=false; button_2_down=false; 
	button_1_up=false; button_2_up=false;	//new
	 
	button_a_down=false; button_b_down=false;
	button_a_up=false; button_b_up=false;

	button_z_held=false; button_c_held=false; button_z_down=false; button_c_down=false;

	button_analog_x_left=0.0f; button_analog_y_left=0.0f;
	button_analog_x_right=0.0f; button_analog_y_right=0.0f;

	button_analog_a_left=0.0f;	button_analog_a_right=0.0f;
	button_motion_roll = 0;	button_motion_pitch = 0; button_motion_yaw=0;
	button_has_pointer=false;

	button_x_held=false; button_y_held=false;
	button_z_up=false;
	
	button_down_down=false; button_up_down=false; button_left_down=false; button_right_down=false; //2021
	
	button_accept_up=false; button_cancel_up=false;
	button_start_up=false;	button_menu_up=false;	
	
	button_accept_down=false; button_cancel_down=false;
	button_start_down=false; button_menu_down=false;
	
	button_select_down=false;
	
    button_l_analog = 0; //2021
    button_r_analog = 0; //2021

}

//=================================================================

static float zero_if_between2(float numf, float low, float high) {
	if ( (numf < high) & (numf > low) ) return 0.0f;
	return numf;
}


static void input_horizontal_wiimote(){ //reorient directions for horizontal wiimote use
	//only necessary for the wiimote because the other controllers cannot be turned sideways
	tl=button_left_held; tu=button_up_held;	tr=button_right_held; td=button_down_held;
	button_down_held=tl;	button_left_held=tu;	button_up_held=tr;			button_right_held=td;
	
	//bool tuu, tru, tdu, tlu;
	tl=button_left_up; tu=button_up_up; tr=button_right_up; td=button_down_up;
	button_down_up=tl;	button_left_up=tu;	button_up_up=tr; button_right_up=td;
				
	//bool tuu, tru, tdu, tlu;
	tl=button_left_down; tu=button_up_down; tr=button_right_down; td=button_down_down;			
	button_down_down=tl;	button_left_down=tu;	button_up_down=tr; button_right_down=td;

}

static void input_stick_to_button_translation(){  //2021
	//analog stick to button translation (remove this is you use your dpad for other things)
	if (button_analog_y_left > analog_margin ) button_up_held=true; //left stick
	if (button_analog_y_left < -analog_margin ) button_down_held=true;
	if (button_analog_x_left > analog_margin ) button_right_held=true;
	if (button_analog_x_left < -analog_margin ) button_left_held=true;

	if (button_analog_y_right > analog_margin ) button_up_scroll=true;//right stick
	if (button_analog_y_right < -analog_margin ) button_down_scroll=true;
	if (button_analog_x_right > analog_margin ) button_right_scroll=true;
	if (button_analog_x_right < -analog_margin ) button_left_scroll=true;
}

//=================================================================

void game_updatebuttons() { // SINGLE PLAYER ONLY! Read the Wiimote and store the results in the designated variables //based on liquidwars source
	input_reset_all();  //reset all variables to false
	input_scan_pads();  //scan for pads
	input_update_wii(0);  //wii check
	input_update_gc(0); //gamecube check
	
	//analog stick to button translation (remove this is you use your buttons for other things)
	input_stick_to_button_translation();
	
	if(button_on_wiimote & button_horizontal_wiimote & !button_on_classic) input_horizontal_wiimote();  //reorient directions for horizontal wiimote use
}

void input_scan_pads(){  //only need to scan pads once per render, since it contains data for all controllers
	WPAD_ScanPads();
	PAD_ScanPads();
}

//=========================================================================

void input_motion_filtering(bool is_filtered){
	is_filtered_motion=is_filtered;
}

static void input_update_nunchuck(){	//nunchuck	

	if (data.type != WPAD_EXP_NUNCHUK) return;
	
	if( WPAD_Held & WPAD_NUNCHUK_BUTTON_Z) { button_z_held=true; button_shoot_held=true; }
	if( WPAD_Held & WPAD_NUNCHUK_BUTTON_C) { button_c_held=true; button_bomb_held=true; }

	if( WPAD_Down & WPAD_NUNCHUK_BUTTON_Z) { button_z_down=true; }
	if( WPAD_Down & WPAD_NUNCHUK_BUTTON_C) { button_c_down=true; }
		
	if (data.type == WPAD_EXP_NUNCHUK) {
		if( (button_analog_x_left==0) && (button_analog_y_left==0) ) { //only check of not changed
			button_analog_x_left=(data.nunchuk.js.pos.x - data.nunchuk.js.center.x )/100.0f;
			button_analog_y_left=(data.nunchuk.js.pos.y - data.nunchuk.js.center.y )/100.0f;

			button_analog_x_left=zero_if_between2( button_analog_x_left, -analog_margin, analog_margin );
			button_analog_y_left=zero_if_between2( button_analog_y_left, -analog_margin, analog_margin );

			button_analog_a_left=data.nunchuk.js.ang;
		}
	}		
}

static void input_update_classic(){ //2021  //dependant on update wiimote data

	if(data.type != WPAD_EXP_CLASSIC) return;

	//classic controller - based on masteroids source
	if(data.type == WPAD_EXP_CLASSIC) {			
		la = data.classic.l_shoulder; //2021
		ra = data.classic.r_shoulder; //2021
		if( la > 0 ) button_l_analog = la;
		if( ra > 0 ) button_r_analog = ra;		

		if( (button_analog_x_left==0) && (button_analog_y_left==0) ) { //only check of not changed
			button_analog_x_left=( (data.classic.ljs.pos.x - data.classic.ljs.center.x)/ (float)data.classic.ljs.max.x )*2.0f ;
			button_analog_y_left=( (data.classic.ljs.pos.y - data.classic.ljs.center.y)/ (float)data.classic.ljs.max.y )*2.0f ;

			if( isnan(button_analog_x_left) ) button_analog_x_left=0;//init bug in extension
			if( isnan(button_analog_y_left) ) button_analog_y_left=0;

			button_analog_x_left=zero_if_between2( button_analog_x_left, -analog_margin, analog_margin );
			button_analog_y_left=zero_if_between2( button_analog_y_left, -analog_margin, analog_margin );

			button_analog_a_left=data.classic.ljs.ang;
			if( (button_analog_x_left!=0) | (button_analog_y_left!=0) ) button_on_classic=true; 
		}

		if( (button_analog_x_right==0) && (button_analog_y_right==0) ) { //only check of not changed
			button_analog_x_right=( (data.classic.rjs.pos.x - data.classic.rjs.center.x)/ (float)data.classic.rjs.max.x )*2.0f ;
			button_analog_y_right=( (data.classic.rjs.pos.y - data.classic.rjs.center.y)/ (float)data.classic.rjs.max.y )*2.0f ;

			if( isnan(button_analog_x_right) ) button_analog_x_right=0;//init bug in extension
			if( isnan(button_analog_y_right) ) button_analog_y_right=0;

			button_analog_x_right=zero_if_between2( button_analog_x_right, -analog_margin, analog_margin );
			button_analog_y_right=zero_if_between2( button_analog_y_right, -analog_margin, analog_margin );

			button_analog_a_right=data.classic.ljs.ang;
			if( (button_analog_x_right!=0) | (button_analog_y_right!=0) ) button_on_classic=true; 
		}

	
	}
		
	bool boc=false;
	
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_HOME) { boc=true; button_menu_held=true; }
	if( WPAD_Up &WPAD_CLASSIC_BUTTON_HOME) { boc=true; button_menu_up=true; }
	if( WPAD_Down &WPAD_CLASSIC_BUTTON_HOME) { boc=true; button_menu_down=true; }

	if( WPAD_Held &WPAD_CLASSIC_BUTTON_A) { boc=true; button_shoot_held=true; button_accept_held=true; button_a_held=true; }
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_B) { boc=true; button_bomb_held=true;	button_cancel_held=true; button_b_held=true; }

	if( WPAD_Down &WPAD_CLASSIC_BUTTON_A) { boc=true; button_shoot_down=true; button_a_down=true; button_accept_down=true; }
	if( WPAD_Down &WPAD_CLASSIC_BUTTON_B) { boc=true; button_bomb_down=true;	button_b_down=true; button_cancel_down=true; }

	if( WPAD_Up &WPAD_CLASSIC_BUTTON_A) { boc=true; button_a_up=true; button_accept_up=true; }
	if( WPAD_Up &WPAD_CLASSIC_BUTTON_B) { boc=true; button_b_up=true; button_cancel_up=true; }

	if( WPAD_Held & WPAD_CLASSIC_BUTTON_FULL_R) { boc=true; button_shoot_held=true; button_r_held=true; }
	if( WPAD_Held & WPAD_CLASSIC_BUTTON_FULL_L) { boc=true; button_bomb_held=true; button_l_held=true; }

	if( WPAD_Up &WPAD_CLASSIC_BUTTON_FULL_R) { boc=true; button_r_up=true; }
	if( WPAD_Up &WPAD_CLASSIC_BUTTON_FULL_L) { boc=true; button_l_up=true; }


	if( WPAD_Held &WPAD_CLASSIC_BUTTON_X) { boc=true; button_x_held=true; button_bomb_held=true;	button_cancel_held=true; }
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_Y) { boc=true; button_y_held=true; button_shoot_held=true; }
	if( WPAD_Up &WPAD_CLASSIC_BUTTON_X) { boc=true; button_x_held=true; button_bomb_held=true;	button_cancel_up=true; }

	if( WPAD_Down &WPAD_CLASSIC_BUTTON_X) { boc=true;  button_cancel_down=true; }

	if( WPAD_Held &WPAD_CLASSIC_BUTTON_LEFT){ boc=true; button_left_held=true; }
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_RIGHT){ boc=true; button_right_held=true; }

	if( ( WPAD_Up & WPAD_CLASSIC_BUTTON_LEFT)  ) { boc=true; button_left_up=true; }  //new
	if( ( WPAD_Up & WPAD_CLASSIC_BUTTON_RIGHT) ) { boc=true; button_right_up=true; }  //new
	if( ( WPAD_Up & WPAD_CLASSIC_BUTTON_UP)  ) { boc=true; button_up_up=true; }  //new
	if( ( WPAD_Up & WPAD_CLASSIC_BUTTON_DOWN) ) { boc=true; button_down_up=true; }  //new

	if( WPAD_Held &WPAD_CLASSIC_BUTTON_DOWN){ boc=true; button_down_held=true; }
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_UP){ boc=true; button_up_held=true; }

	if( WPAD_Up &WPAD_CLASSIC_BUTTON_PLUS) { boc=true; button_accept_up=true; button_start_up=true; }
	if( WPAD_Held &WPAD_CLASSIC_BUTTON_PLUS) { boc=true; button_start_held=true; button_accept_held=true; }
	if( WPAD_Down &WPAD_CLASSIC_BUTTON_PLUS) { boc=true; button_start_down=true; button_accept_down=true; button_start_down=true; }

	if( WPAD_Held &WPAD_CLASSIC_BUTTON_MINUS) { boc=true; button_select_held=true; }
	if( WPAD_Down &WPAD_CLASSIC_BUTTON_MINUS) { boc=true; button_select_down=true; }
	
	button_on_classic=boc;
}

void input_update_wii(int player){  //update variable with wii pad data
	u32 type;
    int res = WPAD_Probe(player, &type);
	
	//check buttons
	if(res != WPAD_ERR_NONE) return; //do nothing
		
	WPAD_Down  =  WPAD_ButtonsDown(player);
	WPAD_Held  =  WPAD_ButtonsHeld(player);
	WPAD_Up =  WPAD_ButtonsUp(player);
	
	if(res == WPAD_ERR_NONE) {
		wd[player]= WPAD_Data(player); //ir
		WPAD_Expansion( player, &data ); //nunchuk

		/*
		WPAD_IR(player, &ir[player]);
		WPAD_Accel(player, &accel[player]);
	    //WPAD_Orientation(player, &orient);
		*/

		//check waggle, Yaw, pitch, and roll range from -180 to 180 degrees.
		r = (wd[player]->orient.roll);
		p = (wd[player]->orient.pitch/180.0f);
		y = (wd[player]->orient.yaw/180.0f);
		
		button_motion_roll =r;
		
		if(is_filtered_motion){		
			diff=(button_motion_pitch - p);		
			if( (diff < -ts) | (diff > ts) ) 
			button_motion_pitch += (button_motion_pitch < p) ? ts : -ts;
			//button_motion_pitch =p;
			
			diff=(button_motion_yaw - y);
			if( (diff < -ts) | (diff > ts) ) 
			button_motion_yaw += (button_motion_yaw < y) ? ts : -ts;		
		} 
		if(!is_filtered_motion){
			button_motion_pitch = p;
			button_motion_yaw = y;
		}
				
		//check ir pointer
		if (wd[player]->ir.valid) {
			button_pointer_x=wd[player]->ir.x;
			button_pointer_y=wd[player]->ir.y;  //read pointer
			button_has_pointer=true;
		} 
			
		//classic controller - based on masteroids source
		input_update_classic();
		
		input_update_nunchuck();
	} 
		 
	if( WPAD_Held | WPAD_Up | WPAD_Down )  button_on_wiimote=true; 
	
	if(!button_on_wiimote) return; //short circuit
	
	//check wiimote
	if( WPAD_Held  & WPAD_BUTTON_HOME) { button_menu_held=true;  }
	if( WPAD_Up & WPAD_BUTTON_HOME) { button_menu_up=true;  }
	if( WPAD_Down & WPAD_BUTTON_HOME) { button_menu_down=true;  }

	if( WPAD_Held  & WPAD_BUTTON_1) { button_1_held=true; button_bomb_held=true; }
	if( WPAD_Held  & WPAD_BUTTON_2) { button_2_held=true; button_shoot_held=true; }

	if( WPAD_Down  & WPAD_BUTTON_1 ){ button_1_down=true; button_bomb_down=true; button_cancel_down=true; }
	if( WPAD_Down  & WPAD_BUTTON_2 ){ button_2_down=true; button_shoot_down=true; button_accept_down=true; }

	if( WPAD_Up  & WPAD_BUTTON_1 ){ button_cancel_up=true; button_1_up=true; }
	if( WPAD_Up  & WPAD_BUTTON_2 ){ button_accept_up=true; button_2_up=true;  }

	if( WPAD_Held  & WPAD_BUTTON_LEFT ) {  button_left_held=true; }
	if( WPAD_Held  & WPAD_BUTTON_RIGHT) {  button_right_held=true; }
	if( WPAD_Held  & WPAD_BUTTON_DOWN ) {  button_down_held=true; }
	if( WPAD_Held  & WPAD_BUTTON_UP  ) {  button_up_held=true; }

	if( ( WPAD_Up & WPAD_BUTTON_LEFT)  ) {  button_left_up=true; }  //new
	if( ( WPAD_Up & WPAD_BUTTON_RIGHT) ) {  button_right_up=true; }  //new
	if( ( WPAD_Up & WPAD_BUTTON_UP)  ) {  button_up_up=true; }  //new
	if( ( WPAD_Up & WPAD_BUTTON_DOWN) ) {  button_down_up=true; }  //new

	if( ( WPAD_Down & WPAD_BUTTON_LEFT)  ) {  button_left_down=true; }  //new
	if( ( WPAD_Down & WPAD_BUTTON_RIGHT) ) {  button_right_down=true; }  //new
	if( ( WPAD_Down & WPAD_BUTTON_UP)  ) {  button_up_down=true; }  //new
	if( ( WPAD_Down & WPAD_BUTTON_DOWN) ) {  button_down_down=true; }  //new

	if( ( WPAD_Held & WPAD_BUTTON_B) ) { button_shoot_held=true; button_cancel_held=true; button_b_held=true; }
	if( ( WPAD_Up & WPAD_BUTTON_B) ) { button_b_up=true; button_cancel_up=true; }
	if( ( WPAD_Down & WPAD_BUTTON_B) ) { button_b_down=true; button_cancel_down=true; }

	if( ( WPAD_Down & WPAD_BUTTON_A) ) {  button_bomb_down=true; button_a_down=true; button_accept_down=true;  } //fix this
	if( ( WPAD_Up & WPAD_BUTTON_A) ) {  button_a_up=true; button_accept_up=true; } //fix this
	if( ( WPAD_Held & WPAD_BUTTON_A) ) {  button_bomb_held=true; button_accept_held=true; button_a_held=true; }

	if( ( WPAD_Held & WPAD_BUTTON_MINUS) ) button_select_held=true;
	if( ( WPAD_Down & WPAD_BUTTON_MINUS) ) button_select_down=true;
	
	if( ( WPAD_Down & WPAD_BUTTON_PLUS) ){ button_start_down=true; button_accept_down=true;  }
	if( ( WPAD_Up & WPAD_BUTTON_PLUS) ){ button_start_up=true; button_accept_up=true; }

	/*
			WPAD_CLASSIC_BUTTON_ZR
	WPAD_CLASSIC_BUTTON_ZL
	PAD_TRIGGER_L
	PAD_TRIGGER_Z

	*/


	//analog stick to button translation (remove this is you use your dpad for other things)
	//input_stick_to_button_translation();
	/*
	if(  button_on_wiimote & button_horizontal_wiimote) {  //reorient directions for horizontal wiimote use
		//only necessary for the wiimote because the other controllers cannot be turned sideways
		tl=button_left_held; tu=button_up_held;	tr=button_right_held; td=button_down_held;
		button_down_held=tl;	button_left_held=tu;	button_up_held=tr;			button_right_held=td;
		
		//bool tuu, tru, tdu, tlu;
		tl=button_left_up; tu=button_up_up; tr=button_right_up; td=button_down_up;
		button_down_up=tl;	button_left_up=tu;	button_up_up=tr; button_right_up=td;
					
		//bool tuu, tru, tdu, tlu;
		tl=button_left_down; tu=button_up_down; tr=button_right_down; td=button_down_down;			
		button_down_down=tl;	button_left_down=tu;	button_up_down=tr; button_right_down=td;
	}
	*/
}

//=========================================================================


void input_update_gc(int player){

	la = PAD_TriggerL(player);
	ra = PAD_TriggerR(player); 

    if(la > 5) button_l_analog = (la / 200.0f); //2021
    if(ra > 5) button_r_analog = (ra / 200.0f); //2021
	  		
	//check both sticks
	if( (button_analog_x_left==0) && (button_analog_y_left==0) ) { //only check of not changed by another controller
		button_analog_x_left=PAD_StickX(player)/105.0f;
		button_analog_y_left=PAD_StickY(player)/105.0f;

		button_analog_x_left=zero_if_between2( button_analog_x_left, -analog_margin, analog_margin );
		button_analog_y_left=zero_if_between2( button_analog_y_left, -analog_margin, analog_margin );
		
		if( (button_analog_x_left!=0) | (button_analog_y_left!=0) ) button_on_gamecube=true;
	}

	if( (button_analog_x_right==0) && (button_analog_y_right==0) ) { //only check of not changed
		button_analog_x_right=PAD_SubStickX(player)/90.0f;
		button_analog_y_right=PAD_SubStickY(player)/90.0f;

		button_analog_x_right=zero_if_between2( button_analog_x_right, -analog_margin, analog_margin );
		button_analog_y_right=zero_if_between2( button_analog_y_right, -analog_margin, analog_margin );
	
		if( (button_analog_x_right!=0) | (button_analog_y_right!=0) ) button_on_gamecube=true;
	}
		
	//was something pressed/held/up?
	
	u32 PAD_Down, PAD_Held, PAD_Up;
	
	PAD_Held = PAD_ButtonsHeld(player);
	PAD_Down = PAD_ButtonsDown(player);
	PAD_Up = PAD_ButtonsUp(player);
	
	if(PAD_Held | PAD_Up | PAD_Down ) button_on_gamecube=true; 
	
	if(!button_on_gamecube) return; //short circuit, nothing but buttons below
	
	//game cube controller - based on masteroids source
	if( PAD_Held & PAD_BUTTON_A) { button_shoot_held=true; button_accept_held=true; button_a_held=true;   }
	if( PAD_Held & PAD_BUTTON_B) { button_bomb_held=true; button_cancel_held=true; button_b_held=true;   }

	if( PAD_Down & PAD_BUTTON_A) { button_accept_down=true; button_shoot_down=true; button_a_down=true;   }
	if( PAD_Down & PAD_BUTTON_B) { button_bomb_down=true; button_b_down=true;  button_cancel_down=true;  }

	if( PAD_Up & PAD_BUTTON_A) { button_a_up=true;   button_accept_up=true; }
	if( PAD_Up & PAD_BUTTON_B) { button_b_up=true;   button_cancel_up=true; }
	
	if( PAD_Held & PAD_TRIGGER_R) { button_shoot_held=true; button_r_held=true; }
	if( PAD_Held & PAD_TRIGGER_L) { button_bomb_held=true; button_l_held=true; }

	if( PAD_Up & PAD_TRIGGER_R) { button_r_up=true; } //new2
	if( PAD_Up & PAD_TRIGGER_L) { button_l_up=true; } //new2

	if( PAD_Held & PAD_BUTTON_X) { button_x_held=true; button_bomb_held=true;	button_cancel_held=true; }
	if( PAD_Held & PAD_BUTTON_Y) { button_y_held=true; button_shoot_held=true; button_accept_held=true; }
	if( PAD_Up & PAD_BUTTON_Y) { button_y_held=true; button_shoot_held=true; button_accept_up=true; }
	if( PAD_Up & PAD_BUTTON_X) { button_cancel_up=true; }
	if( PAD_Down & PAD_BUTTON_X) {  button_cancel_down=true; }
	
	if( PAD_Held & PAD_BUTTON_LEFT){  button_left_held=true;   }
	if( PAD_Held & PAD_BUTTON_RIGHT){ button_right_held=true;   }
	if( PAD_Held & PAD_BUTTON_DOWN){ button_down_held=true;   }
	if( PAD_Held & PAD_BUTTON_UP){ button_up_held=true;   }

	if( PAD_Down & PAD_BUTTON_LEFT){  button_left_down=true;   }
	if( PAD_Down & PAD_BUTTON_RIGHT){ button_right_down=true;   }
	if( PAD_Down & PAD_BUTTON_DOWN){ button_down_down=true;   }
	if( PAD_Down & PAD_BUTTON_UP){ button_up_down=true;   }	
	
	if( PAD_Held & PAD_TRIGGER_Z){ button_z_held=true;  }
	
	if( PAD_Held & PAD_BUTTON_START) { button_start_held=true;  }
	if( PAD_Up & PAD_BUTTON_START) {   button_accept_up=true; button_start_up=true; }
	if( PAD_Down & PAD_BUTTON_START) {   button_accept_down=true; button_start_down=true; }
	
	if( PAD_Up & PAD_BUTTON_MENU) { button_menu_up=true;  button_accept_up=true; }

	if( PAD_Up & PAD_BUTTON_LEFT){ button_left_up=true;  }
	if( PAD_Up & PAD_BUTTON_RIGHT){ button_right_up=true;   }
	if( PAD_Up & PAD_BUTTON_UP){ button_up_up=true;  }
	if( PAD_Up & PAD_BUTTON_DOWN){ button_down_up=true;  }	
	if( PAD_Up & PAD_TRIGGER_Z){ button_z_up=true;  }

	//PAD_TRIGGER_Z PAD_TRIGGER_R PAD_TRIGGER_L PAD_BUTTON_A PAD_BUTTON_B PAD_BUTTON_MENU PAD_BUTTON_START

	//analog stick to button translation (remove this is you use your buttons for other things)
	//input_stick_to_button_translation();	
	
}

//=========================================================================

int numberOfAttachedControllers() {  //https://www.wiibrew.org/wiki/User:Megazig
	// used to check how many controllers are attached
	int i, numAttached = 0;
	u32 type;  //find the type of the expansion

	for(i=0; i<WPAD_MAX_WIIMOTES; i++) {
		if (WPAD_Probe(i, &type) == WPAD_ERR_NONE) {
			numAttached++;
		}
	}
	return numAttached;
}

//=========================================================================

