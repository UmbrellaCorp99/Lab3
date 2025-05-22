#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
	ALLEGRO_DISPLAY* display;

	if (!al_init()) {
		al_show_native_message_box(NULL, "Error", "Allegro failed to initialize", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	int width = 840, height = 600;
	display = al_create_display(width, height);
	
	if (display == NULL) {
		al_show_native_message_box(NULL, "Error", "Display to create the display", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	bool done = false;

	while (!done) {

	}

	al_destroy_display(display);

}
