# .bashrc

## bash rc script

### safety: return if not running interactively

    [ -z "$PS1" ] && return

### Reset Terminal Colors for Command Outputs

    PS0=$(tput sgr0)

### Prompts

    test -f ~/.config/dotfiles/bin/bashprompt &&\
        export PROMPT_COMMAND='PS1="$(~/.config/dotfiles/bin/bashprompt ${?})"'
    PS2="↝ "
    PS4="${EPOCHREALTIME}↝ "

### Source completion files if available

    [ -f /usr/local/etc/bash_completion ] &&\
        source /usr/local/etc/bash_completion
    [ -f /opt/local/etc/profile.d/bash_completion.sh ] &&\
        source /opt/local/etc/profile.d/bash_completion.sh

### add /usr/local/bin to path

    test -d /usr/local &&\
        export PATH="/usr/local/bin:$PATH"

### add macports path

    test -d /opt/local &&\
        export PATH="/opt/local/bin:/opt/local/sbin:${PATH}" &&\
        export MANPATH="/opt/local/share/man:${MANPATH}"

### sudo aliases for admin commands

    for i in systemctl service reboot port; do
        alias ${i}="sudo ${i}"
    done

### Typo correction

    alias sl=ls
    alias gerp=grep
    alias Grep=grep

### macOS Terminal.app prompt_command

    type update_terminal_cwd &>/dev/null && export PROMPT_COMMAND+="; update_terminal_cwd"

### xterm 256 colors

    export TERM="xterm-256color"

### ls colors

    export LSCOLORS="exfxcxdxbxegedabagacad"
    export LS_COLORS="rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:"
    alias ls="ls -G"

### fix cd typos

    shopt -s cdspell

### auto cd to directory when typed as a command (v4+ only)

    shopt -s autocd 2>/dev/null

### set vim as $EDITOR

    export EDITOR="vim"

### use line numbers in less

    # alias less="less -N"

### use vim as pager and man

    if which vim >/dev/null; then
        function vless() { [[ -p /dev/stdin ]] && view -c "map q ZQ" - || view -c "map q ZQ" ${@}; }
        alias less=vless
        function vman()  { view -c "map q ZQ q" -c "runtime ftplugin/man.vim" -c "Man ${@}" -c "only"; }
        alias man=vman
    fi

### alias for google-chrome

    MAC_CHROME="/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
    test -f "${MAC_CHROME}" &&\
        alias google-chrome='"${MAC_CHROME}"'

### save to pdf using chrome headless

    function saveweb() {
        google-chrome --headless --print-to-pdf "$@" &&\
        echo "File saved to output.pdf"
    }

### cd extension

    function cd() {
        builtin cd "${@}"
        [[ -d .git ]] && git status && git log --pretty=oneline -n 5 --graph --abbrev-commit
    }

### command not found handle

    function command_not_found_handle() {
        cmd=${1}

        if ssh-keygen -F ${cmd} &>/dev/null ; then
            echo "ssh ${cmd}"
            ssh ${cmd}
            return 0
        fi

        [[ $cmd =~ ^[a-zA-Z0-9_]*$ ]] && if ! [ -z ${!cmd} ]; then
            echo ${cmd}: ${!cmd}
            return 0
        fi

        [ -z "$2" ] && if host ${cmd} &>/dev/null ; then
            dig +short ${cmd}
            return 0
        fi

        while true; do
            printf "\aYou didn't say the magic word!"
            sleep 1
        done
    }

### esp-idf activation

    function esp_activate() {
        export IDF_PATH=~/esp/esp-idf
        if ! echo ${PATH} | grep esp
          then
          source ~/esp/esp-idf/add_path.sh
        fi
    }

### common aliases

    alias ll='ls -la'
    alias la='ls -a'

### use pythonrc

    [[ -f ~/.pythonrc ]] && export PYTHONSTARTUP=~/.pythonrc

### prefer python3 if available

    which python3>/dev/null && alias python=python3

### set encoding

    export LANG=en_US.UTF-8

### use xresources

    if test -e /tmp/.X11-unix/X0; then
        export DISPLAY=:0
        which xrdb &>/dev/null &&\
            test -f ~/.Xresources &&\
            xrdb ~/.Xresources &>/dev/null
    fi

### don't echo control characters

    stty -echoctl

### shortcut to source ble.sh

    BLE_PATH=~/.config/dotfiles/lib/ble/ble.sh
    test -f $BLE_PATH &&\
        alias ble="source $BLE_PATH"
