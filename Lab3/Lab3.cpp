//Alexander Young
//Lab 3

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
	//creates a display variable in memory
	ALLEGRO_DISPLAY* display;

	//error handling for initializing Allegro
	if (!al_init()) {
		al_show_native_message_box(NULL, "Error", "Allegro failed to initialize", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//setting parameters for the display and creating it
	int width = 840, height = 600;
	display = al_create_display(width, height);
	
	//error handling for creating display
	if (display == NULL) {
		al_show_native_message_box(NULL, "Error", "Display to create the display", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//Variables for keeping track of position and for game loop if/else statements
	bool done = false, color = false;
	int xpos = width / 2, ypos = height / 2;

	//creating eventQueue in memory
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;

	//initializing font and ttf addons
	al_init_font_addon();
	al_init_ttf_addon();

	//creating a font24 font in memory
	ALLEGRO_FONT* font24 = al_load_font("Movistar Text Regular.ttf", 24, 0);
	eventQueue = al_create_event_queue();

	//tying the display into the eventQueue
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();

	//error handling for installing mouse
	if (!al_install_mouse()) {
		al_show_native_message_box(NULL, "Error", "Mouse was not initialized", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	//tying the mouse into the event queue
	al_register_event_source(eventQueue, al_get_mouse_event_source());

	//game loop
	while (!done) {
	
		//creating an Allegro event
		ALLEGRO_EVENT Event;
		al_wait_for_event(eventQueue, &Event);

		//closes the diaplay if the X botton of the window is clicked on
		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		//records the x and y positions when the mouse button 1 is clicked and allows the next else if to run
		else if (Event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (Event.mouse.button & 1) {
				color = true;
				xpos = Event.mouse.x;
				ypos = Event.mouse.y;
			}
		}
		//determines based on the x and y position of the click what the screen and text color will be, prints the text to the screen
		if (color) {
			if (xpos >= 0 && xpos <= (width/2) && ypos >= 0 && ypos <= height/2) {
				al_clear_to_color(al_map_rgb(255, 255, 255));
				al_draw_textf(font24, al_map_rgb(0,0,0), xpos, ypos, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", xpos, ypos);
				al_flip_display();
			}
			else if (xpos >= (width / 2) && xpos <= width && ypos >= 0 && ypos <= height/2) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_textf(font24, al_map_rgb(255, 255, 255), xpos, ypos, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", xpos, ypos);
				al_flip_display();
			}
			else if (xpos >= 0 && xpos <= (width / 2) && ypos >= (height / 2) && ypos <= height) {
				al_clear_to_color(al_map_rgb(0, 0, 255));
				al_draw_textf(font24, al_map_rgb(255, 255, 0), xpos, ypos, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", xpos, ypos);
				al_flip_display();
			}
			else if (xpos >= (width / 2) && xpos <= width && ypos >= (height / 2) && ypos <= height) {
				al_clear_to_color(al_map_rgb(255, 255, 0));
				al_draw_textf(font24, al_map_rgb(0, 0, 255), xpos, ypos, ALLEGRO_ALIGN_LEFT, "The mouse is located at = %i / %i", xpos, ypos);
				al_flip_display();
			}
		}
	}

	//destroying all the pointers that were made to clear up those spaces in memory
	al_destroy_display(display);
	al_destroy_event_queue(eventQueue);
	al_destroy_font(font24);
}
