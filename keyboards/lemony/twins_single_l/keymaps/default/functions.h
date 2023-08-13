#include QMK_KEYBOARD_H

// increments to the next layer and returns its value
int increment_layer(int curr_layer, int num_layers){
  int next_layer = (curr_layer + 1) % num_layers;
  layer_move(next_layer);
  return next_layer;
}

// decrements to the next layer and returns its value
int decrement_layer(int curr_layer, int num_layers){
  int next_layer = (curr_layer - 1) % num_layers;
  layer_move(next_layer);
  return next_layer;
}
