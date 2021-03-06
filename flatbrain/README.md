# Flatbrain

A heavily vertical staggered 44 keys keyboard. Heavily inspired by the fabulous [Kyria](https://splitkb.com).

Make example for this keyboard (after setting up your build environment):

    make flatbrain:default       

## Layouts 
### Default Qwerty Layer

```
,-------------------------------------------.                              ,-------------------------------------------.
|   Tab  | Q    | W    | E    | R    | T    |                              | Y    | U    | I    | O    | P    | `~     |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|   Esc  | A    | S    | D    | F    | G    |                              | H    | J    | K    | L    | ; :  | ' "    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
| Shift  | Z    | X    | C    | V    | B    |                              | N    | M    | , <  | . >  | / ?  | CTRL   |
`----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
         | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Lead |
         `------'                    `------+------+------'  `------+------+------'                    `------'
```
### Colemak-dhm Layer

```
,-------------------------------------------.                              ,-------------------------------------------.
|   Tab  | Q    | W    | F    | P    | B    |                              | J    | L    | U    | Y    | ; :  | `~     |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|   Esc  | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | ' "    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
| Shift  | Z    | X    | C    | D    | V    |                              | K    | H    | , <  | . >  | / ?  | CTRL   |
`----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
         | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Super|
         `------'                    `------+------+------'  `-------+------+-----'                    `------'
```

### Lower Layer

```
,-------------------------------------------.                              ,-------------------------------------------.
|  = +   | / ?  | 7 &  | 8 *  | 9 (  | - _  |                              |      | Home | Up   | End  | Pg up|        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | . >  | 4 $  | 5 %  | 6 ^  | +    |                              |      | Left | Down | Right| Pgdwn|        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        | 0 )  | 1 !  | 2 @  | 3 #  | *    |                              | Vol d| Vol u| Play | Mute | PSCR |        |
`--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
         | Alt  |                    | Enter|      |      |   |      |      |     |                    | Clmk |
         `------'                    `------+------+------'   `------+------+-----'                    `------'
```

### Raise Layer

```
,-------------------------------------------.                              ,-------------------------------------------.
| ` ~    | !    | @    | #    | $    | %    |                              | \ |  | &    | *    | SAI  | HUI  | VAI    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        |      | [ {  | ] }  | (    | )    |                              | [ {  | ] }  | \ |  | SAD  | HUD  | VAD    |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|   F1   | F2   | F3   | F4   | F5   | F6   |                              | F7   | F8   | F9   | F10  | F11  | F12    |
`--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
         | Reset|                    |      |      |      |   |     |      |      |                    |      |
         `------'                    `------+------+------'   `-----+------+-----'                     `------'
```

## Layer template

```
/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * `--------+------+--------------------+------+------+------.  ,------+------+------+--------------------+------+--------'
 *          |      |                    |      |      |      |  |      |      |      |                    |      |
 *          `------'                    `------+------+------'  `------+------+------'                    `------'
 */ 
    [_LAYERINDEX] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
               _______,                   _______, _______, _______, _______, _______, _______,                   _______
    ),
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

