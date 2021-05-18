// Kerberos - Kosy Lockscreen
// Copyright © 2020 Kosy Team <kosyteam.github.io>
// This project is available as GPLv3, see LICENCE.md
#ifndef _ACTIONS_H
#define _ACTIONS_H

void quit_cb(GObject*);
void check_shiftlock(GtkEventControllerKey*, GdkEvent*, GtkWidget*);
void check_passwd(GtkWidget*);
void focus_entry(GtkWidget*, GtkWidget*);

gboolean check_notifications(GDBusProxy*);
void set_notifications(GtkWidget*, int);

void system_call_generic();
void system_call_suspend(GtkWidget*);
void system_call_shutdown(GtkWidget*);

#endif
