#include <wiiuse.h>
#include <studio.h>
//stole this from the examplees page from the wiiuse github shoulf rewrite t
void handle_ctrl_status(struct wiimote_t* wm) {
	print("\n\n--- CONTROLLER STATUS [wiimote id %i] ---\n", wm->unid);

	printf("speaker:         %i\n", WIIUSE_USING_SPEAKER(wm));
	printf("ir:              %i\n", WIIUSE_USING_IR(wm));
	printf("leds:            %i %i %i %i\n", WIIUSE_IS_LED_SET(wm, 1), WIIUSE_IS_LED_SET(wm, 2), WIIUSE_IS_LED_SET(wm, 3), WIIUSE_IS_LED_SET(wm, 4));
	printf("battery:         %f %%\n", wm->battery_level);
}
