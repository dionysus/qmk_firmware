#include QMK_KEYBOARD_H

void display_num(int num){
  switch(num){
    case 0: oled_write_P(PSTR("0"), false); break;
    case 1: oled_write_P(PSTR("1"), false); break;
    case 2: oled_write_P(PSTR("2"), false); break;
    case 3: oled_write_P(PSTR("3"), false); break;
    case 4: oled_write_P(PSTR("4"), false); break;
    case 5: oled_write_P(PSTR("5"), false); break;
    case 6: oled_write_P(PSTR("6"), false); break;
    case 7: oled_write_P(PSTR("7"), false); break;
    case 8: oled_write_P(PSTR("8"), false); break;
    case 9: oled_write_P(PSTR("9"), false); break;
  }
}

void display_nums(int num) {
  if (num < 0) {
    oled_write_P(PSTR("-"), false);
    num = -num;
  } else {
    oled_write_P(PSTR("+"), false);
  }

  //print 100s
  int digit = floor(num / 100);
  display_num(digit);
  num -= digit * 100;

  // print 10s
  digit = floor(num / 10);
  display_num(digit);
  num -= digit * 10;

  //print 1s
  display_num(num);
}
