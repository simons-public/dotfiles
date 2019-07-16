# .vimrc

## Vim Plugins

### Install vim-plug If Not Available

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

### Vim Plugins

    call plug#begin('~/.vim/plugged')
        Plug 'flazz/vim-colorschemes'
        Plug 'xolox/vim-misc'
        Plug 'xolox/vim-colorscheme-switcher'
        Plug 'Raimondi/delimitMate'
        Plug 'nathanaelkane/vim-indent-guides'
        Plug 'Lokaltog/vim-powerline', { 'branch': 'develop' }
        Plug 'tpope/vim-fugitive'
    call plug#end()

### Install Plugins on First Run

    if exists("g:first_run")
        PlugInstall
    endif

### Powerline settings

    let g:Powerline_symbols = 'fancy'

## Vim Settings

### Skip Defaults

    let skip_defaults_vim=1

### Disable vi-Compatible Mode

    set nocompatible

### Show Hybrid (Relative + Absolute)

    set number relativenumber

### Don't Show the Mode

    set noshowmode

### Set Smaller Number Gutter

    set numberwidth=1

### Enable Syntax Highlighting

    syntax enable

### Highlight Current Line

    set cursorline

### Highlight Currrent Column

    set cursorcolumn

### Highlight 80 Character Margin

    set colorcolumn=80

### Set Dark Background

    set background=dark

### Use F5 for paste toggle

    set pastetoggle=<F5>

### Auto Smart Indentation

    set smartindent

### Tabs

    set tabstop=4
    set softtabstop=4
    set shiftwidth=4
    set expandtab

### Show Matching Brackets

    set showmatch

### Highlight Searching

    set hlsearch

### Incremental Searching

    set incsearch

### Ignore Case While Searching

    set ignorecase

### Unless Searching with Uppercase Characters

    set smartcase

### Show Commands Being Typed

    set showcmd

### Set Longer Command History

    set history=1000

### Set Longer Undo History

    set undolevels=1000

### Search Further for Modelines

    set modelines=9000

### Disable Bells

    set noerrorbells
    set novisualbell

### Disable Startup Message

    set shortmess+=I

### Don't Use Backup Files (swp)

    set nobackup

### Use Tab Completion Menu

    set wildmenu

### Allow Buffer Switch Without Saving

    set hidden

### Switch to Existing Tab for Buffers

    set switchbuf=usetab,newtab

### Set Default Split Direction

    set splitbelow
    set splitright

### Always Show Tabs

    set showtabline=2

### Always Show Status Line

    set laststatus=2

### Don't Obscure Long Lines with @

    set display=lastline

### Set Shell for !commands

    set shell=/bin/sh

### Use Mouse in Insert Mode

    set mouse=i

### Enable Folding

    set foldenable
    set foldmethod=syntax

### Reload Files When Changed

    set autoread

### Always Allow Backspace

    set backspace=indent,eol,start

### Change Nonprinting Characters

    set listchars=tab:\ \ ,trail:█,space:\ ,eol:↩,extends:…,precedes:…,trail:\ ,conceal:*

### persistent undo

    if has('persistent_undo')
        set undofile undodir=~/.vim/undo
    endif

### Abbreviations

## Typos

    ab teh the

## Command Shortcuts

    ab tn tabn
    ab tp tabp

## Default to Vertical Split

    ab hsplit split
    ab split vsplit

## Auto Commands

### Auto Open New Buffers in Tabs

    autocmd VimEnter,BufAdd,BufNewFile * tabo | tab sball

### Highlight Trailing Whitespace & Real Tabs

    autocmd BufWinEnter,BufWinLeave,InsertEnter,InsertLeave <buffer> match Cursor /\s\+$/
    autocmd BufWinEnter,BufWinLeave,InsertEnter,InsertLeave <buffer> match Cursor /\t/

### Insert sheband and set x flag for scripts

    augroup SHEBANG
        au!
        au BufEnter *.sh if getline(1) == ""| :call setline(1, "#!/usr/bin/env bash") | endif
        au BufEnter *.py if getline(1) == ""| :call setline(1, "#!/usr/bin/env python") | endif
        au BufEnter *.awk if getline(1) == ""| :call setline(1, "#!/usr/bin/env awk -f") | endif
        au BufWritePost * if getline(1) =~ "#!/.*"| :!chmod a+x <afile>
    augroup END

### Expand tabs in makefiles

    autocmd FileType make setlocal noexpandtab

### openssl encrypted files

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

## Keymaps

### Also Use Semicolon for Commands

    nore ; :
    nore , ;

### Page Down with Space in Normal Mode

    nore <Space> <c-D>

### Switch Buffer Shortcuts

    map <C-n> :tabn <Enter>
    map <C-p> :tabp <Enter>

### Execute Script Shortcut

    map <C-b> :new \| r!./#<Enter>

### Window Command Shortcuts

    nore <C-l> :wincmd l <Enter>
    nore <C-h> :wincmd h <Enter>
    nore <C-k> :wincmd k <Enter>
    nore <C-j> :wincmd j <Enter>

### Quit with C-x

    nore <C-x> :q <Enter>

### Quick Switch to Command Mode with jj

    imap jj <Esc>

### Sudo Write with w!! Command

    cmap w!! w !sudo tee % >/dev/null

## Functions

### Load Templates

    fu! Template()
        let $template = "~/.vim/templates/" . input("Template: ") . ".template"
        read $template
    endfunction
    ca template call Template()

## Color Settings

### Highlights

    function! SetHighlights()
        highlight CursorLine   cterm=NONE   ctermbg=black term=NONE
        highlight CursorColumn cterm=NONE   ctermbg=black term=NONE
        highlight ColorColumn  cterm=NONE   ctermbg=black term=NONE
        highlight LineNR       ctermbg=none ctermfg=green term=NONE
        highlight TabLineFill  cterm=none   ctermbg=black term=NONE
    endfunction

    augroup ColorChange
        autocmd!
        autocmd ColorScheme * call SetHighlights()
    augroup END

### Colorscheme

    colorscheme getafe
