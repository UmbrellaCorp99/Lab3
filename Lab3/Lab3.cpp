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
	int xpos = width / 2, ypos = height / 2;

	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT* font24 = al_load_font("Resident Evil Large.ttf", 24, 0);
	eventQueue = al_create_event_queue();

	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_clear_to_color(al_map_rgb(255, 255, 255));

	if (!al_install_mouse()) {
		al_show_native_message_box(NULL, "Error", "Mouse was not initialized", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_register_event_source(eventQueue, al_get_mouse_event_source());

	while (!done) {
		al_flip_display();

		ALLEGRO_EVENT Event;
		al_wait_for_event(eventQueue, &Event);
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		else if (Event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (Event.mouse.button & 1) {
				
			}
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
	al_destroy_font(font24);
}
