#pragma once
#ifndef LYRICBAR_UI_H
#define LYRICBAR_UI_H
#include <gtk/gtk.h>
#include <deadbeef/deadbeef.h>

#include "utils.h"

#ifdef __cplusplus

#include <glibmm/ustring.h>

using namespace std;

bool isValidHexaCode(string str);

void set_lyrics(DB_playItem_t * track, Glib::ustring past, Glib::ustring present, Glib::ustring future, Glib::ustring padding);

void sync_or_unsync(bool syncedlyrics);

vector<int> sizelines(DB_playItem_t * track, Glib::ustring lyrics);

void get_tags();

extern "C" {
#endif

GtkWidget *construct_lyricbar();

int message_handler(struct ddb_gtkui_widget_s *, uint32_t id, uintptr_t ctx, uint32_t, uint32_t);

void lyricbar_destroy();

#ifdef __cplusplus
}
#endif

#endif // LYRICBAR_UI_H
