nnoremap # "

# .vimrc

## vim-plug

    if !filereadable(expand("$HOME/.vim/autoload/plug.vim"))
        :echom "Installing vim-plug"
        let g:plug_url = "https://raw.github.com/junegunn/vim-plug/master/plug.vim"
        let g:first_run = "1"
        silent !mkdir -p ~/.vim/autoload
        if executable("fetch")
            :echom "fetch exists"
        elseif executable("curl")
            execute "!curl -sfLo ~/.vim/autoload/plug.vim " . g:plug_url
        elseif executable("wget")
            :echom "wget exists"
        endif
    endif

## Vim plugins

    call plug#begin('~/.vim/plugged')
        Plug 'altercation/vim-colors-solarized'
        Plug 'Raimondi/delimitMate'
        Plug 'nathanaelkane/vim-indent-guides'
        Plug 'Lokaltog/vim-powerline', { 'branch': 'develop' }
        Plug 'tpope/vim-fugitive'
    call plug#end()

## Install plugins

    if exists("g:first_run")
        PlugInstall
    endif

## Powerline settings

    let g:Powerline_symbols = 'fancy'

## Abbreviations

    ab teh the

## Vim Settings

    tab sball               "Use tabs for new buffers
    syntax enable           "Turn on syntax highlighting
    syntax on               "Overule syntax with default
    set nocompatible        "Get out of vi-compatible mode
    set nu                  "Turn on line numbers
    set relativenumber!     "Relative line numbers
    set cursorline          "Highlight current line
    set cursorcolumn        "Highlight current column
    set pastetoggle=<F5>    "F5 paste toggle
    set cryptmethod=blowfish "use blowfish instead of zip enc
    set autoindent          "Auto indent
    set smartindent         "Smart indent
    set tabstop=4           "Smaller tabs
    set softtabstop=4       "fix delete on space tabs
    set shiftwidth=4
    set showmatch           "Show matching brackets
    set incsearch           "Incremental searching
    set t_ti= t_te=         "Keep vim on screen
    set ruler               "Keep vim ruler on
    set history=1000        "Long history
    set undolevels=1000     "Long undo history
    set hidden              "Change buffer without saving
    set ignorecase          "Ignore case when searching
    set hlsearch            "Highlight searches
    set incsearch           "Incremental search
    set nolazyredraw        "Don't redraw while executing macros
    set magic               "Set magic on for regex
    set showmatch           "Highlight matching brackets
    set noerrorbells        "No sound on errors
    set novisualbell        "No blink on errors
    set shortmess+=I        "Disable startup message
    set showcmd             "Show the command being typed
    set expandtab           "No real tabs
    set numberwidth=1       "Number gutter small (will expand)
    set wildmenu            "Cool tab completion
    set smartcase           "Smart text case
    set nobackup            "Dont use backup files
    set laststatus=2        "Show status line always
    set title               "Set xterm title
    set titleold=""         "No "Thanks for flying Vim"
    set wrap lbr            "Wrap lines between words
    set display=lastline    "Don't hide lines that are too long with @
    set switchbuf=usetab,newtab
    set shell=/bin/sh       "Use /bin/sh for !command
    set mouse=i            "Mouse support
    set foldenable          "Turn on folding
    "set foldmethod=marker   "Enable marker folds: {{{}}}
    set foldmethod=syntax
    set autoread            "auto reload when file changes
    set backspace=2         "let backspace work like other editors
    "set listchars=tab:\ ⋅,eol:↩,extends:…,trail:⋅  "better list characters"
    set colorcolumn=80      "highlight column 80

## Insert sheband and set x flag for scripts

    augroup SHEBANG
        au!
        au BufEnter *.sh if getline(1) == ""| :call setline(1, "#!/usr/bin/env bash") | endif
        au BufEnter *.py if getline(1) == ""| :call setline(1, "#!/usr/bin/env python") | endif
        au BufEnter *.awk if getline(1) == ""| :call setline(1, "#!/usr/bin/env awk -f") | endif
        au BufWritePost * if getline(1) =~ "#!/.*"| :!chmod a+x <afile>
    augroup END

## Save view options

    au BufWinLeave * silent! mkview
    au BufWinEnter * silent! loadview

## Load new vimrc changes

    autocmd! BufWritePost .vimrc source ~/.vimrc

## Expand tabs in makefiles

    autocmd FileType make setlocal noexpandtab

## openssl encrypted files

    augroup AES
        au!
        au BufReadPre *.aes256 set bin
        au BufReadPre *.aes256 set viminfo=
        au BufReadPre *.aes256 set noswapfile
        au BufReadPost *.aes256 let $vimpass = inputsecret("Password: ")
        au BufReadPost *.aes256 silent '[,']!openssl aes-256-cbc -d -a -pass env:vimpass
        au BufReadPost *.aes256 set nobin
        au BufWritePre *.aes256 set bin
        au BufWritePre *.aes256 '[,']!openssl aes-256-cbc -a -salt -pass env:vimpass
        au BufWritePost *.aes256 u
        au BufWritePost *.aes256 set nobin
    augroup END

## Change term settings for lin/mac

    set background=dark

## allow semicolon for command mode

    nore ; :
    nore , ;

## Page down with space in normal mode

    nore <Space> <c-D>

## Shift Move

    nore <S-j> jjjjj
    nore <S-k> kkkkk
    nore <S-h> hhhhh
    nore <S-l> lllll

## Buffer shortcuts

    map <C-n> :bn <Enter>
    map <C-p> :bp <Enter>

## execute script shortcut

    map <C-b> :new \| r!./#<Enter>

## Wincmds

    "nore <C-l> :wincmd l <Enter>
    "nore <C-h> :wincmd h <Enter>
    "nore <C-k> :wincmd k <Enter>
    "nore <C-j> :wincmd j <Enter>

## Easy switch modes with jj

    imap jj <Esc>

## Sudo write with w!! command

    cmap w!! w !sudo tee % >/dev/null

## Cheatsheet

    fu! Cheat()
        new cheat
        read ~/.vim/cheatsheet.txt
        nore q :q!<enter>
    endfunction
    ca cheat call Cheat()

## Templates

    fu! Template()
        let $template = "~/.vim/templates/" . input("Template: ") . ".template"
        read $template
    endfunction
    ca template call Template()

## Higlight trailing whitespace

    highlight TrailingWhitespace ctermbg=red guibg=red
    match TrailingWhitespace /\s\+$/

## Hilight cursorline/column

    hi CursorLine cterm=NONE ctermbg=black
    hi CursorColumn cterm=NONE ctermbg=black

## Hilight number gutter

    hi LineNR ctermbg=none ctermfg=green

## Colorscheme

    colorscheme default
