#include <pebble.h>
Window *window;
TextLayer *text_layer;
 // defining init and deinit
void init() {
  // creating the text layer in the init
   window = window_create();
   text_layer = text_layer_create(GRect(0, 0, 144, 40));
   text_layer_set_text(text_layer, "Pebble");
   // horizontal alignment
   // See https://developer.getpebble.com/docs/c/User_Interface/Layers/TextLayer/#text_layer_set_text_alignment
   text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
   // vertical alignment
   // See https://forums.getpebble.com/discussion/12492/vertical-text-alignment
   // not implemented yet
  
   layer_add_child(window_get_root_layer(window),
                   text_layer_get_layer(text_layer));
   window_stack_push(window, true);
}
void deinit() {
   text_layer_destroy(text_layer);
   window_destroy(window);
}
   // defining main
int main() {
  init();
  app_event_loop();
  deinit();
  return 0;
}
