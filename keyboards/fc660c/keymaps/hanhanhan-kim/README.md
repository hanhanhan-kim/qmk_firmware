# Han's Keymap for Large Spacebar Keyboards

This keymap has two main goals:

1. Encourages thumb multi-functionality, even though the keyboard has a full-sized spacebar.
2. Encourages resting the fingers on the home position. 
3. Maintains a 'default' keymap, in addition to the various features presented here; reduces muscle memory confusion when using someone else's board. 

To achieve the above goals, this keymap *does **not** make heavy use of layering* (:open_mouth:), because positioning a layer key that is easily accessible from the home position is difficult. Rather, this keymap consists of only the base layer, and an additional layer that consists of ancillary features—for opening programs, mouse control, and media keys. To toggle between the two layers, press what on the default keymap is the "Caps Lock". If on the layer with the ancillary features, the red indicator LED on what was originally the "Caps Lock" key will light up. If on the regular base layer, the indicator LED will turn off. 

The F-keys (F1 to F12) are on the ancillary layer, mapped from "1" to "=" / "+". 

This keymap does not have the "Insert" key (:grimacing:) or the "Caps Lock" key (:open_mouth:). If you need to exercise the text version of shouting, just hold down the "shift"  key with your pinky. The heavy use of the pinky here might seem antithetical to the ergonomic goals stated above, but it's not unlike how shouting is tiring IRL, and should be discouraged. If you need to use shouting-case because of programming conventions ... ah well. I replaced the "Insert" key with the "PrintScreen" key. 

This keymap also works for larger keyboards, such as TKL or a full-sized keyboard, because a mid-60-something% keyboard is a subset of these larger keyboards. 

This keymap is for use with Linux or Windows, and not for Mac. 

This keymap's features are as follows:

## Punctuation Chords

The FC660C has a full-sized spacebar, and so it discourages any multi-functionality via thumb strokes, e.g. via thumb clusters or split-spacebars. To get around this issue, I've multiplexed the spacebar so that on the base layer, *when the space bar is pressed **simultaneously** with a key that sits on or near the home row, it outputs a piece of punctuation that is otherwise hard to reach*—for example, because it requires the wrist to move, and/or because it places strain on the pinky fingers. The requirement for simultaneous key-pressings is sometimes called **chording**.

Punctuation keys that I think people use most frequently are mapped to a chord that uses the spacebar and the index finger. Less frequently used punctuation keys are mapped to a chord that uses the spacebar and the middle finger, followed by a chord that uses the spacebar and the ring finger, and finally, by a chord that uses the spacebar and the pinky (:pensive:). 

This keymap uses the following chords:

| Input Chord  | Output Punctuation |
| ------------ | ------------------ |
| spacebar + f | (                  |
| spacebar + j | )                  |
| spacebar + d | [                  |
| spacebar + k | ]                  |
| spacebar + s | {                  |
| spacebar + l | }                  |
| spacebar + a | <                  |
| spacebar + ; | >                  |
| spacebar + w | #                  |
| spacebar + e | _                  |
| spacebar + r | -                  |
| spacebar + u | +                  |
| spacebar + i | =                  |

As you might have noticed, the first eight punctuation chords have similar logic to [space cadet shifts](https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_space_cadet), but without the use of the pinky (with the exception of the "<" and "'>'" characters). 

Importantly, if these chords aren't your thing, no worries! The regular way of accessing these punctuation characters still exists. 

## Mouse Control

This keymap has a single layer, in addition to the default base layer. This additional layer consists of ancillary features, including the ability to control the mouse. 

| Input Key       | Output Mouse Control |
| --------------- | -------------------- |
| d               | :arrow_left:         |
| f               | :arrow_down:         |
| j               | :arrow_up:           |
| k               | :arrow_right:        |
| spacebar (tap)  | left click           |
| spacebar (hold) | right click          |

As you might have noticed, the :arrow_left:, :arrow_down:, :arrow_up:, :arrow_right: sequence from left to right on the keyboard is identical to Vim's mapping of the insertion point onto the "h", "j", "k", and "l" keys.  The difference, however, is that my mappings sit underneath the index and middle fingers of the home row. 

## Media Control

This keymap has a single layer, in addition to the default base layer. This additional layer consists of ancillary features, including the ability to control media. It can open up commonly used software via a macro, or control audio/video. We've already seen the mouse control features of the ancillary layer. We will now look at the other features: 

### Starting Up Software

These macros work for both Linux and Windows. In the case of terminal / Git Bash, tapping like normal results in opening up the terminal on Linux (and will have no effect on Windows), but holding down the key will result in opening up Git Bash on Windows (and something nonsensical on Linux). 

The keys I have for opening up software I frequently use are:

| Input Key | Output Software                             |
| --------- | ------------------------------------------- |
| t (tap)   | Terminal (Linux only)                       |
| t (hold)  | Git Bash (Windows only)                     |
| x         | Nautilus (Linux) or File Explorer (Windows) |
| v         | VS Code                                     |
| c         | Google Chrome                               |
| s         | Signal                                      |
| a         | Arduino IDE                                 |
| y         | Typora                                      |
| m         | Spotify                                     |

If you wish to customize this layer, make sure not to map anything onto "d", "f", "j", "k" or spacebar, because those keys encode mouse control. 

An important note about using the keys on the ancillary layer to open up software: unlike other keys on this layer, *opening up software via a key on this layer will return the keyboard to the **base layer***. 

### Audio/Video Control

The audio/video controls are mapped onto the arrow keys and the "enter" key:

| Input Key | Output Media Control |
| --------- | -------------------- |
| ←         | Previous track       |
| ↓         | Volume down          |
| ↑         | Volume up            |
| →         | Next track           |
| Enter     | Play or pause media  |

Pressing the audio/video control keys (and any other keys on this layer that don't open up software) will not send the keyboard back to its base layer.

## Programming Shortcuts

The following features enable ease of use when programming—especially in Python—and are cosmetic, more than anything. 

When writing docstrings in Python, text must be flanked from above and below with triple quotes (either single or double, doesn't matter, so long as they're consistent). To output a pair of triple single quotes, simply hold down the quote key. To output a pair of triple double quotes, hold down shift, then hold down the quote key.

Similarly, when writing code blocks in Markdown, text must be flanked from above and below with triple backticks (```). To output a pair of triple backticks, simply hold down the backtick / "Esc" key. 

Sixty-something-% keyboards tend not to have a dedicated "Esc" key. Rather, "Esc" is often overloaded onto the same key for ` (backtick) and ~ (tilde). To access "Esc" on this keymap, simply double-tap the backtick/tilde key. Tap to access the backtick and shift and tap to access the tilde. 

The key to the immediate left of the left arrow key encodes for both "home" and "end". Tap to execute "home", and hold down to execute "end". The "home"/"end "key is placed here because when navigating the insertion point in the terminal, your right hand tends to have already moved to the vicinity of the arrow keys. At least for me, I use the "home" and "end" keys most frequently when on the terminal. 

The "tab" key executes a regular tab when tapped, but when held, executes "shift" + "tab". This function is useful for unindenting code, and for navigating through programs when in the "alt" + "tab" menu; "tab" navigates to the program on the right, whereas "shift" + "tab" navigates to the program on the left. 

In summary, the programming shortcuts are:

| Input Key                                                | Output Keystroke      |
| -------------------------------------------------------- | --------------------- |
| quote (hold)                                             | '''<br /><br />'''    |
| double quote (hold)                                      | """<br /><br />"""    |
| backtick (hold)                                          | ````<br /><br />````` |
| backtick (tap)                                           | `                     |
| backtick (double-tap)                                    | Esc                   |
| whatever key is to the left of the left arrow key (tap)  | Home                  |
| whatever key is to the left of the left arrow key (hold) | End                   |
| Tab (tap)                                                | Tab                   |
| Tab (hold)                                               | Shift + Tab           |





