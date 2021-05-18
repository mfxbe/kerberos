// Kerberos - Kosy Lockscreen
// Copyright © 2020 Kosy Team <kosyteam.github.io>
// This project is available as GPLv3, see LICENCE.md
#include "input-inhibitor.h"
#include <gtk/gtk.h>
#include <wayland-client.h>
#include <gdk/wayland/gdkwayland.h>

static struct wl_registry* wlRegistry = NULL;
struct wl_seat *wl_seat;
static struct zwlr_input_inhibit_manager_v1 *input_inhibit_manager = NULL;

//there are some unimportant signals which must be connected this function is used for those
static void not_care(){/*nobody cares*/};

static void wl_registry_handle_global(void *data, struct wl_registry *wlRegistry, uint32_t id, const char *interface, uint32_t version){
	if (strcmp (interface, zwlr_input_inhibit_manager_v1_interface.name) == 0){
		//bind and add listener if fitting protocol (input_inhibit_manager) is found
		input_inhibit_manager = wl_registry_bind(wlRegistry, id, &zwlr_input_inhibit_manager_v1_interface, 1);
	}
}
static const struct wl_registry_listener registry_listener = {
	.global = wl_registry_handle_global,
	.global_remove = not_care,
};

void inhibit_input(){
	GdkDisplay* gdkDisplay = gdk_display_get_default();
	struct wl_display* wlDisplay = gdk_wayland_display_get_wl_display(gdkDisplay);
	GdkSeat *gdk_seat = gdk_display_get_default_seat(gdkDisplay);
	wl_seat = gdk_wayland_seat_get_wl_seat(gdk_seat);
	wlRegistry = wl_display_get_registry(wlDisplay);
	wl_registry_add_listener(wlRegistry, &registry_listener, NULL);
	wl_display_roundtrip(wlDisplay);
	
	if (input_inhibit_manager == NULL){
		g_print("Error: Can't reach inhibit manager.\n");
	}
	
	zwlr_input_inhibit_manager_v1_get_inhibitor(input_inhibit_manager);
}
