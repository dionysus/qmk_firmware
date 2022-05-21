
void tap_num(int num){
  switch(num){
    case 0: tap_code(KC_0); break;
    case 1: tap_code(KC_1); break;
    case 2: tap_code(KC_2); break;
    case 3: tap_code(KC_3); break;
    case 4: tap_code(KC_4); break;
    case 5: tap_code(KC_5); break;
    case 6: tap_code(KC_6); break;
    case 7: tap_code(KC_7); break;
    case 8: tap_code(KC_8); break;
    case 9: tap_code(KC_9); break;
  }
}

void tap_nums(int num){
  int digit;
  if (num > 100) {
    digit = floor(num / 100);
    tap_num(digit);
    num -= digit * 100;
  }

  digit = floor(num / 10);
  tap_num(digit);
  num -= digit * 10;

  tap_num(num);
}
