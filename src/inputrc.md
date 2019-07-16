# .inputrc

## vi mode

### vi mode editing

    set editing-mode vi
    set keymap vi-insert

### show the vi mode in prompt

    set show-mode-in-prompt
    set vi-ins-mode-string ""
    set vi-cmd-mode-string "⩗ "

## Completion

### allow single-tab completion

    set show-all-if-ambiguous on

### ignore completion case

    set completion-ignore-case
    set completion-map-case

### colorize completions

    set colored-completion-prefix
    set colored-stats

### show visible stats in completion

    set visible-stats

### allow up/down key history search

    "\e[A": history-search-backward
    "\e[B": history-search-forward

## Shortcuts

### add C-a/C-e/C-l shortcuts in vi-keymap

    Control-a: beginning-of-line
    Control-e: end-of-line
    Control-l: clear-screen

### edit command with ctrl+x

    Control-x: edit-and-execute-command

## Misc

### reload inputrc

    Control-.: re-read-init-file

### blink matching parenthesis

    set blink-matching-paren
