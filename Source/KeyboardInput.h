/****************************************************************************
 *  File name: PlayerInput.h
 *  Description:
 *      - Handles any sort of playerside keyboard input.
 *        TODO: Implement gamepad support

*****************************************************************************/
#pragma once

/* Constants                      */


/* Enums                          */

//Keycode declarations
enum class VKey
{
  VKey_UNKNOWN = 0,

  VKey_RETURN = '\r',
  VKey_ESCAPE = '\033',
  VKey_BACKSPACE = '\b',
  VKey_TAB = '\t',
  VKey_SPACE = ' ',
  VKey_EXCLAIM = '!',
  VKey_QUOTEDBL = '"',
  VKey_HASH = '#',
  VKey_PERCENT = '%',
  VKey_DOLLAR = '$',
  VKey_AMPERSAND = '&',
  VKey_QUOTE = '\'',
  VKey_LEFTPAREN = '(',
  VKey_RIGHTPAREN = ')',
  VKey_ASTERISK = '*',
  VKey_PLUS = '+',
  VKey_COMMA = ',',
  VKey_MINUS = '-',
  VKey_PERIOD = '.',
  VKey_SLASH = '/',
  VKey_0 = '0',
  VKey_1 = '1',
  VKey_2 = '2',
  VKey_3 = '3',
  VKey_4 = '4',
  VKey_5 = '5',
  VKey_6 = '6',
  VKey_7 = '7',
  VKey_8 = '8',
  VKey_9 = '9',
  VKey_COLON = ':',
  VKey_SEMICOLON = ';',
  VKey_LESS = '<',
  VKey_EQUALS = '=',
  VKey_GREATER = '>',
  VKey_QUESTION = '?',
  VKey_AT = '@',
  VKey_LEFTBRACKET = '[',
  VKey_BACKSLASH = '\\',
  VKey_RIGHTBRACKET = ']',
  VKey_CARET = '^',
  VKey_UNDERSCORE = '_',
  VKey_BACKQUOTE = '`',
  VKey_a = 'a',
  VKey_b = 'b',
  VKey_c = 'c',
  VKey_d = 'd',
  VKey_e = 'e',
  VKey_f = 'f',
  VKey_g = 'g',
  VKey_h = 'h',
  VKey_i = 'i',
  VKey_j = 'j',
  VKey_k = 'k',
  VKey_l = 'l',
  VKey_m = 'm',
  VKey_n = 'n',
  VKey_o = 'o',
  VKey_p = 'p',
  VKey_q = 'q',
  VKey_r = 'r',
  VKey_s = 's',
  VKey_t = 't',
  VKey_u = 'u',
  VKey_v = 'v',
  VKey_w = 'w',
  VKey_x = 'x',
  VKey_y = 'y',
  VKey_z = 'z',

  VKey_CAPSLOCK = 0x40000039,

  VKey_F1 = 0x4000003A,
  VKey_F2 = 0x4000003B,
  VKey_F3 = 0x4000003C,
  VKey_F4 = 0x4000003D,
  VKey_F5 = 0x4000003E,
  VKey_F6 = 0x4000003F,
  VKey_F7 = 0x40000040,
  VKey_F8 = 0x40000041,
  VKey_F9 = 0x40000042,
  VKey_F10 = 0x40000043,
  VKey_F11 = 0x40000044,
  VKey_F12 = 0x40000045,

  VKey_PRINTSCREEN = 0x40000046,
  VKey_SCROLLLOCK = 0x40000047,
  VKey_PAUSE = 0x40000048,
  VKey_INSERT = 0x40000049,
  VKey_HOME = 0x4000004A,
  VKey_PAGEUP = 0x4000004B,
  VKey_DELETE = '\177',
  VKey_END = 0x4000004D,
  VKey_PAGEDOWN,
  VKey_RIGHT,
  VKey_LEFT,
  VKey_DOWN,
  VKey_UP,

  VKey_NUMLOCKCLEAR,
  VKey_KP_DIVIDE,
  VKey_KP_MULTIPLY,
  VKey_KP_MINUS,
  VKey_KP_PLUS,
  VKey_KP_ENTER,
  VKey_KP_1,
  VKey_KP_2,
  VKey_KP_3,
  VKey_KP_4,
  VKey_KP_5,
  VKey_KP_6,
  VKey_KP_7,
  VKey_KP_8,
  VKey_KP_9,
  VKey_KP_0,
  VKey_KP_PERIOD,

  VKey_APPLICATION = 0x40000065,
  VKey_POWER,
  VKey_KP_EQUALS,
  VKey_F13,
  VKey_F14,
  VKey_F15,
  VKey_F16,
  VKey_F17,
  VKey_F18,
  VKey_F19,
  VKey_F20,
  VKey_F21,
  VKey_F22,
  VKey_F23,
  VKey_F24,
  VKey_EXECUTE,
  VKey_HELP,
  VKey_MENU,
  VKey_SELECT,
  VKey_STOP,
  VKey_AGAIN,
  VKey_UNDO,
  VKey_CUT,
  VKey_COPY,
  VKey_PASTE,
  VKey_FIND,
  VKey_MUTE,
  VKey_VOLUMEUP,
  VKey_VOLUMEDOWN,
  VKey_KP_COMMA = 0x40000085,
  VKey_KP_EQUALSAS400,

  VKey_ALTERASE = 0x40000099,
  VKey_SYSREQ,
  VKey_CANCEL,
  VKey_CLEAR,
  VKey_PRIOR,
  VKey_RETURN2,
  VKey_SEPARATOR,
  VKey_OUT,
  VKey_OPER,
  VKey_CLEARAGAIN,
  VKey_CRSEL,
  VKey_EXSEL,

  VKey_KP_00 = 0x400000B0,
  VKey_KP_000,
  VKey_THOUSANDSSEPARATOR,
  VKey_DECIMALSEPARATOR,
  VKey_CURRENCYUNIT,
  VKey_CURRENCYSUBUNIT,
  VKey_KP_LEFTPAREN,
  VKey_KP_RIGHTPAREN,
  VKey_KP_LEFTBRACE,
  VKey_KP_RIGHTBRACE,
  VKey_KP_TAB,
  VKey_KP_BACKSPACE,
  VKey_KP_A,
  VKey_KP_B,
  VKey_KP_C,
  VKey_KP_D,
  VKey_KP_E,
  VKey_KP_F,
  VKey_KP_XOR,
  VKey_KP_POWER,
  VKey_KP_PERCENT,
  VKey_KP_LESS,
  VKey_KP_GREATER,
  VKey_KP_AMPERSAND,
  VKey_KP_DBLAMPERSAND,
  VKey_KP_VERTICALBAR,
  VKey_KP_DBLVERTICALBAR,
  VKey_KP_COLON,
  VKey_KP_HASH,
  VKey_KP_SPACE,
  VKey_KP_AT,
  VKey_KP_EXCLAM,
  VKey_KP_MEMSTORE,
  VKey_KP_MEMRECALL,
  VKey_KP_MEMCLEAR,
  VKey_KP_MEMADD,
  VKey_KP_MEMSUBTRACT,
  VKey_KP_MEMMULTIPLY,
  VKey_KP_MEMDIVIDE,
  VKey_KP_PLUSMINUS,
  VKey_KP_CLEAR,
  VKey_KP_CLEARENTRY,
  VKey_KP_BINARY,
  VKey_KP_OCTAL,
  VKey_KP_DECIMAL,
  VKey_KP_HEXADECIMAL,

  VKey_LCTRL = 0x400000E0,
  VKey_LSHIFT,
  VKey_LALT = 0x400000E2,
  VKey_LGUI,
  VKey_RCTRL,
  VKey_RSHIFT,
  VKey_RALT,
  VKey_RGUI,
  VKey_MODE = 0x40000101,

  VKey_AUDIONEXT,
  VKey_AUDIOPREV,
  VKey_AUDIOSTOP,
  VKey_AUDIOPLAY,
  VKey_AUDIOMUTE,
  VKey_MEDIASELECT,
  VKey_WWW,
  VKey_MAIL,
  VKey_CALCULATOR,
  VKey_COMPUTER,
  VKey_AC_SEARCH,
  VKey_AC_HOME,
  VKey_AC_BACK,
  VKey_AC_FORWARD,
  VKey_AC_STOP,
  VKey_AC_REFRESH,
  VKey_AC_BOOKMARK,

  VKey_BRIGHTNESSDOWN,
  VKey_BRIGHTNESSUP,
  VKey_DISPLAYSWITCH,
  VKey_KBDILLUMTOGGLE,
  VKey_KBDILLUMDOWN,
  VKey_KBDILLUMUP,
  VKey_EJECT,
  VKey_SLEEP,
  VKey_APP1,
  VKey_APP2,

  VKey_AUDIOREWIND,
  VKey_AUDIOFASTFORWARD,
};


bool KeyPressed(VKey key);

bool KeyIsDown(VKey key);

bool KeyIsUp(VKey key);
