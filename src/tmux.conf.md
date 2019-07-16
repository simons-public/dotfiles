# tmux.conf

## tmux settings

    if shell "which /usr/local/bin/bash" "set-option -g default-shell /usr/local/bin/bash"
    if-shell "which /opt/local/bin/bash" "set-option -g default-shell /opt/local/bin/bash"
    set-option -g status on
    set-option -g status-interval 2

### use 256 colors

    set -g default-terminal "screen-256color"

### increase scrollback

    set -g history-limit 2000

### start window indexing at one instead of zero

    set -g base-index 1

### set the prefix key

    set -g prefix C-b

### enable window titles

    set -g set-titles on

### window title string (uses statusbar variables)

    set -g set-titles-string '#T'

### status bar with load and time

    set -g status-position bottom
    set -g status-bg 'colour236'
    set -g status-fg 'colour247'

### status left

    set -g status-left-length 50
    set -g status-left '\
        #[bg=colour148]#[fg=colour22] #(hostname -s | tr '[:lower:]' '[:upper:]') \
        #[bg=colour240]#[fg=colour250] #I #T '

### status right

    set -g status-right-length 100
    set -g status-right '  #W | #{pane_id} | #{client_cwd} \
        #[bg=colour239]#[fg=colour250]  W:#{client_width} H:#{client_height} \
        #[bg=colour252]#[fg=colour16]  %H:%M \
        #[fg=colour244] %d%b%y '

set -g window-status-format ''
set -g window-status-current-format ''

### bind r to reload config

bind r source-file ~/.tmux.conf
